import <iostream>;
import <format>;
import employee;

using namespace std;
using namespace HR;		// Employee ����ü�� ����ϱ� ���ؼ� HR ���ӽ����̽� ���
int main()
{
	// ���� ���ڵ� ���� �� �� ä���
	Employee anEmplyee{
		.firstInitial = 'S',
		.lastInitial = 'Y',
		.employeeNumber = 1000,
		.salary = 50'000,
		.title = title::SeniorEngineer
	};
	cout << format("Employee : {} {}", anEmplyee.firstInitial, anEmplyee.lastInitial) << endl;;
	cout << format("Number : {}", anEmplyee.employeeNumber) << endl;
	cout << format("Salary : ${}", anEmplyee.salary) << endl;
	string s_title;
	switch (anEmplyee.title)
	{
	case title::manager:
		s_title = "Manager";
		break;
	case title::SeniorEngineer:
		s_title = "Senior Engineer";
		break;
	case title::Engineer:
		s_title = "Engineer";
		break;		
	}
	cout << format("Title : {}", s_title) << endl;

	switch (anEmplyee.title)
	{
		using enum title;
	case manager:
		cout << "Manager" << endl;
		break;
	case SeniorEngineer:
		cout << "Senior Engineer" << endl;
		break;
	case Engineer:
		cout << "Engineer" << endl;
		break;
	}
	
}
