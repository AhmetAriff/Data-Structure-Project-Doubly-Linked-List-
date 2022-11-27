

#ifndef SATIRNODE_HPP
#define SATIRNODE_HPP

#include <iostream>
using namespace std;


class SatirNode {
public:
	int data;
	SatirNode *next;
	SatirNode *prev;

	SatirNode( int data, SatirNode *next = NULL, SatirNode *prev = NULL);

	
};

#endif