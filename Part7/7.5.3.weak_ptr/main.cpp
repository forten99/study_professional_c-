import <iostream>;

using namespace std;

class Simple
{
public:
	Simple()
	{
		cout << "Simple constructor called!" << endl;
	}

	~Simple()
	{
		cout << "Simple destructor called!" << endl;
	}
};

void useResource(weak_ptr<Simple>& weakSimple)
{
	auto resource{ weakSimple.lock() };
	if (resource)
		cout << "Resource still alive." << endl;
	else
		cout << "Resource has benn freed!" << endl;
}

int main()
{
	auto sharedSimple{ make_shared<Simple>() };
	weak_ptr<Simple> weakSimple{ sharedSimple };

	// weak_ptr�� ����Ѵ�.
	useResource(weakSimple);

	// shread_ptr�� �����Ѵ�.
	// Simple ���ҽ��� ���� shared_ptr�� �ϳ����̹Ƿ�
	// weak_ptr�� ��� �ִ��� ���ҽ��� �����ȴ�.
	sharedSimple.reset();

	
	// weak_ptr�� �ѹ� �� ����Ѵ�.
	useResource(weakSimple);
}
