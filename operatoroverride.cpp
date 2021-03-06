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



	// override operators

/*
	parent operator=(const parent aP)
	{
		cout << "calling overrided assignment operator | parent operator=(const parent aP) | " << endl;
		this->x = aP.x;
		return *this;
	};
	parent operator=(const parent &aP)
	{
		cout << "calling overrided assignment operator | parent operator=(const parent &aP) | " << endl;
		this->x = aP.x;
		return *this;
	};
	parent& operator=(const parent aP)
	{
		cout << "calling overrided assignment operator | parent& operator=(const parent aP) | " << endl;
		cout << "caller would allocate a temp instance in caller's stack frame, and destoried by caller " << endl;
		this->x = aP.x;
		return *this;
	};
*/
	parent& operator=(const parent &aP)
	{
		cout << "calling overrided assignment operator | parent& operator=(const parent &aP) | " << endl;
		cout << "caller only pass address of this and aP" << endl;
		this->x = aP.x;
		return *this;
	};
	parent& operator=(const int &aI)
	{
		cout << "calling overrided assignment operator | parent& operator=(const int &aI) | " << endl;
		cout << "caller would allocate a temp integer in caller's stack frame, and pass address of the integer to callee" << endl;
		this->x = aI;
		return *this;
	};
	parent& operator=(double aD)
	{
		cout << "calling overrided assignment operator | parent& operator=(const double aD) | " << endl;
		ident = gident ++;
		this->x = (int)aD;
		return *this;
	};
private:
	int x;
	int ident;
	double j0;
};

parent f0()
{
	return parent(2333);
}
double f1()
{
	return 6666.0;
}


int main()
{
	cout << "-------------------" << "operator override test" << "-------------------" << endl;
	cout << endl << "calling from zero parameter constructor to allocate a instance on stack" << endl;
	parent p0;

	cout << endl << "calling from one parameter constructor to allocate a instance on stack" << endl;
	parent p1(1);

	cout << endl << "allocate a instance on heap" << endl;
	parent *ptr = new parent(2);

	cout << endl << "assign instance allocated on stack to p0" << endl;
	p0 = p1;

	cout << endl << "assign instance allocated on heap to p0" << endl;
	p0 = *ptr;

	cout << endl << "assign immediate integer to p0" << endl;
	p0 = 2333;

	cout << endl << "assign return value to p3" << endl;
	parent p3 = f0();

	cout << endl << "assign double number to p0" << endl;
	p0 = 66666.6;



	cout << endl;
	delete ptr;

	cout << "-------------------" << "end of main" << "-------------------" << endl;
}

