#include"PointCloud.h"
int main()
{
	Point p;
	Point p1;
	PointCloud pc;
	PointCloud pc2;
	for (int i = 0; i < 5; i++)
	{
		p.setX(i);
		p.setY(i + 1);
		p.setZ(i + 2);
		pc.setpoints(p);
	}
	cout << "1.nokta bulutu	:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << pc.getpoints(i).getX() << " ";
		cout << pc.getpoints(i).getY() << " ";
		cout << pc.getpoints(i).getZ() << " ";
		cout << endl;

	}
	for (int i = 7; i < 12; i++)
	{
		p1.setX(i);
		p1.setY(i + 1);
		p1.setZ(i + 2);
		pc2.setpoints(p1);

	}
	cout << endl;
	cout << "2. nokta bulutu	:" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << pc2.getpoints(i).getX() << " ";
		cout << pc2.getpoints(i).getY() << " ";
		cout << pc2.getpoints(i).getZ() << " ";
		cout << endl;

	}
	cout << endl;
	PointCloud pc1;
	pc1 = pc + pc2;
	int size1 = pc1.pointsSize();
	cout << "1. ve 2. nokta bulutlarýnýn toplamý:	" << endl;
	for (int i = 0; i < size1; i++)
	{
		cout << pc1.getpoints(i).getX() << " ";
		cout << pc1.getpoints(i).getY() << " ";
		cout << pc1.getpoints(i).getZ() << " ";
		cout << endl;
	}
	cout << endl;
	cout << "size: " << size1;
	cout << endl;
	system("pause");
}