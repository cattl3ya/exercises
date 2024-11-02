#include <stdio.h>
#include <string.h>

//Ex. 3-2: Write a function escape(s,t) that converts newline and tab characters into visible escape sequences as string s is copied to t. Use a switch statement.

void escape(char s[], char t[]);
void antiescape(char s[], char t[]);

int main()
{
	char s1[] = "hello\tworld\nthis\t\tstring has tabs\nand newlines";
	char s2[100];
	
	printf("Making escape sequences visible:\n");
	escape(s1, s2);
	printf("Parsing escape sequences:\n");
	antiescape(s2, s1);
}

void escape(char s[], char t[])
{
	int i, j = 0;
	for(i = 0; i < strlen(s); i++){
		switch (s[i]){
			case '\n': 
				t[j] = '\\';
				t[++j] = 'n';
				break;
			case '\t': 
				t[j] = '\\';
				t[++j] = 't';
				break;
			default:
				t[j] = s[i];
		}
		j++;
	}

	printf("%s\n%s\n", s, t);
}

void antiescape(char s[], char t[])
{
	int i, j = 0;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == '\\'){
			switch (s[i+1]){
				case 'n': 
					t[j] = '\n';
					i++;
					break;
				case 't': 
					t[j] = '\t';
					i++;
					break;
				default:
					t[j] = s[i];
			}
		}
		j++;
	}

	printf("%s\n%s", s, t);
}
