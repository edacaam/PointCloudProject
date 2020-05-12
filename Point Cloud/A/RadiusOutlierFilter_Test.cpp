#include"RadiusOutlierFilter.h"
#include"DepthCamera.h"
#include<iostream>
using namespace std;
int main()
{
	DepthCamera x;
	PointCloud pc1 = x.capture();///Kameradan okunan degerler pointcloudda tutulur.

	//Point* e;
	//e = pc1.getPointCloud();
	RadiusOutlierFilter fpoint;///RadiusOutlierFilter nesnesi olusturulur.
	/*cout << "Filitrelemeden onceki point sayisi:" << pc1.pointsSize() << endl << endl;
	for (int i = 0; i < pc1.pointsSize(); i++)
	{
		cout << pc1.getpoints(i).getX() << " " << pc1.getpoints(i).getY() << " " << pc1.getpoints(i).getZ() << endl;
	}
	cout << endl << endl << endl;
	///Ilgili nesneye filitreleme uygulanir.
	cout << "Filitrelendikten sonraki point sayisi:" << pc1.pointsSize() << endl << endl;
	for (int i = 0; i < pc1.pointsSize(); i++)
	{
		cout << pc1.getpoints(i).getX() << " " << pc1.getpoints(i).getY() << " " << pc1.getpoints(i).getZ() << endl;
	}*/
	fpoint.filter(pc1);
	system("pause");
}