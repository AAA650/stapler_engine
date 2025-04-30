#include "../src/stapler_engine.h"
using namespace se;

#pragma comment(lib, "stapler_engine.lib")

class test {
public:
	void testout(void* hhh) {
		std::cout << "test!" << std::endl;
	}
};

int main() {
	test ttsstt;
	SDelegate testdelegate;
	testdelegate.join<test, void, void*>(&test::testout, &ttsstt);
	testdelegate.invoke<void*>(nullptr);
	system("pause");
	return 0;
}