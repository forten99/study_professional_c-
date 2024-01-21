import <iostream>;
import <format>;
import <vector>;
import employee;

using namespace std;
using namespace HR;		// Employee 구조체를 사용하기 위해서 HR 네임스페이스 사용

void printemployeeinfo(const Employee& employee);	// 직원 정보 출력 함수

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

	// 직원 레코드 생성 및 값 채우기
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
	vector<Employee> vec;
	vec.push_back(anEmployee1);
	vec.push_back(anEmployee2);
	vec.push_back(anEmployee3);
	for (auto& employee : vec)
	{
		printemployeeinfo(employee);
	}

	vector<HR::Employee> employees;

	employees.push_back(HR::Employee{
		.firstInitial = 'J',
		.lastInitial = 'W',
		.employeeNumber = 42,
		.salary = 80'000,
		.title = HR::title::SeniorEngineer
		}
	);

	employees.push_back(HR::Employee{
		.firstInitial = 'J',
		.lastInitial = 'D',
		.employeeNumber = 133,
		.salary = 64'000,
		.title = HR::title::Engineer
		}
	);

	employees.push_back(HR::Employee{
		.firstInitial = 'B',
		.lastInitial = 'P',
		.employeeNumber = 18,
		.salary = 100'000,
		.title = HR::title::Manager
		}
	);

	for (const auto& employee : employees) {
		// output the values of an employee
		cout << format("Employee: {}{}", employee.firstInitial,
			employee.lastInitial) << endl;
		cout << format("Number: {}", employee.employeeNumber) << endl;
		cout << format("Salary: ${}", employee.salary) << endl;

		switch (employee.title)
		{
			using enum HR::title;

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
