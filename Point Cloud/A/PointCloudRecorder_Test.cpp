#include"PointCloud.h"
#include"Point.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include<iostream>
using namespace std;
int main()
{

	DepthCamera x;
	//DepthCamera y;
	PointCloud pc1 = x.capture();
	//PointCloud pc2= y.capture();
	PointCloudRecorder recorder;

	recorder.save(pc1);
	cout << endl;
	system("pause");
}