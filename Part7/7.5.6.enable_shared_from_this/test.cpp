import <iostream>;

using namespace std;

class Foo : public enable_shared_from_this<Foo>
{
public:
	Foo(int data)
		:m_data(data) {}
	shared_ptr<Foo> getPointer() 
	{
		return shared_from_this();
	}
	int m_data;
};

// bad case
class Foo
{
public:
	shared_ptr<Foo> getPointer()
	{
		return shared_ptr<Foo>(this);
	}
};

int main()
{
	auto ptr1{ make_shared<Foo>(10)};
	auto ptr2{ ptr1->getPointer() };
	cout << ptr1 << " " << ptr2 << endl;
	cout << ptr1->m_data << " " << ptr2->m_data << endl;
	return 0;
}
