#include <stdio.h>
#include <string.h>

// Ex. 2-4: Write an alternative to squeeze(s1,s2) that deletes each character
// in s1 that matches any character in the string s2

#define LEN 100
void smodify(char s1[], char s2[], int s1len, int s2len);
int any(char s1[], char s2[]);

int main() {
  char s1[LEN];
  char s2[LEN];
  char input;
  int s1len, s2len;

  printf("Input string:\n");
  for (int i = 0; i < LEN && (input = getchar()) != '\n'; i++) {
    s1[i] = input;
    s1len++;
  }

  printf("Input characters to delete from the first string:\n");
  for (int j = 0; j < LEN && (input = getchar()) != '\n'; j++) {
    s2[j] = input;
    s2len++;
  }

  printf("First position of any character from the second string in the first "
         "string: %d\n",
         any(s1, s2));

  smodify(s1, s2, s1len, s2len);
  printf("Modified string: %s \n", s1);
}

void smodify(char s1[], char s2[], int s1len, int s2len) {
  int i, j, k;
  int rem = 0;

  for (i = k = 0; i < s1len; i++) {
    for (j = 0; j < s2len; j++) {
      if (s1[i] == s2[j]) {
        rem = 1;
      }
    }
    if (rem == 1) {
      rem = 0;
    } else {
      s1[k++] = s1[i];
    }
  }

  s1[++k] = '\0';
  return;
}

// Ex. 2-5: Write a function any(s1,s2) that returns the first location in s1
// where any character from s2 occurs, or returns -1

int any(char s1[], char s2[]) {
  for (int i = 0; i < strlen(s1); i++) {
    for (int j = 0; j < strlen(s2); j++) {
      if (s1[i] == s2[j])
        return i;
    }
  }
  return -1;
}
