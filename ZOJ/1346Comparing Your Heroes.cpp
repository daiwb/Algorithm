#include <iostream.h>
#include <string.h>
#include <time.h>

char name[20][20];
int namelen,ans,n;
int data[20][20],datalen[20],indegree[20];

int name2id(char *s)
{
    int i;
    for (i=0;i<namelen;i++)
        if (strcmp(name[i],s)==0) return i;
    strcpy(name[namelen],s);
    return namelen++;
}

void search(int d)
{
    int i,j;
    if (d==namelen)
    {
        ans++;
        return;
    }
    for (i=0;i<namelen;i++)
    {
        if (indegree[i]) continue;
        indegree[i]--;
        for (j=0;j<datalen[i];j++)
            indegree[data[i][j]]--;
        search(d+1);
        for (j=0;j<datalen[i];j++)
            indegree[data[i][j]]++;
        indegree[i]++;
    }
}
int main()
{
    int i,id1,id2;
    char name1[20],name2[20];
    while (cin>>n)
    {
        ans=namelen=0;
        memset(datalen,0,sizeof(datalen));
        memset(indegree,0,sizeof(indegree));
        for (i=0;i<n;i++)
        {
            cin>>name1>>name2;
            id1=name2id(name1);
            id2=name2id(name2);
            data[id1][datalen[id1]++]=id2;
            indegree[id2]++;
        }
        search(0);
        cout<<ans<<endl;
    }
    return 0;
}

/*
#include <iostream.h>
#include <string.h>
#include <time.h>
char name[20][20];
int namelen,ans,n;
int data[20][20],datalen[20],indegree[20];
int calced[65536];
int name2id(char *s)
{
    int i;
    for (i=0;i<namelen;i++)
        if (strcmp(name[i],s)==0) return i;
        strcpy(name[namelen],s);
        return namelen++;
}
int search(int left)
{
    int i,j,ans=0;
    if (calced[left]>=0) return calced[left];
    for (i=0;i<namelen;i++)
    {
        if (indegree[i]) continue;
        indegree[i]--;
        for (j=0;j<datalen[i];j++)
            indegree[data[i][j]]--;
        ans+=search(left&~(1<<i));
        for (j=0;j<datalen[i];j++)
            indegree[data[i][j]]++;
        indegree[i]++;
    }
    return calced[left]=ans;
}
int main()
{
    int i,id1,id2;
    char name1[20],name2[20];
    while (cin>>n)
    {
        namelen=0;
        memset(datalen,0,sizeof(datalen));
        memset(indegree,0,sizeof(indegree));
        memset(calced,-1,sizeof(calced));
        calced[0]=1;
        for (i=0;i<n;i++)
        {
            cin>>name1>>name2;
            id1=name2id(name1);
            id2=name2id(name2);
            data[id1][datalen[id1]++]=id2;
            indegree[id2]++;
        }
        ans=search((1<<namelen)-1);
        cout<<ans<<endl;
    }
    return 0;
}
*/