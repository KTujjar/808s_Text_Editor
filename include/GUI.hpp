#pragma once
#include <iostream>
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QSizeGrip>
#include <QStatusBar>
#include <QObject>
#include <QToolBar>
#include <QWidgetAction>
#include <QTextEdit>
#include <QApplication>
#include <QPalette>
#include <QPlainTextEdit>
#include <QString>
#include <QHBoxLayout>
#include <QAction>
#include <QMessageBox>

namespace GUI {
class Window {
  public:
    void drawMain(int argc, char *argv[], std::string text);
    std::string getEditedText();
  private:
    QPlainTextEdit *plainTextEdit;
    QWidget *window;
    void handleEdit(std::string orig, std::string edited);
  };
}
