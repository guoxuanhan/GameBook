#pragma once
#include "disposable.h"

class Network;
class RecvNetworkBuffer;
class SendNetworkBuffer;
class Packet;

class ConnectObj : public IDisposable {
public:
	ConnectObj( Network* pNetWork, int socket );
	~ConnectObj( ) override;

	void Dispose( ) override;

	int GetSocket( ) const { return _socket; }

	/// <summary>
	/// �Ƿ��н��յ�����
	/// </summary>
	/// <returns></returns>
	bool HasRecvData( ) const;

	/// <summary>
	/// �����յ�������ת����packet
	/// </summary>
	/// <returns></returns>
	Packet* GetRecvPacket( ) const;

	bool Recv( ) const;

	/// <summary>
	/// �Ƿ���Ҫ��������
	/// </summary>
	/// <returns></returns>
	bool HasSendData() const;

	/// <summary>
	/// ����packet�е�����
	/// </summary>
	/// <param name="pPacket"></param>
	void SendPacket( Packet* pPacket ) const;
	bool Send( ) const;

protected:
	Network* _pNetWork{ nullptr };
	const int _socket;
	RecvNetworkBuffer* _recvBuffer{ nullptr };
	SendNetworkBuffer* _sendBuffer{ nullptr };
};

