/* liveview.h
 *
 * Copyright (c) 2023 NicsMocs
 *
 * This file is subject to the terms and conditions defined in
 * file 'COPYING', which is part of this source code package.
 */
#pragma once
#include <QProcess>
#include <atomic>

class LiveView : public QObject
{
    Q_OBJECT

public:
    LiveView(QObject *parent = nullptr);
    void enableLiveView(bool enable);
    void enableLiveViewDelayed();
    void shutdownLiveView();

public slots:
    void run();

signals:
    void triggered();
    void finished();
    
private:
    std::atomic<bool> m_doLiveView{true};
    std::atomic<bool> m_stop{false};
    QProcess* m_process;
};
