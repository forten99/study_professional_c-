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
		.salary = 50'000
		/*.title = */
	};
	cout << format("Employee : {} {}", anEmplyee.firstInitial, anEmplyee.lastInitial) << endl;;
	cout << format("Number : {}", anEmplyee.employeeNumber) << endl;
	cout << format("Salary : ${}", anEmplyee.salary) << endl;
}
