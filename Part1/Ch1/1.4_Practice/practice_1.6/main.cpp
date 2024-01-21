import <iostream>;
import <format>;
import airline_ticket;

using namespace std;

int main()
{
	AirlineTicket myTicket;
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	//myTicket.setId(99);
	myTicket.setFrequentFlyerNumber(123'456);
	const double cost{ myTicket.calculatePriceInDollars() };
	cout << format("This ticket will cost ${}", cost) << endl;
	//cout << format("ID : {}", myTicket.getId()) << endl;
	const auto frequentFlyerNumber{ myTicket.getFrequentFlyerNumber() };
	if (frequentFlyerNumber) {
		cout << format("Frequent flyer number: {}", frequentFlyerNumber.value()) << endl;
	}
	else {
		cout << "No frequent flyer number." << endl;
	}
}
