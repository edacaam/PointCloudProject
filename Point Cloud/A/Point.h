/**
* @file		Point.h
* @Author	Ayse Kaya (ayssekyaa@gmail.com)
* @date		3 January 2020
* @brief	Bu classta derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
#pragma once
#include<math.h>
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point();
	~Point();
	void setX(double);
	void setY(double);
	void setZ(double);
	double getX();
	double getY();
	double getZ();
	bool operator==(Point obj);
	double distance(const Point&obj)const;
};

