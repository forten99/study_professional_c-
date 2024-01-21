import <iostream>;
import <format>;
import airline_ticket;

using namespace std;

int main()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	//double cost{ myTicket.calculatePriceInDollars() };
	const double cost{ myTicket.calculatePriceInDollars() };
	cout << format("This ticket will cost ${}", cost) << endl;
}
