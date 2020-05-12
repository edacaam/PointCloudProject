/**
* @file		PointCloudInterface.h
* @Author	Aleyna Isikdaglilar (aleynaisikdaglilar@gmail.com)     Eda CAM --> e-mail: caam.edaa@gmail.com     Elif Esra Eker (ekerelifesra@gmail.com)   Ayse Kaya (ayssekyaa@gmail.com)
* @date		3 January 2020
* @brief	Bu sýnýf iþlemleri basitleþtirmek için kullanýlan bir sýnýftýr.
*/
#include"PointCloud.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include<vector>
#pragma once

class PointCloudInterface
{
	PointCloud pointCloud;
	PointCloud patch;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
public:
	PointCloudInterface();
	~PointCloudInterface();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};

