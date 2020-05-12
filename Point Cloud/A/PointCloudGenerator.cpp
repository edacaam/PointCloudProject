#include "PointCloudGenerator.h"
/**
	@brief:			Bu fonksiyon yapici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloudGenerator::PointCloudGenerator()
{

}
/**
	@brief:			Bu fonksiyon filterPipe nesnesinin degerinin belirlenmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PointCloudGenerator::setFilterPipe(FilterPipe* p)
{
	this->filterPipe = p;
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloudGenerator::~PointCloudGenerator()
{

}