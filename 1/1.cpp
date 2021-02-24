#include <time.h>
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
	int size;//размер массива
public:
	Array(int size) {// конструктор 
		this->size = size;
		objects = new Figure * [size];// создаю массив из объектов
	}
	void set_value(int i, Figure *value) {
		if (i < 0 || i >= size) {
			printf("Выход за границы массива");
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
	srand(time(NULL));// для генерации разныъ рандомных значений кажду. отладку
	//Array a(N);
	Iarray *a= new Array (N);
	for (int i = 0;i < a->get_count();i++)
		//a->set_value(i, new Figure);
		if (rand() % 2 == 0)
			a->set_value(i, new Circle);
		else 
			a->set_value(i, new Square);
	for (int i = 0;i < a->get_count();i++)
		a->get_value(i).Message();
	for (int i = 0; i < 100; i++) {
		int count = rand() % 3;
		int n = a->get_count();
		int index = rand() % n;
		switch (count)
		{
		case 0:// создание и добавление в хранилище объекта
			
		
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
			if (a->get_count() == 0) {
				printf("Массив пуст");
				break;
			}
			a->delete_value(index);
			printf("объект из ячейки %i удален\n", index);
			

			break;
		case 2:// запуск метода у случайного объекта из хранилища
			printf("Вызывается метод объекта из ячейки %i\n", index+1);
			a->get_value(index).Message();
			
			break;

	
			

		}
	}
		printf("\n");
		for (int i = 0;i < a->get_count();i++)
			a->get_value(i).Message();


	return 0;
}


