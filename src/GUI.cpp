#include "GUI.hpp"

void GUI::Window::drawMain(int argc,char *argv[], std::string text){

  QApplication app(argc, argv);
  window = new QWidget;
  QHBoxLayout *layout = new QHBoxLayout(window);
  window->setWindowTitle("808s");
  window->resize(800,600);

  QString myQString = QString::fromStdString(text);
  plainTextEdit = new QPlainTextEdit(window);
  plainTextEdit->setPlainText(myQString);

  //Creates CTRL+S Functionality
  QAction *saveFile = new QAction(("Save File"), window);
  saveFile->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
  QObject::connect(saveFile, &QAction::triggered, window, [=]() {
    handleEdit(text,getEditedText());
  });
  window->addAction(saveFile);

  layout->addWidget(plainTextEdit);
  app.setStyleSheet("QWidget {background-color: rgba(0,0,0,50); font-size: 24px; color: white;}");

  window->show();
  app.exec();
}

std::string GUI::Window::getEditedText()
{
  QTextDocument *textDocument = plainTextEdit->document();
  return textDocument->toPlainText().toStdString();
}

//When file saves handles next operations
void GUI::Window::handleEdit(std::string orig, std::string edited)
{
  QMessageBox::information(window, "Debug", "Hello");
}
