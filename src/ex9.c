#include <stdio.h>

int main(int argc, char  * argv[])
{
    int areas[] = {10, 12, 13, 14, 20};
    char names[] = "Zed";
    char full_name[] = {
        'Z', 'e', 'd', 
        ' ' , 'A' , '.', ' ', 
        'S', 'h', 'a', 'w', '\0'
    };

    int int_array[2][3] = {1,2,3,4,5,6};
    int int_array1[][2]  = {1,2,3,4};

    printf("The size of an int: %ld \n", sizeof(int));

    printf("The size of areas (int[]): %ld\n",
            sizeof(areas));

    printf("The numbe of ints in areas: %ld\n",
            sizeof(areas)/sizeof(int));

    printf("The size of name (char[]): %ld\n",
            sizeof(names));

    printf("The number of chars: %ld\n",
            sizeof(names)/sizeof(char));

    printf("The size of char_arrays(char *[]): %ld\n",
            sizeof(int_array));

    return 0;
}
