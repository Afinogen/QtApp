#include "maincontroller.h"

MainController::MainController()
{
}
MainController::~MainController()
{

}
void MainController::connectDB()
{
    setupDB();
    qDebug() << "begin connect db";
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(databasePath);
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
void MainController::setupDB()
{
    QString tmpString = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QFileInfo databaseFileInfo(QString("%1/%2").arg(tmpString).arg("keaz.db"));
    databasePath = databaseFileInfo.absoluteFilePath();
    qDebug() << "databasePath: "+databasePath;  // to display full name with path of database

    if ( !databaseFileInfo.exists() )
    {
        qDebug()<<"Database does not exist";
        #ifdef Q_OS_ANDROID
        bool copySuccess = QFile::copy( QString("assets:/keaz.db"), databasePath );
        if ( !copySuccess )
        {
            QMessageBox::critical(this, "Error:", QString("Could not copy database from 'assets' to %1").arg(databasePath));
            databasePath.clear();
        }
        #else
        Downloader *d=new Downloader();
        d->getDB("http:://test.ru/keaz.db",databasePath);
        #endif
    }
}
