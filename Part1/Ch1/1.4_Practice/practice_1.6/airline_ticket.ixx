/*****************************************************************//**
 * \file   airline_ticket.ixx
 * \brief  practice 1-5 for Professional C++ (By Marc Gragoire)
 *
 * \author forte
 * \date   January 2024
 *********************************************************************/
export module airline_ticket;

import <string>;
import <optional>;

export class AirlineTicket
{
public:
	AirlineTicket();
	~AirlineTicket();

	double calculatePriceInDollars() const;
	const std::string& getPassengerName() const;
	void setPassengerName(const std::string& name);

	int getNumberOfMiles() const;
	void setNumberOfMiles(int miles);

	bool hasEliteSuperRewardsStatus() const;
	void setHasEliteSuperRewardsStatus(bool status);

	//int getId() const;
	//void setId(const int& id);
	std::optional<int> getFrequentFlyerNumber() const;
	void setFrequentFlyerNumber(int number);
private:
	// 클래스 내부 초기자
	std::string m_passengerName{ "Unknow Passger" };
	int m_numberOfMiles{ 0 };
	bool m_hasEliteSuperRewardsStatus{ false };
	//int m_id{ 0 };
	std::optional<int> m_frequentFlyerNumber;

};
