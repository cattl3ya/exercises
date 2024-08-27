//Ex. 1-13: Write a program to print a histogram of the lengths of words in its input. Displaying the histogram in a vertical orientation is more challenging.

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_OUTPUT 16
#define MAX_WLENGTH 16

main(){
	int c;
	int i = IN;
	int wlength[MAX_WLENGTH];
	int wc = 0;
	
	for (int t = 0; t < MAX_WLENGTH; t++)
		wlength[t] = 0;
	
	while ((c = getchar()) != EOF){
		
		if ( c == ' ' || c == '\n'){
			i = OUT;
			if( wc < MAX_WLENGTH )
				wlength[wc]++;
			wc = 0;
			continue;
		}else if ( i == OUT ){
			i = IN;
			wc++;
			continue;
		}
		
		wc++;
	}
	
	//display vertically for extra challenge
	//find what will be the longest line
	int maxh = 0;
	for (i = 0; i < MAX_WLENGTH; i++ )
		if (wlength[i] > maxh)
			maxh = wlength[i];
	
	//cap output to 16 rows
	if (maxh > MAX_OUTPUT)
		maxh = MAX_OUTPUT;
	
	//start at the top row and draw '#' for each column if needed
	for(int j = maxh; j > 0; j--){
		for(int k = 1; k < MAX_WLENGTH; k++){
			if(wlength[k] >= j)
				printf("  #");
			else
				printf("   ");
		}
		printf("\n");
	}
	
	//format and label the x axis
	for(int j = 1; j < MAX_WLENGTH; j++)
		printf("%3d", wlength[j]);
		
	printf("(Count)\n");
	
	for(int j = 1; j < MAX_WLENGTH; j++)
		printf("%3d", j);
	
	printf("(Length)");
}
