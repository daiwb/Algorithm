#include <iostream> 
using namespace std; 

int a[101][101]; 

int maxsum(int a[],int n)
{ 
    int sum=-10000000,b=0; 
    int i; 
    for(i=0;i<n;i++) 
   { 
        if (b>0) 
            b+=a[i]; 
        else 
            b=a[i]; 
        if(b>sum) 
            sum=b; 
   } 
    return sum; 
} 
int maxsum2(int m,int n)
{ 
    int sum = -10000000; 
    int i,j,k,max; 
    int* b = new int[n+1]; 
    for (i=0;i<m;i++) 
   { 
        for(k=0;k<n;k++) 
            b[k]=a[i][k]; 
        max = maxsum(b,n);
     if(max>sum) 
            sum=max; 
        for(j=i+1;j<m;j++) 
       { 
            for (k=0;k<=n;k++)b[k]+=a[j][k]; 
            max = maxsum(b,n);
            if(max>sum)sum=max; 
       } 
   } 
    delete []b; 
    return sum; 
} 
int main() 
{ 
    int n,i,j; 

    cin >> n; 
    for (i=0;i<n;i++) 
    for (j=0;j<n;j++) 
    cin >> a[i][j]; 
    cout << maxsum2(n,n) << endl; 
    return 0; 
}