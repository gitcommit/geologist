#include <Lib/GUI/Widgets/MainWindow.h>

#include <QtGui/QAction>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QApplication>

#include <Lib/GUI/Widgets/LogWidget.h>
#include <App/App.h>

MainWindow::MainWindow(QWidget* p)
  : QMainWindow(p)
{
  setMinimumWidth(800);
  setMinimumHeight(600);
  setupMenu();
  logW_ = new LogWidget(this);
  setCentralWidget(logW_);
  connect((qobject_cast<App*>(QApplication::instance())), SIGNAL(databaseOpened(const QString&)), this, SLOT(onDatabaseOpened(const QString&)));
  connect((qobject_cast<App*>(QApplication::instance())), SIGNAL(databaseClosed()), this, SLOT(onDatabaseClosed()));
  connect((qobject_cast<App*>(QApplication::instance())), SIGNAL(databaseMessage(const QString&)), this, SLOT(onDatabaseMessage(const QString&)));
  connect(this, SIGNAL(databaseMessage(const QString&)), logW_, SLOT(onDatabaseMessage(const QString&)));
}

MainWindow::~MainWindow()
{}

void MainWindow::onDatabaseMessage(const QString& msg) {
  emit databaseMessage(msg);
}

void MainWindow::setupMenu() {
  dbM_ = new QMenu(tr("&Database"), this);
  connectA_ = new QAction(tr("&Open..."), this);
  connectA_->setShortcut(QKeySequence("Ctrl+o"));
  connect(connectA_, SIGNAL(triggered()), (qobject_cast<App*>(QApplication::instance())), SLOT(onOpenDb()));
  disconnectA_ = new QAction(tr("&Close"), this);
  disconnectA_->setShortcut(QKeySequence("Ctrl+d"));
  connect(disconnectA_, SIGNAL(triggered()), (qobject_cast<App*>(QApplication::instance())), SLOT(onCloseDb()));
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
