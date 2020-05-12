#include"Point.h"
int main()
{
	Point P;
	P.setX(5);
	P.setY(6);
	P.setZ(9);
	cout << P.getX() << " " << P.getY() << " " << P.getZ() << endl;
	Point B;
	B.setX(1);
	B.setY(2);
	B.setZ(9);
	cout << B.getX() << " " << B.getY() << " " << B.getZ() << endl;
	cout << P.distance(B) << endl;
	if (P == B)
		cout << "P nesnesi B nesnesine esit!!" << endl;
	else
		cout << "P nesnesi B nesnesine esit degil!!" << endl;

	system("pause");
}