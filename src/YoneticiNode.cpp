

#include"YoneticiNode.hpp"

using namespace std;

YoneticiNode::YoneticiNode(SatirListesi *data,  YoneticiNode* next , YoneticiNode* prev ) {


	this->data = data;
	this->next = next;
	this->prev = prev;
	this->average=calculateAverage();
	

};

double YoneticiNode::calculateAverage(){

	double total=0;

	int length = this->data->count();

	for(int i=0;i<length;i++){

		total+=this->data->elementAt(i);
	}

	return total/length;

}