#include "PassThroughFilter.h"
#include<list>
using namespace std;
/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PassThroughFilter::PassThroughFilter()
{

}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PassThroughFilter::~PassThroughFilter()
{

}
/**
	@brief:			Bu fonksiyon x icin deger atamalarini yapan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PassThroughFilter::setX(double _lowerLimitX, double _upperLimitX)
{
	this->lowerLimitX = _lowerLimitX;
	this->upperLimitX = _upperLimitX;
}
/**
	@brief:			Bu fonksiyon y icin deger atamalarini yapan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PassThroughFilter::setY(double _lowerLimitY, double _upperLimitY)
{
	this->lowerLimitY = _lowerLimitY;
	this->upperLimitY = _upperLimitY;
}
/**
	@brief:			Bu fonksiyon z icin deger atamalarini yapan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PassThroughFilter::setZ(double _lowerLimitZ, double _upperLimitZ)
{
	this->lowerLimitZ = _lowerLimitZ;
	this->upperLimitZ = _upperLimitZ;
}
/**
	@brief:			Bu fonksiyon xin max degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getXupper()
{
	return this->upperLimitX;
}
/**
	@brief:			Bu fonksiyon xin min degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getXlower()
{
	return this->lowerLimitX;
}
/**
	@brief:			Bu fonksiyon ynin max degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getYupper()
{
	return this->upperLimitY;
}
/**
	@brief:			Bu fonksiyon ynin min degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getYlower()
{
	return this->lowerLimitY;
}
/**
	@brief:			Bu fonksiyon znin max degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getZupper()
{
	return this->upperLimitZ;
}
/**
	@brief:			Bu fonksiyon znin min degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double PassThroughFilter::getZlower()
{
	return this->lowerLimitZ;

}
/**
	@brief:			Bu fonksiyon nokta bulutunu filtrelemeye yarayan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PassThroughFilter::filter(PointCloud& obj)
{
	list<Point> str1, str2;
	list<Point>::iterator iter;
	str1 = obj.getpoints();
	PointCloud obj2;

	for (iter = str1.begin(); iter != str1.end(); iter++)
	{

		if (((*iter).getX() <= getXupper() && (*iter).getX() >= getXlower()) &&
			(((*iter).getY() <= getYupper() && (*iter).getY() >= getYlower())) &&
			((*iter).getZ() <= getZupper() && (*iter).getZ() >= getZlower()))
		{
			str2.push_back(*iter);//Filitrelenen noktalar str2 listesinde tutulmustur.
		}
	}
	obj.setpoints(str2);//Filitrelenen noktalari iceren nokta bulutu dondurulmustur.
}