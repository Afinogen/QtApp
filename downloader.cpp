#include "downloader.h"

Downloader::Downloader(QObject *parent): QObject(parent)
{

}
Downloader::~Downloader()
{
}
void Downloader::getDB(QString downPath, QString savePath)
{
    qnam = new QNetworkAccessManager(this);
    this->savePath=savePath;
    connect(qnam, SIGNAL(finished(QNetworkReply *)), SLOT(httpFinished(QNetworkReply *)));
    qnam->get(QNetworkRequest(QUrl(downPath)));

}
void Downloader::httpFinished(QNetworkReply *reply)
{
    QFile file(savePath);
    if (file.open(QIODevice::WriteOnly))
    {
        file.write(reply->readAll());
        file.flush();
        file.close();
    }

    reply->deleteLater();
    reply = 0;
}

