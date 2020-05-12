/**
* @file		PointCloudRecorder.h
* @Author	Elif Esra Eker (ekerelifesra@gmail.com)
* @date		13 December 2019
* @brief	Bu classta ismi girilen dosyaya islem gormus numaralar  yazilir.
*/

#pragma once
#include<string>
#include<iostream>
#include"PointCloud.h"
using namespace std;
class PointCloudRecorder
{
	string fileName;
public:

	PointCloudRecorder(); //! A constructor. 
	void set_file_name(string);
	string get_file_name();
	bool save(PointCloud&);
	~PointCloudRecorder();
};

