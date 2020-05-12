#include "DepthCamera.h"
/**
	@brief:			Bu fonksiyon yapici fonksiyondur.Filename olusturur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
DepthCamera::DepthCamera() :str(str)
{
	string fileName = "";
}
/**
	@brief:			Bu fonksiyon filename duzenlemeyi saglayan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
void DepthCamera::set(string fileName)
{
	this->str = fileName;
}
/**
	@brief:			Bu fonksiyon filename private olarak kullanmayi saglayan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
string DepthCamera::get()
{
	return this->str;
}
/**
	@brief:			Bu fonksiyon acilan dosyanin icindeki degerleri okuyan ve pointlerin icine atamalari yapan fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloud DepthCamera::capture()
{
	list<Point> A;

	PointCloud Pc;
	Point p;
	fstream file;
	double data;
	int counter = 0;
	string str;
	str=this->get();
	file.open(str, ios::in);
	if (!file)
	{
		cout << str << "File could not be opened.\n";
		system("pause");
		exit(0);
	}

	int i = 0;
	while (!file.eof())
	{
		file >> data;
		p.setX(data);
		file >> data;
		p.setY(data);
		file >> data;
		p.setZ(data);
		A.push_back(p);
	}
	file.close();
	Pc.setpoints(A);
	return Pc;
}
/*!
Noktalari okur.Filtreleme ve transform islemlerini yapar.
*/
/**
	@brief:			Bu fonksiyon dosyadan cekilen noktalari okur.Filtreleme ve transform islemlerini yapar.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
PointCloud DepthCamera::captureFor()
{
	Transform TRNS;
	PointCloud pc1;
	string a;
	pc1=this->capture();
	a=this->get();
	FilterPipe p1;
	PointCloud Total, YPC1, YPC2;
	PassThroughFilter pfilter;
	RadiusOutlierFilter rfilter;
	rfilter.set(25);
	p1.addFilter(&rfilter);
	p1.addFilter(&pfilter);

	if (a == "camera1.txt")
	{	
		pfilter.setX(0, 400);
		pfilter.setY(0, 400);
		pfilter.setZ(-45, 45);
		p1.filterOut(pc1);

		Eigen::Vector3d a(0.0, 0.0, (-90.0));
		TRNS.SetAngles(a);
		Eigen::Vector3d t(100.0, 500.0, 50.0);

		TRNS.SetTrans(t);
		
		TRNS.setRotation(TRNS.GetAngles());

		TRNS.setTranslation(TRNS.GetTrans());
		
	}
	if (a == "camera2.txt")
	{
		cout << endl << endl << endl;
		pfilter.setX(0, 500);
		pfilter.setY(0, 500);
		pfilter.setZ(-45, 45);

		p1.filterOut(pc1);
		Eigen::Vector3d a1(0.0, 0.0, (90.0));
		TRNS.SetAngles(a1);
		Eigen::Vector3d t1(550.0, 150.0, 50.0);
		TRNS.SetTrans(t1);

		TRNS.setRotation(TRNS.GetAngles());

		TRNS.setTranslation(TRNS.GetTrans());
	}
	pc1 = TRNS.doTransform(pc1);


	return pc1;
}
/**
	@brief:			Bu fonksiyon yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
	*/
DepthCamera::~DepthCamera()
{
}