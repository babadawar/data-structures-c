#include<stdio.h>
#include<string.h>

struct book{
    char title[100], auther[100], publisher[100];
    int price, pages;
    struct book *next;
};

int main(){
    struct book b1, b2, b3, b4, b5;
    
    strcpy(b1.title, "math");
    strcpy(b1.auther, "dawar1");
    strcpy(b1.publisher, "ncert");
    b1.price = 300;
    b1.pages = 1000;
    b1.next = &b2;
    
    strcpy(b2.title, "math");
    strcpy(b2.auther, "dawar2");
    strcpy(b2.publisher, "ncert");
    b2.price = 300;
    b2.pages = 1000;
    b2.next = &b3;
    
    strcpy(b3.title, "math");
    strcpy(b3.auther, "dawar3");
    strcpy(b3.publisher, "ncert");
    b3.price = 300;
    b3.pages = 1000;
    b3.next = &b4;
    
    strcpy(b4.title, "math");
    strcpy(b4.auther, "dawar4");
    strcpy(b4.publisher, "ncert");
    b4.price = 300;
    b4.pages = 1000;
    b4.next = NULL;
    
    printf("%s\n", b1.title);
    printf("%s\n", b2.title);
    printf("%s\n", b3.title);
    
    printf("%s\n", b4.title);
    printf("%s\n", b1.next->next->auther);
    
    
    return 0;
}