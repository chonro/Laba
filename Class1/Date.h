#pragma once
#ifndef ISPDATE_H
#define ISPDATE_H
#include <iostream>
#include<string>
#include "Interface.h"
namespace isp
{
	class Date :protected isp::IObject<Date>
	{
	private:
		int day;
		int month;
		int year;
		bool DateIsCorrect(int day, int month, int year);

		 //�������� ��� �������� � ���� ������ �������
		 //void swap(Date& d);
		 Date& assign(const Date& d) ;
		 //Date& copy() ;
		 void dispose() ;
		 


	public:
		//����������� �� ���������(��� ����������)
		Date();
		//�����������
		Date(int day, int month, int year);
		//������ 
		void SetDate(int day, int month, int year);

		//������� 
		int GetDay();

		int GetMonth();
		int GetYear();


		void print_Date();
		std::string to_string() const;
		int cmp(const Date& d);//��������� ���� ���

		friend std::ostream& operator<<(std::ostream& os, const Date& d) ;
		friend std::istream& operator>>(std::istream& is, Date& d);
		bool operator==(const Date& d);
		bool operator<(const Date& d);
		bool operator>(const Date& d);
		Date& operator=(const Date& d);
	};
}

#endif // !ISPDATE_H

