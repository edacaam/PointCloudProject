#include"PointCloud.h"
#include"Point.h"
#include"DepthCamera.h"
#include<iostream>
using namespace std;
int main()
{
	DepthCamera x, y;
	//PointCloud pc1=x.capture();
	x.captureFor();
	//int i = 0;
	////int size = pc1.pointsSize();
	//
	///*for (i = 0; i < size; i++)
	//{
	//	cout << pc1.getpoints(i).getX() << "	" << pc1.getpoints(i).getY() << "	" << pc1.getpoints(i).getZ() << endl;
	//}*/

	//cout << endl << endl;
	//cout << "TRANSFORM" << endl;

	//PointCloud pc2 = y.captureFor();
	//int q = 0;
	////int sizeT = pc2.pointsSize();
	//
	//for (q = 0; q < pc2.pointsSize(); q++)
	//{
	//	cout << pc2.getpoints(q).getX() << "	" << pc2.getpoints(q).getY() << "	" << pc2.getpoints(q).getZ() << endl;
	//}




	system("pause");
}