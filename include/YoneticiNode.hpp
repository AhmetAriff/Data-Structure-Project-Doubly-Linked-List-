

#ifndef YONETICINODE_HPP
#define YONETICINODE_HPP

#include <iostream>
#include"SatirListesi.hpp"
using namespace std;


class YoneticiNode {
public:
	
	SatirListesi *data;
	YoneticiNode *next;
	YoneticiNode *prev;
	double average;

	YoneticiNode(SatirListesi *data,  YoneticiNode *next = NULL, YoneticiNode *prev = NULL);

	double calculateAverage();


};

#endif