#include "GUI.hpp"

void GUI::Window::drawMain(int argc,char *argv[], std::string text){
  QApplication app(argc, argv);

  QWidget *window = new QWidget;

  QHBoxLayout *layout = new QHBoxLayout(window);

  window->setWindowTitle("808s");
  window->resize(800,600);

  QString myQString = QString::fromStdString(text);

  QPlainTextEdit *plainTextEdit = new QPlainTextEdit(window);
  plainTextEdit->setPlainText(myQString);

  layout->addWidget(plainTextEdit);

  app.setStyleSheet("QWidget {background-color: rgba(0,0,0,50); font-size: 24px; color: white;}");

  window->show();
  app.exec();
}
