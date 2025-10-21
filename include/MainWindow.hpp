#pragma once

#include <QWidget>
#include <QMainWindow>
#include "PieceTable.hpp"
#include "EditorWindow.hpp"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void newFile();
    void openFile();
    void saveFile();
    void saveFileAs();

private:
    void createMenus();
    void connectSignals();

    PieceTable pt;
    EditorView *view;
    QString currentPath;
};
