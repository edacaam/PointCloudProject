#include "RadiusOutlierFilter.h"
/**
	@brief:			Bu fonksiyon yapici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
RadiusOutlierFilter::RadiusOutlierFilter()
{

}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
RadiusOutlierFilter::~RadiusOutlierFilter()
{

}
/**
	@brief:			Bu fonksiyon radius deger atamasini yapan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void RadiusOutlierFilter::set(double _radius)
{
	radius = _radius;
}
/**
	@brief:			Bu fonksiyon radius degerini donduren fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
double RadiusOutlierFilter::get()
{
	return this->radius;
}
/**
	@brief:			Bu fonksiyon nokta bulutunu filtrelemeye yarayan fonksiyondur..
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void RadiusOutlierFilter::filter(PointCloud& obj)
{
	list<Point> str1, str2;
	list<Point>::iterator iter1, iter2;
	Point st;
	str1 = obj.getpoints();
	int i = 0, j = 0;
	for (iter1 = str1.begin(); iter1 != str1.end(); iter1++)
	{
		for (iter2 = str1.begin(); iter2 != str1.end(); iter2++)
		{
			if ((*iter1).distance(*iter2) < get() && iter1 != iter2)
			{
				str2.push_back(*iter1);//Filitrelenen noktalar T listesinde tutulmustur.
				break;
			}
		}
	}
	obj.setpoints(str2);//Filitrelenen noktalari iceren nokta bulutu dondurulmustur.

}
