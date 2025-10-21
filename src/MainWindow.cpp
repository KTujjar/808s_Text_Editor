#include "MainWindow.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("808s Editor");
    resize(900, 600);

    view = new EditorView(this);
    view->setModel(&pt);
    setCentralWidget(view);

    createMenus();
    connectSignals();
}

void MainWindow::createMenus() {
    QMenu *fileMenu = menuBar()->addMenu("&File");
    QAction *newAct = fileMenu->addAction("&New", this, &MainWindow::newFile, QKeySequence::New);
    QAction *openAct = fileMenu->addAction("&Open...", this, &MainWindow::openFile, QKeySequence::Open);
    fileMenu->addSeparator();
    QAction *saveAct = fileMenu->addAction("&Save", this, &MainWindow::saveFile, QKeySequence::Save);
    QAction *saveAsAct = fileMenu->addAction("Save &As...", this, &MainWindow::saveFileAs);
    fileMenu->addSeparator();
    fileMenu->addAction("E&xit", this, &QWidget::close);
}

void MainWindow::connectSignals() {
    connect(view, &EditorView::insertRequested, [&](int idx, const std::string &text) {
        pt.handleInsert(idx, text);
        view->refresh();
    });
    connect(view, &EditorView::deleteRequested, [&](int a, int b) {
        pt.handleDelete(a, b);
        view->refresh();
    });
    connect(view, &EditorView::saveRequested, this, &MainWindow::saveFile);
}

void MainWindow::newFile() {
    pt = PieceTable("");
    view->refresh();
    currentPath.clear();
}

void MainWindow::openFile() {
    QString path = QFileDialog::getOpenFileName(this, "Open File");
    if (path.isEmpty()) return;

    std::ifstream in(path.toStdString());
    std::string contents((std::istreambuf_iterator<char>(in)), {});
    pt = PieceTable(contents);
    currentPath = path;
    view->refresh();
}

void MainWindow::saveFile() {
    if (currentPath.isEmpty()) { saveFileAs(); return; }
    std::ofstream out(currentPath.toStdString(), std::ios::trunc);
    out << pt.getFullText();
}

void MainWindow::saveFileAs() {
    QString path = QFileDialog::getSaveFileName(this, "Save As");
    if (path.isEmpty()) return;
    currentPath = path;
    saveFile();
}
