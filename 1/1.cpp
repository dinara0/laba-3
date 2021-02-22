
#include <iostream>

using namespace std;
const int N = 10;
class Iarray {
public:
	virtual void set_value(int i, int value) = NULL;
	virtual int get_value(int i) = NULL;
	virtual int delete_value(int i) = NULL;
	virtual void prev() = NULL;
	virtual void next() = NULL;
};
class Array : public Iarray {
private:
	int data[N];
	int curr;
public:

	virtual void set_value(int i, int value) = NULL;
	virtual int get_value(int i) {
		return
	}


	virtual int delete_value(int i) = NULL;
	virtual void prev() = NULL;
	virtual void next() = NULL;
};
};
	/*
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

*/
int main()
{
	Iarray
	return 0;
}


