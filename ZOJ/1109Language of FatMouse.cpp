/*
ZJU 1109 Language of FatMouse
00:03.19 8456K
*/

#include<iostream> 
#include<stdio.h> 
#include<stdlib.h> 
#include<string> 
using namespace std; 
typedef struct 
{ 
   string e,m; 
}tlang; 

tlang dir[100005]; 

int cmp(const void *t1,const void *t2) 
{ 
   tlang *a,*b; 
   a=(tlang *)t1; b=(tlang *)t2; 
   if((*a).m>(*b).m)return 1; 
   if((*a).m<(*b).m)return -1; 
   return 0; 
} 

int main() 
{ 
   bool end; 
   char r; 
   string in; 
   int i,low,high; 
   long index; 
   index=0; 
   end=0; 
   while(1){//输入字典内容 
      cin>>in; 
      r=getchar(); 
      if(r!=' ')break; 
      dir[index].e=in; 
      cin>>dir[index].m; 
      index++; 
   } 
   qsort(dir,index,sizeof(tlang),cmp);//快排 
   do{//输入查找内容 
      low=0; 
      high=index-1; 
      i=0; 
      while(low<=high){ 
         i=(high+low)/2; 
         if(in>dir[i].m)low=i+1; 
         else if(in<dir[i].m)high=i-1; 
         else{ 
            cout<<dir[i].e<<endl; 
            break; 
         } 
         if(low>high){ 
            cout<<"eh"<<endl; 
         } 
      } 
   }while(cin>>in); 
   return 0; 
}