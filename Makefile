all: proj3.exe

main.o: main.cpp ColorImageClass.h showMainMenu.h constants.h
	g++ -std=c++98 -g -Wall -c main.cpp -o main.o

colorInRange.o: colorInRange.cpp colorInRange.h constants.h
	g++ -std=c++98 -g -Wall -c colorInRange.cpp -o colorInRange.o

ColorClass.o: ColorClass.cpp ColorClass.h constants.h colorInRange.h
	g++ -std=c++98 -g -Wall -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h constants.h
	g++ -std=c++98 -g -Wall -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h constants.h ColorClass.h RectangleClass.h chooseFill.h chooseColor.h PatternClass.h
	g++ -std=c++98 -g -Wall -c ColorImageClass.cpp -o ColorImageClass.o

RectangleClass.o: RectangleClass.cpp RectangleClass.h ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c RectangleClass.cpp -o RectangleClass.o

PatternClass.o: PatternClass.cpp PatternClass.h RowColumnClass.h ColorClass.h constants.h
	g++ -std=c++98 -g -Wall -c PatternClass.cpp -o PatternClass.o

showMainMenu.o: showMainMenu.cpp showMainMenu.h constants.h
	g++ -std=c++98 -g -Wall -c showMainMenu.cpp -o showMainMenu.o

chooseColor.o: chooseColor.cpp chooseColor.h constants.h
	g++ -std=c++98 -g -Wall -c chooseColor.cpp -o chooseColor.o

chooseFill.o: chooseFill.cpp chooseFill.h constants.h
	g++ -std=c++98 -g -Wall -c chooseFill.cpp -o chooseFill.o

proj3.exe: colorInRange.o ColorClass.o RowColumnClass.o ColorImageClass.o RectangleClass.o PatternClass.o showMainMenu.o chooseColor.o chooseFill.o main.o
	g++ -std=c++98 colorInRange.o ColorClass.o RowColumnClass.o ColorImageClass.o RectangleClass.o PatternClass.o showMainMenu.o chooseColor.o chooseFill.o main.o -o proj3.exe

clean:
	rm -f *.o *.exe

