#pragma once

#include <thread>
#include <list>

#include "thread_obj.h"
#include "sn_object.h"

//线程类并不关心这个流水线上的包裹有什么用，它只需要在更新时遍历Objlist中的所有对象，调用这些对象的Update帧函数即可。
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
    // 本线程的所有对象    
    std::list<ThreadObject*> _objlist;
    std::list<ThreadObject*> _tmpObjs;
    std::mutex _thread_lock;

    bool _isRun;
    std::thread _thread;
};

