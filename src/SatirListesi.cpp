

#include "SatirListesi.hpp"


SatirListesi::SatirListesi() {
	head = NULL;
	size = 0;
}

SatirNode* SatirListesi::FindPreviousByPosition(int index) {
	
    return this->FindPosition(index -1);
}



SatirNode* SatirListesi::FindPosition(int index) {

		SatirNode* tmp = head;
		int i = 0;

		for (SatirNode* itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
			tmp = tmp->next;
		}
		return tmp;

}

void SatirListesi::add(int item) {
	insert(size, item);

}

void SatirListesi::insert(int index, int item) {

	if (index == 0) {
		head = new SatirNode(item, head);
		if (head->next != NULL) head->next->prev = head;
	}
	else {
		SatirNode* prv = FindPreviousByPosition(index);
		prv->next = new SatirNode(item, prv->next, prv);
		if (prv->next->next != NULL)
			prv->next->next->prev = prv->next;
	}
	size++;

}


int SatirListesi::elementAt(int index){
	if(index == 0) return head->data;
	return FindPreviousByPosition(index)->next->data;
}

void SatirListesi::removeAt(int index){

	SatirNode *del;
	if(index == 0){
		del = head;
		head = head->next;
		if(head != NULL) head->prev = NULL;
	}
	else{
		SatirNode *prv = FindPreviousByPosition(index);
		del = prv->next;
		prv->next = del->next;
		if(del->next != NULL)
			del->next->prev = prv;
	}
	size--;
	delete del;
}

int SatirListesi::calculateAverage(){

	int i =0;
	double total=0;
	double average;
	for(SatirNode* itr= head;i<count();itr=itr->next,i++){
		total+=itr->data;
	}
	average = total/ count();

	return average;
}

int SatirListesi::generateRandomIndex(){

	srand(time(NULL));
	return(rand()%count());
}

void SatirListesi::clear(){

	for(int i =0;i<count();i++){
		removeAt(0);
	}
}

int SatirListesi::count(){
	return size;
}

void SatirListesi::printFirstLine(){
 
 	cout<<setw(9)<<"^^^^^^^^^^^  "<<endl;
	 
}

void SatirListesi::printLine(){

	cout<<setw(9)<<"-----------  "<<endl;
}

void SatirListesi::printAddress(int i){

	SatirNode* satirNode = FindPosition(i);
	cout<<" "<<setw(9)<<satirNode<<"   "<<endl;

}

void SatirListesi::printNumber(int i){

	SatirNode* satirNode = FindPosition(i);
	cout<<"|"<<setw(9)<<satirNode->data<<"|  "<<endl;

}

void SatirListesi::printNextAddress(int i){

	SatirNode* satirNode = FindPosition(i);
	cout<<"|"<<setw(9)<<satirNode->next<<"|  "<<endl;


}

void SatirListesi::spaceOut(int index){

	cout<<setw(13*index)<<"";

}

void SatirListesi::printSatirListesi(SatirListesi* satirListesi,int SatirListesiToDisplay){
	
	spaceOut(SatirListesiToDisplay%8);
	printFirstLine();

	for(int i =0;i<satirListesi->count();i++){
		
		spaceOut(SatirListesiToDisplay%8);
		printAddress(i);
		spaceOut(SatirListesiToDisplay%8);
		printLine();
		spaceOut(SatirListesiToDisplay%8);
		printNumber(i);
		spaceOut(SatirListesiToDisplay%8);
		printLine();
		spaceOut(SatirListesiToDisplay%8);
		printNextAddress(i);
		spaceOut(SatirListesiToDisplay%8);
		printLine();
		cout<<endl;

	}

}

void SatirListesi::printSatirListesiToDeleteNode(SatirListesi* satirListesi,int satirListesiToDisplay,int index){

	spaceOut(satirListesiToDisplay%8);
	printFirstLine();

	for(int i =0;i<satirListesi->count();i++){
		
		spaceOut(satirListesiToDisplay%8);
		printAddress(i);
		spaceOut(satirListesiToDisplay%8);
		printLine();
		spaceOut(satirListesiToDisplay%8);
		printNumber(i);
		spaceOut(satirListesiToDisplay%8);
		cout<<setw(9)<<"-----------  ";
		if(i==index){
			cout<<"     <--- silinecek secili";
		}
		cout<<endl;
		spaceOut(satirListesiToDisplay%8);
		printNextAddress(i);
		spaceOut(satirListesiToDisplay%8);
		printLine();
		cout<<endl;

	}

}



SatirListesi::~SatirListesi(){
		clear();
}






