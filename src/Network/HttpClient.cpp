#include "HttpClient.h"

#include <QtNetwork>
#include <qlogging.h>

namespace Lumen {
    void HttpClient::startRequest(const QUrl& requestedUrl, const QString& file) {
        startRequest(requestedUrl);
        m_file = file.trimmed();
    }

    void HttpClient::startRequest(const QUrl& requestedUrl) {
        m_file.clear();
        m_url = requestedUrl;
        m_httpRequestAborted = false;

        m_reply.reset(m_qnam.get(QNetworkRequest(m_url)));
        connect(m_reply.get(), &QNetworkReply::finished, this, &HttpClient::httpFinished);
    }

    void HttpClient::cancelDownload() {
        m_reply->abort();
    }

    void HttpClient::httpFinished() {
        if (!m_file.isEmpty()) {
            QFile file(m_file);
            if (!file.open(QIODevice::WriteOnly)) {
                qWarning() << "Unable to write to" << file.fileName() << ":" << file.errorString();
            } else {
                file.write(m_reply->readAll());
                file.close();
            }
        }

        emit downloadFinished(m_reply.data());
    }
}

