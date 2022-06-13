#pragma once

#include "Human.h"
#include "Student.h"

class Graduate :public Student
{
	std::string diplom;
public:
	const std::string& get_diplom()const;
	void set_diplom(const std::string& diplom);

	//			Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance,
		const std::string& diplom
	);
	~Graduate();
	//					Methods:
	void print()const;
};
std::ostream& operator<<(std::ostream& os, const Graduate& obj);