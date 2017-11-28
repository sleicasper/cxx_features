#include <iostream>
using namespace std;

// declearation 
class parent;


int gident = 0;

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
	virtual void sayhello()
	{
		cout << "Hello, I'am parent" << endl;
	}
	~parent()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};

private:
	int x;
	int ident;
};
class son: public parent
{
public:
	virtual void sayhello()
	{
		cout << "Hello, I'am son" << endl;
	}
	virtual void saybye()
	{
		cout << "Bye, I'am son" << endl;
	}
};

class grandson: public son
{
public:
	virtual void sayhello()
	{
		cout << "Hello, I'am grand son" << endl;
	}
	virtual void saybye()
	{
		cout << "Bye, I'am grandson" << endl;
	}
};


int main()
{
	cout << "-------------------" << "vt test" << "-------------------" << endl;
	cout << "allocating parent pointer on stack" << endl;
	parent *ptr0;
	cout << "allocating son pointer on stack" << endl;
	son *ptr1;

	cout << endl << "calling from zero parameter constructor | parent() |" << endl;
	cout << "it would pass p0 address quitely to contructor" << endl;
	parent p0;

	cout << endl << "calling from zero parameter constructor | son() |" << endl;
	cout << "it would pass s1 address quitely to contructor" << endl;
	son s1;

	cout << endl << "calling from zero parameter constructor | grandson() |" << endl;
	cout << "it would pass g2 address quitely to contructor" << endl;
	grandson g2;


	cout << endl << "set ptr0 to parent, and call |sayhello()|" << endl;
	ptr0 = &p0;
	ptr0->sayhello();

	cout << endl << "set ptr0 to son" << endl;
	ptr0 = &s1;
	cout << "call |sayhello()|" << endl;
	ptr0->sayhello();

	cout << endl << "set ptr0 to grandson" << endl;
	ptr0 = &g2;
	cout << "call |sayhello()|" << endl;
	ptr0->sayhello();



	cout << endl << "set ptr1 to son" << endl;
	ptr1 = &s1;
	cout << "call |saybye()|" << endl;
	ptr1->saybye();

	cout << endl << "set ptr1 to grandson" << endl;
	ptr1 = &g2;
	cout << "call |saybye()|" << endl;
	ptr1->saybye();

	cout << endl;
}

