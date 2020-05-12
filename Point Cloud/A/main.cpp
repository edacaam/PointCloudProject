#include<iostream>
#include<stdlib.h>
#include"PointCloudInterface.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
using namespace std;
void main(void)
{
	PointCloudInterface intf;
	DepthCamera x, y;
	PointCloudRecorder r;
	string str1 = "camera1.txt";
	string str2 = "camera2.txt";
	
	intf.setRecorder(&r);
	x.set(str1);
	y.set(str2);
	intf.addGenerator(&x);
	intf.addGenerator(&y);
	intf.generate();


	intf.record();

	system("pause");
}