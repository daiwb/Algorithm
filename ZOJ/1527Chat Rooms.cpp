#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

const char *cons="bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZ";

char lastten[10][211];
int Index;

bool isaeiou(char c) {
    for (int i = 0; i < 40; ++i) {
        if (c == cons[i]) return false;
    }
    return true;
}

int hascons(char *s, int l) {
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        int cnt = 0;
        for (int j = i; j < i + l && j < len; ++j) {
            if (s[j] == ' ') break;
            if (! isaeiou(s[j])) ++cnt;
            else break;
        }
        if(cnt >= l) return 1;
    }
    return 0;
}
int morethan2() {
    int re = 0;
    for (int i = 0; i < 10; ++i) {
        if (lastten[i][210] == '!' || lastten[i][210] == '@') ++re;
    }
    if (re > 2) return 1;
    return 0;
}
int equcount(char *s){
    int re = 0;
    for (int i = 0; i < 10; ++i) {
        if (lastten[0] == 0) return re;
        if (strcmp(s, lastten[i]) == 0) ++re;
    }
    return re;
}
int main(){
    int n;
    char str[211];
    while (cin >> n) {
        getchar();
        Index = 0;
        memset(lastten, '*', sizeof(lastten));
        while (n--) {
            cin.getline(str, 211);
            if (hascons(str, 6)) str[210] = '!';
            else if (hascons(str, 5)) str[210] = '@';
            else str[210] = '#';
            
            if (str[210] == '!') cout<< "n" << endl;
            else if (str[210] == '@' && morethan2()) cout << "n" << endl;
            else if (equcount(str) > 1) cout << "n" << endl;
            else cout << "y" << endl;
            memcpy(lastten[Index++], str, sizeof(str));
            Index %= 10;
        }
    }
    return 0;
}