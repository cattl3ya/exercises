//Ex. 1-15: Rewrite the temperature conversion program of section 1.2 to use a function for the conversion
#include <stdio.h>

float convert(float c);

main(){
	printf("Fahrenheit\tCelsius\n");
	
	float f, c;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	c = lower;
	while (c <= upper) {
		f = convert(c);
		
		printf("%6.1f\t\t%6.1f\n", f, c);
		c = c + step;
	}
}

float convert(float c){
	float f;
	f = (c/(5.0/9.0)) + 32.0;
	return f;
}
