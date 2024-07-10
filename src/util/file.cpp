//
// Created by Cjsah on 2024/7/10.
//

#include <QFile>
#include "file.h"

using namespace std;

QString readFile(const QString& name) {
    QFile qfs(name);
    if (qfs.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QByteArray fileData = qfs.readAll();
        qfs.close();
        return fileData;
    }

    return "";
}
