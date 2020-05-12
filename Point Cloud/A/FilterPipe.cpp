#include "FilterPipe.h"
#include"DepthCamera.h"
/**
	@brief:			Bu fonksiyon yapici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
FilterPipe::FilterPipe()
{

}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
FilterPipe::~FilterPipe()
{

}
/**
	@brief:			Bu fonksiyon nesneye filitre eklenmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void FilterPipe::addFilter(PointCloudFilter *filter)
{
	filters.push_back(filter);
}
/**
	@brief:			Bu fonksiyon nesneye eklenen filitrelerin sirasina göre nokta bulutunun filitrelenmesini saglar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void FilterPipe::filterOut(PointCloud &pc)
{
	for (int i = 0; i < filters.size(); i++) {
		filters[i]->filter(pc);
	}
}