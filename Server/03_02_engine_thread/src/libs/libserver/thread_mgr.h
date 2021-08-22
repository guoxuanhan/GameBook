#pragma once

#include <mutex>

#include "common.h"
#include "thread.h"
#include "singleton.h"
#include <map>

class ThreadObject;


/*
�̹߳�������������Ҫ����
��1��ÿ֡���һ��ÿ���߳��Ƿ��ڹ��������߳�ȫ���˳���������˳���
��2���������̶߳��󡣵����µ��̰߳�����������߳�ʱ�����������ദ���Ὣ�¶�����õ�һ�����ʵ��߳��С�ThreadObject������֪���Լ�������ĸ��߳��С�
*/
class ThreadMgr :public Singleton<ThreadMgr> {
public:
    ThreadMgr( );
    void StartAllThread( ); //���������߳�
    bool IsGameLoop( );     //�����߳��Ƿ���������
    void NewThread( );
    void AddObjToThread( ThreadObject* obj );

    void Dispose( );

private:
    uint64 _lastThreadSn { 0 }; // ʵ���̶߳������

    std::mutex _thread_lock;
    std::map<uint64, Thread*> _threads;
};

