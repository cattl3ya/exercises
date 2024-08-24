#include <stdio.h>

main(){
	printf("Ex. 1-1 and 1-2: Hello world and testing\nescape \"sequences\" \n");
	
	printf("Ex. 1-3 and 1-4: Modify the temperature conversion program to print a heading and print a C to F conversion\n");
	printf("Fahrenheit\tCelsius\n");
	
	float f, c;
	int lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	
	c = lower;
	while (c <= upper) {
		f = (c/(5.0/9.0)) + 32.0;
		
		printf("%6.1f\t\t%6.1f\n", f, c);
		c = c + step;
	}
	
	printf("Ex. 1-5: Print the table in reverse order using a for loop\n");
	int f2;
	for (f2 = 300; f2 >= 0; f2 = f2 - 20)
		printf("%3d\t%6.1f\n", f2, (5.0/9.0)*(f2-32));
}
