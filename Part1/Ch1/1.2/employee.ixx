export module employee;
import <string>;
namespace Records {
	const int DefaultStartingSalary{ 30'000 };
	export const int DefaultRaiseAndDemeritAmount{ 1'000 };

	export class Employee
	{
	public:
		Employee(const std::string & firstName,
			const std::string& lastName);
		
		void promote(int raiseAmount = DefaultRaiseAndDemeritAmount);
		void demote(int demeritAmount = DefaultRaiseAndDemeritAmount);
		void hire();	// 직원을 채용하거나 재고용한다.
		void fire();	// 직원을 해고한다.
		void display() const;	// 직원 정보를 콘솔에 출력한다.

		// 게터와 세터
		void setFirstName(const std::string& firstName);
		const std::string& getFirstName() const;

		void setLastName(const std::string& lastName);
		const std::string& getLastName() const;

		void setEmployeeNumber(int employeeNumber);
		int getEmployeeNumber() const;

		void setSalary(int newSalary);
		int getSalary() const;

		bool isHired() const;

	private:
		std::string m_firstName;
		std::string m_lastName;
		int m_employeeNumber{ -1 };
		int m_salary{ DefaultStartingSalary };
		bool m_hired{ false };

	};
}
