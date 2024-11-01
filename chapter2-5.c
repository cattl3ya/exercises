#include <stdio.h>
#include <string.h>

// Ex. 2-10: Rewrite lower(s1) to use a conditional expression instead of
// if-else
void lower(char s1[]);

int main() {

  int i = 0;
  char input;
  char s1[100];

  while ((input = getchar()) != '\n') {
    s1[i] = input;
    i++;
  }

  lower(s1);
  printf("%s\n", s1);

  return 0;
}

void lower(char s1[]) {
  int p = 0;

  while (p < strlen(s1))
    (s1[p] >= 'A' && s1[p] <= 'Z') ? s1[p] += 32 : p++;

  return;
}
