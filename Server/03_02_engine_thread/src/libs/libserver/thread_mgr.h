#pragma once

#include <mutex>

#include "common.h"
#include "thread.h"
#include "singleton.h"
#include <map>

class ThreadObject;


/*
线程管理类有两个主要任务：
（1）每帧检查一下每个线程是否还在工作，若线程全部退出，则进程退出。
（2）管理多个线程对象。当有新的线程包裹对象加入线程时，丢给管理类处理，会将新对象放置到一个合适的线程中。ThreadObject本身并不知道自己会加入哪个线程中。
*/
class ThreadMgr :public Singleton<ThreadMgr> {
public:
    ThreadMgr( );
    void StartAllThread( ); //启动所有线程
    bool IsGameLoop( );     //所有线程是否还在运行中
    void NewThread( );
    void AddObjToThread( ThreadObject* obj );

    void Dispose( );

private:
    uint64 _lastThreadSn { 0 }; // 实现线程对象均分

    std::mutex _thread_lock;
    std::map<uint64, Thread*> _threads;
};

