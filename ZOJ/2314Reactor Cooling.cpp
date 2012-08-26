//ac

#include <iostream>
#include <vector>
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
int mat[MAXN][MAXN], flow[MAXN][MAXN];
int ll[MAXN][MAXN];
int inner[MAXN], outer[MAXN];

void run() {
        cin >> n >> m;
        memset(mat, 0, sizeof(mat));
        memset(ll, 0, sizeof(ll));
        vector<pair<int, int> > mm;
        int s = n, t = n + 1;
        for (int i = 0; i < m; ++i) {
                int u, v, l, c;
                cin >> u >> v >> l >> c;
                --u, --v;
                mat[s][v] += l, mat[u][t] += l;
                mat[u][v] = c - l;
                ll[u][v] = l;
                mm.push_back(make_pair(u, v));
        }
        max_flow(n + 2, mat, s, t, flow);
        for (int i = 0; i < n; ++i) {
                if (flow[s][i] != mat[s][i] || flow[i][t] != mat[i][t]) {
                        cout << "NO" << endl;
                        return;
                }
        }
        cout << "YES" << endl;
        for (int i = 0; i < mm.size(); ++i) {
                int u = mm[i].first, v = mm[i].second;
                cout << flow[u][v] + ll[u][v]<< endl;
        }
}

int main() {
        int kase;
        for (cin >> kase; kase; --kase) {
                run();
        }
        return 0;
}
