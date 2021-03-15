#include <stdio.h>
#include <assert.h>

int my_strlen(char *a){
    assert(a != NULL);
    int len ;
    while(*a++ != '\0'){
        ++len;
    }
    return len;   
}

char* my_strcpy(char *a, const char *b){
    assert(a != NULL && b != NULL);
    char *c = a;
    while((*a = *b) != '\0'){
        ++a;
        ++b;
    }
    return c;
}

char* my_strncpy(char *a, const char *b, int n){
    assert(a != NULL && b != NULL);
    char *c = a;
    while(n > 0){
        *a = *b;
        ++a;
        ++b;
        --n;
    }
    *a = '\0';
    return c;
}

char* my_strcat(char *a, const char *b){
    assert(a != NULL && b != NULL);
    char *c = a;
    while(*a != '\0'){
        ++a;
    }
    while((*a = *b) != '\0'){
        ++a;
        ++b;
    }
    return c;
}

char* my_strncat(char *a, const char *b, int n){
    assert(a != NULL && b != NULL);
    char *c = a;
    while(*a != '\0'){
        ++a;
    }
    while(n>0){
        *a = *b;
        ++a;
        ++b;
        --n;
    }
    *a = '\0';
    return c;
}

int my_strcmp(const char *a, const char *b){
    assert(a != NULL && b != NULL);
    while(*a != '\0' && *b != '\0' && *a == *b){
        ++a;
        ++b;
    }
    return *a-*b;
}

int my_strncmp(const char *a, const char *b, int n){
    assert(a != NULL && b != NULL);
    while(*a != '\0' && *b != '\0' && n>1 && *a == *b){
        ++a;
        ++b;
        --n;
    }
    return *a-*b;
}

int main(){
    char a[20] = "hello";
    char b[20] = " world!";
    int len ;
    len = my_strlen(a);
    printf("len: %d\n",len);
    char c[10];
    my_strcpy(c, a);
    printf("c: %s\n",c);
    my_strncpy(c, a, 2);
    printf("c: %s\n",c);
    my_strcat(a, b);
    printf("a cat b: %s\n",a);
    my_strncat(a, b, 3);
    printf("a ncat b: %s\n",a);
    my_strcpy(c, "hello");
    my_strcpy(a, "hello");
    printf("c: %s a: %s\n", c, a);
    int res;
    res = my_strcmp(a, c);
    printf("a cmp c: %d\n",res);
    res = my_strncmp(a, c, 3);
    printf("a ncmp c: %d\n",res);
    return 0;
}