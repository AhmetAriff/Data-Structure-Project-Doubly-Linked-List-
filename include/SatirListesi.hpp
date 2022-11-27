

#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include"SatirNode.hpp"
#include<sstream>
#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

class SatirListesi
{
private:
	
	SatirNode *head;
	int size;

	SatirNode* FindPreviousByPosition(int index);

public:

	SatirListesi();

	SatirNode* FindPosition(int index);

	void insert(int index, int item);

	void add(int item);

	int elementAt(int index);

	int count();

	void removeAt(int index);

	int calculateAverage();

	void clear();

	void printFirstLine();

	void printLine();

	void printAddress(int i);

	void printNextAddress(int i);

	void printNumber(int i);

	void spaceOut(int index);

	int generateRandomIndex();

	void printSatirListesi(SatirListesi* satirListesi,int satirListesiToDisplay);

	void printSatirListesiToDeleteNode(SatirListesi* satirListesi,int satirListesiToDisplay,int index);


	

	~SatirListesi();


};
#endif