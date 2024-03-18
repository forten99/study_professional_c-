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

	// weak_ptr을 사용한다.
	useResource(weakSimple);

	// shread_ptr을 리셋한다.
	// Simple 리소스에 대한 shared_ptr은 하나뿐이므로
	// weak_ptr이 살아 있더라도 리소스가 해제된다.
	sharedSimple.reset();

	
	// weak_ptr을 한번 더 사용한다.
	useResource(weakSimple);
}
