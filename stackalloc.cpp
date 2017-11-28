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
		cout << "calling constructor, ident = " << ident  << endl;
	};
	parent(int nx):x(nx)
	{
		ident = gident ++;
		cout << "calling constructor, ident = " << ident  << endl;
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

parent retparent()
{
	return parent(4);
}
parent hookretparent()
{
	return retparent();
}



int main()
{
	cout << "-------------------" << "stack alloc test" << "-------------------" << endl;
	cout << "calling from zero parameter constructor | parent() |" << endl;
	cout << "it would pass p0 address quitely to contructor" << endl;
	parent p0;

	cout << endl << "calling from one parameter constructor | parent(int nx):x(nx) |" << endl;
	cout << "it would pass p1 address quitely to contructor" << endl;
	parent p1(1);

	cout << endl << "calling from zero parameter constructor | parent() | , another form. This is equivalent to the first one." << endl;
	cout << "it would pass p2 address quitely to contructor" << endl;
	parent p2 = parent();

	cout << endl << "calling from one parameter constructor | parent(int nx):x(nx) |, another form. This is equivalent to the second one." << endl;
	cout << "it would pass p3 address quitely to contructor" << endl;
	parent p3 = parent(3);

	cout << endl << "calling return instance function" << endl;
	cout << "it would pass p4 address quitely to contructor" << endl;
	parent p4 = hookretparent();
	cout << endl;
}

