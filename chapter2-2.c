#include <stdio.h>
#include <math.h>

//Ex. 2-3: Write a function that converts a string of hex digits into an integer value.

#define MAXLEN 8

unsigned int convert(char input[], int len);

int main()
{
	int c;
	int inputLen = 0;
	char hexinput[MAXLEN];
	
	//Get user input
	printf("Input a hex string up to 8 digits: 0x");
	for(int i=0; i<MAXLEN && (c=getchar())!='\n'; i++){
		hexinput[i] = c;
		inputLen++;
	}

	unsigned int toInt = convert(hexinput, inputLen);
	printf("Converting to decimal: %ld\n", toInt);
	
	return 0;
}

unsigned int convert(char input[], int len)
{
	unsigned int x = 0;
	int digit = 0;
	for(int i=len-1; i>=0; i--){
		if(input[i] > '9'){
			input[i] = input[i] - 87;
		}else
			input[i] = input[i] - '0';
		
		x = x + (input[i] * pow(16, digit));
		digit++;
	}
	
	return x;
}
