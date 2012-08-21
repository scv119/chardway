#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

struct Person {
    char* name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(const char* name, int age, int height, int weight) {
    struct Person *ret = malloc(sizeof(struct Person));
    assert(ret != NULL);

    ret->name = strdup(name);
    ret->age = age;
    ret->height = height;
    ret->weight = weight;

    return ret;
}

void Person_destroy(struct Person* person) {
    assert(person != NULL);
    assert(person->name != NULL);

    free(person->name);
    free(person);
}


void Person_print(struct Person* person) {
    assert(person != NULL);
    assert(person->name != NULL);

    printf("name %s\n", person->name);
    printf("age %d\n", person->age);
    printf("height %d\n", person->height);
    printf("weight %d\n", person->weight);
}

int main(int argc, char *argv[])
{
    struct Person *me = Person_create("shenchen", 23, 178, 88);
    Person_print(me);
    Person_destroy(me);
    return 0;
}
