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

void normalfunc(base arg)
{
	cout << "in function |normalfunc|" << endl;
}
void rvaluefunc(base &&arg)
{
	cout << "in function |rvaluefunc|" << endl;
}



int main()
{
	cout << "-------------------" << "constructor test" << "-------------------" << endl;

	cout << endl << "[+] calling normal function with object allocated when passing argument" << endl;
	normalfunc(base(2333));

	cout << endl << "[+] calling function which receives rvalue with object allocated when passing argument" << endl;
	rvaluefunc(base(2333));

	cout << "-------------------" << "end of main" << "-------------------" << endl;
}

