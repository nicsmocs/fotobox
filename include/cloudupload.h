/* cloudupload.h
 *
 * Copyright (c) 2023 NicsMocs
 *
 * This file is subject to the terms and conditions defined in
 * file 'COPYING', which is part of this source code package.
 */
#pragma once
#include <QProcess>

class CloudUpload : public QObject
{
    Q_OBJECT

public:
    CloudUpload(QObject *parent = nullptr);
    void setPath(const QString& path);

public slots:
    void run();

signals:
    void finished();
    
private:
    QProcess* m_process;
    QString m_path;
};
