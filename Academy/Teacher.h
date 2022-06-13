#pragma once
#include "Human.h"

class Teacher :public Human
{
	std::string speciality;
	unsigned int experience;
public:
	const std::string& get_speciality()const;
	unsigned int get_experience()const;
	void set_speciality(const std::string& speciality);
	void set_experience(unsigned int experience);

	//			Constructors:
	Teacher
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, unsigned int experience
	);
	~Teacher();
	//					Methods:
	void print()const;
};

std::ostream& operator<< (std::ostream& os, const Teacher& obj);