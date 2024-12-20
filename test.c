#include <stdio.h>
#include "loopBuffer.h"

char a[]    = "casdfxx";
char b[]    = "lalakaka";
int main(int argc, char* argv[]){
    char temp[100];
    int cnt;
    
    //test1: normal test
    #if 0
    x_InitLoopBuffer();
    cnt = x_loopWrite(a, 7);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 10);
    printf("read read: %d\n", cnt);
    puts(temp);
    #endif

    //test2: beyond size write
    #if 0
    x_InitLoopBuffer();
    cnt = x_loopWrite("12345678901234567890", 20);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 20);
    printf("read read: %d\n", cnt);
    puts(temp);
    #endif


    //test3: write read write read
    #if 0
    x_InitLoopBuffer();
    
    cnt = x_loopWrite(a, 7);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 20);
    printf("read read: %d\n", cnt);
    puts(temp);
    cnt = x_loopWrite(b, 8);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 20);
    printf("read read: %d\n", cnt);
    puts(temp);
    #endif

    //test4: write read write read
    #if 1
    x_InitLoopBuffer();
    
    cnt = x_loopWrite(a, 7);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 20);
    printf("read read: %d\n", cnt);
    puts(temp);

    cnt = x_loopWrite(a, 7);
    printf("read write: %d\n", cnt);

    cnt = x_loopWrite(b, 8);
    printf("read write: %d\n", cnt);
    cnt = x_loopRead(temp, 20);
    printf("read read: %d\n", cnt);
    puts(temp);
    #endif

    return 0;
}
