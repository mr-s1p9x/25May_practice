#include <iostream>
#include <time.h>

using namespace std;

// класс Engine, который представляет двигатель автомобиля
class Engine
{
    int horsepower; // Приватная переменная для хранения мощности двигателя
    int cylinders; // Приватная переменная для хранения кол-ва цилиндров

public:
    // Конструктор класса Engine, инициализирующий переменные horsepower и cylinders
    Engine(int hp, int cyl)
    {
        horsepower = hp;
        cylinders = cyl;
    }

    // Метод для вывода переменной horsepower.
    void Show()
    {
        cout << horsepower << " HP" << endl;
    }

    // Метод для получения значения переменной horsepower.
    int GetHorsepower()
    {
        return horsepower; // Возвращение значения horsepower.
    }
};

// Класс Car, представляющий автомобиль.
class Car
{
    const int wheels; // Константная переменная для хранения кол-ва колес
    int doors;        // Переменная для хранения кол-ва дверей
    int& fuelTank;    // Ссылка на переменную fuelTank
    Engine engine;    // Объект класса Engine, представляющий двигатель автомобиля

public:
    // Конструктор класса Car с параметрами для инициализации переменны и объекта Engine
    // + список инициализаторов для переменных wheels, fuelTank и объекта engine
    Car (int wh, int dr, int& fT, int hp, int cyl):wheels(wh), fuelTank(fT), engine(hp, cyl)
    {
        cout << "Construct Car with engine\n"; // Вывод сообщения о вызове конструктора
        doors = dr; // Инициализация переменной doors значением dr.
    }

    // Метод для инициализации переменной doors случайным значением
    void Init()
    {
        doors = rand() % 5 + 2; // Присваивание переменной doors случайного значения от 2 до 6
    }

    // Константный метод для вывода значений переменных wheels и doors.
    void Output() const
    {
        cout << "Wheels: " << wheels << "\t Doors: " << doors << endl;
    }

    // Метод для получения значения переменной horsepower из объекта Engine
    int GetEngineHorsepower()
    {
        return engine.GetHorsepower(); // Возвращение значения horsepower из объекта Engine
    }
};

int main()
{
    srand(time(NULL));

    int fuel = 50; // Объем топливного бака

    // Создание объектов Car с разными конструкторами для демонстрации делигирования
    Car car1(4, 4, fuel, 150, 6); // Создание авто с 4 колесами, 4 дверьми, 150 л.с, и 6 цилиндрами

    // Использование метода Output для вывода значений переменных wheels и doors.
    car1.Output(); // Вывод значений для объекта car1

    // Использование метода для получения мощности двигателя
    cout << "Engine Horsepower of car1 is: " << car1.GetEngineHorsepower() << endl; // Вывод мощности двигателя объекта car1

    // Изменение кол-ва дверей случайным значением
    car1.Init(); // Инициализация случайного кол-ва дверей для объекта car1
    car1.Output(); // Повторный вывод значений для объекта car1 после инициализации

    return 0;
}

