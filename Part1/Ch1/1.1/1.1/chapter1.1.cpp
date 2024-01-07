/*****************************************************************//**
 * \file   chapter1.1.cpp
 * \brief  Chapter1 Example for Professional C++ (By Marc Gregoire) 
 * 
 * \author Sunmo, Yun
 * \date   December 2023
 *********************************************************************/
//#include <iostream>
//import iostream;	// ���� ����
//import format;	// ���� ����
//#include <initializer_list> //1.1.21 initializer_list 
import std.core;
import employee;
import airline_ticket;
using namespace std;

#pragma region 1.1.12 function func name
int addNumbers(int number1, int number2)
{
	cout << "Entering function " << __func__ << endl;
	return number1 + number2;
}
#pragma endregion

#pragma region 1.1.13 attribute

	[[nodiscard("Some explanation")]] int func()
	{
		return 42;
	}

	[[noreturn]] void forceProgramTermination()
	{
		std::exit(1);	// <cstdlib>�� ���ǵ�
	}

	bool isDongleAvailable()
	{
		bool isAvailable{ false };
		// ���̼��� ������ ����� �� �ִ��� Ȯ��
		return isAvailable;
	}

	bool isFeatureLicensed(int featuredId)
	{
		if (!isDongleAvailable()) {
			// ��� ������ ���̼��� ������ ���ٸ� ���α׷��� �ߴ��Ѵ�.
			forceProgramTermination();
		}
		else {
			bool isLicensed{ featuredId == 42 };
			// ������ �ִٸ� �־��� ��ɿ� ���� ���̼��� �˻縦 �Ѵ�.
			return isLicensed;
		}
	}

	[[deprecated("Unsafe method, pelase use xyz")]] void funcDeprecated()
	{
		cout << "deprecated" << endl;	
	}	

#pragma endregion

#pragma region 1.1.18 std::optional
	optional<int> getData(bool giveIt)
	{
		if (giveIt) {
			return 42;
		}
		return nullopt;	// �Ǵ� �׳� {};
	}
#pragma endregion

#pragma region 1.1.21 initializer_list
	int makeSum(initializer_list<int> values)
	{
		int total{ 0 };
		for (int value : values) {
			total += value;
		}
		return total;
	}
#pragma endregion

#pragma region 1.1.24 scope

	class Demo
	{
	public:
		int get() { return 5; }
	};

	int get() { return 10; }

	namespace NS
	{
		int get() { return 20; }
	}
#pragma endregion

#pragma region 1.1.25 uniform initialization
	struct CircleStruct
	{
		int x, y;
		double radious;
	};

	class CircleClass
	{
	public:
		CircleClass(int x, int y, double radius)
			: m_x{ x }, m_y{ y }, m_radius{ radius } {}
	private:
		int m_x, m_y;
		double m_radius;
	};

	class MyClass
	{
	public:
		MyClass() :m_array { 0, 1, 2, 3 }{}
	private:
		int m_array[4];
	};
	void func(int i) { /* ... */ }
	
#pragma endregion

#pragma region 1.1.28 constexpr
	const int getArraySize() { return 32; }

	constexpr int getArraySize2() { return 32; }
#pragma endregion

#pragma region 1.1.27 const
	void mysteryFunction(const string* someString)
	{
		//*someString = "Test";	// ������ ������ �߻�
	}
#pragma endregion

#pragma region 1.1.29 consteval
	constexpr double inchToMm(double inch) { return inch * 25.4; }

	consteval double inchToMm2(double inch) { return inch * 25.4; }		// ��� ���� �Լ�

#pragma endregion

#pragma region 1.1.30 reference
	string getString() { return "Hello world!"; }

	void addOne(int i)
	{
		i++;	// �������� ���޵Ǿ��� ������ �������� �ƹ��� ������ ��ġ�� �ʴ´�.
	}

	void addOne_2(int& i)
	{
		i++;	// ���� ������ ����ȴ�.
	}

	void swap(int& first, int& second)
	{
		int tmep{ first };
		first = second;
		second = tmep;
	}

	void printString(const string& myString)
	{
		cout << myString << endl;
	}

	void refcall(int& t) { ++t; }

	void separateOddsAndEvens_ptr(const int arr[], size_t size, int** odds,
		size_t* numOdds, int** evens, size_t* numEvens)
	{
		// ¦���� Ȧ���� ������ ����.
		*numOdds = *numEvens = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] % 2 == 0)
			{
				++(*numEvens);
			}
			else
			{
				++(*numOdds);
			}
		}

		// ���� ���� �� �迭�� ũ�⿡ �°� ������ �Ҵ��Ѵ�.
		*odds = new int[*numOdds];
		*evens = new int[*numEvens];
		
		// ���� �迭�� ��� Ȧ���� ¦�� ���Ҹ� ���� ���� �迭�� �����Ѵ�.
		size_t oddPos = 0, evenPos = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] % 2 == 0)
			{
				(*evens)[evenPos++] = arr[i];
			}
			else
			{
				(*odds)[oddPos++] = arr[i];
			}
		}
	}

	void separateOddsAndEvens_ref(const int arr[], size_t size, int*& odds,
		size_t& numOdds, int*& evens, size_t& numEvens)
	{
		numEvens = numOdds = 0;
		for (int i=0; i < size; i++)
		{
			if (arr[i] % 2 == 0)
			{
				++numEvens;
			}
			else
			{
				++numOdds;
			}
		}

		odds = new int[numOdds];
		evens = new int[numEvens];

		size_t evensPos{ 0 }, oddsPos{ 0 };
		for (int i = 0; i < size; i++)
		{
			if (arr[i] % 2 == 0)
			{
				evens[evensPos++] = arr[i];
			}
			else
			{
				odds[oddsPos++] = arr[i];
			}
		}
	}

	void separateOddsAndEvens_vector(const vector<int>& arr, vector<int>& odds, vector<int>& evens)
	{
		for (int i : arr)
		{
			if (i % 2 == 0) {
				evens.push_back(i);
			}
			else
			{
				odds.push_back(i);
			}
		}
	}


	struct OddsAndEvens { vector<int> odds, evens; };
	OddsAndEvens separateOddsAndEvens(const vector<int>& arr)
	{
		vector<int> odds, evens;
		for (int i : arr) {
			if (i % 2 == 1) {
				odds.push_back(i);
			}
			else {
				evens.push_back(i);
			}
		}
		return OddsAndEvens{ .odds = odds, .evens = evens };
	}
#pragma endregion

#pragma region 1.1.31 const_cast()
	void ThirdPartyLibraryMethod(char* str)
	{
		return;
	}

	void f(const char* str)
	{
		ThirdPartyLibraryMethod(const_cast<char*>(str));
	}
#pragma endregion

#pragma region 1.1.32 exception
	double divideNumbers(double numerator, double denominator)
	{
		if (denominator == 0) {
			throw invalid_argument("Denominator cannot be 0.");		// <stdexcept>�� ���ǵ� std::invalid_argument
		}
		return numerator / denominator;
	}
#pragma endregion

#pragma region 1.1.35 auto
	const string& foo() 
	{ 
		const string message{ "Test" };
		return message; 
	}
#pragma endregion 

#pragma region 1.1.33 type alias
	//void processVector(const vector<basic_string<char>>& vec)
	void processVector(const vector<string>& vec)
	{
		for (string str : vec)
			cout << str << endl;
	}
#pragma endregion

int main() {
	//std::cout << "Hello, World!" << std::endl;

#pragma region HelloWorld
	//cout << "Hello, World!" << endl;
#pragma endregion

#pragma region numeric_limits
	/*{
		cout << "int:\n";
		cout << format("Max int value: {}\n", numeric_limits<int>::max());
		cout << format("Min int value: {}\n", numeric_limits<int>::min());
		cout << format("Lowest int value: {}\n", numeric_limits<int>::lowest());

		cout << "\ndouble:\n";
		cout << format("Max double value: {}\n", numeric_limits<double>::max());
		cout << format("Min double value: {}\n", numeric_limits<double>::min());
		cout << format("Lowest double value: {}\n", numeric_limits<double>::lowest());
	}*/
#pragma endregion

#pragma region cast
	//{
	//	float myFloat{ 3.14f };
	//	int i1{ (int)myFloat };					// ù ��° ���
	//	int i2{ int(myFloat) };					// �� ��° ���
	//	int i3{ static_cast<int>(myFloat) };	// �� ��° ���

	//	short someShort{ 5 };
	//	long someLong{ someShort }; // ��������� ĳ��Ʈ�� �ʿ䰡 ����.
	//}
#pragma endregion

#pragma region oper
	//{
	//	int someInteger{ 256 };
	//	short someShort;
	//	long someLong;
	//	float someFloat;
	//	double someDouble;

	//	someInteger++;											//257
	//	cout << "someInteger :" << someInteger << endl;
	//	someInteger *= 2;										//514
	//	cout << "someInteger :" << someInteger << endl;
	//	someShort = static_cast<short>(someInteger);			//514
	//	cout << "someShort :" << someShort << endl;
	//	someLong = someShort * 10000;							//5140000
	//	cout << "someLong :" << someLong << endl;
	//	someFloat = someLong + 0.785f;							//5.14785e+6 -> 5.14e+6
	//	cout << "someFloat :" << someFloat << endl;
	//	someDouble = static_cast<double>(someFloat) / 100000;	//5.14785e+1 -> 51.4
	//	cout << "someDouble :" << someDouble << endl;
	//}

#pragma endregion

#pragma region 1.16 enum
	//{
	//	enum class PieceType1 { King, Queen, Rook, Pawn }; // 0, 1, 2, 3
	//	enum class PieceType2
	//	{
	//		King = 1, 
	//		Queen,		// 2
	//		Rook = 10, 
	//		Pawn		// 11
	//	};
	//	PieceType1 piece{ PieceType1::King };

	//	//if(PieceType2::Queen == 2) {}	// ���� �߻�.	
	//	if (static_cast<int>(PieceType2::Queen) == 2) { cout << "eqaul" << endl; }	// ��������� ����ȭ �ؾ���.

	//	// C++20
	//	using enum PieceType1;
	//	PieceType1 piece2{ King };
	//	cout << static_cast<int>(piece2) << endl;

	//	// ���� ����� ���� Ÿ��
	//	enum PieceType3 { PiceTypeKing, PiceTypeQueen, PiceTypeRook, PiceTypePawn };
	//	PieceType3 myPice{ PiceTypeQueen };

	//	bool ok{ false };
	//	enum Status { error, ok };	// ������ ���� �߻�
	//}
#pragma endregion

#pragma region 1.1.7 struct
	//{
	//	// ���� ���ڵ� ���� �� �� ä���
	//	Employee anEmployee;
	//	anEmployee.firstInitial = 'J';
	//	anEmployee.lastInitial = 'D';
	//	anEmployee.employeeNumber = 42;
	//	anEmployee.salary = 80000;
	//	// ���� ���ڵ忡 ����� �� ����ϱ�
	//	cout << format("Employee: {} {}", anEmployee.firstInitial,
	//		anEmployee.lastInitial) << endl;
	//	cout << format("Number: {}", anEmployee.employeeNumber) << endl;
	//	cout << format("Number: {}", anEmployee.employeeNumber) << endl;
	//	cout << format("Salary: {}", anEmployee.salary) << endl;
	//}
#pragma endregion

#pragma region 1.1.8 conditional statement
	//{
	//	// ������ fallthrough
	//	enum class Mode { Default, Custom, Standard };

	//	int value{ 42 };
	//	Mode mode{ /* ...*/ };
	//	switch (mode) {
	//		using enum Mode;
	//	case Custom:
	//		value = 84;
	//		//[[fallthrough]]; // ��Ʈ����Ʈ �����ؼ� �ǵ������� ������ ������� �ۼ��ߴٰ� �����Ϸ��� �˷��ش�.
	//	case Standard:
	//	case Default:
	//		// �۾��� �����Ѵ�.
	//		break;
	//	}
	//}
#pragma endregion

#pragma region 1.1.11 three-way comparison operator
	//{
	//	int i{ 11 };
	//	strong_ordering result{ i <=> 0 };
	//	if (result == strong_ordering::less) { cout << "less" << endl; };
	//	if (result == strong_ordering::greater) { cout << "greater" << endl; };
	//	if (result == strong_ordering::equal) { cout << "equal" << endl; };
	//					
	//}

	//// named comparison function
	//{
	//	int i{ 11 };
	//	strong_ordering result{ i <=> 0 };
	//	if (is_lt(result)) { cout << "less" << endl; };
	//	if (is_gt(result)) { cout << "greater" << endl; };
	//	if (is_eq(result)) { cout << "equal" << endl; };

	//}
#pragma endregion

#pragma region 1.1.12 function
//{		
//	auto result = addNumbers(3, 5);
//}
#pragma endregion

#pragma region 1.1.13 attribute
	//{
	//	func();	// C4834 warning

	//	bool isLicensed{ isFeatureLicensed(42) };	// waring C4715

	//	//funcDeprecated();	// Error C4996

	//	int value{/*...*/ };
	//	if (value > 11) [[unlikely]] { /* �ʿ��� �۾��� �����Ѵ� */}
	//	else {/*�ʿ��� �۾��� �����Ѵ�*/ }

	//	switch (value)
	//	{
	//		[[likely]] case 1:
	//			// �ʿ��� �۾��� �����Ѵ�.
	//			break;
	//		case 2:
	//			// �ʿ��� �۾��� �����Ѵ�.
	//			break;
	//		[[unlikely]] case 12:
	//			// �ʿ��� �۾��� �����Ѵ�.
	//			break;

	//	}
	//}
#pragma endregion

#pragma region 1.1.14 C Style Array
	//{
	//	int myArray[3]{};
	//	size_t arraySize{ std::size(myArray) };
	//	cout << arraySize << endl;
	//	arraySize = sizeof(myArray) / sizeof(myArray[0]);
	//	cout << arraySize << endl;
	//}
#pragma endregion

#pragma region 1.1.15 std::array
	//{
	//	array<int, 3> arr{ 9,8,7 };
	//	cout << format("Array size = {}", arr.size()) << endl;
	//	cout << format("2nd element = {}", arr[1]) << endl;

	//	array arr2{ 9,8,7 };	// CTAD 
	//}
#pragma endregion

#pragma region 1.1.16 std::vector
	//{
	//	// ���� Ÿ�� ���͸� �����Ѵ�.
	//	vector<int> myVector{ 11,22 };

	//	// push_back()�� �̿��Ͽ� ������ ���Ϳ� �������� �� �� �� �߰��Ѵ�.
	//	myVector.push_back(33);
	//	myVector.push_back(44);

	//	// ���ҿ� �����Ѵ�.
	//	cout << format("1st element: {}", myVector[0]) << endl;

	//	vector myVector2{ 11, 22 };	//CTAD

	//	//vector myVector3;	// �߸��� ����
	//}
#pragma endregion

#pragma region 1.1.17 std::pair
//{
//	pair<double, int> myPair{ 1.23, 5 };
//	cout << format("{} {}", myPair.first, myPair.second) << endl;

//	pair myPair2{ 1.23, 5 }; //CTAD
//}
#pragma endregion

#pragma region 1.1.18 std::optional
//{
//	optional<int> data1{ getData(true) };
//	optional<int> data2{ getData(false) };

//	cout << "data1.has_value = " << data1.has_value() << endl;
//	if (data2) {
//		cout << "data2 has a value." << endl;
//	}

//	cout << "data1.value = " << data1.value() << endl;
//	cout << "data1.value = " << *data1 << endl;
//	
//	cout << "data2.value = " << data2.value_or(0) << endl;
//	
//}
#pragma endregion

#pragma region 1.1.19 structured binding
	//{
	//	std::array values{ 11,22,33 };
	//	
	//	auto [x, y, z] {values};
	//	cout << format("x : {}, y : {}, z : {}", x, y, z) << endl;	

	//	struct Point { double m_x, m_y, m_z; };
	//	Point point;
	//	point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
	//	auto [x2, y2, z2] { point };

	//	cout << format("x2 : {}, y2 : {}, z2 : {}", x2, y2, z2) << endl;

	//	pair myPair{ "hello", 5 };
	//	auto [theString, theInt] {myPair};	// ������ ���ε��� �̿��� ������
	//	cout << format("theString: {}", theString) << endl;
	//	cout << format("theInt: {}", theInt) << endl;

	//}
#pragma endregion

#pragma region 1.1.20 loop
	//{
	//	//while
	//	{
	//		int i{ 0 };
	//		while (i < 5) {
	//			cout << "This is silly." << endl;
	//			++i;
	//		}			
	//	}

	//	// do/while
	//	{
	//		int i{ 100 };
	//		do {
	//			cout << "Thils is silly." << endl;
	//			++i;
	//		} while (i < 5);

	//	}

	//	// for
	//	{
	//		for (int i{ 0 }; i < 5; ++i) {
	//			cout << "This is silly." << endl;
	//		}
	//	}

	//	// range-based for
	//	{
	//		array arr{ 1,2,3,4 };
	//		for (int i : arr) { cout << i << endl; }

	//		// C++20
	//		for (array arr{ 1,2,3,4 }; int i : arr) { cout << i << endl; }
	//	}
	//}
#pragma endregion

#pragma region 1.1.21 initializer_list
	//{
	//	int a{ makeSum({1,2,3}) };
	//	int b{ makeSum({10,20,30,40,50,60}) };
	//	
	//	cout << a << endl;
	//	cout << b << endl;

	//}
#pragma endregion

#pragma region 1.1.22 String
	//{
	//	string myString{ "Hello, World" };
	//	cout << format("The value of myString is{}", myString) << endl;
	//	cout << format("The secod letter is {}", myString[1]) << endl;
	//}
#pragma endregion

#pragma	region 1.1.23 OOP
//{
//	AirlineTicket myTicket;
//	myTicket.setPassengerName("Sherman T. Socketwrench");
//	myTicket.setNumberOfMiles(700);
//	double cost{ myTicket.calculatePriceInDollars() };
//	cout << format("This ticket will cost ${}", cost) << endl;
//}
#pragma endregion

#pragma region 1.1.24 scope
	//{
	//	Demo d;
	//	cout << d.get() << endl;	// 5�� ����Ѵ�.
	//	cout << NS::get() << endl;	// 20�� ����Ѵ�.
	//	cout << ::get() << endl;	// 10�� ����Ѵ�.
	//	cout << get() << endl;		// 10�� ����Ѵ�.
	//}
#pragma endregion

#pragma region 1.1.25 uniform initialization
	//{
	//	// C++11 ����
	//	CircleStruct myCircle1 = { 10, 10, 2.5 };
	//	CircleClass myCircle2(10, 10, 2.5);

	//	// C++11 ~
	//	CircleStruct myCircle3 = { 10,10,2.5 };
	//	CircleClass myCircle4 = { 10,10,2.5 };

	//	CircleStruct myCircle5 { 10,10,2.5 };
	//	CircleClass myCircle6 { 10,10,2.5 };

//	// 1.1.7 Struct ����
//	// ���� ���ڵ� ���� �� �� ä���
//	Employee anEmployee;
//	anEmployee.firstInitial = 'J';
//	anEmployee.lastInitial = 'D';
//	anEmployee.employeeNumber = 42;
//	anEmployee.salary = 80000;

//	// �տ� �ʱ�ȭ ��� ��
//	Employee anEmployee2{ 'J', 'D', 42, 80'000 };

//	int a = 3;
//	int b(3);
//	int c = { 3 };	// ���� �ʱ�ȭ
//	int d{ 3 };		// ���� �ʱ�ȭ

//	// x�� ���� �����ϰų� func()�� ȣ���� �� 3.14�� 3���� �߶󳽴�
//	int x = 3.14;		// �����Ϸ� ������ �ս� ���� ��� �޽��� �߻�
//	func(3.14);			// �����Ϸ� ������ �ս� ���� ��� �޽��� �߻�

//	//int x2{ 3.14 };		// ��� ��ȯ���� ���� ���� �߻�
//	//func({ 3.14 });		// ��� ��ȯ���� ���� ���� �߻�

//	// ���� �ʱ���
//	struct Employee2 {
//		char firstInitial;
//		char lastInitial;
//		int employeeNumber;
//		int salary{ 75'000 };
//	};

//	Employee2 anEmployee3{
//		.firstInitial = 'J',
//		.lastInitial = 'D',
//		.employeeNumber = 42,
//		.salary = 80'000
//	};
//	cout << format("firstInitial : {}", anEmployee3.firstInitial) << endl;
//	cout << format("lastInitial : {}", anEmployee3.lastInitial) << endl;
//	cout << format("employeeNumber : {}", anEmployee3.employeeNumber) << endl;
//	cout << format("salary : {}", anEmployee3.salary) << endl;

//	// employeeNumber�� ���� �ʱ��ڰ� ���� ������ 0���� �ʱ�ȭ 
//	Employee2 anEmployee4{
//		.firstInitial = 'J',
//		.lastInitial = 'D', 
//		.salary = 80'000
//	};
//	cout << format("firstInitial : {}", anEmployee4.firstInitial) << endl;
//	cout << format("lastInitial : {}", anEmployee4.lastInitial) << endl;
//	cout << format("employeeNumber : {}", anEmployee4.employeeNumber) << endl;
//	cout << format("salary : {}", anEmployee4.salary) << endl;

//	// salary�� ���� �ʱ��ڰ� �����Ƿ� 75,000
//	Employee2 anEmployee5{
//		.firstInitial = 'J',
//		.lastInitial = 'D',
//	};
//	cout << format("firstInitial : {}", anEmployee5.firstInitial) << endl;
//	cout << format("lastInitial : {}", anEmployee5.lastInitial) << endl;
//	cout << format("employeeNumber : {}", anEmployee5.employeeNumber) << endl;
//	cout << format("salary : {}", anEmployee5.salary) << endl;
//
//}
#pragma endregion

#pragma region 1.1.26 pointer, dynamic memory
//{
//	int* myIntegerPointer{ nullptr };
//	if (!myIntegerPointer)
//	{
//		cout << "�Ҵ���� ���� null pointer" << endl;
//		myIntegerPointer = new int;
//		*myIntegerPointer = 8;
//	}
//	cout << myIntegerPointer << " " << format("*myIntegerPointer : {}", *myIntegerPointer) << endl;

//	if (myIntegerPointer)
//	{
//		delete myIntegerPointer;
//		myIntegerPointer = nullptr;
//	}

//	int i{ 8 };
//	myIntegerPointer = &i;	
//	cout << *myIntegerPointer << endl;
//	
//	int arraySize{ 8 };
//	int* myVariableSizedArray{ new int[arraySize] };
//	myVariableSizedArray[3] = 2;
//	for (int i=0; i<arraySize; i++)
//		cout << myVariableSizedArray[i] << endl;
//	delete[] myVariableSizedArray;
//	myVariableSizedArray = nullptr;

//}
#pragma endregion

#pragma region 1.1.27 const
	//{
	//	const int versionNumberMajor{ 2 };
	//	const int versionNumberMinor{ 1 };
	//	const std::string productName{ "Super Hyper Net Modulator" };
	//	const double PI{ 3.141592653589793238462 };

	//	const int* ip;					// int const* ip�� ����. ip�� ����Ű�� ���� ������ �� ������
	//	ip = new int[10];
	//	//ip[4] = 5;					// ������ ���� �߻�

	//	int* const ip2{ nullptr };		// ip ���� ������ �� ������
	//	//ip2 = new int[10];				// ������ ���� �߻�

	//	int* const ip3{ new int[10] };	// ����� ���ÿ� �ʱ�ȭ�ؼ� ���
	//	ip3[4] = 5;
	//	cout << ip3[4] << endl;

	//	const int* const ip4{ nullptr };

	//	std::string myString{ "The string" };
	//	mysteryFunction(&myString);

	//}
#pragma endregion

#pragma region 1.1.28 constexpr
	//{
	//	//int myArray[getArraySize()];	// C++���� ������� �ʴ� ǥ��

	//	int myArray[getArraySize2()];	// OK
	//	int myArray2[getArraySize2() + 1];

	//	// constexpr ������
	//	class Rect
	//	{
	//	public:
	//		constexpr Rect(size_t width, size_t height)
	//			: m_width{ width }, m_height{ height } {}

	//		constexpr size_t getArea() const { return m_width * m_height; }
	//	private:
	//		size_t m_width{ 0 }, m_height{ 0 };
	//	};

	//	constexpr Rect r{ 8,2 };
	//	int myArray3[r.getArea()];	//OK
	//	cout << sizeof(myArray3) / sizeof(myArray3[0]) << endl;
	//}
#pragma endregion

#pragma region 1.1.29 consteval
	//{
	//	constexpr double const_inch{ 6.0 };
	//	constexpr double mm1{ inchToMm(const_inch) };	// ������ �ð��� �򰡵�

	//	double dynamic_inch{ 8.0 };
	//	double mm2{ inchToMm(dynamic_inch) };			// ����ð��� �򰡵�

	//	constexpr double const_inch2{ 6.0 };
	//	constexpr double mm2{ inchToMm2(const_inch2) };	// ������ �ð��� �򰡵�

	//	double dynamic_inch2{ 8.0 };
	//	//double mm2{ inchToMm2(dynamic_inch2) };			// ������ �ð��� �򰡵� �� ���� ������ ���� �߻�
	//}
#pragma endregion

#pragma region 1.1.30 reference
	//{
	//	/*int x{ 3 };
	//	int& xRef{ x };

	//	cout << format("x : {}, xRef : {}", x, xRef) << endl;
	//	xRef = 10;
	//	cout << format("x : {}, xRef : {}", x, xRef) << endl;*/

	//	//int& emptyRef	// ������ ���� �߻�

	//	//int x{ 3 }, y{ 4 };
	//	//int& xRef{ x };
	//	//cout << format("x : {}, xRef : {}, y : {}", x, xRef, y) << endl;
	//	//xRef = y;	// xRef�� ����Ű�� ����� y�� �������� �ʰ� x�� ���� 4�� �ٲ��.
	//	//y += 1;
	//	//cout << format("x : {}, xRef : {}, y : {}", x, xRef, y) << endl;

	//	//int x{ 3 }, z{ 5 };
	//	//int& xRef{ x };
	//	//int& zRef{ z };
	//	//cout << format("x : {}, xRef : {}", x, xRef) << endl;
	//	//cout << format("z : {}, zRef : {}", z, zRef) << endl;
	//	//zRef = xRef;		// ���۷����� �ƴ� ���� ���Եȴ�.
	//	//xRef += 1;
	//	//cout << format("x : {}, xRef : {}", x, xRef) << endl;
	//	//cout << format("z : {}, zRef : {}", z, zRef) << endl;

	//	int z;
	//	const int& zRef{ z };
	//	//zRef = 4;				// ������ ���� �߻�

	//	//int& unnamedRef1{ 5 };		// ������ ���� �߻�
	//	const int& unnamedRef2{ 5 };	// ���� �۵�

	//	//string& string1{ getString() };		// ������ ���� �߻�
	//	const string& string2{ getString() };	// ���� �۵�

	//	int* intP{ nullptr };
	//	int*& ptrRef{ intP };
	//	ptrRef = new int;
	//	*ptrRef = 5;
	//	cout << format("*intP : {}, *ptrRef : {}", *intP, *ptrRef) << endl;

	//	int x{ 3 };
	//	int& xRef{ x };
	//	int* xPtr{ &xRef };
	//	*xPtr = 100;
	//	cout << format("x : {}, xRef : {}, *xPtr : {}", x, xRef, *xPtr) << endl;

	//	pair myPair{ "hello", 5 };
	//	auto& [theString, theInt] {myPair};			// �� const ���۷����� ����
	//	const auto& [theString2, theInt2] {myPair};	// const ���۷����� ����
	//	theInt = 500;
	//	//theInt2 = 100;							// ������ ���� �߻�

	//	class MyClass
	//	{
	//	public:
	//		MyClass(int& ref) : m_ref{ ref } {/* ������ ����*/ }
	//	private:
	//		int& m_ref;
	//	};

	//	int myInt{ 7 };
	//	addOne(myInt);
	//	cout << myInt << endl;
	//	addOne_2(myInt);
	//	cout << myInt << endl;
	//
	//	int x1{ 5 }, y1{ 6 };
	//	swap(x1, y1);
	//	cout << format("x : {}, y : {}", x1, y1)<< endl;

	//	int* xp{ &x1 }, * yp{ &y1 };
	//	swap(*xp, *yp);
	//	cout << format("x : {}, y : {}", x1, y1) << endl;

	//	// const reference parameter
	//	string someString{ "Hello World" };
	//	printString(someString);
	//	printString("Hello World");	// ���ͷ��� �����ص� �ȴ�.

	//	//int* ptr{ (int*)8 };
	//	//refcall(*ptr);				// ���� �Ұ�

//	int unSplit[]{ 1,2,3,4,5,6,7,8,9,10 };
//	int* oddNums{ nullptr };
//	int* evenNums{ nullptr };
//	size_t numOdds{ 0 }, numEvens{ 0 };
//	
//	separateOddsAndEvens_ptr(unSplit, std::size(unSplit),
//		&oddNums, &numOdds, &evenNums, &numEvens);

//	// ������ �迭�� ����ϴ� �ڵ�
//	for (int i = 0; i < numOdds; i++)
//	{
//		cout << oddNums[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < numEvens; i++)
//	{
//		cout << evenNums[i] << " ";
//	}
//	cout << endl;

//	separateOddsAndEvens_ref(unSplit, std::size(unSplit),
//		oddNums, numOdds, evenNums, numEvens);

//	// ������ �迭�� ����ϴ� �ڵ�
//	for (int i = 0; i < numOdds; i++)
//	{
//		cout << oddNums[i] << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < numEvens; i++)
//	{
//		cout << evenNums[i] << " ";
//	}
//	cout << endl;
//	delete[] oddNums; oddNums = nullptr;
//	delete[] evenNums; evenNums = nullptr;

//	vector<int> v_unSplit{ 1,2,3,4,5,6,7,8,9,10 };
//	vector<int> v_oddNums;
//	vector<int> v_evenNums;

//	separateOddsAndEvens_vector(v_unSplit, v_oddNums, v_evenNums);
//	for (int i : v_oddNums)
//	{
//		cout << i;
//	}
//	cout << endl;
//	for (int i : v_evenNums)
//	{
//		cout << i;
//	}
//	cout << endl;

//	auto oddsAndEvens{ separateOddsAndEvens(v_unSplit) };
//	for(int i:oddsAndEvens.odds)
//	{
//		cout << i;
//	}
//	cout << endl;
//	for (int i : oddsAndEvens.evens)
//	{
//		cout << i;
//	}
//	cout << endl;
//	auto [odds, evens] { separateOddsAndEvens(v_unSplit) };
//	for (int i : odds)
//	{
//		cout << i;
//	}
//	cout << endl;
//	for (int i : evens)
//	{
//		cout << i;
//	}
//	cout << endl;
//}
#pragma endregion

#pragma region 1.1.31 const_cast()
	//{
	//	std::string str{ "C++" };
	//	const std::string& constStr{ as_const(str) };
	//}
#pragma endregion

#pragma region 1.1.32 exception
	//{
	//	try {
	//		cout << divideNumbers(2.5, 0.5) << endl;
	//		cout << divideNumbers(2.3, 0) << endl;
	//		cout << divideNumbers(4.5, 2.5) << endl;
	//	}
	//	catch (const invalid_argument& exception) {
	//		cout << format("Exception caught: {} ", exception.what()) << endl;
	//	}
	//}
#pragma endregion

#pragma region 1.1.33 type alias
	//{
	//	//vector<basic_string<char>> myVector;		// using string = basic_string<char>
	//	vector<string> myVector;
	//	myVector.push_back("abc");
	//	myVector.push_back("def");
	//	processVector(myVector);
	//}
#pragma endregion

#pragma region 1.1.35 auto
	{
		//auto x{ 123 };	// x�� int Ÿ������ ����

		//auto f1{ foo() };	// ���۷����� const ����, �� ����
		
		// auto&
		const auto& f2{ foo() };

		string str{ "C++" };
		auto result{ as_const(str) };	// ���۷����� const ����, �� ����		

		// auto*
		int i{ 123 };
		auto p{ &i };

		auto* p2{ &i };

		// ���� ����Ʈ �ʱ�ȭ�� ���� ����Ʈ �ʱ�ȭ
		// ���� ����Ʈ �ʱ�ȭ
		auto a = { 11 };		// initializer_list<int>
		auto b = { 11,22 };		// initializer_list<int>
		for (int i : b)
			cout << i << endl;
		// ���� ����Ʈ �ʱ�ȭ
		auto c{ 11 };			// initializer_list<int>
		//auto d{ 11,22 };		// initializer_list<int>	//error


		// decltype Ű����
		int x{ 123 };
		decltype(x) y{ 456 };

		decltype(foo()) f3{ foo() };
	}
#pragma endregion
	return 0;
}
