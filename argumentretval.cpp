#include <iostream>
using namespace std;

// declearation 
class parent;

parent *gptr0;
parent *gptr1;


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
	~parent()
	{
		cout << "calling destructor, ident  = " << ident << endl;
	};


private:
	int x;
	int ident;
	double j0;
};

void f0(parent aP)
{
}
void f1(parent &aP)
{
}
void f2(parent *aP)
{
}
parent f3()
{
	return parent(12);
}
parent f4()
{
	gptr0 = new parent(14);
	return *gptr0;
}
parent& f5()
{
	gptr1 = new parent(14);
	return *(gptr1); 
}

int main()
{
	cout << "-------------------" << "pass, return instace test" << "-------------------" << endl;
	cout << endl << "calling from one parameter constructor to allocate a instance on stack" << endl;
	parent p11(11);

	cout << endl << "calling | void f0(parent aP) |" << endl;
	cout << "created temp instance and pass to callee" << endl;
	f0(p11);

	cout << endl << "calling | void f0(parent &aP) |" << endl;
	cout << "pass address to callee" << endl;
	f1(p11);

	cout << endl << "calling | void f0(parent *aP) |" << endl;
	cout << "pass address to callee" << endl;
	f2(&p11);

	cout << endl << "calling | return parent(12) |" << endl;
	cout << "pass temp variable address to callee, then copy temp variable to caller's stack variable" << endl;
	p11 = f3();

	cout << endl << "calling | return *( new parent(13) ) |" << endl;
	cout << "pass temp variable address to callee, then copy temp variable to caller's stack variable" << endl;
	p11 = f4();

	cout << endl << "calling | return *( new parent(13) ) |" << endl;
	cout << "copy return variable directly to caller's stack variable" << endl;
	p11 = f5();

	parent(1024);



	cout << endl;
	delete gptr0;
	gptr0 = NULL;
	delete gptr1;
	gptr1 = NULL;
}
