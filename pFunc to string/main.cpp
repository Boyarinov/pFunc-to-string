#include <string>
#include <iostream>
#include <sstream> 
using namespace std;


using callback_t = void(*)(string arg);
void callback(string data);
void call_callback(callback_t func);

int main()
{
	callback_t address = (reinterpret_cast<callback_t>(callback));
	std::stringstream ss;
	ss << address;
	std::string name = "0x" + ss.str();
	unsigned long ulBuffer;
	sscanf_s(name.c_str(), "%lx", &ulBuffer);

	callback_t newAddress = reinterpret_cast<callback_t>(static_cast<uintptr_t>(ulBuffer));
	cout << newAddress << endl;

	call_callback(newAddress);
	return 0;
}


void callback(string data)
{
	cout << data.c_str() << endl;
}

void call_callback(callback_t func)
{
	func("test_message");
}
