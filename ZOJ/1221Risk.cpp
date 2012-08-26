//ZJU 1221 Risk
//2003.08.24 BY ADAI
//Dijkstra Algorithm

#include <iostream>

using namespace std;

int small(int a,int b){
    if(a<b) return a;
    return b;
}

int main(void){
    int n,i,j,k,kase=1;
    while(cin>>n){
        int a[20][20];  //表示连通图
        for(i=0;i<20;i++){
            for(j=0;j<20;j++) a[i][j]=100;
        }
        for(i=0;i<n;i++){
            cin>>k;
            a[0][k-1]=a[k-1][0]=1;
        }
        for(i=1;i<19;i++){
            cin>>n;
            for(j=0;j<n;j++){
                cin>>k;
                a[i][k-1]=a[k-1][i]=1;
            }
        }
        cout<<"Test Set #"<<kase++<<endl;
        cin>>n;
        int s,d,p,min,temp;    //starting ending countries
        while(n--){
            cin>>s>>d;
            s--;
            d--;
            int b[20]={0};  //表示是否已找到最短路径 
            int c[20];  //表示到指定点之间距离值
            for(i=0;i<20;i++) c[i]=100;
            c[s]=0;
            p=s;
            for(i=0;i<20;i++){
                b[p]=1;
                min=100;
                for(j=0;j<20;j++){
                    if(j==i||b[j]==1) continue;
                    c[j]=small(c[j],c[p]+a[p][j]);
                    if(c[j]<min){
                        min=c[j];
                        temp=j;
                    }
                }
                if(temp==d) break;
                p=temp;
            }
            cout<<s+1<<" to "<<d+1<<": "<<c[d]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
                

/*
bfs version

#include <iostream>
#include <string>
using namespace std;

int a[20][20];
int visited[20];
int depth, s, d;
int queue[50];

int bfs() {
	int front(0), rear(0);
	int nfront, nrear;
	while (1) {
		depth ++;
		nfront = rear + 1;
		nrear = rear;
		for (int i = front; i <= rear; i ++) {
			int tt = queue[i];
			for (int j = 0; j < 20; j ++) {
				if (a[tt][j] == 0) continue;
				if (visited[j]) continue;
				visited[j] = 1;
				queue[++ nrear] = j;
			}
		}
		if (visited[d]) break;
		if (nfront > nrear) break;
		for (int i = nfront; i <= nrear; i ++)
			queue[i - nfront] = queue[i];
		front = 0, rear = nrear - nfront;
	}
	return 0;
}

int main() {
	int n, kase(1);
	while (1) {
		memset(a, 0, sizeof(a));
		for (int i = 0; i < 19; i ++) {
			cin >> n;
			for (int j = 0; j < n; j ++) {
				cin >> d;
				d --;
				a[i][d] = a[d][i] = 1;
			}
		}
		if (cin.fail()) break;
		cin >> n;
		cout << "Test Set #" << kase ++ << endl;
		while (n --) {
			cin >> s >> d;
			cout << s << " to " << d << ": ";
			s --, d --;
			depth = 0;
			memset(visited, 0, sizeof(visited));
			visited[s] = 1;
			queue[0] = s;
			bfs();
			cout << depth << endl;
		}
		cout << endl;
	}
	return 0;
}
*/