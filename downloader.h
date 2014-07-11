#ifndef DOWNLOADER_H
#define DOWNLOADER_H
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QFile>

class Downloader: public QObject
{
    Q_OBJECT
public:
    Downloader(QObject *parent=0);
    ~Downloader();
    void getDB(QString downPath, QString savePath);
private:
    QNetworkAccessManager *qnam;
    QString savePath;
private slots:
    void httpFinished(QNetworkReply *reply);
};

#endif // DOWNLOADER_H
