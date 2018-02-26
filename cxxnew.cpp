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


int main()
{
	void *buf = malloc(0x1000);
	int n = 10;
	cout << "-------------------" << "New Test" << "-------------------" << endl;
	cout << "[+] New array test" << endl;
	cout << "[+] new int[10];" << endl;
	cout << "[+] new int[10];" << endl;
	cout << "[+] new int[n];" << endl;
	cout << "[+] new int[10][10];" << endl;
	cout << "[+] new int[n][10];" << endl;
	cout << "[+] new int[10][10][10];" << endl;
	cout << "[+] new int[n][10][10];" << endl << endl;
	new int[10];
	new int[n];
	new int[10][10];
	new int[n][10];
	new int[10][10][10];
	new int[n][10][10];

	cout << "[+] New function pointer test" << endl;
	cout << "[+] new (int (*)(int, int));" << endl;
	new (int (*)(int, int));
	cout << "[+] New one demension function pointer array" << endl;
	cout << "[+] new (int (*[10])(int, int));" << endl;
	new (int (*[10])(int, int));
	cout << "[+] New two demension function pointer array" << endl;
	cout << "[+] new (int (*[10][10])(int, int));" << endl << endl;
	new (int (*[10][10])(int, int));

	cout << "[+] Normal new method" << endl;
	cout << "[+] new parent();" << endl << endl;
	new parent();

	cout << "[+] Normal new method with parameter" << endl;
	cout << "[+] new parent(233);" << endl << endl;
	new parent(233);

	cout << "[+] This is placement new" << endl;
	cout << "[+] new (buf) parent();" << endl << endl;
	new (buf) parent();
}

