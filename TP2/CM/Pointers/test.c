#include <stdio.h>
#include <stdlib.h>

void foo(void){
    printf("foo\n");
}

void foo2(int i){
    printf("foo2:%d\n", i);
}

void foo3(int i, char *s, size_t l){
    printf("foo3:%d,%s,%d\n", i,s,l);
}

int main(int argc, char const *argv[])
{
    void (*p)(void) = &(foo);
    void (*p2) (int) = &(foo2);
    void (*p3) (int, char*, size_t) = &(foo3);
    (*p)();
    (*p2)(atoi(argv[1]));
    (*p3)(atoi(argv[2]),"Nif", 7);
    return EXIT_SUCCESS;
}
