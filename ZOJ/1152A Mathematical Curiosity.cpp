#include <iostream> 
using namespace std; 

int main(void) 
{ 
   int n,m,d,i,count,a,b,num; 
   cin>>d; 
   for(i=0;i<d;i++){ 
      if (i) cout<<endl; 
      num=1; 
      while(cin>>n>>m&&!(n==0&&m==0)){ 
         count=0; 
         for(a=1;a<n-1;a++) 
            for(b=a+1;b<n;b++) 
               if((a*a+b*b+m)%(a*b)==0) count++; 
      cout<<"Case "<<num++<<": "<<count<<endl; 
      } 
   } 
   return 0; 
}