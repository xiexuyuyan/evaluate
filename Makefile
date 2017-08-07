#this is make file
main.out:main.c lianbiao.o evaluate.o
	  cc main.c lianbiao.o evaluate.o -o main.out
lianbiao.o:lianbiao.c
	  cc -c lianbiao.c -o lianbiao.o
evaluate.o:evaluate.c
	  cc -c evaluate.c -o evaluate.o