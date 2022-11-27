

#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include"YoneticiNode.hpp"
#include<iostream>
#include<iomanip>
#include <time.h>
using namespace std;

class YoneticiListesi
{
private:

	YoneticiNode* head;
	int size;

	YoneticiNode* FindPreviousByPosition(int index);

public:

	YoneticiListesi();
	
	void insert(int index, SatirListesi *data);

	void add(SatirListesi *data);

	int count();

	void removeAt(int index);

	void clear();

	void printLine(int i ,int j);

	void printAddress(int i ,int j);

	void printNextAddress(int i ,int j);

	void printPrevAddress(int i ,int j);

	void printAverage(int i ,int j);

	void printYoneticiListesi(int i,int j,YoneticiListesi* yoneticiListesi);

	void calculateAverage(int index);

	YoneticiNode* findPosition(int index);

	~YoneticiListesi();

};
	
#endif
