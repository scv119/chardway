#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <errno.h>
#include <string.h>

void die(const char* message)
{
    if(errno) {
        perror(message);
    } else {
        printf("ERROR %s.\n", message);
    }
    
    exit(1);
}

typedef int (*compare_cb)(int a, int b);

int *bubble_sort(int *numbers, int size, compare_cb cmp)
{
    int tmp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(size * sizeof(int));

    if(!target)
        die("Memory Error");

    memcpy(target, numbers, size* sizeof(int));

    for(i = 0; i < size ; i ++) {
        for(j = i ; j < size - 1; j ++) {
            if(cmp(target[j], target[j+1]) > 0) {
                tmp = target[i];
                target[i] = target[j];
                target[j] = tmp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b) { return a - b; }
int reverse_order(int a, int b) { return b - a; }

void test_sorting(int *number, int count, compare_cb cmp) {
    int i = 0;
    int *sorted = bubble_sort(number, count, cmp);
    
    if(!sorted) die("Failed to sort as requested");

    for(i = 0 ; i < count; i++) {
        printf("%d ",sorted[i]);
    }
    printf("\n");

    free(sorted);
}

int main(int argc, char* argv[]) {
   if(argc < 2) die ("USAGE: ex18 4 3 1 5 6"); 
   int count = argc - 1;

   int *numbers = malloc(count * sizeof(int));

   if(!numbers) die("Memory Error");

   int i = 0;
   for(i = 0; i < count; i ++) {
        numbers[i] = atoi(argv[i+1]);
   }

   test_sorting(numbers, count, sorted_order);
   test_sorting(numbers, count, reverse_order);

   free(numbers);

   return 0;
}
