/*
Pointers on c - ch9, ex12, ex13, ex14
encryption.c - very basic encryption scheme and functions 
	- assume key array is 27 chars long
	- ignore non-alpha, preserve case

author: nicolas miller <nicolasmiller@gmail.com>
*/

#include <stdio.h>
#include <ctype.h>


void kill_dups(char *key) {
	char *other;
	while(*key != '\0') {
		other = key + 1;
		while(*other != '\0') {
			if(*key == *other) {
				char *cpy = other + 1;
				while(*cpy != '\0') {
					*(cpy - 1) = *cpy;
					cpy++;
				}
				*(cpy - 1) = '\0';
				continue;
			}

			other++;
		}
		key++;	
	}
}

int contains(char *key, char ch) {
	while(*key != '\0') {
		if(*key == ch)
			return 1;
		key++;
	}
	return 0;
}

void fill_in_rest(char *key) {
	char *key_front = key;
	int i;
	while(*key != '\0')
		key++;
	char ch = 'a';
	while(ch <= 'z') {
		if(!contains(key_front, ch)) {
			*key = ch;
			*(key + 1) = '\0';
			key++;
		}
		ch++;
	}
}

int prepare_key(char *key)
{
	char *ptr = key;
	if(*key == '\0')
		return 0;

	while(*ptr != '\0') {
		if(!isalpha(*ptr))
			return 0;
		ptr++;
	}
	ptr = key;
	while(*ptr != '\0') {
		*ptr = tolower(*ptr);	
		ptr++;
	}
	kill_dups(key);
	fill_in_rest(key);
	return 1;	
}

void encrypt(char *data, char const *key)
{
	while(*data != '\0') {
		if(isalpha(*data)) {
			int upper = isupper(*data);
			if(upper)
				*data = tolower(*data);
			*data = key[*data - 'a'];
			if(upper)
				*data = toupper(*data);
		}
		data++;
	}
}

void decrypt(char *data, char const *key)
{
	while(*data != '\0') {
		if(isalpha(*data)) {
			int upper = isupper(*data);
			char const *key_ptr = key;
			if(upper)
				*data = tolower(*data);
			while(*data != *key_ptr)
				key_ptr++;
			*data = 'a' + (key_ptr - key);
			if(upper)
				*data = toupper(*data);
		}
		data++;
	}
}

int main(int argc, char* argv[])
{
	char test[27] = "abcdefg";
	char test2[27] = "aabbcdabddbbadaefbagfffaqq";
	char test3[27] = "aaabbb";
	char test4[27] = "trailblazers";
	char test4upper[27] = "TRAILBLAZERS";
	char nonalpha[27] = "123213*(*@#$&*@&$";
	char empty[27] = "";

	char toencrypt[] = "abcdefg";
	char toencrypt_upper[] = "ABCDEFG";
	char toencrypt2[] = "abcdefg@*&#@*&#*@ABCDEFG";

/*
	kill_dups(test);
	printf("%s\n", test);
	kill_dups(test2);
	printf("%s\n", test2);
	kill_dups(test3);
	printf("%s\n", test3);
	kill_dups(test4);
	printf("%s\n", test4);

	printf("%d\n", contains(test, 'a'));
	printf("%d\n", contains(test, 'b'));
	printf("%d\n", contains(test, 'c'));
	printf("%d\n", contains(test, 'd'));
	printf("%d\n", contains(test, 'e'));
	printf("%d\n", contains(test, 'z'));
	printf("%d\n", contains(test, '1'));

	fill_in_rest(test);
	printf("%s\n", test);
	fill_in_rest(test2);
	printf("%s\n", test2);
	fill_in_rest(test3);
	printf("%s\n", test3);
	fill_in_rest(test4);
	printf("%s\n", test4);
*/

	prepare_key(test);
	printf("%s\n", test);
	prepare_key(test2);
	printf("%s\n", test2);
	prepare_key(test3);
	printf("%s\n", test3);
	prepare_key(test4);
	printf("%s\n", test4);
	prepare_key(test4upper);
	printf("%s\n", test4upper);
	printf("%d\n", prepare_key(nonalpha) == 0);
	printf("%d\n", prepare_key(empty) == 0);

	encrypt(toencrypt, test4);
	printf("%s\n", toencrypt);
	encrypt(toencrypt_upper, test4);
	printf("%s\n", toencrypt_upper);
	encrypt(toencrypt2, test4);
	printf("%s\n", toencrypt2);

	decrypt(toencrypt, test4);
	printf("%s\n", toencrypt);
	decrypt(toencrypt_upper, test4);
	printf("%s\n", toencrypt_upper);
	decrypt(toencrypt2, test4);
	printf("%s\n", toencrypt2);
	return 1;
}
