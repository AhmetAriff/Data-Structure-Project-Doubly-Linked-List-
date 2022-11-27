

#include<iostream>
#include"File.hpp"
#include"YoneticiListesi.hpp"
#include"PrintConsole.hpp"

using namespace std;

int main()
{
    system("CLS");
    Dosya* file =new Dosya();
    YoneticiListesi* yoneticiListesi=file->readFile();
    PrintConsole* printConsole=new PrintConsole(yoneticiListesi);

    string character="";
    

    do{

	cin>>character;
	if(character=="d"){
		printConsole->displayNextPart();
	}

	else if(character=="a"){;
		printConsole->displayPrevPart();
	}

	else if(character=="c"){
		printConsole->displayNextSatirListesi();
	}

	else if(character=="z"){
		printConsole->displayPrevSatirListesi();
	}

	else if(character=="k"){
		int nodeSelectedToDelete;
		SatirListesi* satirListesi=yoneticiListesi->findPosition(printConsole->getSatirListesiToDisplay())->data;
		nodeSelectedToDelete=satirListesi->generateRandomIndex();
		printConsole->displayCurrentPart();
		printConsole->displayCurrentSatirListesiToDeleteNode(nodeSelectedToDelete);
		
		cin>>character;

		if(character=="k"){
			satirListesi->removeAt(nodeSelectedToDelete);
			if(satirListesi->count()!=0){

				SatirListesi* newSatirListesi = new SatirListesi();
				int i =0;
				for(SatirNode* itr = satirListesi->FindPosition(0);i<satirListesi->count();itr=itr->next,i++)
				{
					newSatirListesi->add(itr->data);
				}
				
				yoneticiListesi->removeAt(printConsole->getSatirListesiToDisplay());
				yoneticiListesi->add(newSatirListesi);

			}
			else{yoneticiListesi->removeAt(printConsole->getSatirListesiToDisplay());}
			
			printConsole->displayCurrentPart();
			printConsole->displayCurrentSatirListesi();

		}

	}
	else if(character=="p"){

		printConsole->deleteNode();
	}
    
		
	}while(character!="q");

	delete yoneticiListesi;
	delete file;
	delete printConsole;



}


