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

base retbase()
{
	return base(5);
}


void passclass(base obj)
{
	obj.getx();
}
void passclassandaccessit(base obj)
{
	base st = obj;
}
void passrvalue(base&& obj)
{
	obj.getx();
}

void passrvalueandaccessit(base&& obj)
{
	base sv = obj;
}


int main()
{
	cout << "-------------------" << "constructor test" << "-------------------" << endl;
	cout << endl << "[+] assign integer to a class" << endl;
	base c0 = 0;

	cout << endl << "[+] assign integer to a rvalue class" << endl;
	base &&c1 = 1;

	cout << endl << "[+] assign return value to a normal class" << endl;
	base c2 = retbase();

	cout << endl << "[+] assign return value to a rvalue class" << endl;
	base &&c3 = retbase();


	cout << endl << "[+] pass normal class to a function" << endl;
	passclass(c0);

	cout << endl << "[+] pass normal class to a function and access it" << endl;
	passclassandaccessit(c0);

	cout << endl << "[+] pass rvalue class to a function" << endl;
	passrvalue( retbase() );

	cout << endl << "[+] pass rvalue class to a function and access it" << endl;
	passrvalueandaccessit( retbase() );

	cout << endl;
}

