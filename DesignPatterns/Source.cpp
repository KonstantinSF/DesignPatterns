#include <iostream>
#include <ctime>
#include<string>
using namespace std; 

class Singleton
{
	static Singleton* instance; //экземпл€р
	string last_name; 
	string first_name; 
	tm birth_date; 
	Singleton()
	{
		cout << "Constructor:\t" << this << endl; 
	}
public:
	const string& get_last_name()const
	{
		return last_name; 
	}
	const string& get_first_name()const
	{
		return first_name; 
	}
	tm get_birth_date()
	{
		return birth_date;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name; 
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_day(size_t year, size_t month, size_t day)
	{
		this->birth_date.tm_year = year; 
		this->birth_date.tm_mon	 = month;
		this->birth_date.tm_mday = day; 
	}
	~Singleton()
	{
		delete instance; 
		cout << "Destructor:\t" << this << endl; 
	}
	static Singleton* getInstance()
	{
		if (instance == nullptr) instance = new Singleton; 
		return instance; 
	}
	void print()const
	{
		//time_t timer; //эта перем-€ будет содержать текущее врем€
		//time(&timer); //ф-и€ тайм записывает текущее врем€ в timer
		//tm* current_time = localtime(&timer); 
		//cout << asctime(current_time); 

		cout << last_name << " " << first_name << endl; 
	}
};

Singleton* Singleton::instance = nullptr; 

void main()
{
	setlocale(LC_ALL, ""); 

	//Singleton* director = Singleton::getInstance(); //создан объект
	//director->set_first_name("¬асилий"); 
	//director->set_last_name("“упенко"); 
	//director->set_birth_day(1990, 04, 01); 
	//director->print(); 

	Singleton::getInstance()->set_last_name("ƒурко");
	Singleton::getInstance()->set_first_name("¬италий"); 
	Singleton::getInstance()->set_birth_day(1990, 04,1); 
	Singleton::getInstance()->print(); 
	Singleton::getInstance()->~Singleton(); 

}