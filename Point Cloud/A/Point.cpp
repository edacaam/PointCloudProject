#include "Point.h"

/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Point::Point()
{
}

/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
Point::~Point()
{
}
/**
	@brief:			Bu fonksiyon x icin deger atamasi yapan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Point::setX(double X)
{
	x = X;
}
/**
	@brief:			Bu fonksiyon y icin deger atamasi yapan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void Point::setY(double Y)
{
	y = Y;
}
/**
	@brief:			Bu fonksiyon z icin deger atamasi yapan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void Point::setZ(double Z)
{
	z = Z;
}
/**
	@brief:			Bu fonksiyon x in degerini donduran fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
double Point::getX()
{
	return x;
}
/**
	@brief:			Bu fonksiyon y nin degerini donduran fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
double Point::getY()
{
	return y;
}
/**
	@brief:			Bu fonksiyon z nin degerini donduran fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
double Point::getZ()
{
	return z;
}
/**
	@brief:			Bu fonksiyon noktalarin esit olup olmadigini gosteren fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool Point::operator==(Point P)
{
	if ((x == P.x) && (y == P.y) && (z == P.z))
		return true;
	else
		return false;
}
/**
	@brief:			Bu fonksiyon iki nokta arsindaki uzakligi bulan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
double Point::distance(const Point&P)const
{
	double distance;
	distance = sqrt(pow((x - P.x), 2) + pow((y - P.y), 2) + pow((z - P.z), 2));
	return distance;
}
