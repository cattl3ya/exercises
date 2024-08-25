#include <stdio.h>

main(){
	printf("Ex. 1-6: Verify the expression getchar() != EOF is 0 or 1\n");
	int a = (getchar() != EOF);
	printf("%d\n",a);
	
	printf("Ex. 1-7: Print the value of EOF\n");
	printf("%d\n", EOF);
	
	printf("Ex. 1-8: Write a program to count blanks, tabs, and newlines\n");
	int c, d;
	d = 0;
	while ( (c = getchar()) != EOF){
		if (c == ' ' || c == '\t' || c == '\n')
			d++;
	}
	printf("\n%d blanks, tabs, or newlines typed\n", d);

}
