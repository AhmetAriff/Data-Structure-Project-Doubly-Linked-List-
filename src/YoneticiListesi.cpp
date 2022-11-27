

#include "YoneticiListesi.hpp"

YoneticiListesi::YoneticiListesi() {
	head = NULL;
	size = 0;
}

YoneticiNode* YoneticiListesi::FindPreviousByPosition(int index) {

    return this->findPosition(index -1);
}


YoneticiNode* YoneticiListesi::findPosition(int index) {
	
	YoneticiNode* tmp = head;
	int i = 0;

	for (YoneticiNode* itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
		tmp = tmp->next;
	}
	return tmp;

}

void YoneticiListesi::add(SatirListesi* data) {

	int i =0;

	if(head==NULL){
		insert(0,data);
		return;
	}
	else{
		for(YoneticiNode* itr = head;itr!=NULL;itr=itr->next,i++){

			if(data->calculateAverage() < itr->average){
				insert(i,data);
				return;
			}
		}
		insert(size,data);
	}  

}

void YoneticiListesi::insert(int index, SatirListesi *data) {

	if (index == 0) {
		head = new YoneticiNode(data, head);
		if (head->next != NULL) head->next->prev = head;
	}
	else {
		YoneticiNode* prv = FindPreviousByPosition(index);
		prv->next = new YoneticiNode(data, prv->next, prv);
		if (prv->next->next != NULL)
			prv->next->next->prev = prv->next;
	}
	size++;

}

int YoneticiListesi::count(){
	return size;
}

void YoneticiListesi::calculateAverage(int index){

	YoneticiNode* yoneticiNode=findPosition(index);
	double total=0;
	for(int i =0;i<yoneticiNode->data->count();i++){
		total+=yoneticiNode->data->elementAt(i);
	}

	yoneticiNode->average=total/yoneticiNode->data->count();

}

void YoneticiListesi::removeAt(int index){

	YoneticiNode* del;
	if(index == 0){
		del = head;
		head = head->next;
		if(head != NULL) head->prev = NULL;
	}
	else{
		YoneticiNode* prv = FindPreviousByPosition(index);
		del = prv->next;
		prv->next = del->next;
		if(del->next != NULL)
			del->next->prev = prv;
	}
	size--;
	delete del->data;//satir listesi iadesi
	delete del;
}



void YoneticiListesi::clear(){

	for(int i =0;i<count();i++){
		removeAt(0);
	}
}	


void YoneticiListesi::printLine(int i ,int j){

	for(i;i<j;i++){

		cout<<setw(9)<<"-----------  ";
	}
	cout<<endl;
}

void YoneticiListesi::printAddress(int i ,int j){

	YoneticiNode* yoneticiNode=findPosition(i);

	for(i;i<j;i++){
		cout<<" "<<setw(9)<<yoneticiNode<<"   ";
		yoneticiNode=yoneticiNode->next;
	}
	cout<<endl;

}

void YoneticiListesi::printNextAddress(int i ,int j){

	YoneticiNode* yoneticiNode=findPosition(i);

	for(i;i<j;i++){
		cout<<"|"<<setw(9)<<yoneticiNode->next<<"|  ";
		yoneticiNode=yoneticiNode->next;
	}
	cout<<endl;
	
}

void YoneticiListesi::printPrevAddress(int i ,int j){

	YoneticiNode* yoneticiNode=findPosition(i);

	for(i;i<j;i++){
		cout<<"|"<<setw(9)<<yoneticiNode->prev<<"|  ";
		yoneticiNode=yoneticiNode->next;
	}
	cout<<endl;
	
}

void YoneticiListesi::printAverage(int i ,int j){

	YoneticiNode* yoneticiNode=findPosition(i);

	for(i;i<j;i++){
		cout<<"|"<<setw(9)<<yoneticiNode->average<<"|  ";
		yoneticiNode=yoneticiNode->next;
	}
	cout<<endl;
	
}

void YoneticiListesi::printYoneticiListesi(int i,int j,YoneticiListesi* yoneticiListesi){
	if(i==0){cout<<"ilk";}
	if(i%8==0 && i!=0){
		cout<<"<--";
	}
	if (j==yoneticiListesi->count())	{
		cout<<setw(10*(j-i))<<""<<"son"<<endl;
	}
	if(j%8==0 && j!=yoneticiListesi->count()-1){
		cout<<setw(12*(j-i))<<""<<"-->"<<endl;
	}
		
	printAddress(i,j);
	printLine(i,j);
   	printPrevAddress(i,j);
	printLine(i,j);
	printAverage(i,j);
	printLine(i,j);
	printNextAddress(i,j);
	printLine(i,j);

}

YoneticiListesi::~YoneticiListesi(){
	clear();
}

