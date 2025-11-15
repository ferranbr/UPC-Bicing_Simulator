OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o Estacion.o Bicicleta.o Estaciones.o Bicicletas.o 
	g++ -o program.exe program.o Estacion.o Bicicleta.o Estaciones.o Bicicletas.o $(OPCIONS)

program.o: program.cc Bicicleta.hh Estacion.hh Estaciones.hh
	g++ -c program.cc $(OPCIONS)

Estacion.o: Estacion.cc Estacion.hh Bicicleta.hh
	g++ -c Estacion.cc $(OPCIONS)

Bicicleta.o: Bicicleta.cc Bicicleta.hh
	g++ -c Bicicleta.cc $(OPCIONS)

Estaciones.o: Estaciones.cc Estaciones.hh Estacion.hh Bicicletas.hh
	g++ -c Estaciones.cc $(OPCIONS)

Bicicletas.o: Bicicletas.cc Bicicletas.hh Bicicleta.hh
	g++ -c Bicicletas.cc $(OPCIONS)

clean:
	rm -rf *.o *.exe
