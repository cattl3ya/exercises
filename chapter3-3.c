#include <stdio.h>
#include <string.h>

//Ex. 3-3: Write a function expand(s1,s2) that expands shorthand notation in s1 to a complete list in s2

void expand(char s1[], char s2[]);

int main()
{
	char s1[] = "a-z0-9f-vC-Qapples-1-5";
	char s2[1000];
	
	expand(s1,s2);
	printf("Original string: %s\nExpanded string:%s\n", s1, s2);
}

void expand(char s1[], char s2[])
{
	int j = 0;
	
	for(int i = 0; i < strlen(s1); i++){
		if(s1[i+1] == '-' && s1[i+3] != '-'){
			for(char k = s1[i]; k != s1[i+2]; k++, j++)
				s2[j] = k;
			i++;
		}else
			s2[j++] = s1[i];
	}
	s2[j] = '\0';
	return;
}
