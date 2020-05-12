/**
* @file		PointCloud.h
* @Author	Aleyna Isikdaglilar (aleynaisikdaglilar@gmail.com)     Eda CAM --> e-mail: caam.edaa@gmail.com     Elif Esra Eker (ekerelifesra@gmail.com)
* @date		3 January 2020
* @brief	Bu classta derinlik kamerasi fonksiyonlarini gerceklemeye yarar.
*/
#pragma once
#include"Transform.h"
#include"PointCloud.h"
#include"FilterPipe.h"
class PointCloudGenerator //Bu sýnýf abstract sýnýftýr.
{
	Transform transform;
	FilterPipe* filterPipe;
public:
	
	PointCloudGenerator();
	virtual PointCloud capture() = 0;//Bu fonksiyon pure virtual fonksiyondur.
	virtual PointCloud captureFor() = 0;//Bu fonksiyon pure virtual fonksiyondur.
	void setFilterPipe(FilterPipe*);
	~PointCloudGenerator();
};

