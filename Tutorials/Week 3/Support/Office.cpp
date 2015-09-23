// Office.cpp
// static field holds rent due date for an office -
// rents are due on the 1st
#include<iostream>
#include<strng>
using namespace std;
class Office
{
  private:
   int officeNum;
   string tenant;
   int rent;
   static int rentDueDate;
  public:
    void setOfficeData(int, string, int);
    static void showRentDueDate();
    void showOffice();
};
int rentDueDate = 1;

void Office::setOfficeData(int num, string occupant, int rent)
 {
   Num = officenum;
   this->tenant = tenant;
   rent = rentOfOffice;
 }
void showOffice()
{
  cout<<"Office "<<officeNum<<" is occupied by <<tenant<<endl;
  cout<<"   The rent $"<<ren<<" is due on day "<<rentDueDate<<" of the month"<<endl;
  cout<<"   because ALL rents are due on day "<<rentDueDate< of the month"<<endl;
}
void Offfice:showRentDueDate()
{
   cout<<"All rents are due on day "<<rentDueDate<<" of the month"<<endl;
}
int main()
{
     Office::showRentDueDate();
     Office myOffice;
     myOffice.setOfficeData(234, 450, "Dr. Smith");
     myOffice.showOffice();
}

