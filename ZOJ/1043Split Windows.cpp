/**
 * P1004: Split Windows
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: Tree Structure + Recursion
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#   define _cpp_max max
#endif

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// tree node
class node {
public:
    char content;
    int width, height;
    node *left, *right;
    // contruct from string
    node(string& str) : width(2), height(2), left(NULL), right(NULL) {
        content = str[0];
        str = str.substr(1);
        if (content == '|' || content == '-') {
            left = new node(str);
            right = new node(str);
            if (content == '|') {
                width = left->width + right->width;
                height = max(left->height, right->height);
            } else {
                width = max(left->width, right->width);
                height = left->height + right-> height;
            }
        }
    }
    // destructor
    ~node() {
        if (content == '|' || content == '-') {
            delete left;
            delete right;
        }
    }
    // print onto virtual screen
    void draw(vector<string>& screen, int x, int y, int height, int width) {
        if (content == '|') {
            int tmp = width - width * right->width / this->width;
            left->draw(screen, x, y, height, tmp);
            right->draw(screen, x, y + tmp, height, width - tmp);
        } else if (content == '-') {
            int tmp = height - height * right->height / this->height;
            left->draw(screen, x, y, tmp, width);
            right->draw(screen, x + tmp, y, height - tmp, width);
        } else {
            screen[x][y] = content;
            screen[x + height][y] = '*';
            screen[x + height][y + width] = '*';
            screen[x][y + width] = '*';
            for (int i = 1; i < height; ++i) {
                if (screen[x + i][y] == ' ') {
                    screen[x + i][y] = '|';
                }
                if (screen[x + i][y + width] == ' ') {
                    screen[x + i][y + width] = '|';
                }
            }
            for (int i = 1; i < width; ++i) {
                if (screen[x][y + i] == ' ') {
                    screen[x][y + i] = '-';
                }
                if (screen[x + height][y + i] == ' ') {
                    screen[x + height][y + i] = '-';
                }
            }
        }
    }
};

void run() {
    string str;
    cin >> str;
    node root(str);
    vector<string> screen(root.height + 1, string(root.width + 1, ' '));
    root.draw(screen, 0, 0, root.height, root.width);
    for (int i = 0; i <= root.height; ++i) {
        cout << screen[i] << endl;
    }
}

int main() {
    int total;
    cin >> total;
    for (int now = 0; now < total; ++now) {
        cout << now + 1 << endl;
        run();
    }
    return 0;
}
