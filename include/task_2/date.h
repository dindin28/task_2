#ifndef _TASK_2_INCLUDE_TASK_2_DATE_H_
#define _TASK_2_INCLUDE_TASK_2_DATE_H_

#include <iostream>

class Date
{
public:
  Date();
  Date(int day, int month, int year);
  Date(const Date &copy);
  ~Date();

  //Getters
  int GetDay() const;
  int GetMonth() const;
  int GetYear() const;

  //Selectors
  Date &SetDay(int day);
  Date &SetMonth(int month);
  Date &SetYear(int year);

  void Print();

  friend std::ostream &operator<<(std::ostream &out, const Date &obj);
  friend std::istream &operator>>(std::istream &in, Date &obj);

private:
  int day_, month_, year_;
}; //Class (Date)

#endif //Header Guard