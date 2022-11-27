

#include"File.hpp"
#include<iostream>

YoneticiListesi* Dosya::readFile(){
    
	ifstream dosyaOku("veriler.txt");
	string line = "";
	string number;
	int IntNumber;

	if (dosyaOku.is_open()) {
		
		YoneticiListesi* yoneticiListesi = new YoneticiListesi();

		while (getline(dosyaOku, line)) {

			SatirListesi* satirListesi = new SatirListesi();
			
			for (int i = 0; i < line.length(); i++)
			{
				if (isspace(line[i]))
				{
					number = line.substr(i - 2, 2);
					IntNumber = stoi(number);
					satirListesi->add(IntNumber);

				}
			}

			yoneticiListesi->add(satirListesi);
			
		}
		
		dosyaOku.close();
		return yoneticiListesi;
	}
		

}
