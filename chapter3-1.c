#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Ex. 3-1: Modify the binary search function to only use one comparison inside the loop, and measure the difference in runtime.

int binsearch(int x, int v[], int n);
int modifiedbinsearch(int x, int v[], int n);

int main()
{
	//Initialize the sorted list
	int list[1000];
	for(int i = 0; i < 1000; i++)
		list[i] = i;
	
	//Initialize timing functions
	clock_t start, end;
	long double cputime;
	
	srand(time(NULL));
	int target = rand() % (999 - 0 + 1) + 0;
	
	printf("Calling binary search of number %d\n", target);
	start = clock();
	int t = binsearch(target, list, 1000);
	end = clock();
	cputime = ((long double) (end - start)) / CLOCKS_PER_SEC;
	printf("Found target %d at position %d in %Lf seconds with unmodified search\n", target, t, cputime);
	
	start = clock();
	t = modifiedbinsearch(target, list, 1000);
	end = clock();
	cputime = ((long double) (end - start)) / CLOCKS_PER_SEC;
	printf("Found target %d at position %d in %Lf seconds with modified search\n", target, t, cputime);
}

int binsearch(int x, int v[], int n)
{
	int low = 0;
	int high = n-1;
	int mid;
	
	while(low <= high) {
		mid = (low+high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

int modifiedbinsearch(int x, int v[], int n)
{
	int low = 0;
	int high = n-1;
	int mid = (low+high)/2;
	
	while(low <= high && v[mid] != x) {
		mid = (low+high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	
	if(v[mid] == x)
		return mid;
	else
		return -1;
}
