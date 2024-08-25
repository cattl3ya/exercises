#include <stdio.h>

main(){
	printf("Ex. 1-9 and 1-10: Write a program to copy input to ouput, replacing each string of blanks with a single blank. Replace tab, backspace, and backslash with the escape sequence.\n");
	int e = 0;
	int f;
	while ( (f = getchar()) != EOF){
    //ex 1-9, use e to determine if f contains the first space that's been typed
		if (f == ' ' && e == 1)
			f = 0;
		else if (f == ' ' && e == 0)
			e = 1;
		else if (f != ' ')
			e = 0;

    //ex 1-10, replace the single character constant with two character constants
		if (f == '\t'){
			putchar('\\');
			putchar('t');
			continue;
		}else if (f == '\b'){
			putchar('\\');
			putchar('b');
			continue;
		}else if (f == '\\'){
			putchar('\\');
			putchar('\\');
			continue;
		}

		putchar(f);
	}
}
