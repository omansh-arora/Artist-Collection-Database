
CPPFLAGS = -std=c++17 -Wall -Wextra -Werror -Wfatal-errors -Wno-sign-compare -Wnon-virtual-dtor -g

fp_main_test: artist.o database.o menu.o fp_main.o 
	g++ -o fp_main_test artist.o database.o menu.o fp_main.o 

artist:
	g++ -c $(CPPFLAGS) artist.cpp

database:
	g++ -c $(CPPFLAGS) database.cpp
menu:
	g++ -c $(CPPFLAGS) menu.cpp

fp_main:
	g++ -c $(CPPFLAGS) fp_main.cpp


clean:
	rm -f artist.o database.o fp_main_test menu.o fp_main.o 
