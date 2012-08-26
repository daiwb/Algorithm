/*ZJU 1700 Falling Leaves
2003.11.29 By adai
00:00.00 380K*/

#include <cstdio>
#include <cstring>

using namespace std;

class node{
public:
    char letter;
    node* left;
    node* right;
    node(){
        left=NULL;
        right=NULL;
    }
}nd[26];

char input[26][27];

void print(node* root){
    printf("%c",(*root).letter);
    if((*root).left!=NULL) print((*root).left);
    if((*root).right!=NULL) print((*root).right);
}

int main(void){
    char temp[27];
    int num,count(0),i,j,len;
    node* root;
    while(1){
        scanf("%s",&temp);
        if(strcmp(temp,"*")==0||strcmp(temp,"$")==0){
            nd[0].letter=input[count-1][0];
            num=1;
            for(i=count-2;i>=0;i--){
                len=strlen(input[i]);
                node* a;
                for(j=0;j<len;j++){
                    a=&nd[0];
                    while(1){
                        if(input[i][j]<(*a).letter){
                            if((*a).left==NULL){
                                (*a).left=&nd[num];
                                nd[num++].letter=input[i][j];
                                break;
                            }
                            else{
                                a=(*a).left;
                                continue;
                            }
                        }
                        else{
                            if((*a).right==NULL){
                                (*a).right=&nd[num];
                                nd[num++].letter=input[i][j];
                                break;
                            }
                            else{
                                a=(*a).right;
                                continue;
                            }
                        }
                    }    
                }
            }
            root=&nd[0];
            print(root);
            printf("\n");
            for(i=0;i<26;i++){
                nd[i].left=NULL;
                nd[i].right=NULL;
            }
            if(strcmp(temp,"*")==0){
                count=0;
                continue;
            }
            else{
                break;
            }
        }
        else{
            strcpy(input[count++],temp);
        }
    }
    return 0;
}
            
