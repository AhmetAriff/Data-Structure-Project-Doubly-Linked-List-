

#include"SatirNode.hpp"

using namespace std;

SatirNode::SatirNode(int data, SatirNode* next , SatirNode* prev ) {


	this->data = data;
	this->next = next;
	this->prev = prev;

};