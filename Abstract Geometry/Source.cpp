#define _USE_MATH_DEFINES // ��� C++
#include<iostream>
#include<math.h>
using namespace std;
#include<Windows.h>
//#include <cmath>
//#define PI 3.14159265358979323846

namespace Geometry
{
	//enum (Enumeration - ������������) - �������� ������������� ��������
// ������������ ����� �������� ����� ������
	enum Color
	{
		red = 0x000000FF,
		green = 0x0000FF00,
		blue = 0x00FF0000,
		yellow = 0x0000FFFF,


		console_default = 0x07,
		console_blue = 0x99,
		console_green = 0xAA,
		console_red = 0xCC,
		console_yellow = 0xEE,
		console_white = 0xFF
	};
	enum Defaults
	{
		min_start_x = 100,
		max_start_x = 1000,
		min_start_y = 50,
		max_start_y = 800,
		min_line_width = 5,
		max_line_width = 20,
		min_line_length = 10,
		max_line_length = 500,

	};
	class Shape
	{
	protected:
		Color color;
		int start_x;
		int start_y;
		unsigned int line_width;
	public:
		Color get_color()const
		{
			return color;
		}
		int get_start_x()const
		{
			return start_x;
		}
		int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(int start_x)
		{
			if (start_x < Defaults::min_start_x) this->start_x = Defaults::min_start_x;
			else if (start_x > Defaults::max_start_x)this->start_x = Defaults::max_start_x;
			else this->start_x = start_x;
		}
		void set_start_y(int start_y)
		{
			if (start_y < Defaults::min_start_y) this->start_y = Defaults::min_start_y;
			else if (start_y > Defaults::max_start_y)this->start_y = Defaults::max_start_y;
			else this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			if (line_width < Defaults::min_line_width) this->line_width = Defaults::min_line_width;
			else if (line_width < Defaults::max_line_width) this->line_width = Defaults::max_line_width;
			else this->line_width = line_width;
		}
		Shape(int start_x, int start_y, unsigned int line_width, Color color) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		virtual void info()const
		{
			cout << "������� ������: " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
			cout << typeid(*this).name() << endl;
			draw();
		}
	};

	class Square : public Shape
	{
		double side;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 10;
			this->side = side;
		}
		Square(double side, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_side(side);
		}
		~Square() {}

		double get_area()const
		{
			return side*side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void draw()const
		{
			// � ���������� hConsole �������� ������������ ����� �������� ���� �������
			HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsole, get_color()); //��� ������������ ������ �������� ���� ������ ���� ������ � ����
			for (int i = 0; i < side; i++)
			{
				for (int j = 0; j < side; j++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsole, Color::console_default);
		}

		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "����� ������� ��������: " << get_side() << endl;
			Shape::info();
		}
	};
	class Rectangle : public Shape
	{
		double side_a, side_b;
	public:
		double get_side_a()const
		{
			return side_a;
		}
		double get_side_b()const
		{
			return side_b;
		}
		void set_side_a(double side_a)
		{
			if (side_a <= 0)side_a = 20;
			this->side_a = side_a;
		}
		void set_side_b(double side_b)
		{
			if (side_b <= 0)side_b = 10;
			this->side_b = side_b;
		}
		Rectangle(double side_a, double side_b, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_side_a(side_a);
			set_side_b(side_b);
		}
		~Rectangle() {}
		double get_area()const
		{
			return side_a * side_b;
		}
		double get_perimeter()const
		{
			return (side_a + side_b) * 2;
		}
		void draw()const
		{
			//1) �������� ���� �������
			//HWND - Handler to Window (���������� ���� �������)
			HWND hwnd = GetConsoleWindow();
			// 2) ��� ����, ����� ��������, ����� ������� �������� ����������:
			HDC hdc = GetDC(hwnd); //HDC - Handler to Device Context.
			//����� ������, hdc - ��� ��, �� ��� �� ����� ��������

			//3) �������� �����������, �������� �� ����� ��������:
			HPEN hPen = CreatePen(PS_SOLID, line_width, color); //�������� ������ ������ ������
			//��� ����, ����� ��������� �������, ����� �����:
			HBRUSH hBrush = CreateSolidBrush(color);

			//4) ������� �������� �� ����������, ��� ��� ����� �������, 
			// � ������ ����� �� ������ �� ��������:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5) ������ �������������:
			::Rectangle(hdc, start_x, start_y, start_x + side_a, start_y + side_b);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "������� �: " << side_a << endl;
			cout << "������� B: " << side_b << endl;
			Shape::info();
		}
	};
	class Circle : public Shape
	{
		double radius;
	public:
		double get_radius()const
		{
			return radius;
		}
		void set_radius(double radius)
		{
			if (radius >= 10 && radius <= 500)this->radius = radius;
			else if (radius < 10) this->radius = 10;
			else this->radius = 500;
		}
		Circle(double radius, int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color)
		{
			set_radius(radius);
		}

		~Circle() {}
		double get_area()const
		{
			return M_PI * (radius * radius);
		}
		double get_perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + radius * 2, start_y + radius * 2);

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);

		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "������: " << get_radius() << endl;
			Shape::info();
		}
	};
	class Triangle :public Shape
	{
	public:
		Triangle(int start_x, int start_y, unsigned int line_width, Color color)
			:Shape(start_x, start_y, line_width, color) {}
		~Triangle() {}
		virtual double get_height()const = 0;
	};
	class EquilateralTriangle :public Triangle
	{
		double side;
		//double height;
	public:
		double get_side()const
		{
			return side;
		}
		void set_side(double side)
		{
			if (side <= Defaults::min_line_length)this->side = Defaults::min_line_length;
			else if (side <= Defaults::max_line_length)this->side = Defaults::max_line_length;
			else this->side = side;
		}
		EquilateralTriangle(double side/*, double height*/, int start_x, int start_y, unsigned int line_width, Color color)
			:Triangle(start_x, start_y, line_width, color)
		{
			set_side(side);
			//height;
		}
		~EquilateralTriangle() {}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(side / 2, 2));
			//return (sqrt(3)*side) / 2;
		}
		double get_area()const
		{
			return side*get_height() / 2;
			//return (1 / 2)*side*height;
		}
		double get_perimeter()const
		{
			return side * 3;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{start_x, start_y + side},								//2
				{start_x + side, start_y + side},						//3
				{start_x + side / 2, start_y + side - get_height()}		//4
			};

			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "C������ ������������: " << /*get_*/side/*()*/ << endl;
			cout << "������ ������������: " << get_height() << endl;
			cout << "������� ������������� " << get_area() << endl;
			cout << "�������� ������������� " << get_perimeter() << endl;
			Shape::info();
		}
	};
	class IsoscalesTriangle : public Triangle
	{
		double base;
		double side;
	public:
		double get_base()const
		{
			return base;
		}
		double get_side()const
		{
			return side;
		}
		void set_base(double base)
		{
			if (base < Defaults::min_line_length)base = Defaults::min_line_length;
			else if (base > Defaults::max_line_length)base = Defaults::max_line_length;
			//if (base >= side * 2)base /= 2;
			this->base = base;
		}
		void set_side(double side)
		{
			if (side < Defaults::min_line_length)side = Defaults::min_line_length;
			else if (side > Defaults::max_line_length)side = Defaults::max_line_length;
			if (side * 2 <= base)side = base;
			this->side = side;
		}
		IsoscalesTriangle& operator()(double base, double side)
		{
			if (base >= side * 2)base = side;
			set_base(base);
			set_side(side);
			return *this;
		}
		IsoscalesTriangle(double base, double side, int start_x, int start_y, unsigned int line_widht, Color color)
			:Triangle(start_x, start_y, line_widht, color)
		{
			operator()(base, side);
		}
		~IsoscalesTriangle() {}
		double get_height()const
		{
			return sqrt(pow(side, 2) - pow(base / 2, 2));
		}
		double get_area()const
		{
			return base*get_height() / 2;
		}
		double get_perimeter()const
		{
			return base + side * 2;
		}
		void draw()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			POINT vertices[] =
			{
				{ start_x, start_y + side },								//2
				{ start_x + base, start_y + side },						//3
				{ start_x + base / 2, start_y + side - get_height() }		//4
			};

			::Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));

			DeleteObject(hBrush);
			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << typeid(*this).name() << endl;
			cout << "��������� ������������: " << base << endl;
			cout << "C������ ������������: " << side << endl;
			cout << "������ ������������: " << get_height() << endl;
			//cout << "������� ������������� " << get_area() << endl;
			//cout << "�������� ������������� " << get_perimeter() << endl;
			Shape::info();
		}
	};
}

	void main()
	{
		setlocale(LC_ALL, "");
		//Shape shape(Color::console_blue);
		Geometry::Square square(5, 50, 10, 5, Geometry::Color::console_red);
		/*cout << "����� ������� ��������: " << square.get_side() << endl;
		cout << "������� ��������: " << square.get_area() << endl;
		cout << "�������� ��������: " << square.get_perimeter() << endl;
		square.draw();*/
		square.info();

		//Geometry::Rectangle rect(200, 100, 0, 100, 5, Geometry::Color::blue);
		//rect.info();

		Geometry::Circle circle(50, 700, 150, 15, Geometry::Color::yellow);
		circle.info();

		Geometry::EquilateralTriangle qtri(150, 700, 200, 5, Geometry::Color::green);
		qtri.info();

		Geometry::IsoscalesTriangle itri1(100, 150, 300, 200, 5, Geometry::Color::blue);
		itri1.info();

		Geometry::IsoscalesTriangle itri2(100, 75, 900, 200, 5, Geometry::Color::blue);
		itri2.info();

	}