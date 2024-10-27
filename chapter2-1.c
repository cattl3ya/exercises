#include <stdio.h>

//Ex. 2-2: Write a loop equivalent to the for loop without using || or &&

int main(){
	char s[10];
	int i;
	int lim = 10;
	char c;
	
	for (i=0; ((i<lim-1) >= ((c=getchar()) != '\n')) >= (c != EOF); i++){ //logical expressions evaluate to 0 or 1, so the || or && operators can be replaced with >=
		s[i] = c;
		putchar(s[i]);	
	}	
}
