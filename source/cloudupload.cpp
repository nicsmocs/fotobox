/* cloudupload.cpp
 *
 * Copyright (c) 2023 NicsMocs
 *
 * This file is subject to the terms and conditions defined in
 * file 'COPYING', which is part of this source code package.
 */
#include "cloudupload.h"
#include "preferenceprovider.h"

#include <QDebug>
#include <QDir>

CloudUpload::CloudUpload(QObject *parent) :
    QObject(parent), m_process(new QProcess(this))
{
    QDir dir(FotoBox::PreferenceProvider::instance().photoFolder() + "/reduced");
    if(!dir.exists())
    {
        dir.mkpath(".");
    }
}

void CloudUpload::setPath(const QString& path)
{
    m_path=path;
}

void CloudUpload::run()
{
    auto strings = m_path.split("/");
    QString photoName = strings.at(strings.size()-1);
    QString picPathCLI = "@"+m_path;
    
    if(FotoBox::PreferenceProvider::instance().useCompression())
    {
        qDebug() << "Compression started";

        QString reducedDir = FotoBox::PreferenceProvider::instance().photoFolder() + "/reduced/";
        picPathCLI = "@"+reducedDir+photoName;
        QString sizeCLI = "--size=" + QString::number(FotoBox::PreferenceProvider::instance().cloudComprSize()) + "k";
        m_process->start("jpegoptim", {m_path, "-d", reducedDir, sizeCLI,"-q"});
        if(!m_process->waitForFinished())
        {
            qDebug() << m_process->errorString();
        }
    }
    
    qDebug() << "Upload started";

    QString userData = FotoBox::PreferenceProvider::instance().cloudUser() + ":" + FotoBox::PreferenceProvider::instance().cloudPassword();
    QString completeUploadUrl = FotoBox::PreferenceProvider::instance().cloudUrl() + "/" + photoName;
    m_process->start("curl", {"-i", "-X", "PUT", "-u", userData,"--data-binary", picPathCLI, completeUploadUrl});

    if(!m_process->waitForFinished())
    {
        qDebug() << m_process->errorString();
    }
    emit finished();
}
