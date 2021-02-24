#include <iostream>
#include <ctime>
using namespace std;
const int N = 10;

class Figure {
private:
	int S = 0;
public:
	virtual void Message() {
		printf("!\n");
	}
};

class Circle : public Figure {
public:
	void Message() {
		printf("Circle\n");
	}
	void Circle_method() {
		printf("Circle_method()\n");
	}
};

class Square : public Figure {
public:
	void Message() {
		printf("Square\n");
	}
	void Square_method() {
		printf("Square_method()\n");
	}
};


class Iarray {
public:
	virtual void set_value(int i, Figure *value) = NULL;
	// функция добавления элемента 
	virtual Figure &get_value(int i) = NULL;
	// функция добавления элемента
	virtual void delete_value(int index) = NULL;
	// функция удаления элемента
	//virtual void prev() = NULL;
	//virtual void next() = NULL;
	virtual int get_count() = NULL;
	// функция возвращает размер массива
};
class Array : public Iarray {
private:
	Figure **objects; // указатель на указатель объекта класса Figure
	//int i;
	int maxsize;//размер массива
	int size;
public:
		Array(int size) {// конструктор 
		maxsize = size;
		this->size = maxsize;
		objects = new Figure * [size];// создаю массив из объектов
	}
	void set_value(int i, Figure *value) {
		if (i < 0 || i >= maxsize) {
			printf("Выход за границы массива\n");
			return;
		}
		if (i > size) {
			objects[size + 1] = value;
			size++;
			return;
		}
		objects[i] = value;
	}

	Figure &get_value(int i) {
		return *objects[i];
	}
	int get_count() {
		return size;
	}
	virtual void delete_value(int index) {
		if (index < 0 || index >= size) {
			printf("Выход за границы массива");
			return;
		}
		for (int i = index + 1, j = index; i < this->size; i++, j++) {
			objects[j] = objects[i];
		}
		this->size--;
	}
	/*virtual void prev() {
		i--;
	}
	void next(int i) {
		i++;
	}*/
};


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));// для генерации разных рандомных значений каждую отладку
	//Array a(N);
	Iarray *a= new Array (N);
	for (int i = 0;i < a->get_count();i++)
		//a->set_value(i, new Figure);
		if (rand() % 2 == 0)
			a->set_value(i, new Circle);
		else 
			a->set_value(i, new Square);
	for (int i = 0;i < a->get_count();i++) {
		printf("\t%i. ", i + 1);
		a->get_value(i).Message();
	}
	for (int i = 0; i < 100; i++) {
		int count = rand() % 3;
		//int n = a->get_count();
		int index = 0;
		//if (n)
			index = rand() % N;
		printf("%i. ", i+1);
		switch (count)
		{
		case 0:// создание и добавление в хранилище объекта
			
			if (index > a->get_count()) {
				a->set_value(index, new Circle);
				printf("добавление объекта Circle в ячейке\n");
				break;
		}

			if (rand() % 2 == 0) {
				a->set_value(index, new Circle);
				printf("создание объекта Circle в ячейке %i\n", index + 1);
			}
			else {
				a->set_value(index, new Square);
				printf("создание объекта Square в ячейке %i\n", index + 1);
			}
			break;
		case 1:// удаление объекта
			printf("удаление объекта: \n");
			if (a->get_count() == 0) {
				printf("Массив пуст\n");
				break;
			}
			a->delete_value(index);
			printf("объект из ячейки %i удален\n", index+1);
			

			break;
		case 2:// запуск метода у случайного объекта из хранилища
			printf("Вызывается метод объекта из ячейки %i\n", index+1);
			/*Circle* c = dynamic_cast<Circle*>(a->get_value(index));
			if (c != NULL)
				c->Circle_method();
			
			Square* s = dynamic_cast<Square*>(a->get_value(index));
			if (s != NULL)
				s->Square_method();*/
				a->get_value(index).Message();
			break;

	
			

		}
		printf("\n");
		for (int i = 0;i < a->get_count();i++) {
			printf("\t%i. ", i+1);
			a->get_value(i).Message();
		}
	}
	cout << "runtime = " << clock() / 1000.0 << endl; // время работы программы

	return 0;
}


