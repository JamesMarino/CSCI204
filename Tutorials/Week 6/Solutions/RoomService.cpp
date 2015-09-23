/*
 * Changes are commented below
 */

#include <iostream>
#include <string>

using namespace std;

// Add Forward declarations
class RestaurantMeal;
class HotelService;
class RoomServiceMeal;


/*
 * Interface:
 * Class Restaurant Meal
 */

// Setting of properties is used instead of contructor
class RestaurantMeal
{
	// Protected and Private properties in appropriate sections
	private:
		string entree;
	protected:
		int price;
	public:
		RestaurantMeal();
		void setProperties(string, int);
		void showRestaurantMeal();
};

/*
 * Interface:
 * Class Hotel Service
 */
class HotelService
{
	// Protected and Private properties in appropriate sections
	private:
		string service;
		int roomNumber;
	protected:
		double serviceFee;
	public:
		HotelService();
		void setProperties(string, double, int) /*const*/;
		void showHotelService();
};

/*
 * Interface:
 * Class Room Service Meal
 */

// Extended the class to two others
class RoomServiceMeal : HotelService, RestaurantMeal
{
	// Removed Class instances
	public:
		RoomServiceMeal(string, double, string, double, int);
		void RestaurantMeal(string, double);
		void showRoomServiceMeal();
};

/*
 * Implementation:
 * Class Restaurant Meal
 */
RestaurantMeal::RestaurantMeal()
{
	this->entree = "No Entree";
	this->price = 0;
}

void RestaurantMeal::setProperties(string meal, int pr)
{
	this->entree = meal;
	this->price = pr;
}

void RestaurantMeal::showRestaurantMeal()
{
	cout << this->entree << " $" << this->price << endl;
}

/*
 * Implementation:
 * Class Hotel Service
 */
HotelService::HotelService()
{
	this->service = "No Service Type";
	this->serviceFee = 0.0;
	this->roomNumber = 0.0;
}

void HotelService::setProperties(string serv, double fee, int rm)
{
	this->service = serv;
	this->serviceFee = fee;
	this->roomNumber = rm;
}

void HotelService::showHotelService()
{
	cout << this->service << " service fee $" << this->serviceFee
			<< " to room #" << this->roomNumber << endl;
}

/*
 * Implementation:
 * Class Room Service Meal
 */
RoomServiceMeal::RoomServiceMeal(string serviceName, double servicePrice, string entreeName, double entreePrice, int roomNum)
{
	// Give the Instances of classes values
	this->RestaurantMeal::setProperties(entreeName, entreePrice);
	this->HotelService::setProperties(serviceName, servicePrice, roomNum);
}

void RoomServiceMeal::showRoomServiceMeal()
{
	this->RestaurantMeal::showRestaurantMeal();
	this->HotelService::showHotelService();
	
	double totalCost = this->price + this->serviceFee;
	cout << "Total is $" << totalCost << endl;
}

int main()
{
	RoomServiceMeal roomService("Room Service", 4.00, "Steak Dinner", 19.99, 1202);
	cout << "Room Service Order: " << endl;
	roomService.showRoomServiceMeal();
}

