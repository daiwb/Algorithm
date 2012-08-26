/*
O(n) 
 1. 利用两个指针p1,p2. 初始化时p1指向s[0],p2指向s[1]. 
 2. k=0开始，检验s[p1+k] 与 s[p2+k] 对应的字符是否相等.若相等，则k++,一直下去， 
    直到找到第一个不同的(若k试了一个字符串的长度也没找到不同，则算法终止). 
    此时,因为s[p1+k] 与 s[p2+k] 不同，就有两种情况: 
    case I: 
        s[p1+k]>s[p2+k]. 可以证明，从p1到p1+k都不可能是要求的那个字符串的开头 
        字母。于是，可以把p1移到p1+k+1, p2不变。 
    case II: 
        s[p1+k]<s[p2+k]. 可以证明，从p2到p2+k都不可能是要求的那个字符串的开头 
        字母。于是，可以把p2移到p2+k+1, p1不变。 
    复重此操作，直到p1、p2把整个字符串都检验完毕. 
 3. 输出p1与p2中的最小值. 

 注意： 
    1. 可以先把字符串double，这样做可能方便些. 
    2. 例如，p1要移到p1+k+1时，如果p1+k+1不大于p2的话，可以直接把p1移到 
       p2前，因为，p2后面的已经检验过了.(p2时的类似) 这样会快一点.
*/

/*
ZJU 2006 Glass Beads
2004.05.07 By adai
00:00.01 456K
*/

#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int kase,i;
	cin>>kase;
	char input[20001];
	while(kase--){
		cin>>input;
		int len=strlen(input);
		for(i=0;i<len;i++) input[i+len]=input[i];
		int p1(0),p2(1),k(0);
		while(1){
			if(input[p1+k]==input[p2+k]){
				k++;
				if(k==len) break;
			}
			else if(input[p1+k]>input[p2+k]){
				p1+=k+1;
				if(p1<=p2) p1=p2+1;
				if(p1>=len){
					p1=len-1;
					break;
				}
				k=0;
			}
			else{
				p2+=k+1;
				if(p2<=p1) p2=p1+1;
				if(p2>=len){
					p2=len-1;
					break;
				}
				k=0;
			}
		}
		int sign(0);
		for(k=0;k<len;k++){
			if(input[p1+k]<input[p2+k]){
				sign=-1;
				break;
			}
			else if(input[p1+k]>input[p2+k]){
				sign=1;
				break;
			}
		}
		if(sign>0) cout<<p2+1<<endl;
		else if(sign<0) cout<<p1+1<<endl;
		else{
			if(p1>p2) p1=p2;
			cout<<p1+1<<endl;
		}
	}
	return 0;
}