// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include <task_1/date.h>

#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <iostream>

Date::Date()
{
  std::time_t now = std::time(nullptr);
  char buff[4];

  strftime(buff, sizeof(buff) + 1, "%d", std::localtime(&now));
  day_ = atoi(buff);

  strftime(buff, sizeof(buff) + 1, "%m", std::localtime(&now));
  month_ = atoi(buff);

  strftime(buff, sizeof(buff) + 1, "%Y", std::localtime(&now));
  year_ = atoi(buff);
}

Date::Date(int day, int month, int year)
    : day_(day), month_(month), year_(year) {}

Date::Date(const Date &copy)
    : day_(copy.day_), month_(copy.month_), year_(copy.year_) {}

Date::~Date() {}

//Getters
int Date::GetDay() { return day_; }
int Date::GetMonth() { return month_; }
int Date::GetYear() { return year_; }

//Selectors
Date &Date::SetDay(int day)
{
  day_ = day;
  return *this;
}

Date &Date::SetMonth(int month)
{
  month_ = month;
  return *this;
}

Date &Date::SetYear(int year)
{
  year_ = year;
  return *this;
}

void Date::Print()
{
  std::cout << std::setfill('0');
  std::cout << std::setw(2) << day_ << "/"
            << std::setw(2) << month_ << "/"
            << std::setw(4) << year_ << std::endl;
}

std::ostream& operator<< (std::ostream &out, const Date &obj)
{
  out << std::setfill('0');
  out << std::setw(2) << obj.day_ << "/"
            << std::setw(2) << obj.month_ << "/"
            << std::setw(4) << obj.year_;
    return out;
}

std::istream& operator>> (std::istream &in, Date &obj)
{
  std::cout << "Enter new day of date: ";
  in >> obj.day_;
  std::cout << "Enter new month of date: ";
  in >> obj.month_;
  std::cout << "Enter new year of date: ";
  in >> obj.year_;
  return in;
}