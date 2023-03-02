/* liveview.cpp
 *
 * Copyright (c) 2023 NicsMocs
 *
 * This file is subject to the terms and conditions defined in
 * file 'COPYING', which is part of this source code package.
 */
#include "liveview.h"
#include <QThread>
#include <QStandardPaths>

LiveView::LiveView(QObject *parent) :
    QObject(parent), m_process(new QProcess(this))
{
}

void LiveView::enableLiveView(bool enable)
{
    m_doLiveView = enable;
}

void LiveView::enableLiveViewDelayed()
{
    QThread::msleep(5000);
    m_doLiveView = true;
}

void LiveView::shutdownLiveView()
{
    m_stop = true;
}

void LiveView::run()
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation) + "/feed.jpg";
    while (true)
    {
        if(m_doLiveView)
        {
            m_process->start("bash", {"-c","gphoto2 --capture-movie --stdout | ffmpeg -i pipe:0 -frames:v 1 -y -s 1280x720 -preset ultrafast -tune zerolatency -q:v 2 "+desktopPath});
            m_process->waitForFinished();
            emit triggered();
        }
        if(m_stop)
        {
            emit finished();
        }
    }
}
