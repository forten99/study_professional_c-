/*****************************************************************//**
 * \file   airline_ticket.ixx
 * \brief  practice 1-5 for Professional C++ (By Marc Gragoire)
 * 
 * \author forte
 * \date   January 2024
 *********************************************************************/
export module airline_ticket;

import <string>;

export class AirlineTicket
{
public:
	AirlineTicket();
	~AirlineTicket();

	double calculatePriceInDollars() const;					//// const method
	const std::string& getPassengerName() const;			//// const method + return a const reference
	void setPassengerName(const std::string &name);			//// Accept a const reference

	int getNumberOfMiles() const;							//// const method
	void setNumberOfMiles(int miles);				

	bool hasEliteSuperRewardsStatus() const;				//// const method
	void setHasEliteSuperRewardsStatus(bool status);
private:
	// 클래스 내부 초기자
	std::string m_passengerName{ "Unknow Passger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };

};
