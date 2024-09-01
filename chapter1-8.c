#include <stdio.h>
#define MAXLINE 1000

int getnewline(char line[], int maxline);
void copy(char to[], char from[]);

int main(){
	int len, max;
	char line[MAXLINE], longest[MAXLINE];
	
	max = 0;
	while ((len = getnewline(line, MAXLINE)) > 0){
		//Ex. 1-16: Revise the program to print the length of arbitrarily long input lines, and as much as possible of the text.
		if (line[len-1] != '\n'){ //if we exceeded the buffer size without a newline
			while ((getchar() != '\n'))
				len++; //increment the length until we hit the real end of the line
		}
		if (len > max){
			max = len;
			copy(longest, line);
		}
		//Ex. 1-17: Print all input lines >80 characters
		if (len > 80)
			printf("\nLine >80 characters detected: %s", longest);
	}
	if (max > 0)
		printf("Length of longest input: %d\nLongest input was: %s", max, longest);

	return 0;
}

int getnewline(char s[], int lim){
	int c, i;
	
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]){
	int i;
	
	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
