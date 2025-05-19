#include "../src/stapler_engine.h"
#include <iostream>
using namespace std;

int tstfunc(int a) {
	cout << "func called " << a << endl;
	return a;
}

class tstcls{
public:
	int clsfunc(int a) {
		cout << "cls called " << a << endl;
		return a;
	}	
};

int main() {
	se::SDelegate<int(int)> tstdel;
	tstcls tstc;
	tstdel.join(&tstfunc);
	tstdel.join(&tstc, &tstcls::clsfunc);
	tstdel.join([](int a)->int {
		cout << "lambda called " << a << endl;
		return a;
		});

	vector<int> results;
	tstdel.invoke(results, 2);
	for (auto& it : results) {
		cout << "invk res " << it << endl;
	}

	system("pause");

	return 0;
}