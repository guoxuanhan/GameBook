#pragma once
#include "disposable.h"
#include "thread_mgr.h"
#include "common.h"

template<class APPClass>
inline int MainTemplate()
{
    APPClass* pApp = new APPClass();    //����һ������������
    pApp->InitApp();                    //��ʼ��APP
    pApp->StartAllThread();             //���������߳�
    pApp->Run();                        //update�����������һֱ������ѭ����֪���յ��˳��ź�
    pApp->Dispose();                    //�˳���ִ��Dispose��������رպ�����
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

