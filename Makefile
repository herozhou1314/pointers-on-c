CFLAGS=-Wall -g

all:
	gcc -o ex_ch1_1 ex_ch1_1.c
	gcc -o ex_ch1_2 ex_ch1_2.c

clean:
	rm -f ex_ch1_1
	rm -f ex_ch1_2
