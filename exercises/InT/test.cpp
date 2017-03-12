#include "header.h"
#include "func.h"

int main() {
	inT a,b,c,d;
	a = 8;
	b = 10;
	c = 2;
	//c =d*( b + a)-b;
	//d = b / a;
	
	a = b + 4/c;
	a = 1 - b;
	a = 2 + c;
	a.show(); cout << endl;
	a = a + 2;
	a.show(); cout << endl;
	a = b + c;
	a.show(); cout << endl;

	d = 5 * 11;
	d++;
	d.show(); cout << endl;
	d = c*b;
	//c = a + d;
	
	
	
	d.show(); cout << endl;
	//printf("%d\n", c);
	system("pause");
	return 0;
}