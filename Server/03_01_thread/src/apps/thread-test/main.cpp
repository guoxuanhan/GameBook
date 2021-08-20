#include <thread>
#include <iostream>

void ThreadTest1( int value ) {
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::cout << "thread test. value:" << value << std::endl;
}

int main( int argc, char *argv[] ) {
	int value = 1;
	std::thread t1( ThreadTest1, value );

	//t1.join( );//主线程结束前会等待子线程退出再退出
	t1.detach();//子线程从主线程分离，主线程不会等待子线程

	std::cout << "exit main" << std::endl;
	return 0;
}