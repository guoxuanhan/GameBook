#pragma once
#include <mutex>
#include <map>
#include <list>
#include <functional>

class Packet;

//回调函数
typedef std::function<void(Packet*)> HandleFunction;


/*
在这个类中，对4个函数的调用流程如下：
（1）在MessageList类初始化时需要调用RegisterFunction函数，主动注册协议号，并为该协议号指定一个处理函数。
（2）当有协议到达时，调用IsFollowMsgId函数判断一个协议号是否是自己关心的。如果是，就调用AddPacket函数将Packet类缓存，以便处理。
（3）在帧函数中调用ProcessPacket来处理缓存的Packet协议。每个线程包裹类ThreadObject继承自MessageList，也就是每个Actor模型类都有一个消息处理基类。
*/
class MessageList
{
public:
    //注册回调函数
    void RegisterFunction(int msgId, HandleFunction function);
    bool IsFollowMsgId(int msgId);
    void ProcessPacket();
    void AddPacket(Packet* pPacket);

protected:
    std::mutex _msgMutex;
    std::list<Packet*> _msgList; //待处理的Packet列表
    std::map<int, HandleFunction> _callbackHandle; //协议号对应的处理函数
};
