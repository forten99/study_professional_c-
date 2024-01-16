//import Database;
import Database;
import <stdexcept>;
import employee;
using namespace std;

namespace Records {
	Employee& Database::addEmployee(const string& firstName, const string& lastName)
	{
		Employee theEmployee{ firstName, lastName };
		theEmployee.setEmployeeNumber(m_nextEmployeeNumber++);
		theEmployee.hire();
		m_employees.push_back(theEmployee);
		return m_employees.back();
	}

	Employee& Database::getEmployee(int employeeNumber)
	{
		for (auto& employee : m_employees) {	// Employee& employee
			if (employee.getEmployeeNumber() == employeeNumber) {
				return employee;
			}
		}
		throw logic_error{ "No employee found." };
	}

	void Database::displayAll() const
	{
		for (const auto& employee : m_employees) { employee.display(); }
	}

	void Database::displayCurrent() const
	{
		for (const auto& employee : m_employees) {
			if (employee.isHired()) { employee.display(); }
		}
	}

	void Database::displayFormer() const
	{
		for (const auto& employee : m_employees) {
			if (employee.isHired() == false) { employee.display(); }
		}
	}
}
