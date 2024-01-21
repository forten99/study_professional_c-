import airline_ticket;

using namespace std;
AirlineTicket::AirlineTicket()
	:m_passengerName{ "Unknow Passger" }
	, m_numberOfMiles{ 0 }
	, m_hasEliteSuperRewardsStatus{ false }
{
}

//// ������ �������� �ʱ�ȭ �ϴ� ���
//AirlineTicket::AirlineTicket()	
//{
//	// ������ ��� �ʱ�ȭ
//	m_passengerName = "Unknow Passger";
//	m_numberOfMiles = 0;
//	m_hasEliteSuperRewardsStatus = false;
//}

AirlineTicket::~AirlineTicket()
{
	// �Ҹ�
}

double AirlineTicket::calculatePriceInDollars() const
{
	if (hasEliteSuperRewardsStatus()) {
		// ��� ���(Elite Super Rewards) ȸ�����Դ� ���� Ƽ���� �����Ѵ�.
		return 0;
	}
	// Ƽ�� ������ ���� �Ÿ��� 0.1�� ���� ���̴�.
	// ������ �װ��翡�� �����ϴ� ������ �̺��� �����ϴ�.
	return getNumberOfMiles() * 0.1;
}

const string& AirlineTicket::getPassengerName() const
{
	return m_passengerName;
}

void AirlineTicket::setPassengerName(const string &name) { m_passengerName = name; }

int AirlineTicket::getNumberOfMiles() const
{
	return m_numberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	m_numberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
	return m_hasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	m_hasEliteSuperRewardsStatus = status;
}



