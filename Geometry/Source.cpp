#include<iostream>
using std::cin;
using std::cout;
using std::endl;

	class Shape
	{
	public:
		virtual double area()const = 0;		//�������
		virtual double perimeter()const = 0;//�������� 
		virtual void figure()const = 0;		//����� ������ �� �����
	};

	class Square : public Shape
	{
		double side; //�������
	public:
		double get_side()const
		{
			return side;
		}
		double set_side(double side)
		{
			if (side < 0)side = side * (-1);
			return this->side = side;
		}

		Square(double side)
		{
			set_side(side);
			std::cout << "SquareConstructor:\t" << this << std::endl;
		}
		~Square()
		{
			std::cout << "SquareDestructor:\t" << this << std::endl;
		}

		double area()const
		{
			return side * side;
		}
		double perimeter()const
		{
			return side * 4;
		}
		void figure() const
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
	};

	class Rectangle :public Shape
	{
		double side;
		double side1;
	public:
		double get_side()const
		{
			return side;
		}
		double get_side1()const
		{
			return side1;
		}
		double set_side(double side)
		{
			if (side < 0)side = side*(-1);
			return this->side = side;
		}
		double set_side1(double side1)
		{
			if (side1 < 0)side1 = side1*(-1);
			return this->side1 = side1;
		}

		Rectangle(double side, double side1)
		{
			set_side(side);
			set_side1(side1);
			std::cout << "RectangleConstructor:\t" << this << std::endl;
		}
		~Rectangle()
		{
			std::cout << "RectangleDestructor:\t" << this << std::endl;
		}

		double area()const
		{
			return side * side1;
		}
		double perimeter()const
		{
			return (side + side1) * 2;
		}

		void figure()const
		{
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side1; j++)
				{
					std::cout << "* ";
				}
				std::cout << std::endl;
			}
		}
	};


void main()
{
	setlocale(LC_ALL, "");
	Square square(3);
	square.figure();
	std::cout << "������� ��������: " << square.area() << std::endl;
	std::cout << "�������� ��������:" << square.perimeter() << std::endl;

	Rectangle rectangle(3, 5);
	rectangle.figure();
	std::cout << "������� ��������������: " << rectangle.area() << std::endl;
	std::cout << "�������� ��������������:" << rectangle.perimeter() << std::endl;
}