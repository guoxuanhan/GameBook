#pragma once

#include "disposable.h"

class ThreadObject : public IDisposable {
public:
    virtual ~ThreadObject() {}

    virtual bool Init( ) = 0;//初始化函数
    virtual void RegisterMsgFunction( ) = 0;//注册自己感兴趣的协议
    virtual void Update( ) = 0;//帧函数，更新数据

    bool IsActive() const;

protected:
    bool _active { true };
};
