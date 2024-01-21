import <iostream>;
import <format>;
import <array>;
import employee;

using namespace std;
using namespace HR;		// Employee ����ü�� ����ϱ� ���ؼ� HR ���ӽ����̽� ���

void printemployeeinfo(const Employee& employee);	// ���� ���� ��� �Լ�

void printemployeeinfo(const Employee& employee)
{
	cout << format("employee : {} {}", employee.firstInitial, employee.lastInitial) << endl;;
	cout << format("number : {}", employee.employeeNumber) << endl;
	cout << format("salary : ${}", employee.salary) << endl;
	string s_title;
	switch (employee.title)
	{
	case title::Manager:
		s_title = "manager";
		break;
	case title::SeniorEngineer:
		s_title = "senior engineer";
		break;
	case title::Engineer:
		s_title = "engineer";
		break;
	}
	cout << format("title : {}", s_title) << endl << endl;
}

int main()
{
	const int firstEmployeeNumber = 1000;
	int emplyoeeNumber = firstEmployeeNumber;
	
	// ���� ���ڵ� ���� �� �� ä���
	Employee anEmployee1{
		.firstInitial = 'S',
		.lastInitial = 'Y',
		.employeeNumber = emplyoeeNumber++,
		.salary = 150'000,
		.title = title::Manager
	};

	Employee anEmployee2{
		.firstInitial = 'S',
		.lastInitial = 'K',
		.employeeNumber = emplyoeeNumber++,
		.salary = 50'000,
		.title = title::SeniorEngineer
	};

	Employee anEmployee3{
		.firstInitial = 'Z',
		.lastInitial = 'Y',
		.employeeNumber = emplyoeeNumber++,
		.salary = 10'000,
		.title = title::Engineer
	};
	
	//std::array<char, 3> arr1;
	//{ anEmployee1.firstInitial, anEmployee2.firstInitial, anEmployee3.firstInitial };
	array<Employee, 3> arr = { anEmployee1, anEmployee2, anEmployee3 };
	for (auto& employee : arr)
	{
		printemployeeinfo(employee);
	}
	
	array<char, 3> firstInitialArr = { anEmployee1.firstInitial, anEmployee2.firstInitial , anEmployee3.firstInitial };
	array<char, 3> lastInitialArr = { anEmployee1.lastInitial, anEmployee2.lastInitial , anEmployee3.lastInitial };
	array<int, 3> employeeNumber = { anEmployee1.employeeNumber, anEmployee2.employeeNumber , anEmployee3.employeeNumber };
	array<title, 3> titleArr = { anEmployee1.title, anEmployee2.title , anEmployee3.title };

	for (auto& c : firstInitialArr)
		cout << c << endl;
	for (auto& c : lastInitialArr)
		cout << c << endl;
	for (auto& i : employeeNumber)
		cout << i << endl;
	for (auto& c : titleArr)
		cout << (int)c << endl;

	for (const auto& employee : arr) {
		// output the values of an employee
		cout << format("Employee: {}{}", employee.firstInitial,
			employee.lastInitial) << endl;
		cout << format("Number: {}", employee.employeeNumber) << endl;
		cout << format("Salary: ${}", employee.salary) << endl;

		switch (employee.title)
		{
			using enum title;

		case Engineer:
			cout << "Engineer" << endl;
			break;
		case SeniorEngineer:
			cout << "Senior Engineer" << endl;
			break;
		case Manager:
			cout << "Manager" << endl;
			break;
		}
		cout << endl;
	}

}
