#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QFile>
#include <QFileInfo>
#include <QStandardPaths>
#include "treeitem.h"
#include "treemodel.h"
#include "downloader.h"

class MainController
{
public:
    MainController();
    ~MainController();
    void connectDB();
    void closeDB();
    TreeModel *createTreeView();
private:
    void createTreeItem(TreeItem *parentItem, int parentId);
    void setupDB();
    QSqlDatabase db;
    QString databasePath;
private slots:
    void TreeItemClick();
};

#endif // MAINCONTROLLER_H
