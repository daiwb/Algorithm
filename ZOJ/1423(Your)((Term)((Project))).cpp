#include <stdio.h>

int main(void){
    int m,num,i,j,t,count,count2;
    char exp[300];
    char out[300];
    scanf("%d",&m);
    getchar();
    while(m--){
        gets(exp);
        num=count=count2=0;
        for(i=0;exp[i]!='\0';i++){
            if(exp[i]!=' ') out[count++]=exp[i];
        }
        for(i=0;i<count;i++){
            if(out[i]>=65&&out[i]<=90){
                for(j=1;;j++){
                    if(i-j<0||i+j>=count) break;
                    if(out[i-j]=='('){
                        if(out[i+j]==')') out[i-j]=out[i+j]=' ';
                        else break;
                    }
                    else break;
                }
            }
        }
        for(i=0;i<count;i++){
            if(out[i]!=' ') out[count2++]=out[i];
        }
        for(i=0;i<count2;i++){
            if(out[i]=='('){
                out[i]=' ';
                for(j=i+1;;j++){
                    if(out[j]=='(') num++;
                    else if(out[j]==')'){
                        if(num==0){
                            out[j]=' ';
                            break;
                        }
                        else num--;
                    }    
                }
            }
            else break;
        }
        count=0;
        for(i=0;i<count2;i++){
            if(out[i]!=' ') out[count++]=out[i];
        }
        for(i=0;i<count;i++){
            if(out[i]=='+'){
                for(t=i+1;out[t]=='(';t++){
                    out[t]=' ';
                    for(j=t+1;;j++){
                        if(out[j]=='(') num++;
                        else if(out[j]==')'){
                            if(num==0){
                                out[j]=' ';
                                break;
                            }
                            else num--;
                        }
                    }
                }
            }
        }
        count2=0;
        for(i=0;i<count;i++){
            if(out[i]!=' ') out[count2++]=out[i];
        }
        for(i=0;i<count2;i++){
            if(out[i]=='-'&&out[i+1]=='('){
                for(t=i+2;out[t]=='(';t++){
                    out[t]=' ';
                    for(j=t+1;;j++){
                        if(out[j]=='(') num++;
                        else if(out[j]==')'){
                            if(num==0){
                                out[j]=' ';
                                break;
                            }
                            else num--;
                        }
                    }
                }
            }
        }
        for(i=0;i<count2;i++){
            if(out[i]!=' ') printf("%c",out[i]);
        }
        printf("\n");
    }
    return 0;
}
        
