#pragma once
#include <QMainWindow>
#include <QMdiArea>
#include <QMdiSubWindow>
#include <QMenu>
#include <QMenuBar>
#include <QSizeGrip>
#include <QStatusBar>
#include <QToolBar>
#include <QWidgetAction>
#include <QTextEdit>
#include <QApplication>
#include <QPalette>
#include <QPlainTextEdit>
#include <QString>
#include <QHBoxLayout>

namespace GUI {
  class Window {
  public:
      void drawMain(int argc, char *argv[], std::string text);
  };
}
