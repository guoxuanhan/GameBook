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
	/// 是否有接收到数据
	/// </summary>
	/// <returns></returns>
	bool HasRecvData( ) const;

	/// <summary>
	/// 将接收到的数据转换成packet
	/// </summary>
	/// <returns></returns>
	Packet* GetRecvPacket( ) const;

	bool Recv( ) const;

	/// <summary>
	/// 是否需要发送数据
	/// </summary>
	/// <returns></returns>
	bool HasSendData() const;

	/// <summary>
	/// 发送packet中的数据
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

