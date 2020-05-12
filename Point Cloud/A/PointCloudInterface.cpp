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
	@brief:			Fonksiyonu generators �yesinde bulunan t�m nesnelerden captureFor fonksiyonu �a�r�larak nokta bulutlar� sa�lan�p patch'e atilir.
					Daha sonra her bir nokta bulutu pointCloud �yesine eklenir.
					K�saca, proje K�s�m 1 �de yapt���n� uygulamadaki a�amalar bu tek fonksiyon ile ger�ekle�tirilir
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
	@brief:			Bu fonksiyon pointCloud i�indeki noktalar� dosyaya kaydeder.
	@see main():	Fonksiyonun hangi amacla cagirildigini inceleyiniz.
*/
bool  PointCloudInterface::record()
{
	string str = "cikti.txt";
	recorder->set_file_name(str);
	recorder->save(pointCloud);
		return true;
	
}