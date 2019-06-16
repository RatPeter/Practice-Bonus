all: mainexe

clean:
	rm -f ./bin/spring.exe

mainexe:sprobj 
	gcc -o ./bin/spring.exe ./spring_g.o -lgsl -lgslcblas -lm
	rm -f ./spring_g.o

sprobj:
	gcc -c -o ./spring_g.o ./src/spring_g.c 