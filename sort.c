#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sort.h"

__attribute__ ((weak))
int compare(int a, int b) {
	    return a - b;
}

void bubble_sort(int *numbers, unsigned count) {
	int temp;
	int i, j;

	for(i = 0; i < count; i++) {
		for(j = 0; j < count - 1; j++) {
			if(compare(numbers[j+1], numbers[j]) < 0) {
				temp = numbers[j+1];
				numbers[j+1] = numbers[j];
				numbers[j] = temp;
			}
		}
	}
}

void insertion_sort(int *numbers, unsigned count) {
	int new[count];
	unsigned new_count = 0;

	while (new_count < count) {
		int num = numbers[new_count];

		unsigned idx = 0;
		while (true) {
			if (idx == new_count) {
				new[idx] = num;
				break;
			}

			if (compare(num, new[idx]) < 0) {
				unsigned i;
				for (i=new_count;i>idx;i--) {
					new[i] = new[i-1];
				}
				new[i] = num;
				break;
			}

			idx++;
		}

		new_count++;
	}

	memcpy(numbers, new, count*sizeof(int));
}



//comparison function for the Q wrapper function below
//allows the 'compare' function defined weakly above to
//interface with stdlib:qsort
int compar(const void* a, const void* b)
{
  if(compare(*(int*)a, *(int*)b) < 0) return -1; //a goes before b
  else if(compare(*(int*)a,*(int*)b) > 0) return 1; //b goes before a
  else return 0; //they are equal, order doesn't matter
}


// wraps qsort to be used by the functor 
// sorting_fn
// requires: 'count' to be the number of elements
// in the array 'numbers' to be sorted
void Q(int* numbers, unsigned count)
{
  qsort(numbers, count, sizeof(int), compar);
}


sorting_fn sorting_fns[] = {bubble_sort, insertion_sort, Q, NULL};

