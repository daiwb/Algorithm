//zju 2085 Wishingbone's Victory

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
  int n,i,c;
  double p,t[2];
  while(cin>>n>>p){
    double* a=new double[2*n+1];
    double* b=new double[2*n+1];
    for(i=0;i<2*n+1;i++) a[i]=0;
    a[n+1]=p;
    a[n-1]=1-p;
    while(1){
      for(i=1;i<2*n;i++){
        b[i]=a[i];
        a[i]=0;
      }
	  b[0]=a[0];
	  b[2*n]=a[2*n];
      c=0;
      for(i=1;i<2*n;i++){
        t[0]=b[i]*p;
        t[1]=b[i]*(1-p);
        if(t[0]>=0.000000001) c=1;
        if(t[1]>=0.000000001) c=1;
        a[i+1]+=t[0];
        a[i-1]+=t[1];
      }
      if(c==0) break;
      //printf("%.6f\n",a[2*n]);
    }
	cout<<setiosflags(ios::fixed)<<setprecision(6)<<a[2*n]<<endl;
    delete []a;
    delete []b;
  }
  return 0;
}
