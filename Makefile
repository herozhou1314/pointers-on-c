CFLAGS=-Wall -g

all:
	gcc -o ex_ch1_1 ex_ch1_1.c
	gcc -o ex_ch1_2 ex_ch1_2.c
	gcc -o ex_ch1_3 ex_ch1_3.c
	gcc -o ex_ch1_4 ex_ch1_4.c

clean:
	rm -f ex_ch1_1
	rm -f ex_ch1_2
	rm -f ex_ch1_3
	rm -f ex_ch1_4
