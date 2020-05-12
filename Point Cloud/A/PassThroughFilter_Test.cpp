#include"PassThroughFilter.h"
#include"DepthCamera.h"
#include<iostream>
using namespace std;
int main()
{
	DepthCamera x;
	PointCloud pc1 = x.capture();///Kameradan okunan degerler pointcloudda tutulur.
	PointCloud pc2 = x.capture();///Kameradan okunan degerler pointcloudda tutulur.

	PassThroughFilter fpoint;///PassThroughFilter nesnesi olusturulur.
	fpoint.setX(0, 400);
	fpoint.setY(0, 400);
	fpoint.setZ(-45, 45);
	/*cout << "Filitrelemeden onceki cloud sayisi:" << pc1.pointsSize() << endl << endl;
	for (int i = 0; i < pc1.pointsSize(); i++)
	{
		cout << pc1.getpoints(i).getX() << " " << pc1.getpoints(i).getY() << " " << pc1.getpoints(i).getZ() << endl;
	}*/
	cout << endl << endl << endl;
	fpoint.filter(pc1);///Ilgili nesneye filitreleme uygulanir.
	cout << "Filitrelendikten sonraki cloud sayisi:" << pc1.pointsSize() << endl << endl;
	for (int i = 0; i < pc1.pointsSize(); i++)
	{
		cout << pc1.getpoints(i).getX() << " " << pc1.getpoints(i).getY() << " " << pc1.getpoints(i).getZ() << endl;
	}
	fpoint.setX(0, 300);
	fpoint.setY(0, 500);
	fpoint.setZ(-45, 45);
	cout << "Filitrelemeden onceki cloud sayisi:" << pc2.pointsSize() << endl << endl;
	/*for (int i = 0; i < pc2.pointsSize(); i++)
	{
		cout << pc2.getpoints(i).getX() << " " << pc2.getpoints(i).getY() << " " << pc2.getpoints(i).getZ() << endl;
	}*/
	cout << endl << endl << endl;
	fpoint.filter(pc2);///Ilgili nesneye filitreleme uygulanir.
	cout << "Filitrelendikten sonraki cloud sayisi:" << pc2.pointsSize() << endl << endl;
	for (int i = 0; i < pc2.pointsSize(); i++)
	{
		cout << pc2.getpoints(i).getX() << " " << pc2.getpoints(i).getY() << " " << pc2.getpoints(i).getZ() << endl;
	}
	system("pause");
}