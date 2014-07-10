#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createMenus()
{
    QMenu * mnFile = new QMenu("File"); // создаём меню Файл
    // ----------- здесь добавляем пункт меню и подключаем его к слоту----
    QAction *msgAction = new QAction("show Message",mnFile);
    connect(msgAction, SIGNAL(triggered()), this, SLOT(showMessage()));
    mnFile->addAction(msgAction);

    QAction * mnEdit = new QAction("Пуск",mnFile); // создаём меню Edit
    connect(mnEdit, SIGNAL(triggered()), this, SLOT(connectDB()));
    mnFile->addAction(mnEdit);
    QMenu * mnService = new QMenu("Service"); // Меню Сервис
    QMenu * mnHelp = new QMenu("Help"); // Меню помощь
    ui->menuBar->addMenu(mnFile); // Добавляем пункты меню в menuBar, т.е. те, которые будут отображаться в гл. окне
    //ui->menuBar->addMenu(mnEdit);
    ui->menuBar->addMenu(mnService);
    ui->menuBar->addMenu(mnHelp);


    QDirModel *model = new QDirModel;
    ui->treeView->setModel(model);
}

void MainWindow::showMessage()
{
    qDebug() << "menu clicked";
}

void MainWindow::connectDB()
{
    qDebug() << "begin connect db";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("customdb.db");
    qDebug() << db.open();
    QSqlQuery qry;
    if (qry.exec("SELECT * FROM `product_category`;"))
    {
        // если запрос выполнен, то запускаем цикл перехода по каждой
        // строке
        while(qry.next())
        {
            QAction *act = new QAction(qry.value(4).toString(),ui->treeView);
            ui->treeView->addAction(act);
        }
    }
    else
    {
        qDebug() << qry.lastError();
    }
}
