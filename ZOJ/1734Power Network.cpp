//ac

#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAXN 105
#define inf 1000000000

vector<string> split( const string& s, const string& delim =" ()," ) {
        vector<string> res;
        string t;
        for ( int i = 0 ; i != s.size() ; i++ ) {
                if ( delim.find( s[i] ) != string::npos ) {
                        if ( !t.empty() ) {
                                res.push_back( t );
                                t = "";
                        }
                } else {
                        t += s[i];
                }
        }
        if ( !t.empty() ) {
                res.push_back(t);
        }
        return res;
}

int max_flow(int n,int mat[][MAXN],int source,int sink,int flow[][MAXN])
{
        int pre[MAXN],que[MAXN],d[MAXN],p,q,t,i,j;
        if (source==sink) return inf;
        for (i=0;i<n;i++)
                for (j=0;j<n;flow[i][j++]=0);
        for (;;){
                for (i=0;i<n;pre[i++]=0);
                pre[t=source]=source+1,d[t]=inf;
                for (p=q=0;p<=q&&!pre[sink];t=que[p++])
                        for (i=0;i<n;i++)
                                if (!pre[i] && (j=mat[t][i]-flow[t][i]))
                                        pre[que[q++]=i]=t+1,d[i]=d[t]<j?d[t]:j;
                                else if (!pre[i]&& (j=flow[i][t]))
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

int f(string& s) {
        int ret = 0;
        for (int i = 0; i < s.length(); ++i) ret = ret * 10 + s[i] - '0';
        return ret;
}

int n, np, nc, m;
int mat[MAXN][MAXN];
int flow[MAXN][MAXN];

void run() {
        memset(mat, 0, sizeof(mat));
        string tmp;
        for (int i = 0; i < m; ++i) {
                cin >> tmp;
                vector<string> mm = split(tmp);
                int u, v, z;
                u = f(mm[0]); v = f(mm[1]); z = f(mm[2]);
                mat[u][v] = z;
        }
        for (int i = 0; i < np; ++i) {
                cin >> tmp;
                vector<string> mm = split(tmp);
                int u, z;
                u = f(mm[0]); z = f(mm[1]);
                mat[n][u] = z;
        }
        for (int i = 0; i < nc; ++i) {
                cin >> tmp;
                vector<string> mm = split(tmp);
                int u, z;
                u = f(mm[0]); z = f(mm[1]);
                mat[u][n + 1] = z;
        }
        int ret = max_flow(n + 2, mat, n, n + 1, flow);
        cout << ret << endl;
}

int main() {
        while (cin >> n >> np >> nc >> m) {
                run();
        }
        return 0;
}