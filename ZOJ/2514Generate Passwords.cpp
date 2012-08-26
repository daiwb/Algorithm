//ac
#include <iostream>
using namespace std;

int main() {
    int n;
    char s[1000][20];
    char team[1000][20];
    int count;
    bool flag[1000];
    while(true) {
        cin >> n;
        if (n == 0) break;
        count = 0;
        bool global;
        for (int i = 0; i < n; ++i) {
            cin >> team[i] >> s[i];
            flag[i] = false;
            global = false;
            for (int j = 0; j < strlen(s[i]); ++j) {
                if (s[i][j] == '1') {
                    s[i][j] = '@';
                    global = flag[i] = true;
                } else if (s[i][j] == '0') {
                    s[i][j] = '%';
                    global = flag[i] = true;
                } else if (s[i][j] == 'l') {
                    s[i][j] = 'L';
                    global = flag[i] = true;
                } else if (s[i][j] == 'O') {
                    s[i][j] = 'o';
                    global = flag[i] = true;
                }
            }
            if (global == true) {
                ++ count;
            }
        }
        if (count == 0) {
            cout << "No account is modified." << endl;
        } else {
            cout << count << endl;
            for (int i = 0; i < n; ++i) {
                if (flag[i] == true) {
                    cout << team[i] << ' ' << s[i] << endl;
                }
            }
        }



    }

    return 0;
}