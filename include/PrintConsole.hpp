

#ifndef PRINTCONSOLE_HPP
#define PRINTCONSOLE_HPP
#include<iostream>
#include"YoneticiListesi.hpp"
#include"SatirListesi.hpp"
using namespace std;

class PrintConsole
{

private:
    YoneticiListesi* yoneticiListesi;
    SatirListesi* satirListesi;
    int startingIndexToDisplay=0;
    int lastElementToDisplay=8;
    int satirListesiToDisplay=0;
    int part =1;
    
    
public:

    PrintConsole(YoneticiListesi *yoneticiListesi);

    void displayNextPart();

    void displayPrevPart();

    void displayCurrentPart();

    void displayNextSatirListesi();

    void displayPrevSatirListesi();

    void displayCurrentSatirListesi();

    void displayCurrentSatirListesiToDeleteNode(int index);

    void deleteNode();

    int getSatirListesiToDisplay();
    
};





#endif