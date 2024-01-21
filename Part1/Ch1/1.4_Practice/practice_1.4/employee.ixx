/*****************************************************************//**
 * \file   engineer.ixx
 * \brief  practice 1.4 for Professional C++ (By Marc Gragoire)
 *
 * \author forte
 * \date   January 2024
 *********************************************************************/
export module employee;

namespace HR {
	export enum class title {
		Manager = 0,
		SeniorEngineer = 100,
		Engineer = 1000
	};
	export struct Employee {
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary;
		title title = title::Engineer;
	};
}