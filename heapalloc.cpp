#include <iostream>
using namespace std;

// declearation 
class parent;


int gident = 0;
parent* gptr0;
parent* gptr1;

class parent
{
public:
	parent()
	{
		ident = gident ++;
		x = 0;
		cout << "ident = " << ident  << endl;
	};
	parent(int nx):x(nx)
	{
		ident = gident ++;
		cout << "ident = " << ident  << endl;
	};
	int getx()
	{
		return x;
	}
	~parent()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};



private:
	int x;
	int ident;
};



int main()
{
	cout << "-------------------" << "heap alloc test" << "-------------------" << endl;
	cout << endl << "using new to alloca instance, with no parameter" << endl;
	parent *p0 = new parent;

	cout << endl << "using new to alloca instance, with no parameter, but with brackets" << endl;
	parent *p1 = new parent();

	cout << endl << "using new to alloca instance, with one parameter, but with brackets" << endl;
	parent *p2 = new parent(2);

	cout << endl;
	delete p0;
	delete p1;
	delete p2;
}


