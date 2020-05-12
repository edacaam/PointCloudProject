#include "PointCloudRecorder.h"
#include"PointCloud.h"
#include"Point.h"
#include<fstream>
#include<iostream>
using namespace std;
/**
	@brief:			Bu fonksiyon yapici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloudRecorder::PointCloudRecorder()
{

}
/**
	@brief:			Bu fonksiyon icine deger yazilacak olan dosyanin ismini düzenleyen fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void PointCloudRecorder::set_file_name(string fileName)
{
	this->fileName = fileName;
}
/**
	@brief:			Bu fonksiyon private deger olan filenami donduren fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string PointCloudRecorder::get_file_name()
{
	return this->fileName;
}



/**
	@brief:			Bu fonksiyon ile fileName alýnýr ve dosya acilir.Acilan dosya icine islem gormus ve filtrelenmis numaralar yazilir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
bool PointCloudRecorder::save(PointCloud& pc)
{
	ofstream file;
	list<Point> P;
	list<Point>::iterator iter;
	P = pc.getpoints();
	file.open(this->get_file_name(), ios::out);
	for (iter = P.begin(); iter != P.end(); iter++)
		file << (*iter).getX() << " " << (*iter).getY() << " " << (*iter).getZ() << endl;
	file.close();
	return true;
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloudRecorder::~PointCloudRecorder()
{

}