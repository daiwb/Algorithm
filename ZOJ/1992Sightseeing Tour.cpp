// ac

#include <iostream>
#include <string>
using namespace std;

#define see(n) cout << #n << " = " << n << endl
#define seeArray(n, a) cout << #a << " = ";\
for (int __i__ = 0; __i__ < n; ++__i__)\
        cout << a[__i__] << " ";\
        cout << endl;
#define seeArray2(n, m, a) cout << #a << " = " << endl;\
for (int __i__ = 0; __i__ < n; ++__i__) {\
        for (int __j__ = 0; __j__ < m; ++__j__)\
                cout << a[__i__][__j__] << " ";\
                        cout << endl;\
}

#define MAXN 205
#define inf 1000000000

int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN]){
        int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
        if (source==sink) return inf;
        for (i=0;i<n;i++)
                for (j=0;j<n;flow[i][j++]=0);
        for (;;){
                for (i=0;i<n;pre[i++]=0);
                pre[t=source]=source+1,d[t]=inf;
                for (p=q=0;p<=q&&!pre[sink];t=que[p++])
                        for (i=0;i<n;i++)
                                if (!pre[i]&&(j=mat[t][i]-flow[t][i]))
                                        pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
                                else if (!pre[i]&&(j=flow[i][t]))
                                        pre[que[q++]=i]=-t-1,d[i]=d[t]<j?d[t]:j;
                if (!pre[sink]) break;
                for (i=sink;i!=source;)
                        if (pre[i]>0)
                                flow[pre[i]-1][i]+=d[sink],i=pre[i]-1;
                        else
                                flow[i][-pre[i]-1]-=d[sink],i=-pre[i]-1;
        }
        for (j=i=0;i<n;j+=flow[source][i++]);
        return j;
}

int n, m;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];
int deg[MAXN];

void run() {
        cin >> n >> m;
        memset(mat, 0, sizeof(mat));
        memset(deg, 0, sizeof(deg));
        for (int i = 0; i < m; ++i) {
                int x, y, d;
                cin >> x >> y >> d;
                deg[x]--, deg[y]++;
                if (d != 1) {
                        mat[y][x] += 2;
                }
        }
        //seeArray(n + 2, deg);
        int s = 0, t = n + 1;
        int t1 = 0, t2 = 0;
        for (int i = 1; i <= n; ++i) {
                if (abs(deg[i]) & 1) {
                        cout << "impossible" << endl;
                        return;
                }
                if (deg[i] > 0) {
                        mat[s][i] = deg[i];
                        t1 += deg[i];
                } else if (deg[i] < 0) {
                        mat[i][t] = -deg[i];
                }
        }
        int ret = max_flow(n + 2, mat, 0, n + 1, flow);
        //see(ret); see(t1);
        if (ret == t1) cout << "possible" << endl;
        else cout << "impossible" << endl;
}

int main() {
        int kase;
        for (cin >> kase; kase; --kase) {
                run();
        }
        return 0;
}
