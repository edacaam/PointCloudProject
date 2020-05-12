#include "PointCloud.h"
/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloud::PointCloud()
{
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloud::~PointCloud()
{
}
/**
	@brief:			Bu fonksiyon listenin eleman sayisini bulur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
int PointCloud::pointsSize()
{
	return points.size();
}
/**
	@brief:			Bu fonksiyon listeyi olusturur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void PointCloud::setpoints(list<Point>p)
{
	this->points = p;
}
/**
	@brief:			Bu fonksiyon listeye ulasmamizi saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
list<Point> PointCloud::getpoints()
{
	return points;
}
/**
	@brief:			Bu fonksiyon operator overloading fonksiyonudur ve iki nesneyi toplama islemi yapar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloud PointCloud::operator+(PointCloud& A)
{
	list<Point> K1, K2, tmp;
	list<Point>::iterator iter1, iter2;
	PointCloud C;
	K1 = this->getpoints();
	K2 = A.getpoints();
	int j = 0;
	iter1 = K1.begin();
	iter2 = K2.begin();
	int a = K1.size();
	for (int i = 0; i < K1.size() + K2.size(); i++) {
		if (i < K1.size())
		{
			tmp.push_back(*iter1++);
		}
		else
		{
			tmp.push_back(*iter2++);
		}
	}
	
	C.setpoints(tmp);
	return C;
}
/**
	@brief:			Bu fonksiyon operator overloading fonksiyonudur ve bir nesneyi baþka bir nesneye kopyalar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void PointCloud::operator=(PointCloud *obj)
{
	list<Point>::iterator iter;
	for (iter = obj->points.begin(); iter != obj->points.end(); iter++)
	{
		this->points.push_back(*iter);
    }
}