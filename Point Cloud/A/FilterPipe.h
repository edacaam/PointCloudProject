/**
	@author:		Eda CAM --> e-mail: caam.edaa@gmail.com
	@date:			3 January 2020
	@brief:			Bu kod parcacigi derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
#pragma once
#include<vector>
#include"PointCloudFilter.h"
class FilterPipe
{
private:
	vector<PointCloudFilter*> filters;//Eklenen filitreler vektorde tutulur.
public:
	FilterPipe();
	~FilterPipe();
	void addFilter(PointCloudFilter*);
	void filterOut(PointCloud&);
};

