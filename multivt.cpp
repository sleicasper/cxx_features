#include <iostream>
using namespace std;

// declearation 
class base0;
class base1;
class derived;


int gident = 0;

class base0
{
public:
	base0()
	{
		ident = gident ++;
		x = 0;
		cout << "calling constructor, ident = " << ident  << endl;
	};
	virtual void sayhello()
	{
		cout << "Hello, I'am BASE 0" << endl;
	}
	virtual void sayhello_onlybase0()
	{
		cout << "Hello, this is sayhello_onlybase0()" << endl;
	}
	~base0()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};

private:
	int x;
	int ident;
};
class base1
{
public:
	base1()
	{
		ident = gident ++;
		x = 1;
		cout << "calling constructor, ident = " << ident  << endl;
	};
	virtual void sayhello()
	{
		cout << "Hello, I'am BASE 1" << endl;
	}
	virtual void sayhello_onlybase1()
	{
		cout << "Hello, this is sayhello_onlybase1()" << endl;
	}
	~base1()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};

private:
	int x;
	int ident;
};
class derived: public base0, public base1
{
public:
	derived()
	{
		ident = gident ++;
		x = 1;
		cout << "calling constructor, ident = " << ident  << endl;
	};
	virtual void sayhello()
	{
		cout << "Hello, I'am DERIVED" << endl;
	}
	virtual void sayhello_onlyderived()
	{
		cout << "Hello, this is sayhello_onlyderived()" << endl;
	}
private:
	int x;
	int ident;
};


int main()
{
	cout << "-------------------" << "multivt test" << "-------------------" << endl;
	cout << "allocating base0 pointer on stack" << endl;
	base0 *ptr0;
	cout << "allocating base1 pointer on stack" << endl;
	base1 *ptr1;
	cout << "allocating derived pointer on stack" << endl;
	derived *ptr2;

	cout << endl << "calling from zero parameter constructor | base0() |" << endl;
	base0 c0;

	cout << endl << "calling from zero parameter constructor | base1() |" << endl;
	base1 c1;

	cout << endl << "calling from zero parameter constructor | derived() |" << endl;
	derived c2;

	cout << endl << "c2's memory layout looks like this" << endl;
	cout << "structure		offset											" << endl;
	cout << "{														" << endl;
	cout << "  vptr;			0x0	overrided and none-overrided base0 pointer, as well as derived pointer	" << endl;
	cout << "  x;			0x8											" << endl;
	cout << "  ident;		0xc											" << endl;
	cout << "}														" << endl;
	cout << "{														" << endl;
	cout << "  vptr;			0x10	overrided and none-overrided base1 pointer				" << endl;
	cout << "  x;			0x18											" << endl;
	cout << "  ident;		0x1c											" << endl;
	cout << "}														" << endl;
	cout << "x;			0x20											" << endl;
	cout << "ident;			0x24											" << endl;



	cout << endl << "set ptr0 to base0, offset is 0, and call |sayhello()|" << endl;
	ptr0 = &c0;
	ptr0->sayhello();
	cout << "call |sayhello_onlybase0()|" << endl;
	ptr0->sayhello_onlybase0();

	cout << endl << "set ptr0 to derived, offset is 0, and call |sayhello()|" << endl;
	ptr0 = &c2;
	ptr0->sayhello();

	cout << endl << "set ptr1 to base0, offset is 0, and call |sayhello()|" << endl;
	ptr1 = &c1;
	ptr1->sayhello();
	cout << "call |sayhello_onlybase1()|" << endl;
	ptr1->sayhello_onlybase1();

	cout << endl << "set ptr1 to derived, offset is 0x10, and call |sayhello()|" << endl;
	ptr1 = &c2;
	ptr1->sayhello();

	cout << endl << "set ptr2 to base0, offset is 0, and call |sayhello()|" << endl;
	ptr2 = &c2;
	ptr2->sayhello();
	cout << "call |sayhello_onlyderived()|" << endl;
	ptr2->sayhello_onlyderived();

	cout << endl;
}

