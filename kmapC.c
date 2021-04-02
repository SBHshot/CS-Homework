#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(void)
{
    FILE *fPtr;
    char s[50]; 
     
    fPtr = fopen("oldname.txt", "r");
    if (!fPtr) {
        printf("檔案開啟失敗...\n");
        exit(1);
    }
     
    while (fgets(s, 50, fPtr) != NULL) {
        printf(s);
    }
    printf("\n");
 
    fclose(fPtr);
     
    return 0;
}