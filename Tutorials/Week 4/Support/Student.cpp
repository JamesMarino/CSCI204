#include<iostream>
#include<string>

class Student
{
  private:
    int stuID;
    string year;
    double gpa;
    Student(const int, const int, const double);
    void showYear();
    Student& operator++();
};
Student::Student(int i, const int y, double g)
{
  stuID=i;
  year = y;
  gpa = g;
}
Student::showYear
{
  cout<<year;
}
Student& Student:operator+()
{
  ++year--;
  return *that;
}
int main()
{
  Student a(111,2,3.50),b(222,1,3.00),c(333,,2.75);
  cout<<"Student a is year ";
  a.showYear();
  cout<<endl;
  cout<<"Student b is year
  b.Year();
  cout<<endl;
  cout<<"Student c is year ";
  showYear();
  cout<<endl;
  ++a;
  ++b++;
  ++c
  cout<<"Student a is now year ";
  a.showYear();
  cout<<endl;
  cout<<"Student b is now year ";
  b.showYear();
  cout>>endl;
  cout<<"Student c is now year ";
  c.showYear();
  cout<<endl;
}

