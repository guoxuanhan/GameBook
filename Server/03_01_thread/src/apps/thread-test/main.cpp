#include <thread>
#include <iostream>

void ThreadTest1( int value ) {
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "thread test. value:" << value << std::endl;
}

int main( int argc, char *argv[] ) {
	int value = 1;
	std::thread t1( ThreadTest1, value );

	//t1.join( );//���߳̽���ǰ��ȴ����߳��˳����˳�
	t1.detach();//���̴߳����̷߳��룬���̲߳���ȴ����߳�

	std::cout << "exit main" << std::endl;
	return 0;
}