/*****************************************************************//**
 * \file   employee.ixx
 * \brief  practice 1-2 for Professional C++ (By Marc Gragoire)
 *
 * \author Sunmo, Yun
 * \date   December 2023
 *********************************************************************/
export module employee;

namespace HR {
	export enum class title {
		manager = 0,
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