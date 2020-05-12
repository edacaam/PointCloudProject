#pragma once
#include"PointCloud.h"
#include"PointCloudFilter.h"
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			3 January 2020
	@brief:			Bu kod parcacigi derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
class PassThroughFilter :public PointCloudFilter
{
	double upperLimitX;
	double lowerLimitX;
	double upperLimitY;
	double lowerLimitY;
	double upperLimitZ;
	double lowerLimitZ;
public:
	PassThroughFilter();
	~PassThroughFilter();
	void setX(double, double);
	void setY(double, double);
	void setZ(double, double);
	double getXupper();
	double getXlower();
	double getYupper();
	double getYlower();
	double getZupper();
	double getZlower();
	void filter(PointCloud&);
};

