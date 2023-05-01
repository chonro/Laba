#include <iostream>
#include "Date.h"
using namespace std;



#pragma region class Person

class Person
	
{
protected:
	string name;
	string surname;
	string patronymic;

public:
	Person()
	{
		//cout << this << " Person constructor()" << endl;

	};
	Person(string surname, string name, string patronymic)
	{
		//cout << this << " Person constructor(string name)" << endl;
		this->name = name;
		this->surname = surname;
		this->patronymic = patronymic;
	};

	Person(const Person& p)
	{
		//cout << this << "  copy constructor" << endl;
		this->name = p.name;
		this->surname = p.surname;
		this->patronymic = p.patronymic;

	};
	~Person()
	{
		//cout << this << "  destructor" << endl;

	}

	string getFIO() {
		return this->surname + " " + this->name + " " + this->patronymic;
	}

	//переопределение операторов

	Person& operator=(const Person& p)
	{
		this->name = p.name;
		this->surname = p.surname;
		this->patronymic = p.patronymic;
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Person& p);
	friend istream& operator>>(istream& is, Person& p);

};

ostream& operator<<(ostream& os, const Person& p)
{
	return os << p.surname << " " << p.name << " " << p.patronymic;

}

istream& operator>>(istream& is, Person& p)
{
	return is >> p.surname >> p.name >> p.patronymic;

}

#pragma endregion

class Student :public Person
{
private:
	string gradebook;
	string group;
public:
	//Конструкторы
	Student() :Person()
	{
		//cout << this << " Student constructor()" << endl;
	}
	Student(string surname, string name, string patronymic) :Person(surname, name, patronymic)
	{


	};
	Student(string surname, string name, string patronymic, string gradebook) :Person(surname, name, patronymic)
	{
		this->gradebook = gradebook;
	}
	Student(string surname, string name, string patronymic, string group, string gradebook) :Person(surname, name, patronymic)
	{
		this->gradebook = gradebook;
		this->group = group;

	}
	Student(const Student& s) :Person(s)
	{
		//cout << "copy constructor student";
		this->group = s.group;
		//Нет двух студентов с одиноковой зачетной книжкой. Не копируем
	}
	//Конструкторы окончание

	// Геттеры
	string get_group()
	{
		return group;
	}
	string get_gradebook()
	{
		return gradebook;
	}
	//Cеттеры
	void set_group(string group)
	{
		this->group = group;
	}
	void set_gradebook(string gradebook)
	{
		this->gradebook = gradebook;
	}
	//Окончание сеттеров
	//переопределение операторов

	Student& operator=(const Student& s)
	{
		this->name = s.name;
		this->surname = s.surname;
		this->patronymic = s.patronymic;
		this->group = s.group;
		//Нет двух студентов с одиноковой зачетной книжкой. Не копируем
		return *this;
	}
	friend ostream& operator<<(ostream& os, const Student& t);
	friend istream& operator>>(istream& is, Student& t);

};

ostream& operator<<(ostream& os, const Student& s)
{
	return os << s.surname << " " << s.name << " " << s.patronymic << "\t|\t" << s.group << "\t|\t" << s.gradebook;

}

istream& operator>>(istream& is, Student& s)
{
	cout << " Entering student..." << endl;
	cout << "  Surname:";
	is >> s.surname;
	cout << "  Name:";
	is >> s.name;
	cout << "  Patronymic:";
	is >> s.patronymic;
	cout << "  Group:";
	is >> s.group;
	cout << "  Gradebook:";
	is >> s.gradebook;
	return is;

}

class Tutor : public Person {
private:
	string post;//должность
	string email;
public:
	//Кострукторы
	Tutor() :Person() {
		//cout << this << "Tutor constructor()" << endl;
	}
	Tutor(string surname, string name, string patronymic) :Person(surname, name, patronymic) {}
	Tutor(string name, string surname, string patronymic, string post, string email) :Person(surname, name, patronymic)
	{
		this->post = post;
		this->email = email;
	}
	string get_post()
	{
		return post;
	}
	string get_email()
	{
		return email;
	}
	void set_post(string post)
	{
		this->post = post;
	}
	void set_email(string email)
	{
		this->email = email;
	}
	void print_tutor()
	{
		cout << surname << " " << name << " " << patronymic << " .post: " << post;
	}


	friend ostream& operator<<(ostream& os, const Tutor& t);
	friend istream& operator>>(istream& is, Tutor& t);


	Tutor& operator=(const Tutor& t)
	{
		this->name = t.name;
		this->surname = t.surname;
		this->patronymic = t.patronymic;
		this->email = t.email;
		this->post = t.post;
		return *this;
	}

};

ostream& operator<<(ostream& os, const Tutor& t)
{
	return os << t.surname << " " << t.name << " " << t.patronymic << "\temail:" << t.email;

}

istream& operator>>(istream& is, Tutor& t)
{
	cout << " Entering tutor..." << endl;
	cout << "  Surname:";
	is >> t.surname;
	cout << "  Name:";
	is >> t.name;
	cout << "  Patronymic:";
	is >> t.patronymic;
	cout << "  Email:";
	is >> t.email;
	cout << "  Post:";
	is >> t.post;
	return is;

}

class GradeRecord {
private:
	Student student;
	unsigned int grade;
public:
	GradeRecord()
	{
		
	}
	GradeRecord(Student& student, int grade)
	{
		this->student = student;
		this->grade = grade;

	}
	GradeRecord(Student& student)
	{
		this->student = student;
	}
	const Student& get_student() const
	{
		return student;
	}
	int get_grade()
	{
		return grade;
	}
	void set_student(Student student)
	{
		this->student = student;
	}
	void set_grade(int grade)
	{
		this->grade = grade;
	}
	friend ostream& operator<<(ostream& os, const GradeRecord& g);
	friend istream& operator>>(istream& is, GradeRecord& g);
	GradeRecord& operator=(const GradeRecord& g)
	{
		this->student = g.student;
		this->grade = g.grade;
		return *this;
	}

};

ostream& operator<<(ostream& os, const GradeRecord& g)
{
	os << g.student << " | ";
	if (g.grade > 0 && g.grade < 6)
		os << g.grade;
	return os;

}

istream& operator>>(istream& is, GradeRecord& g)
{
	int grade;
	cout << "New grade record: " << endl;
	is >> g.student;
	cout << " Enter grade:";
	is >> grade;

	if (grade > 0 && grade < 6)
		g.grade = grade;
	else grade = 0;
	return is;

}


class GradeRegister //Зачетная ведомость
{
private:
	string university;
	string subject;
	Tutor  tutor;
	isp::Date date;
	GradeRecord* records;//массив для таблицы со студентами и оценками
	unsigned int count;//колво записей студентов
	unsigned int size;//размер массива
public:
	GradeRegister()
	{
		records = nullptr;
		count = 0;
		size = 0;

	}
	GradeRegister(unsigned int size)
	{
		records = new GradeRecord[size];
		this->size = size;
		this->count = 0;
		
	}
	~GradeRegister()
	{
		if (records != nullptr) delete[] records;

	}

	bool add(GradeRecord&)            // добавить строку ведомости (если памяти не хватает - увеличить)
	{
		if (records = nullptr);


	}
	bool del(GradeRecord&);      // удалить визстроку ведомости 
	bool del(unsigned int strNum);      // удалить строку ведомости  по номеру строки
	void set_grade(unsigned int strNum, unsigned int  grade);//установить оценку для студента в выбранной строке
	void set_grade(Student& student, unsigned int  grade);//установить оценку для выбранного студента 
	void set_university(string university)
	{
		this->university = university;
	}
	void set_subject(string subject)
	{
		this->subject = subject;
	}
	void set_tutor(Tutor& tutor)
	{
		this->tutor = tutor;
	}
	void set_date(isp::Date& date)
	{
		this->date = date;
	}
	string get_university()
	{
		return university;
	}
	string get_subject()
	{
		return subject;
	}
	Tutor get_tutor()
	{
		return tutor;
	}
	isp::Date get_date()
	{
		return date;
	}
	friend ostream& operator<<(ostream& os, const GradeRegister& g);
	friend istream& operator>>(istream& is, GradeRegister& g);
	GradeRegister& operator=(const GradeRegister& g); //ведомость смысл копирования?
	

};
istream& operator>>(istream& is, GradeRegister& g_register)
{
	return is;
}
ostream& operator<<(ostream& os, const GradeRegister& g_reg)
{
	os << g_reg.university <<endl;
	os << g_reg.subject << endl;
	os << g_reg.tutor << endl;
	os << g_reg.date << endl;
	if(g_reg.records!=nullptr)
	{
		for (unsigned int i = 0; i < g_reg.count; i++) 
		{
		os<<g_reg.records[i];
		}
	}
	return os;
}

int main()
{
	GradeRecord GR;
	Student st("Paykov", "Ivan", "Serg");
	GR.set_student(st);
	GradeRegister G_register;
	isp::Date d(12, 12, 2012);
	G_register.set_date(d);
	Tutor t("Petrov", "Ul", "ttt","assist","my@milo.yu");
	G_register.set_tutor(t);
	G_register.set_subject("matan");
	G_register.set_university("UNN");
	cout << G_register;
}