#include <stdio.h>
//Ex 1-11: The wordcount program should be tested with all possible inputs, including numbers and escape sequences.

//Ex 1-12: Write a program that prints its output one word per line.
main(){
	int c;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			putchar('\n');
		else
			putchar(c);
	}
}
