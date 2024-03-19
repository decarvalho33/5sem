#include <stdlib.h>
#include <stdio.h>

int main(){
    char buffer;
    scanf("%c", &buffer);

    if (buffer == '+'){
        printf("essa é a %c", buffer);
    }
    return 0;
}