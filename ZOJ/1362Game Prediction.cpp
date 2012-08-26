//ZJU 1362 Game Prediction
//2003.08.03 BY ADAI

#include <iostream>
#include <cstdio>

using namespace std;

int main(void){
    int n,m,kase=0,i,j,t,s,next,win;
    char ch[2];
    while(1){
        if(kase++) gets(ch);
        cin>>m>>n;
        if(n==0&&m==0) break;
        int* card=new int[n*m+1];
        for(i=1;i<=n*m;i++) card[i]=0;
        int* a=new int[n];
        for(i=0;i<n;i++){
            cin>>a[i];
            card[a[i]]=2;
        }
        for(i=1;i<n;i++){
            next=a[i];
		    for(j=i-1;j>=0&&next<a[j];j--)
            a[j+1]=a[j];
		    a[j+1]=next;
	    }
	    i=1;
	    j=n*m;
	    win=0;
	    for(t=n-1;t>=0;t--){
	        card[a[t]]=1;
            if(j==a[t]){
                win++;
	            for(s=0;s<m-1;s++){
                    while(card[i]!=0) i++;
	                card[i]=1;
                }
                j--;
                while(card[j]==1) j--;
            }
            else{
                card[j]=1;
                for(s=0;s<m-2;s++){
                    while(card[i]!=0) i++;
                    card[i]=1;
                }
                j--;
                while(card[j]==1) j--;
            }
        }
        cout<<"Case "<<kase<<": "<<win<<endl;
        delete []card;
        delete []a;
    }
    return 0;
}
                
	       
	    
        
        
