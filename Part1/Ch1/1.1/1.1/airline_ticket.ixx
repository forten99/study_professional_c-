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
	// Ŭ���� ���� �ʱ���
	std::string m_passengerName{ "Unknow Passger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };

};
