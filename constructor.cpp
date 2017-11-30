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



int main()
{
	cout << "-------------------" << "constructor test" << "-------------------" << endl;
	cout << endl << "[+] calling zero parameter constructor | base() |" << endl;
	base c0;

	cout << endl << "[+] calling one parameter constructor | base(int) |" << endl;
	base c1(1);

	cout << endl << "[+] calling one parameter constructor | base(int) |, another form" << endl;
	base c2 = 2;

	cout << endl << "[+] calling copy constructor" << endl;
	base c3(c1);

	cout << endl << "[+] calling copy constructor, another form" << endl;
	base c4 = c1;

	cout << endl << "[+] calling overrided assignment operator constructor" << endl;
	c4 = c2;

	cout << endl << "[+] calling |retbase()|" << endl;
	base c5 = retbase();

	cout << endl;
}

