#include <iostream>
#include <cmath>

using namespace std;

int main(void){
	unsigned long t,n,s,m,num;
	double temp,a,b,c;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=45){
			temp=(sqrt(8*n+1.0)-1)/2;
			if((double)((long)temp)==temp) s=(long)temp-1;
			else s=(long)temp;
			num=n-s*(s+1)/2;
			cout<<num<<endl;
		}
		else if(n<=9045){
			n-=45;
			temp=sqrt(n+25.0)+4;
			if((double)((long)temp)==temp) s=(long)temp-1;
			else s=(long)temp;
			s=n-(s*s-8*s-9);
			if(s<=9) num=s;
			else{
				s-=9;
				m=(s+1)/2+9;
				if(s%2==0) num=m%10;
				else num=m/10%10;
			}
			cout<<num<<endl;
		}
		else if(n<=1395495){
			n-=9045;
			temp=(sqrt(213.0*213+12*(99*84+2*n))+213)/6;
			if((double)((long)temp)==temp) s=(long)temp-1;
			else s=(long)temp;
			s=n-(3*s*s-213*s-99*84)/2;
			if(s<=9) num=s;
			else if(s<=189){
				s-=9;
				m=(s+1)/2+9;
				if(s%2==0) num=m%10;
				else num=m/10%10;
			}
			else{
				s-=189;
				m=(s+1)/3+99;
				if(s%3==0) num=m%10;
				else if(s%3==1) num=m/100%10;
				else num=m/10%10;
			}
			cout<<num<<endl;
		}
		else if(n<=189414495){
			n-=1395495;
			temp=(sqrt(1105.0*1105+8*(999*893+n))+1105)/4;
			if((double)((long)temp)==temp) s=(long)temp-1;
			else s=(long)temp;
			s=n-(2*s*s-1105*s-999*893);
			if(s<=9) num=s;
			else if(s<=189){
				s-=9;
				m=(s+1)/2+9;
				if(s%2==0) num=m%10;
				else num=m/10%10;
			}
			else if(s<=2889){
				s-=189;
				m=(s+1)/3+99;
				if(s%3==0) num=m%10;
				else if(s%3==1) num=m/100%10;
				else num=m/10%10;
			}
			else{
				s-=2889;
				m=(s+1)/4+999;
				if(s%4==0) num=m%10;
				else if(s%4==1) num=m/1000%10;
				else if(s%4==2) num=m/100%10;
				else num=m/10%10;
			}
			cout<<num<<endl;
		}
		else{
			n-=189414495;
			a=22207*22207;
			b=27788*9999;
			b*=20;
			c=40*double(n);
			temp=(sqrt(a+b+c+0.0)+22207)/10;
			if((double)((long)temp)==temp) s=(long)temp-1;
			else s=(long)temp;
			a=5*s-22207;
			a*=s;
			b=9999*27788;
			s=long(n-(a-b)/2);
			if(s<=9) num=s;
			else if(s<=189){
				s-=9;
				m=(s+1)/2+9;
				if(s%2==0) num=m%10;
				else num=m/10%10;
			}
			else if(s<=2889){
				s-=189;
				m=(s+1)/3+99;
				if(s%3==0) num=m%10;
				else if(s%3==1) num=m/100%10;
				else num=m/10%10;
			}
			else if(s<=38889){
				s-=2889;
				m=(s+1)/4+999;
				if(s%4==0) num=m%10;
				else if(s%4==1) num=m/1000%10;
				else if(s%4==2) num=m/100%10;
				else num=m/10%10;
			}
			else{
				s-=38889;
				m=(s+1)/5+9999;
				if(s%5==0) num=m%10;
				else if(s%5==1) num=m/10000%10;
				else if(s%5==2) num=m/1000%10;
				else if(s%5==3) num=m/100%10;
				else num=m/10%10;
			}
			cout<<num<<endl;
		}
	}
	return 0;
}

