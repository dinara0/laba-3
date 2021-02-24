#include <iostream>
#include <ctime>
using namespace std;
const int N = 10;

class Figure {
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

};

class Square : public Figure {
public:
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
	virtual int get_count() = NULL;
	// функция возвращает размер массива
};
class Array : public Iarray {
private:
	Figure **objects; // указатель на указатель объекта класса Figure
	int maxsize;//размер массива максимальный
	int size; // размер массива
public:
		Array(int size) {// конструктор 
		maxsize = size;
		this->size = maxsize;
		objects = new Figure * [size];// создаю массив из объектов
	}
	void set_value(int i, Figure *value) {
		if (i < 0 || i >= maxsize) {// если индекс выходит за размеры массива
			printf("Выход за границы массива\n");
			return;
		}
		if (i > size) {// если индекс больше нынещнего размера массива, но меньше максимального
			objects[size + 1] = value;//добавляем объект в свободную ячейку
			size++;
			return;
		}
		objects[i] = value;// вставляем элемент вместо другого объекта
	}

	Figure &get_value(int i) {
		return *objects[i];//возвращаем объект по индексу
	}
	int get_count() {
		return size;//возвращаем нынешний размер массива
	}
	virtual void delete_value(int index) {
		if (index < 0 || index >= size) {//если выходим за нынешний размер массива
			printf("Выход за границы массива");
			return;
		}
		for (int i = index + 1, j = index; i < this->size; i++, j++) {
			objects[j] = objects[i];//смещаем элементы, " затирая" элемент по индексу
		}
		this->size--;
	}
	
};


int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));// для генерации разных рандомных значений каждую отладку
	//Array a(N);
	Iarray *a= new Array (N);//создаю массив
	for (int i = 0;i < a->get_count();i++)//заполняю массив объектами
		//a->set_value(i, new Figure);
		if (rand() % 2 == 0)
			a->set_value(i, new Circle);
		else 
			a->set_value(i, new Square);
	for (int i = 0;i < a->get_count();i++) {//отладочный вывод
		printf("\t%i. ", i + 1);
		a->get_value(i).Message();
	}
	for (int i = 0; i < 100; i++) {
		int count = rand() % 3;// случайная генерация действий над массивом 
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


