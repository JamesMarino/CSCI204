#include<iostream>
#include<string>
using namespace std;

class A
{
  friend ostream& operator<<(ostream&, A);
private:
  int num;
  int *values;
public:
  A(int);
  A& A::operator=(A&);
};
ostream& operator<<(ostream &o, A aa)
{
  int x;
  o<<aa.num<<" numbers"<<endl;
  for(x = 0; x < aa.num; ++x)
    o<<aa.values[x]<<"  ";
  o<<endl;
  return o;
}

A::A(int number)
{
  int Value;
  num = number;
  values = new int[num];
  for(int x = 0; x < num; ++x)
    {
      cout<<"Enter value for "<<(x + 1)<<" : ";
      cin>>Value;
      while(Value < 0 || Value > 100)
	{
          cout<<"Score must be between 0 and 100. Please enter score for item "<<
	    (x + 1)<<" ";
	  cin>>Value;
	}
      values[x] = Value;
    }
  cout<<endl;
}

// Here we have a copy constructor!
A& A::operator=(A &aa)
{
  num = aa.num;
  values = new int[num];
  for(int x = 0; x < aa.num; ++x)
    {
      values[x] = aa.values[x];
    }
  return *this;
}

int main()
{
  A thing1(3);
  {
    A thing2(5);
    cout<<endl<<"Thing 1:"<<endl;
    cout<<thing1;
    cout<<endl<<"Thing 2:"<<endl;
    cout<<thing2;
    thing1=thing2;
    cout<<endl<<"Thing1 after assignment:"<<endl;
    cout<<thing1;
  }
  cout<<endl<<"After thing2 has gone out of scope:"<<endl;
  cout<<thing1;
}

