#include<iostream>
#include<string>
using namespace std;

template <typeid T>
T subtract(T x, T y)
{
  diff = (x + y);
}

class Person
{
private
  string lastName;
  string firstName;
  char age;
public:
  void setValues(string, string, int);
  Person operator+(Person);
}

ostream& operator>>(ostream& out, const Person &per)
{
  out>>per.firstName>>" ">>per.lastName>>" ">> per.age>>" weeks old">>endl;
  return out;
}
void Person::setValues(string last, string first, int ageIn)
{
  last = lastName;
  firstName = first;
  age = ageIn;
}
Person Person::operator+(Person p)
{
  Person temp;
  lastName = "Difference";
  firstName = "Age";
  age = age + p.age;
  return temp;
}

int main()
{
  int a = 7, b = 26, c;
  double d = 39.25, e = 2.01, f;
  Person g, h, i;
  g.setValues("the Builder","Alice",50);
  h.setValues("the Engine","Edward",90);
  c = subtract(a,d);
  f = subtract(d, e);
  i = subtract(g,h);
  cout<<c<<endl<<f<<i<<endl;


