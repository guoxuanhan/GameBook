#pragma once
#include <mutex>
#include <map>
#include <list>
#include <functional>

class Packet;

//�ص�����
typedef std::function<void(Packet*)> HandleFunction;


/*
��������У���4�������ĵ����������£�
��1����MessageList���ʼ��ʱ��Ҫ����RegisterFunction����������ע��Э��ţ���Ϊ��Э���ָ��һ����������
��2������Э�鵽��ʱ������IsFollowMsgId�����ж�һ��Э����Ƿ����Լ����ĵġ�����ǣ��͵���AddPacket������Packet�໺�棬�Ա㴦��
��3����֡�����е���ProcessPacket���������PacketЭ�顣ÿ���̰߳�����ThreadObject�̳���MessageList��Ҳ����ÿ��Actorģ���඼��һ����Ϣ������ࡣ
*/
class MessageList
{
public:
    //ע��ص�����
    void RegisterFunction(int msgId, HandleFunction function);
    bool IsFollowMsgId(int msgId);
    void ProcessPacket();
    void AddPacket(Packet* pPacket);

protected:
    std::mutex _msgMutex;
    std::list<Packet*> _msgList; //�������Packet�б�
    std::map<int, HandleFunction> _callbackHandle; //Э��Ŷ�Ӧ�Ĵ�����
};
