//ZJU 1225 Scramble Sort
//2003.09.24 BY adai

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void){
	char input[100];
	while(1){
		gets(input);
		if(strcmp(input,".")==0) break;
		int len=strlen(input);
		int sign=0,i,j,tempi=0;//sign 0表示不确定 1表示为字符串 2表示为数字
		char temp[100];
		char a_str[100][100];//存放大写转小写后的字符串
		char a_str2[100][100];//存放原始字符串
		long a_num[100];
		int num1,num2;//分别为字符串的个数与数字的个数
		int style[100];//表示是字符串还是数字
		int stylei=0;
		num1=num2=0;
		for(i=0;i<len;i++){
			if((input[i]>='a'&&input[i]<='z')||(input[i]>='A'&&input[i]<='Z')){
				if(sign==0) style[stylei++]=sign=1;
				temp[tempi++]=input[i]; 
			}
			else if((input[i]>='0'&&input[i]<='9')||input[i]=='-'){
				if(sign==0) style[stylei++]=sign=2;
				temp[tempi++]=input[i];
			}
			else if(input[i]==' ') continue;
			else if(input[i]==','){
				temp[tempi]='\0';
				if(sign==1){
					strcpy(a_str2[num1++],temp);
					for(j=0;a_str2[num1-1][j]!='\0';j++){
						if(a_str2[num1-1][j]>='A'&&a_str2[num1-1][j]<='Z')
							a_str[num1-1][j]=a_str2[num1-1][j]-'A'+'a';
						else a_str[num1-1][j]=a_str2[num1-1][j];
					}
					a_str[num1-1][j]='\0';
				}
				else{
					long tempnum=0;
					if(temp[0]=='-'){
						for(j=1;j<tempi;j++) tempnum=tempnum*10+temp[j]-'0';
						tempnum*=-1;
					}
					else for(j=0;j<tempi;j++) tempnum=tempnum*10+temp[j]-'0';
					a_num[num2++]=tempnum;
				}
				sign=0;
				tempi=0;
			}
			else if(input[i]=='.'){
				temp[tempi]='\0';
				if(sign==1){
					strcpy(a_str2[num1++],temp);
					for(j=0;a_str2[num1-1][j]!='\0';j++){
						if(a_str2[num1-1][j]>='A'&&a_str2[num1-1][j]<='Z')
							a_str[num1-1][j]=a_str2[num1-1][j]-'A'+'a';
						else a_str[num1-1][j]=a_str2[num1-1][j];
					}
					a_str[num1-1][j]='\0';
				}
				else{
					long tempnum=0;
					if(temp[0]=='-'){
						for(j=1;j<tempi;j++) tempnum=tempnum*10+temp[j]-'0';
						tempnum*=-1;
					}
					else for(j=0;j<tempi;j++) tempnum=tempnum*10+temp[j]-'0';
					a_num[num2++]=tempnum;
				}
				break;
			}
		}
		char next[100];
		char next2[100];
		for(i=1;i<num1;i++){
			strcpy(next,a_str[i]);
			strcpy(next2,a_str2[i]);
			for(j=i-1;j>=0&&strcmp(next,a_str[j])<0;j--){
				strcpy(a_str[j+1],a_str[j]);
				strcpy(a_str2[j+1],a_str2[j]);
			}
			strcpy(a_str[j+1],next);
			strcpy(a_str2[j+1],next2);
		}
		int nextnum;
		for(i=1;i<num2;i++){
			nextnum=a_num[i];
			for(j=i-1;j>=0&&nextnum<a_num[j];j--)
				a_num[j+1]=a_num[j];
			a_num[j+1]=nextnum;
		}
		//for(i=0;i<num1;i++) cout<<a_str2[i]<<endl;
		//cout<<endl;
		//for(i=0;i<num2;i++) cout<<a_num[i]<<endl;
		//cout<<endl;
		int m,n;
		m=n=0;
		//cout<<"num1="<<num1<<" num2="<<num2<<endl;
		//cout<<"stylei="<<stylei<<endl;
		for(i=0;i<stylei;i++){
			if(style[i]==1) cout<<a_str2[m++];
			else cout<<a_num[n++];
			if(i==stylei-1) cout<<"."<<endl;
			else cout<<", ";
		}
	}
	return 0;
}




				
					
			
