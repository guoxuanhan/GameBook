#include <iostream>
#include "network/network.h"

int main(int argc, char *argv[])
{
	//1. 初始化网络环境（linux不需要）
	_sock_init();
	
	//2. 创建服务器监听套接字
	SOCKET socket = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (socket == INVALID_SOCKET)
	{
		std::cout << "::socket failed. err:" << _sock_err() << std::endl;
		return 1;
	}

	//3. 构造服务器地址和端口
	sockaddr_in addr;
	memset(&addr, 0, sizeof(sockaddr_in));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(2233);
	::inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

	//4. 绑定监听套接字到地址
	if (::bind(socket, reinterpret_cast<sockaddr *>(&addr), sizeof(addr)) < 0)
	{
		std::cout << "::bind failed. err:" << _sock_err() << std::endl;
		return 1;
	}

	//5. 监听网络
	int backlog = GetListenBacklog();
	if (::listen(socket, backlog) < 0)
	{
		std::cout << "::listen failed." << _sock_err() << std::endl;
		return 1;
	}

	//6. 等待客户端连接
	struct sockaddr socketClient;
	socklen_t socketLength = sizeof(socketClient);
	int newSocket = ::accept(socket, &socketClient, &socketLength);
	std::cout << "accept one connection" << std::endl;

	char buf[1024];
    memset(&buf, 0, sizeof(buf));
	auto size = ::recv(newSocket, buf, sizeof(buf), 0);
	if (size > 0)
	{
		std::cout << "::recv." << buf << std::endl;
		::send(newSocket, buf, size, 0);
		std::cout << "::send." << buf << std::endl;
	}

	_sock_close(socket);
	_sock_exit();
	return 0;
}

