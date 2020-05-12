/**
 * @file   Transform.h
 * @Author Aleyna Isikdaglilar (aleynaisikdaglilar@gmail.com)  
 * @date   13 December 2019
 * @brief  Gonderilen nokta ya da nokta bulutlarýný istenilen taban koordinat sistemine donusturur.
 *
 * Detailed description of file.
*/
#pragma once
#include "PointCloud.h"
#include "Point.h"
#include <iomanip>
#include<math.h>
#include<Eigen/Dense>
#include<Eigen/Geometry>
using namespace std;
class Transform
{
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;

public:
	Transform();
	~Transform();
	void setRotation(Eigen::Vector3d);
	void setTranslation(Eigen::Vector3d);
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud pc);
	Eigen::Vector3d GetAngles();
	Eigen::Vector3d GetTrans();
	void SetAngles(Eigen::Vector3d);
	void SetTrans(Eigen::Vector3d);

	list<Point> doTransform(list<Point>);

	Eigen::Matrix4d GetRot_Test();
	void SetRot_Test(Eigen::Matrix4d);

	Eigen::Matrix4d GetTra_Test();
	void SetTra_Test(Eigen::Matrix4d);
};

