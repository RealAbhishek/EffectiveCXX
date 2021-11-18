/*
 * =====================================================================================
 *
 *       Filename:  decltype.cpp
 *
 *    Description: Modern C++ `decltype` implementation
 *
 *
 *        Version:  1.0
 *        Created:  11/18/2021 07:52:33 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Abhishek Dubey (AD), abhishek@netc.eu
 *        Company:  ConstCast, Inc.
 *
 * =====================================================================================
 */

#include <iostream>
#include <chrono>
#include <thread>
#include <string>

bool authenticateUser()
{
	std::cout << "Reading session and authenticating user..." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	return true;
}

template<typename Container, typename Index>
auto authAndAccess(Container& c, Index i)
{
	authenticateUser();
	return c[i];
}

int main(int argc, char* argv[])
{
	std::string name = "Abhishek Dubey";
	int index = 9;
	auto value = authAndAccess(name, index);
	std::cout << value << std::endl;
	return 0;
}
