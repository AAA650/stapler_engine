#include "stapler_engine.h"
#include <iostream>
using namespace std;

void add_vector(smath::SVector2& vec) {
	vec += smath::SVector2(1, 1);
}

int main() {
	PROPERTY(int, val, { return value + 1; }, { value = in_arg + 1; });
	val.set(22);
	cout << val() << endl;
	se::SDelegate<void(smath::SVector2&)> dele1;
	dele1.join(add_vector);
	smath::SVector2 vector2(0.1f, 5);
	dele1.invoke(vector2);
	printf("%f,%f\n", vector2.x_, vector2.y_);

	cout << "Thanks for using Stapler Engine!" << endl;
	//system("pause");
	return 0;
}