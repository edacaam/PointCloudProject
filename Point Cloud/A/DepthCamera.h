/**
* @file		DepthCamera.h
* @Author	Elif Esra Eker (ekerelifesra@gmail.com)
* @date		3 January 2020
* @brief	Bu classta ismi girilen dosyadan numaralar okunur ve pointte olusturulan diziye atanýr.
			Point dizisi de pointclouda atanr.Pointnumber hesaplanýr.
*/

#pragma once
#include<iostream>
#include <fstream>
#include <iomanip>
#include<string>
#include"PointCloud.h"
#include"Point.h"
#include"PointCloudGenerator.h"
#include"PassThroughFilter.h"
#include "RadiusOutlierFilter.h"
using namespace std;
class DepthCamera :public PointCloudGenerator
{
	string str;
public:
	DepthCamera();
	void set(string);
	string get();
	PointCloud capture();
	PointCloud captureFor();
	~DepthCamera();
};

