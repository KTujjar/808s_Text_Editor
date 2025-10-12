#pragma once
#include <iostream>
#include <QMainWindow>
#include <QObject>
#include <QApplication>
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
