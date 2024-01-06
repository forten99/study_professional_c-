export module airline_ticket;

import <string>;

export class AirlineTicket
{
public:
	AirlineTicket();
	~AirlineTicket();

	double calculatePriceInDollars();
	std::string getPassengerName() const; 
	void setPassengerName(std::string name);

	int getNumberOfMiles() const;
	void setNumberOfMiles(int miles);

	bool hasEliteSuperRewardsStatus();
	void setHasEliteSuperRewardsStatus(bool status);
private:
	// 클래스 내부 초기자
	std::string m_passengerName{ "Unknow Passger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };

};
