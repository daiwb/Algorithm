#include <iostream>
#include <string>
#include <map>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)

string ct[] = {
    "y qee",
    "ejp mysljylc kd kxveddknmc re jsicpdrysi",
    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
    "de kr kd eoya kw aej tysr re ujdr lkgc jv"
};

string pt[] = {
    "a zoo",
    "our language is impossible to understand",
    "there are twenty six factorial possibilities",
    "so it is okay if you want to just give up"
};

map<char, char> mp;

void init() {
    mp['z'] = 'q';
    REP(i,4) {
        REP(j,ct[i].length()) {
            if (pt[i][j] == ' ') continue;
            mp[ct[i][j]] = pt[i][j];
        }
    }
}

string str;

void run() {
    getline(cin, str);
    REP(i,str.length()) {
        if (str[i] == ' ') continue;
        str[i] = mp[str[i]];
    }
    cout << str << endl;
}

int main() {
    init();
    int k;
    cin >> k;
    getline(cin, str);
    FOR(c,1,k) {
        cout << "Case #" << c << ": ";
        run();
    }
    return 0;
}
