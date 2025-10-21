#include "EditorWindow.hpp"


EditorView::EditorView(QWidget *parent)
  : QPlainTextEdit(parent)
{
  setWordWrapMode(QTextOption::NoWrap);
  setFont(QFont("Consolas", 12));
  setReadOnly(true);
}

void EditorView::setModel(PieceTable *pt){
  model = pt;
  refresh();
}

void EditorView::refresh(){
  if(!model) return;
  setPlainText(QString::fromStdString(model->getFullText()));
  QTextCursor c = textCursor();
  c.setPosition(cursorIdx);
  setTextCursor(c);
}

void EditorView::keyPressEvent(QKeyEvent * e){
  if(!model || model->isEmpty()) return;

  if(e->matches(QKeySequence::Save)){
    emit saveRequested();
    return;
  }
  switch(e->key()){
    case Qt::Key_Left: cursorIdx = std::max(0, cursorIdx - 1); refresh(); return;
    case Qt::Key_Right: cursorIdx = std::min<int>(static_cast<int>(model->getFullText().size()), cursorIdx + 1); refresh(); return;
    case Qt::Key_Backspace:
      if (cursorIdx > 0) emit deleteRequested(cursorIdx - 1, cursorIdx);
        cursorIdx = std::max(0, cursorIdx - 1);
        refresh();
        return;
    case Qt::Key_Delete:
      emit deleteRequested(cursorIdx, cursorIdx + 1);
      refresh();
      return;
    case Qt::Key_Return:
    case Qt::Key_Enter:
      emit insertRequested(cursorIdx, "\n");
      cursorIdx++;
      refresh();
      return;
    default: break;
  }

  QString t = e->text();
  if (!t.isEmpty() && t.at(0).isPrint()) {
    std::string utf8 = t.toUtf8().toStdString();
    emit insertRequested(cursorIdx, utf8);
    cursorIdx += utf8.size();
    refresh();

  }
}
