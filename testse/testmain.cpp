#include "../src/stapler_engine.h"
using namespace se;

#pragma comment(lib, "stapler_engine.lib")

class test {
public:
	void testout() {
		std::cout << "test!" << std::endl;
	}
};

int main() {
	test ttsstt;
	SDelegate testdelegate;
	testdelegate.join<test, void>(&test::testout, &ttsstt);
	testdelegate.invoke();
	system("pause");
	return 0;
}