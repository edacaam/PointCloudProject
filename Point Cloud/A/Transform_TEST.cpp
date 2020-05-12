#include"PointCloud.h"
#include"Point.h"
#include"Transform.h"
#include<iostream>
using namespace std;
int main()
{
	Point *c = new Point[3];
	Point A, YP;
	PointCloud pc2, YPC;
	Transform d;

	A.setX(150);
	A.setY(150);
	A.setZ(-50);

	c->setX(2);
	c->setY(5);
	c->setZ(1);



	(c + 1)->setX(1000);
	(c + 1)->setY(190);
	(c + 1)->setZ(-70);


	(c + 2)->setX(100);
	(c + 2)->setY(200);
	(c + 2)->setZ(300);



	Eigen::Vector3d a(0.0, 0.0, (-90.0));
	d.SetAngles(a);

	Eigen::Vector3d t(100.0, 500.0, 50.0);
	d.SetTrans(t);

	cout << endl;
	cout << endl << "get angles" << endl << "-------" << endl << endl;

	Eigen::Vector3d a1(d.GetAngles());
	for (int i = 0; i < a1.size(); i++)
	{
		cout << a1[i] << "	";
	}

	cout << endl;
	cout << endl << "get trans" << endl << "-------" << endl << endl;

	Eigen::Vector3d t1(d.GetTrans());
	for (int i = 0; i < t1.size(); i++)
	{
		cout << t1[i] << "	";
	}
	cout << endl;


	d.setRotation(d.GetAngles());
	cout << endl << "SetRotation" << endl << "-------" << endl;
	Eigen::Matrix4d TM(d.GetRot_Test());
	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << TM(i, j) << "  ";
		}
		cout << endl;
	}

	d.setTranslation(d.GetTrans());
	cout << endl << "SetTranslation" << endl << "-------" << endl;
	Eigen::Matrix4d TMX(d.GetTra_Test());
	cout << endl;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << TMX(i, j) << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;

	YP = d.doTransform(A);
	cout << YP.getX() << endl;
	cout << YP.getY() << endl;
	cout << YP.getZ() << endl;

	cout << "--------" << endl;

	for (int i = 0; i < 3; i++) {
		pc2.setpoints(*(c + i));
	}
	for (int i = 0; i < 3; i++) {
		YPC.operator=(d.doTransform(pc2));
	}
	for (int i = 0; i < 3; i++)
	{
		cout << YPC.getpoints(i).getX() << endl;
		cout << YPC.getpoints(i).getY() << endl;
		cout << YPC.getpoints(i).getZ() << endl;
		cout << endl;
	}


	system("pause");
}