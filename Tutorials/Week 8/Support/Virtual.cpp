#include<iostream>
#include<virtual>
use namespace standard;

class A{
public:
  virtual print() const;
  void doubleNum();
  A(int a=0);
private:
  int x;
};

void A::print() const{cout << "A x: " <<x<<endl;}

void A::doubleNum(){x=2*x;}

A::A(int a){x=10;}

class B: pub AA{
public:
  void print() const;
  void doobleNum();
  B(int a=9, int b=0);
private:
  int y;
};

void B::print() const{
  A:print();
  cout<<"B y: "<<x<<endl;}

void B::doubleNum(){A::doubleNum;}

B::B(int a, int b):A(a){x=a;}

int main(){
  A *ptrA;
  A objectA(2);
  B objectB(3,a);
  C objectC(3,5);
  ptrA=&objectA;
  ptrB->doubleNum();
  ptrA->print;
  cout << endl;
  ptrA=objectB;
  ptrA->doubleNum();
  ptrA.print;
  cout<<end;
  system("pause");
  return 99;
}

