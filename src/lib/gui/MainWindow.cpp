#include <MainWindow.h>

#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QApplication>

#include <LogWidget.h>
#include <App.h>

MainWindow::MainWindow(QWidget* p)
  : QMainWindow(p)
{
  setMinimumWidth(800);
  setMinimumHeight(600);
  setupMenu();
  logW_ = new LogWidget(this);
  setCentralWidget(logW_);
  connect(this, SIGNAL(databaseMessage(const QString&)), logW_, SLOT(onDatabaseMessage(const QString&)));
  connect((qobject_cast<App*>(QApplication::instance())), SIGNAL(databaseOpened(const QString&)), this, SLOT(onDatabaseOpened(const QString&)));
  connect((qobject_cast<App*>(QApplication::instance())), SIGNAL(databaseClosed()), this, SLOT(onDatabaseClosed()));
}

MainWindow::~MainWindow()
{}

void MainWindow::onDatabaseMessage(const QString& msg) {
  emit databaseMessage(msg);
}

void MainWindow::setupMenu() {
  dbM_ = new QMenu(tr("&Database"), this);
  connectA_ = new QAction(tr("&Open..."), this);
  connect(connectA_, SIGNAL(triggered()), (qobject_cast<App*>(QApplication::instance())), SLOT(openDb()));
  disconnectA_ = new QAction(tr("&Close"), this);
  connect(disconnectA_, SIGNAL(triggered()), (qobject_cast<App*>(QApplication::instance())), SLOT(closeDb()));
  dbM_->addAction(connectA_);
  dbM_->addAction(disconnectA_);
  menuBar()->addMenu(dbM_);
}

void MainWindow::onDatabaseOpened(const QString& info) {
  connectA_->setEnabled(false);
  disconnectA_->setEnabled(true);
}

void MainWindow::onDatabaseClosed() {
  connectA_->setEnabled(true);
  disconnectA_->setEnabled(false);
}
