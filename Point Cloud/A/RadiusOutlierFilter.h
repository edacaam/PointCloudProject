#pragma once
#include "PointCloud.h"
#include"PointCloudFilter.h"
/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			13 Aralik 2019 Persembe
	@brief:			Bu kod parcacigi derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
class RadiusOutlierFilter :public PointCloudFilter
{
	double radius;
public:
	RadiusOutlierFilter();
	void set(double);
	double get();
	void filter(PointCloud&);
	~RadiusOutlierFilter();
};

