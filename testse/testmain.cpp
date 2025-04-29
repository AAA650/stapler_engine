#include "../src/stapler_engine.h"
using namespace se;

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
}