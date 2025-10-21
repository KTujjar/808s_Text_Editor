#pragma once
#include <QtWidgets>
#include "PieceTable.hpp"  // your backend header
#include <QKeyEvent>

class EditorView : public QPlainTextEdit {
    Q_OBJECT
public:
    explicit EditorView(QWidget *parent = nullptr);

    void setModel(PieceTable *pt);
    void refresh();

signals:
    void insertRequested(int idx, const std::string &text);
    void deleteRequested(int begin, int end);
    void saveRequested();

protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    PieceTable *model = nullptr;
    int cursorIdx = 0;
};
