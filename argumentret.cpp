#include <iostream>
using namespace std;

// declearation 
class base;


int gident = 0;
base* gptr0;
base* gptr1;

class base
{
public:
	base()
	{
		ident = gident ++;
		x = 0;
		cout << "calling none argument constructor, ident = " << ident  << endl;
	};
	base(const base& other)
	{
		ident = gident ++;
		x = other.x;
		cout << "calling copy constructor, ident = " << ident  << endl;
	};
	base& operator=(const base& other)
	{
		ident = gident ++;
		x = other.x;
		cout << "calling overrided assignment operator= , ident = " << ident  << endl;
		return *this;
	}
	base(int nx):x(nx)
	{
		ident = gident ++;
		cout << "calling constructor with one integer argument, ident = " << ident  << endl;
	};
	int getx()
	{
		return x;
	}
	~base()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};

private:
	int x;
	int ident;
};



base retnormal()
{
	return base(5);
}
base& retreference()
{
	cout << "you can't return a reference of stack object" << endl;
	int x;
	x/0;
	base tmp = base(5);
	return tmp;
}


void passclass(base obj)
{
	obj.getx();
}
void passreference(base& obj)
{
	obj.getx();
}


int main()
{
	cout << "-------------------" << "constructor test" << "-------------------" << endl;
	cout << endl << "[+] assign integer to a class" << endl;
	base c0 = 0;

	cout << endl << "[+] pass class to a function receive normal object" << endl;
	passclass(c0);

	cout << endl << "[+] pass class to a function receive reference object" << endl;
	passreference(c0);

	cout << endl << "[+] return normal object" << endl;
	retnormal();

	cout << endl << "[+] return normal object and assign it to an object" << endl;
	base c1 = retnormal();


	cout << "-------------------" << "end of main" << "-------------------" << endl;
}

