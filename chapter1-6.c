//Ex. 1-14: Write a program to print a histogram of the frequencies of different characters in its input

#include <stdio.h>

main(){
	int c;
	int ccount[26]; //counting only a-z characters, case insensitive
	
	for(int i=0; i<26; i++)
		ccount[i] = 0;
	
	while((c=getchar()) != EOF){
		//count characters
		if(c >= 'A' && c <= 'Z')
			ccount[c - 'A']++;
		if(c >= 'a' && c <= 'z')
			ccount[c - 'a']++;
	}
		
	//print horizontal histogram
	for(int i=0; i<26; i++){
		putchar(i+'A');
		printf("(%2d) |", ccount[i]);
		
		for(int j=0; j<ccount[i]; j++)
			printf("#");
		printf("\n");
	}
}
