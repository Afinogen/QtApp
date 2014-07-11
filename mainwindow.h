#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractItemModel>
#include "treemodel.h"
#include "maincontroller.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createMenus();
    Ui::MainWindow *ui;
private slots:
    void showMessage();
    void connectDB();
};

#endif // MAINWINDOW_H
