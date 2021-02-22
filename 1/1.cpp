
#include <iostream>

using namespace std;
const int N = 10;
class Figure {
public:
	string name;
	virtual void Message() {
		printf("!\n");
	}
};

class Circle : public Figure {
	void Message() {
		printf("Circle\n");
	}
};

class Square : public Figure {
	void Message() {
		printf("Square\n");
	}
};


int main()
{
	Figure* f[N];
	for (int i = 0; i < N;i++) {
		if (rand() % 2 == 0)
			f[i] = new Circle;
		else
			f[i] = new Square;
		
	}
	for (int i = 0; i < N;i++) {
		f[i]->Message();
	}
	return 0;
}


