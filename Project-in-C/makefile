hepsi: derle calistir

derle:

	gcc -I ./include/ -o ./lib/Taktik.o -c ./src/Taktik.c
	gcc -I ./include/ -o ./lib/Ataktik.o -c ./src/Ataktik.c
	gcc -I ./include/ -o ./lib/Btaktik.o -c ./src/Btaktik.c
	gcc -I ./include/ -o ./lib/Uretim.o -c ./src/Uretim.c
	gcc -I ./include/ -o ./lib/Auretim.o -c ./src/Auretim.c
	gcc -I ./include/ -o ./lib/Buretim.o -c ./src/Buretim.c
	gcc -I ./include/ -o ./lib/Koloni.o -c ./src/Koloni.c
	gcc -I ./include/ -o ./lib/Oyun.o -c ./src/Oyun.c

	gcc -I ./include/ -o ./bin/Test ./lib/Taktik.o ./lib/Ataktik.o ./lib/Btaktik.o ./lib/Uretim.o ./lib/Auretim.o ./lib/Buretim.o ./lib/Koloni.o ./lib/Oyun.o ./src/Test.c
	
calistir:
	./bin/Test