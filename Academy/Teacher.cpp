#include "Human.h"
class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}

	//			Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//					Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality + " " << "Опыт: " << experience << endl;
	}
};

std::ostream& operator<< (std::ostream& os, const Teacher& obj)
{
	return os << (Human&)obj
		<< obj.get_speciality() << " " << obj.get_experience();
}