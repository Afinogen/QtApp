#include "maincontroller.h"

MainController::MainController()
{
}
MainController::~MainController()
{

}
void MainController::connectDB()
{
    qDebug() << "begin connect db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("keaz.db");
    qDebug() << "open db: " << db.open();
}
void MainController::closeDB()
{
    qDebug() << "close db ";
    db.close();
}
TreeModel *MainController::createTreeView()
{
    TreeModel *model = new TreeModel();
    createTreeItem(model->getRoot(),1);
    return model;
}
void MainController::createTreeItem(TreeItem *parentItem, int parentId)
{
    QSqlQuery qry;
    qDebug() << "SELECT * FROM `product_category` WHERE `parent_id`='"+QString("%1").arg(parentId)+"';";
    if (qry.exec("SELECT * FROM `product_category` WHERE `parent_id`='"+QString("%1").arg(parentId)+"';"))
    {
        // если запрос выполнен, то запускаем цикл перехода по каждой
        // строке
        while(qry.next())
        {
            TreeItem *item = new TreeItem(QString(qry.value(4).toString()),parentItem);
            parentItem->appendChild(item);
            //QObject::connect(parentItem, SIGNAL(triggered()), this, SLOT(TreeItemClick()));
            createTreeItem(item,qry.value(0).toInt());
        }
    }
    else
    {
        qDebug() << qry.lastError();
    }
}
void MainController::TreeItemClick()
{
    qDebug() << "item click";
}
