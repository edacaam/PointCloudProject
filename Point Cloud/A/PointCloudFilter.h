/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			3 January 2020
	@brief:			Bu kod parcacigi derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
#pragma once
#include"PointCloud.h"
class PointCloudFilter
{
public:
	PointCloudFilter();
	virtual void filter(PointCloud&) = 0;
	~PointCloudFilter();
};

