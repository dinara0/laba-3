
#include <iostream>
const int N = 100;
class Figure {

};

class Circle : public Figure {

};

class Square : public Figure {

};


int main()
{
	Figure* f[N];
	for (int i = 0; i < N;i++) {
		if (rand() % 2 == 0)
			f[i] = new Circle;
		else
			f[i] = new Sguare;

	}
}


