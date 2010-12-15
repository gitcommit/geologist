#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>

class QAction;
class QMenu;

class LogWidget;

class MainWindow : public QMainWindow {
    Q_OBJECT;
public:
    MainWindow(QWidget* p = 0);
    virtual ~MainWindow();

signals:
    void databaseMessage(const QString& msg);
public slots:
    void onDatabaseMessage(const QString& msg);
    void onDatabaseOpened(const QString& info);
    void onDatabaseClosed();
private:
    void setupMenu();

    LogWidget* _logW;
    QMenu* _fM;
    QMenu* _dbM;

    QAction* _quitA;
    QAction* _connectA;
    QAction* _disconnectA;
};

#endif
