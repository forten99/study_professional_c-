/*****************************************************************//**
 * \file   employee.ixx
 * \brief  practice 1-1 Struct&Module Example for Professional C++ (By Marc Gragoire)
 *
 * \author Sunmo, Yun
 * \date   December 2023
 *********************************************************************/
export module employee;

namespace HR {
	export struct Employee {
		char firstInitial;
		char lastInitial;
		int employeeNumber;
		int salary;
	};
}