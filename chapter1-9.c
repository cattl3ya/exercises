#include <stdio.h>
#define MAXLINE 1000

int getnewline(char line[], int maxline);
int trimline(char line[], int end);
void reverseline(char line[], char revline[], int end);

//Ex. 1-18: Write a program to remove trailing blanks and tabs from each line of input, and delete blank lines.
int main(){
	char line[MAXLINE];
	char revLine[MAXLINE];
	int len;
	
	while((len = getnewline(line, MAXLINE)) != 0){
		len = trimline(line, len);
		reverseline(line, revLine, len);
		printf("%s\n%s\n", line, revLine);
	}

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

int trimline(char s[], int end){
	while(s[end] == ' ' || s[end] == '\t' || s[end] == '\n' || s[end] == '\0'){ //remove trailing unwanted characters
		s[end] = '\0';
		end--;
	}
	return end; //return the new length of the string
}

//Ex. 1-19: Write a function that reverses the character string s
void reverseline(char s[], char r[], int end){
	int i = 0;
	
	for(int j = 0; j < MAXLINE; j++) //clear the reversed string buffer
		r[j] = '\0';

	while(end >= 0){
		if(s[end] != '\0' || s[end] != '\n'){
			r[i] = s[end];
			i++;
		}
		end--;
	}
}
