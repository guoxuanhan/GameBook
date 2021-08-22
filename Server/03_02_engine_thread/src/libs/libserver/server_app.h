#pragma once
#include "disposable.h"
#include "thread_mgr.h"
#include "common.h"

template<class APPClass>
inline int MainTemplate()
{
    APPClass* pApp = new APPClass();    //创建一个服务器对象
    pApp->InitApp();                    //初始化APP
    pApp->StartAllThread();             //启动所有线程
    pApp->Run();                        //update函数，程序会一直在这里循环，知道收到退出信号
    pApp->Dispose();                    //退出后，执行Dispose函数处理关闭后事宜
    delete pApp;
    return 0;
}

class ServerApp : public IDisposable
{
public:
    ServerApp(APP_TYPE  appType);
    ~ServerApp();

    virtual void InitApp() = 0;
    void Dispose() override;

    void StartAllThread() const;
    void Run() const;
    void UpdateTime() const;

    bool AddListenerToThread(std::string ip, int port) const;

protected:
    ThreadMgr * _pThreadMgr;
    APP_TYPE _appType;
};

