//zju 1387 Decoding Morse Sequences

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAX_CHAR_LEN        4
#define MAX_CODE_LEN        10000
#define MAX_WORD_LEN        20
#define MAX_ANSWER          2000000000

static char morse[][MAX_CHAR_LEN + 1] = {
    ".-", "-...", "-.-.", "-..",            /* ABCD */
        ".", "..-.", "--.", "....",         /* EFGH */
        "..", ".---", "-.-", ".-..",        /* IJKL */
        "--", "-.", "---", ".--.",          /* MNOP */
        "--.-", ".-.", "...", "-",          /* QRST */
        "..-", "...-", ".--", "-..-",       /* UVWX */
        "-.--", "--.."};                    /* YZ */

typedef struct Trie {
    int count;
    struct Trie *dot, *dash;
} Trie;

Trie *trie_new(void) {
    Trie *p = new Trie;
    p->dot = p->dash = NULL;
    p->count = 0;
    return p;
}

void trie_add(Trie *node, const char *code) {
    while (*code) {
        if (*code == '.') {
            if (!node->dot)
                node->dot = trie_new();
            node = node->dot;
        }
        else {
            if (!node->dash)
                node->dash = trie_new();
            node = node->dash;
        }
        code++;
    }
    node->count++;
}

void trie_free(Trie *p) {
    if (p) {
        trie_free(p->dot);
        trie_free(p->dash);
        free(p);
    }
}

void get_word_code(const char *word, char *wordcode) {
    const char *w = word;
    char *c = wordcode;
    *c = 0;
    while (*w) {
        strcpy(c, morse[*w - 'A']);
        c += strlen(c);
        w++;
    }
}

void read_data(char *code, Trie *dict) {
    char word[MAX_WORD_LEN + 1];
    char wordcode[MAX_CHAR_LEN * MAX_WORD_LEN + 1];
    int cdict, i;
    scanf("%s", code);
    scanf("%d", &cdict);
    for (i = 0; i < cdict; i++) {
        scanf("%s", word);
        get_word_code(word, wordcode);
        trie_add(dict, wordcode);
    }
}

int compute_result(const char *code, const Trie *dict) {
    int count[MAX_CODE_LEN + 1];
    int i, j;
    int len = strlen(code);
    count[len] = 1;
    for (i = len - 1; i >= 0; i--) {
        const Trie *p = dict;
        count[i] = 0;
        for (j = i; j < len && p; j++) {
            if (code[j] == '.')
                p = p->dot;
            else
                p = p->dash;
            if (p && p->count) {
                count[i] += p->count * count[j + 1];
            }
        }
    }
    return count[0];
}

int main() {
    char code[MAX_CODE_LEN + 1];
    Trie *dict;
    int d, i, count;
    scanf("%d",&d);
    for (i = 0; i < d; i++) {
        dict = trie_new();
        read_data(code, dict);
        count = compute_result(code, dict);
        printf("%d\n", count);
        trie_free(dict);
    }
    return 0;
}
