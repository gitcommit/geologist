#include <Lib/GUI/Widgets/MainWindow.h>

#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QApplication>

#include <Lib/GUI/Widgets/LogWidget.h>
#include <Lib/Tools/tools.h>
#include <App/App.h>

MainWindow::MainWindow(QWidget* p)
: QMainWindow(p) {
    setMinimumWidth(800);
    setMinimumHeight(600);
    setupMenu();
    _logW = new LogWidget(this);
    setCentralWidget(_logW);
    connect(getApp(), SIGNAL(databaseOpened(const QString&)), this, SLOT(onDatabaseOpened(const QString&)));
    connect(getApp(), SIGNAL(databaseClosed()), this, SLOT(onDatabaseClosed()));
    connect(getApp(), SIGNAL(databaseMessage(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
    connect(this, SIGNAL(databaseMessage(const QString&)), _logW, SLOT(onDatabaseMessage(const QString&)));
}

MainWindow::~MainWindow() {
}

void MainWindow::onDatabaseMessage(const QString& msg) {
    emit databaseMessage(msg);
}

void MainWindow::setupMenu() {
    _fM = new QMenu(tr("&File"), this);

    _quitA = new QAction(tr("&Quit"), this);
    _quitA->setShortcut(QKeySequence("Ctrl+q"));
    connect(_quitA, SIGNAL(triggered()), getApp(), SLOT(quit()));

    _dbM = new QMenu(tr("&Database"), this);

    _connectA = new QAction(tr("&Open..."), this);
    _connectA->setShortcut(QKeySequence("Ctrl+o"));
    connect(_connectA, SIGNAL(triggered()), getApp(), SLOT(onOpenDB()));

    _disconnectA = new QAction(tr("&Close"), this);
    _disconnectA->setShortcut(QKeySequence("Ctrl+d"));
    connect(_disconnectA, SIGNAL(triggered()), getApp(), SLOT(onCloseDB()));

    _dbM->addAction(_connectA);
    _dbM->addAction(_disconnectA);
    menuBar()->addMenu(_dbM);
}

void MainWindow::onDatabaseOpened(const QString& info) {
    _connectA->setEnabled(false);
    _disconnectA->setEnabled(true);
}

void MainWindow::onDatabaseClosed() {
    _connectA->setEnabled(true);
    _disconnectA->setEnabled(false);
}
