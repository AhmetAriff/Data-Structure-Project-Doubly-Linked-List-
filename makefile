
All :Compile Run

Compile:
	g++ -I ./include/ -o ./lib/SatirListesi.o -c ./src/SatirListesi.cpp 
	g++ -I ./include/ -o ./lib/YoneticiListesi.o -c ./src/YoneticiListesi.cpp 
	g++ -I ./include/ -o ./lib/SatirNode.o -c ./src/SatirNode.cpp 
	g++ -I ./include/ -o ./lib/YoneticiNode.o -c ./src/YoneticiNode.cpp
	g++ -I ./include/ -o ./lib/File.o -c ./src/File.cpp
	g++ -I ./include/ -o ./lib/PrintConsole.o -c ./src/PrintConsole.cpp 
	g++ -I ./include/ -o ./bin/Test ./lib/SatirListesi.o ./lib/YoneticiListesi.o ./lib/SatirNode.o ./lib/YoneticiNode.o ./lib/File.o ./lib/PrintConsole.o ./src/Test.cpp

Run:
	./bin/Test