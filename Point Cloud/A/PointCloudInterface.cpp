#include "PointCloudInterface.h"
/**
	@brief:			Bu kurucu fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloudInterface::PointCloudInterface()
{
}

/**
	@brief:			Bu yikici fonksiyondur.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
PointCloudInterface::~PointCloudInterface()
{
}
/**
	@brief:			Bu fonksiyon ile PointCloudGenerator tarafindan yaratilan nesneler generators'un icine atilir.
	@param:			Parametre olarak PointCloudGenerator* g degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void PointCloudInterface::addGenerator(PointCloudGenerator* g)
{
	generators.push_back(g);
}
/**
	@brief:			Bu fonksiyon PointCloudRecorder dan alinan nesne ile islem gormus noktari dosyaya kaydeder.
	@param:			Parametre olarak PointCloudRecorder* s degeri alinir.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
void PointCloudInterface::setRecorder(PointCloudRecorder* s)
{
	this->recorder = s;
}
/**
	@brief:			Fonksiyonu generators üyesinde bulunan tüm nesnelerden captureFor fonksiyonu çaðrýlarak nokta bulutlarý saðlanýp patch'e atilir.
					Daha sonra her bir nokta bulutu pointCloud üyesine eklenir.
					Kýsaca, proje Kýsým 1 ‘de yaptýðýný uygulamadaki aþamalar bu tek fonksiyon ile gerçekleþtirilir
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool  PointCloudInterface::generate()
{
	for (int i = 0; i < generators.size(); i++)
	{
		patch = generators[i]->captureFor();
		pointCloud = pointCloud + patch;
	}
	return true;
}
/**
	@brief:			Bu fonksiyon pointCloud içindeki noktalarý dosyaya kaydeder.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool  PointCloudInterface::record()
{
	string str = "cikti.txt";
	recorder->set_file_name(str);
	recorder->save(pointCloud);
		return true;
	
}