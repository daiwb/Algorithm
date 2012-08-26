/**
 * 2101 Virtual Keyboard
 * by skatou
*/

#include <cstring>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

struct node {
    char ch;
    node *pre, *next;
};
node *head, *tail, *now;
int ins;
char buf[10000];

inline int isBlank(char ch) { return ch == ' ' || ch == '\t' || ch == '\n'; }

void Left() { if (now->pre != head) now = now->pre; }

void Right() { if (now->next) now = now->next; }

void CtrlLeft() {
    if (!isBlank(now->pre->ch))
        while (!isBlank(now->pre->ch) && now->pre != head)
            now = now->pre;
        else {
            node* p = now->pre;
            while (p->pre != head && isBlank(p->ch)) p = p->pre;
            if (p == head) return;
            for (now = p; !isBlank(now->pre->ch) && now->pre != head; )
                now = now->pre;
        } // end else
}

void CtrlRight() {
    if (now == tail) return;
    node* p = now->next;
    while (p->next && !isBlank(p->ch))
        p = p->next;
    if (p == tail) return;
    while (p->next && isBlank(p->ch))
        p = p->next;
    if (p == tail) return;
    now = p;
}

void Home() {
    while (now->pre != head && now->pre->ch != '\n')
        now = now->pre;
}

void End() {
    while (now->next && now->ch != '\n')
        now = now->next;
}

inline void Insert() { ins ^= 1; }

inline void Delete() {
    if (now == tail) return;
    node* p = now;
    now->pre->next = now->next;
    now->next->pre = now->pre;
    now = now->next;
    delete p;
}

inline void Backspace() {
    if (now->pre == head) return;
    node* p = now->pre;
    now->pre->pre->next = now;
    now->pre = now->pre->pre;
    delete p;
}

inline void Blankspace() {
    if (!ins && now != tail && now->ch != '\n') { now->ch = ' '; now = now->next; return; }
    node* p = new node(); p->ch = ' ';
    now->pre->next = p; p->pre = now->pre;
    p->next = now; now->pre = p;
}

void Press(char* str) {
    for (int i = 0; str[i]; ++i) {
        if (!ins && now != tail && now->ch != '\n') {
            now->ch = str[i]; now = now->next;
        } else {
            node* p = new node(); p->ch = str[i];
            now->pre->next = p; p->pre = now->pre;
            p->next = now; now->pre = p;
        } // enmd else
    } // end for
}

inline void Enter() {
    node* p = new node(); p->ch = '\n';
    now->pre->next = p; p->pre = now->pre;
    p->next = now; now->pre = p;
}

void go(char* cmd) {
    if (strcmp(cmd, "Left") == 0)
        Left();
    else if (strcmp(cmd, "Right") == 0)
        Right();
    else if (strcmp(cmd, "CtrlLeft") == 0)
        CtrlLeft();
    else if (strcmp(cmd, "CtrlRight") == 0)
        CtrlRight();
    else if (strcmp(cmd, "Home") == 0)
        Home();
    else if (strcmp(cmd, "End") == 0)
        End();
    else if (strcmp(cmd, "Insert") == 0)
        Insert();
    else if (strcmp(cmd, "Delete") == 0)
        Delete();
    else if (strcmp(cmd, "Backspace") == 0)
        Backspace();
    else if (strcmp(cmd, "Blankspace") == 0)
        Blankspace();
    else if (strcmp(cmd, "Enter") == 0)
        Enter();
    else if (strcmp(cmd, "Press") == 0) {
        fgets(buf, 10000, stdin); int i;
        buf[strlen(buf) - 1] = '\0';
        for (i = 0; buf[i] && buf[i] == ' '; ++i);
        if (buf[i]) Press(&buf[i]);
    } // end else
}

int main() {
    //      freopen("1.in", "r", stdin);
    head = new node(); tail = new node(); head->ch = tail->ch = 0;
    while (scanf("%s", buf) && strcmp(buf, "EndOfInput")) {
        ins = 1;
        head->next = tail; tail->pre = head;
        head->pre = tail->next = 0;
        for (now = tail, go(buf); scanf("%s", buf) && strcmp(buf, "EndWithEndl"); )
            go(buf);
        for (node* p = head->next; p != tail; p = p->next)
            printf("%c", p->ch);
        printf("\n\n");
        for (node* p = head->next; p != tail; ) {
            node* t = p; p = p->next;
            delete t;
        } // end for
    } // end while
    delete head; delete tail;
    return 0;
}
