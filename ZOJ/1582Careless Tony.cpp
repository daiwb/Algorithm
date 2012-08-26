/*ZJU 1582 Careless Tony
2003.07.30 BY ADAI*/

#include <stdio.h>
#include <string.h>

int main (void) {
    int n,t;
    char in[100],out[100]; 
    int i; 
    scanf("%d",&n);
    while (n--){ 
        scanf("%d", &t); 
        getchar();
        gets(in); 
        gets(out); 
        for (i=0;;i++){
            if(in[i]=='\0'||out[i]=='\0'||in[i]!=out[i]) break;
        } 
        printf("%d\n",t*(strlen(out)-i+strlen(in)-i)); 
    } 
    return 0; 
} 

