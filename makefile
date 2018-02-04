all: busca.o ordenacao.o main.o
	@gcc busca.o ordenacao.o main.o -o executavel
busca.o: busca.c
	@gcc busca.c -c
ordenacao.o: ordenacao.c
	@gcc ordenacao.c -c
main.o: main.c
	@gcc main.c -c
clean:
	rm *.o
	rm executavel
