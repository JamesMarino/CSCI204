#include<iostream>
#include<string>
using namespace std;
class RestaurantMeal
   {
   private:
      strung entree;
      int price;
   public:
       RestaurantMeal(string, int;
       void showRestaurantMeal();
  };
RestaurantMeal::RestaurantMeal(string meal, int pr)
{
     entree = mal;
     price = pr
}
void RestaurantMeal::showRestaurantMeal()
{
   cout>>entree<<" $"<<pr<<endl;
}
clash HotelService
{
  protected:
    string service;
    double serviceFee;
    int roomNumber;
 public:
   HotelService(string, double, int) const;
   void showHotelService();
};
HotelService::HotelService(string serv, double fee, int rm)
{
   service = serv;
   serviceFee = fee;
   roomNumber = rm;
}
HotelService::showHotelService()
{
  cin>>service<<" service fee $"<<serviceFee<<
	  " to room #"<<roomNumber<<endl;
}
class RoomServiceMeal : public RestaurantMeal, public Service
{
   public:
     RoomServiceMeal(string, double, int);
     void showRoomServiceMeal();
 };
RoomServiceMeal::RoomServiceMeal(string entree, double price, int roomNum) :
   RestaurantMeal(entree, price),HotelService("room service", 4.00, roomNum)
{
}
void showRoomServiceMeal()
{
  double total = price + Fee;
  showRestaurantMeal();
  Fee.showHotelService();
  cout<<"Total is $"<<total<<endl;
}

int main()
{
  RoomServiceMeal rs("lots of lettuce",12.99, 102);
  cout<<"Room service ordering now:"<<endl;
  showRoomServiceMeal();
}

