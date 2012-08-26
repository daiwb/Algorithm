/*
ZJU 1518 This Sentence is False
00:00:00 476K
2004.07.12 by adai
*/

#include <iostream>
using namespace std;

#define TRUE  1
#define FALSE 0


class sentence
{
public:
	int next;		//which sentence this sentence is about
	int say;		//what this sentence says about
	int sign;		//whether this sentence has been assigned to a component
	int value;		//set true/false to this sentence
	int group;		//which component this sentence belongs to
	int visited;	//whether has been visited to count tv,fv,no of a group
}sen[1001];


class component
{
public:
	int start;		//which sentence to start
	int tv;			//the number of vertices labelled true
	int fv;			//the number of vertices labelled false
	int no;			//num of false edges in the cycle of this component
}group[1001];


int groupno,inconsistent,solution;


//computer which group each sentence belongs to
int f(int i)
{
	int next=sen[i].next;
	if(sen[i].group!=0) return sen[i].group;
	sen[i].sign=1;
	if(sen[next].sign==1&&sen[next].group==0)
	{
		groupno++;
		group[groupno].start=i;
		group[groupno].tv=0;
		group[groupno].fv=0;
		group[groupno].no=0;
		sen[i].group=groupno;
		return groupno;
	}
	sen[i].group=f(next);
	return sen[i].group;
}


//compute the value of each sentence
int g(int i)
{
	int next=sen[i].next;
	if(sen[i].visited==TRUE) return sen[i].value;
	sen[i].visited=TRUE;
	sen[i].value=(sen[i].say==g(next));
	if(sen[i].value==TRUE) group[sen[i].group].tv++;
	else group[sen[i].group].fv++;
	return sen[i].value;
}


int max(int i,int j)
{
	if(i>j) return i;
	return j;
}


int main()
{
	int n;
	int i,j,next;
	char ch[10],say[10];

	while(cin>>n&&n!=0)
	{
		for(i=1;i<=n;i++)
		{
			cin>>ch>>j>>ch>>say;
			sen[i].next=j;
			if(say[0]=='t') sen[i].say=TRUE;
			else sen[i].say=FALSE;
			sen[i].sign=0;
			sen[i].value=-1;
			sen[i].group=0;
			sen[i].visited=FALSE;
		}
		
		groupno=0;
		inconsistent=FALSE;
		solution=0;

		for(i=1;i<=n;i++)
		{
			f(i);
		}

		for(i=1;i<=groupno;i++)
		{
			j=group[i].start;
			sen[j].value=TRUE;
			group[i].tv++;
			while(1)
			{
				if(sen[j].visited==TRUE) break;
				sen[j].visited=TRUE;
				if(sen[j].say==FALSE) group[i].no++;
				next=sen[j].next;
				if(sen[next].visited==TRUE) break;
				sen[next].value=(sen[j].value==sen[j].say);
				if(sen[next].value==TRUE) group[i].tv++;
				else group[i].fv++;
				j=next;
			}
			if(group[i].no%2==1)
			{
				inconsistent=TRUE;
				break;
			}
		}
		
		if(inconsistent==TRUE)
		{
			cout<<"Inconsistent"<<endl;
			continue;
		}

		for(i=1;i<=n;i++)
		{
			g(i);
		}

		for(i=1;i<=groupno;i++)
		{
			solution+=max(group[i].tv,group[i].fv);
		}
		cout<<solution<<endl;
	}
	return 0;
}