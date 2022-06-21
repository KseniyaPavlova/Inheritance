#include<iostream>
using namespace std;

class Vehicle
{
	int speed;
public:
	virtual void move() = 0;
	//Абстрактный класс
};
class GroundVehicle :public Vehicle
{

};
class Car : public GroundVehicle
{
public:
	void move()
	{
		cout << "Машина едет на четырех колесах (как минимум)" << endl;
	}
	// Конкретный класс
};
class Bike :public GroundVehicle
{
public:
	void move()
	{
		cout << "Мотоцикл едет на двух колесах" << endl;
	}
};

class AirVehicle : public Vehicle
{
	int height;
public:
	virtual void take_off() = 0;
};
class Helicopter :public AirVehicle
{
public:
	void move()
	{
		cout << "Вертолет летит на винте" << endl;
	}
	void take_off()
	{
		cout << "Вертикальный взлет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	//Vehicle v; //Невозможно создать экземпляр абстрактного класса
	//GroundVehicle gv;
	Car bmv;
	Bike hd;
	bmv.move();
	hd.move();

	Helicopter apache;
	apache.take_off();
	apache.move();
}