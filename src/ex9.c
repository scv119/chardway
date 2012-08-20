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


    printf("The size of an int: %ld \n", sizeof(int));

    printf("The size of areas (int[]): %ld\n",
            sizeof(areas));

    printf("The numbe of ints in areas: %ld\n",
            sizeof(areas)/sizeof(int));

    printf("The size of name (char[]): %ld\n",
            sizeof(names));

    printf("The number of chars: %ld\n",
            sizeof(names)/sizeof(char));

    return 0;
}
