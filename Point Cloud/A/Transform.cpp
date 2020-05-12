#include"Transform.h"
#include <iomanip>
/**
	@brief:			Bu fonksiyon kurucu fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Transform::Transform()
{

}
/**
	@brief:			Bu fonksiyon ile aci degerleri alinir.
	@param:			Parametre olarak vector3d ang degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::SetAngles(Eigen::Vector3d ang)
{
	angles = ang;
}
/**
	@brief:			Bu fonksiyon ile taban koordinat sistemi noktalari alinir.
	@param:			Parametre olarak vector3d tr degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::SetTrans(Eigen::Vector3d tr)
{
	trans = tr;
}
/**
	@brief:			Bu fonksiyon angles degerlerini dondurur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Eigen::Vector3d Transform::GetAngles()
{
	return angles;
}
/**
	@brief:			Bu fonksiyon trans degerlerini dondurur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Eigen::Vector3d Transform::GetTrans()
{

	return trans;
}
/**
	@brief:			Bu fonksiyon ile rotation matrixi olusturulur.
	@param:			Parametre olarak vector3d ang degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::setRotation(Eigen::Vector3d ang)
{
	transMatrix(0, 0) = cos(ang[2])*cos(ang[1]);
	transMatrix(0, 1) = cos(ang[2])*sin(ang[1])*sin(ang[0]) - sin(ang[2]) * cos(ang[0]);
	transMatrix(0, 2) = cos(ang[2])*sin(ang[1])*cos(ang[0]) + sin(ang[2]) * sin(ang[0]);
	transMatrix(1, 0) = sin(ang[2])*cos(ang[1]);
	transMatrix(1, 1) = sin(ang[2])*sin(ang[1])*sin(ang[0]) + cos(ang[2]) * cos(ang[0]);
	transMatrix(1, 2) = sin(ang[2])*sin(ang[1])*cos(ang[0]) - cos(ang[2]) * sin(ang[0]);
	transMatrix(2, 0) = -sin(ang[1]);
	transMatrix(2, 1) = cos(ang[1])*sin(ang[0]);
	transMatrix(2, 2) = cos(ang[1])*cos(ang[0]);
}
/**
	@brief:			Bu fonksiyon ile rotation matrix testi olusturulur.
	@param:			Parametre olarak matrix4d trmtx degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::SetRot_Test(Eigen::Matrix4d trmtx)
{
	transMatrix = trmtx;
}
/**
	@brief:			Bu fonksiyon ile rotation matrix testi dondurulur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Eigen::Matrix4d Transform::GetRot_Test()
{
	return transMatrix;
}
/**
	@brief:			Bu fonksiyon ile transform matrix testi olusturulur.
	@param:			Parametre olarak matrix4d trx degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::SetTra_Test(Eigen::Matrix4d trx)
{
	transMatrix = trx;
}
/**
	@brief:			Bu fonksiyon ile transform matrix testi dondurulur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Eigen::Matrix4d Transform::GetTra_Test()
{
	return transMatrix;
}
/**
	@brief:			Bu fonksiyon ile translation vector3d matrixi olusturulur.
	@param:			Parametre olarak vector3d tr degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Transform::setTranslation(Eigen::Vector3d tr)
{

	transMatrix(0, 3) = tr[0];
	transMatrix(1, 3) = tr[1];
	transMatrix(2, 3) = tr[2];
	transMatrix(3, 0) = 0;
	transMatrix(3, 1) = 0;
	transMatrix(3, 2) = 0;
	transMatrix(3, 3) = 1;

}
/**
	@brief:			Bu fonksiyon ile alinan bir adet point icin transform donusumu yapilir.
	@param:			Parametre olarak Point p degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Point Transform::doTransform(Point p)
{
	Point Transpoint;
	double sum = 0;
	double result_point[4][1], new_point[4][1];
	new_point[0][0] = p.getX();
	new_point[1][0] = p.getY();
	new_point[2][0] = p.getZ();
	new_point[3][0] = 1;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 4; k++) {
				sum += (transMatrix(i, k) * new_point[k][j]);
			}
			result_point[i][j] = sum;
			sum = 0;
		}
	}

	Transpoint.setX(result_point[0][0]);
	Transpoint.setY(result_point[1][0]);
	Transpoint.setZ(result_point[2][0]);

	return Transpoint;
}
/**
	@brief:			Bu fonksiyon ile alinan point icin transform donusumu yapilir. List dondurur.
	@param:			Parametre olarak list<Point>lp degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
list<Point> Transform::doTransform(list<Point>lp)
{
	/*list<Point> transformedList;
	list<Point>::iterator iter;
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		transformedList.push_back(doTransform(*iter));
	}
	return transformedList;*/
	list<Point> transformedpoint;
	list<Point>::iterator iter;
	Point temp;
	Eigen::Vector4d pointb, pointa, tempMatrix;
	//iter = lp.begin();

	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		pointb(0) = iter->getX();
		pointb(1) = iter->getY();
		pointb(2) = iter->getZ();
		pointb(3) = 1;
		tempMatrix = transMatrix * pointb;
		temp.setX(tempMatrix(0));
		temp.setY(tempMatrix(1));
		temp.setZ(tempMatrix(2));

		transformedpoint.push_back(temp);
	}

	return transformedpoint;
}
/**
	@brief:			Bu fonksiyon ile alinan Pointcloud icin transform donusumu yapilir. Pointcloud dondurur.
	@param:			Parametre olarak Pointcloud pc degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloud Transform::doTransform(PointCloud pc)
{
	PointCloud Transpointcloud;
	list<Point>P;
	P = pc.getpoints();
	Transpointcloud.setpoints(doTransform(P));
	

	return Transpointcloud;
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Transform::~Transform()
{

}