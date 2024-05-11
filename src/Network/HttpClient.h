#pragma once

#include <QNetworkAccessManager>
#include <QUrl>
#include <QtCore>
#include <qnetworkreply.h>

namespace Lumen {
    class HttpClient : public QObject {
        Q_OBJECT

    public:
        void startRequest(const QUrl& requestedUrl);
        void startRequest(const QUrl& requestedUrl, const QString& file);

    private slots:
        void cancelDownload();
        void httpFinished();

    signals:
        void downloadFinished(QNetworkReply* replay);

    private:
        QUrl m_url;
        QNetworkAccessManager m_qnam;
        QScopedPointer<QNetworkReply, QScopedPointerDeleteLater> m_reply;
        QString m_file;
        bool m_httpRequestAborted = false;
    };
}

