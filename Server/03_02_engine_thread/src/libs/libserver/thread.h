#pragma once

#include <thread>
#include <list>

#include "thread_obj.h"
#include "sn_object.h"

//�߳��ಢ�����������ˮ���ϵİ�����ʲô�ã���ֻ��Ҫ�ڸ���ʱ����Objlist�е����ж��󣬵�����Щ�����Update֡�������ɡ�
class Thread : public SnObject, IDisposable {
public:
    Thread( );
    void AddThreadObj( ThreadObject* _obj );

    void Start( );
    void Stop( );
    void Update( );
    bool IsRun( ) const;
    void Dispose( ) override;
    
private:
    // ���̵߳����ж���    
    std::list<ThreadObject*> _objlist;
    std::list<ThreadObject*> _tmpObjs;
    std::mutex _thread_lock;

    bool _isRun;
    std::thread _thread;
};
