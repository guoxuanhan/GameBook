#pragma once

#include "disposable.h"

class ThreadObject : public IDisposable {
public:
    virtual ~ThreadObject() {}

    virtual bool Init( ) = 0;//��ʼ������
    virtual void RegisterMsgFunction( ) = 0;//ע���Լ�����Ȥ��Э��
    virtual void Update( ) = 0;//֡��������������

    bool IsActive() const;

protected:
    bool _active { true };
};
