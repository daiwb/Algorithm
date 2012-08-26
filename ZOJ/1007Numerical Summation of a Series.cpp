#include<iostream.h> 
#include<stdio.h> 
#include<math.h> 
int main() 
{ 
    double sum,a,k; 

    for(a=0.000;a<=2.000;a=a+0.001) 
    { 
        sum=0; 
        for(k=1;k<14000;k++) 
        { 
            sum=sum+(1-a)/(k*(k+1)*(k+a)); 
        } 
        sum=sum+(1-a)/(2*14000*14000)+1; 
        printf("%5.3f %16.12f\n", a, sum ); 
    } 

    return 0; 
}