
#include <iostream>

using namespace std;
const int N = 10;

class Figure {
public:
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


class Iarray {
public:
	virtual void set_value(int i, Figure *value) = NULL;
	virtual Figure &get_value(int i) = NULL;
	//virtual int delete_value(int i) = NULL;
	//virtual void prev() = NULL;
	//virtual void next() = NULL;
	virtual int get_count() = NULL;
};
class Array : public Iarray {
private:
	Figure **objects;
	int i=0;
	int size;
public:
	Array(int size) {
		this->size = size;
		objects = new Figure * [size];
	}
	void set_value(int i, Figure *value) {
		objects[i] = value;
	}

	Figure &get_value(int i) {
		return *objects[i];
	}
	int get_count() {
		return size;
	}
	/*virtual int delete_value(int i) {
	
	}*/
	/*virtual void prev() {
		i--;
	}
	void next(int i) {
		i++;
	}*/
};


int main()
{
	//Array a(N);
	Iarray *a= new Array (N);
	for (int i = 0;i < a->get_count();i++)
		if (rand() % 2 == 0)
			a->set_value(i, new Circle);
		else 
			a->set_value(i, new Square);
	for (int i = 0;i < a->get_count();i++)
		a->get_value(i).Message();

	return 0;
}


