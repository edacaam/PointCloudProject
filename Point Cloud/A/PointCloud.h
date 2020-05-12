/**
* @file		PointCloud.h
* @Author	Ayse Kaya (ayssekyaa@gmail.com)
* @date		3 January 2020
* @brief	Bu classta derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
#pragma once
#include"Point.h"
#include<list>
#include<iterator>
class PointCloud
{
private:
	list<Point>points;
public:
	PointCloud();
	~PointCloud();
	int pointsSize();   
	void setpoints(list<Point>p);
	//void sil();
	list<Point> getpoints();
	PointCloud operator+(PointCloud&);
	void operator=(PointCloud*);
};

