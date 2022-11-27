

#include"PrintConsole.hpp"
#include"YoneticiListesi.hpp"


 PrintConsole::PrintConsole(YoneticiListesi* yoneticiListesi){

	this->yoneticiListesi=yoneticiListesi;
	this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
	yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);
	satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);
       
}

void PrintConsole::displayNextPart(){

	system("CLS");
	part++;
	if(part>yoneticiListesi->count()/8+1){part=part-1;}

	satirListesiToDisplay=(part-1)*8;
	
	if(lastElementToDisplay+8<yoneticiListesi->count())
	{
		startingIndexToDisplay=(part-1)*8;
		lastElementToDisplay=part*8;
		yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);
		this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
		satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);
		
	}
	else
	{
		startingIndexToDisplay=(part-1)*8;
		lastElementToDisplay=yoneticiListesi->count();
		yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);
		this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
		satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);
		
	}

}

void PrintConsole::displayPrevPart(){

	system("CLS");

	part--;
	if(part==0){part=1;}

	if((satirListesiToDisplay+1)%8!=0){
		//	8*x inci elemandan 8*x-1. elemana geçereken
		satirListesiToDisplay=(part-1)*8;
		startingIndexToDisplay=(part-1)*8;
		lastElementToDisplay=part*8;
		yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);
		this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
		satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);	
	}

	else{
		startingIndexToDisplay=(part-1)*8;
		lastElementToDisplay=part*8;
		yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);

	}


}

void PrintConsole::displayCurrentPart(){

	system("CLS");

	yoneticiListesi->printYoneticiListesi(startingIndexToDisplay,lastElementToDisplay,yoneticiListesi);
}

void PrintConsole::displayNextSatirListesi(){

	satirListesiToDisplay+=1;
	if(satirListesiToDisplay==yoneticiListesi->count()){satirListesiToDisplay=yoneticiListesi->count()-1;}

	if(satirListesiToDisplay/8+1>part){
	
		displayNextPart();
	}
	else{displayCurrentPart();}

	if(satirListesiToDisplay%8!=0){
		//ilk elemenı iki kez yazmamak için
		this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
		satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);
	}
		
	
}

void PrintConsole::displayPrevSatirListesi(){

	satirListesiToDisplay-=1;
	if(satirListesiToDisplay==-1){satirListesiToDisplay=0;}
	
	if(satirListesiToDisplay/8+1<part){
	
		displayPrevPart();
	}
	else{displayCurrentPart();}
	
	this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
	satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);

}

void PrintConsole::displayCurrentSatirListesi(){

	this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
	satirListesi->printSatirListesi(satirListesi,satirListesiToDisplay);
}

void PrintConsole::displayCurrentSatirListesiToDeleteNode(int index){
	this->satirListesi=(yoneticiListesi->findPosition(satirListesiToDisplay))->data;
	satirListesi->printSatirListesiToDeleteNode(satirListesi,satirListesiToDisplay,index);

}

void PrintConsole::deleteNode(){
	startingIndexToDisplay--;
	lastElementToDisplay--;
	yoneticiListesi->removeAt(getSatirListesiToDisplay());
	system("CLS");
	displayCurrentPart();
	displayCurrentSatirListesi();
	
}


int PrintConsole::getSatirListesiToDisplay(){
	return satirListesiToDisplay;
}













       

