/*
	Testing out the 1959 sort method developed by D. L. Shell


*/

#include <stdio.h>
#include <stdlib.h>

#define SIZEOFARRAY 10

//shellsort: sort v[0] ... v[n-1] into increasing order
void shellsort(int v[], int n){
	int gap, i, f, temp; // i is intermediate iterator, f is the final iterator
	
	for (gap = n/2; gap > 0; gap /= 2){
		printf("gap: %d\n", gap);
		for(i = gap; i < n; i++){
			printf("intermediate: %d\n", i);
			for(f = i - gap; f >= 0 && v[f] > v[f + gap]; f -= gap){
				printf("final: %d\n", f);
				printf("Switching %d from %d with %d from %d\n", v[f], f, v[f + gap], f + gap);
				temp = v[f];
				v[f] = v[f + gap];
				v[f + gap] = temp;
			}
		}
	}
}

int main(){
	int sortThis[SIZEOFARRAY];
	srand(time(NULL));
	
	for(int i = 0; i < SIZEOFARRAY; i++){
		sortThis[i] = rand() % (SIZEOFARRAY);
		printf("%d: %d\n", i, sortThis[i]);
	}

	shellsort(sortThis, SIZEOFARRAY);

	for (int i = 0; i < SIZEOFARRAY; i++){
		printf("%d: %d\n", i, sortThis[i]);
	}

	return 0;
}
