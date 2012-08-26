/*ZJU 1902 Hay Points
2003.12.11 By adai
00:00.00 436K*/

#include <iostream>
#include <cstring>

using namespace std;

class dic{
public:
    char word[17];
    double value;
};

int main(void){
    long m,n,i;
    char temp[85];
    double total(0);
    cin>>m>>n;
    dic* dict=new dic[m];
    for(i=0;i<m;i++) cin>>dict[i].word>>dict[i].value;
    while(n){
        cin>>temp;
        if(strcmp(temp,".")==0){
            n--;
            cout<<(long)total<<endl;
            total=0;
            continue;
        }
        for(i=0;i<m;i++){
            if(strcmp(temp,dict[i].word)==0){
                total+=dict[i].value;
                break;
            }
        }
    }
    return 0;
}
        
        
        
