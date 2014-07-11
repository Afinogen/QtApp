#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include "treeitem.h"
#include "treemodel.h"

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
    QSqlDatabase db;
private slots:
    void TreeItemClick();
};

#endif // MAINCONTROLLER_H
