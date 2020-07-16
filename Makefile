all:
	gcc main.c -O2 -std=gnu99 -lm -lrt -ffast-math -o main 
	./main

show:
	gcc main.c -O2 -std=gnu99 -ffast-math -S -o -|grep sqrt
