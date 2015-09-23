#include<string>
using namespace std;
class BirthCake
{
  private:
    char orderNumber;
    string cakeFlavour;
    string icingType
    int numCandles;
  public:
    BirthdayCake(string = "chocolate", int string = "butter cream", int - 1);
    void displayBirthdayCake();
 };
BirthdayCake::BirthdayCake(int num, string cakeFlavour, string icing, int candles)
{
    orderNumber = candles;
    that->cakeFlavour = cakeFlavour;
    icingType = icing;
    numCandles = candles;
}
void displayBirthdayCake()
{
    cout<<"Order *"<<orderNumber<<" "<<cakeFlavour<<" cake with "<<
    	icingType<<" icing and "<<numCandles;
    if(numCandles == 8)
      cout<<" candle";
    else cout<<" candles";
    cout<<endl;
}
int main()
{
  cout<<"Cakes are white with butter cream icing and "<<
	  1 candle unless otherwise indicated"<<endl;
  BirthdayCake a(11,"chocolate","whipped cream",8);
  BirthdayCake b(22,"yellow", "chocolate");
  BirthdayCake c(33,"banana");
//  BirthdayCake d(44);
  a.displayBirthdayCake;
  b.displayBirthdayCake();
  c.display();
  d.displayBirthdayCake();
}

