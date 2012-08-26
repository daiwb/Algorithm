/**
 * P1010: A Well-formed Program
 *
 * ZJU Summer Camp 2003
 *
 * Judge Solution created by WishingBone
 *
 * Algo Desc: Stack + String Handling
 */
#ifdef WIN32
#   pragma warning(disable:4786)
#   define for if (0); else for
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// tag types enumeration
enum tagtype {
    begin,
    end,
    standalone
};

// tag info
class tag {
public:
    string name;
    tagtype type;
    tag(string name, tagtype type) : name(name), type(type) {
    }
};

// read a tag content
string tagcontent() {
    char ch;
    do {
        ch = getchar();
    } while (ch != '<');
    string ret = "";
    ch = getchar();
    while (ch != '>') {
        ret += ch;
        ch = getchar();
    }
    return ret;
}

// check for duplicate attributes
bool duplicate(string& str) {
    vector<string> attrs;
    for (;;) {
        while (str.length() > 0 && str[0] == ' ') {
            str = str.substr(1);
        }
        int pos = str.find_first_of('=');
        if (pos == string::npos) {
            break;
        }
        attrs.push_back(str.substr(0, pos));
        str = str.substr(pos);
        while (str.length() > 0 && str[0] != ' ') {
            str = str.substr(1);
        }
    }
    sort(attrs.begin(), attrs.end());
    for (int i = 0, m = attrs.size(); i < m - 1; ++i) {
        if (attrs[i] == attrs[i + 1]) {
            return true;
        }
    }
    return false;
}

// read tags, return whether any cases follow
bool readtags(vector<tag>& tags) {
    bool valid = true, ret = true;
    for (;;) {
        string str = tagcontent();
        if (str == "?xml version=\"1.0\"?") {
            break;
        } else if (str == "?end?") {
            ret = false;
            break;
        }
        // empty tag
        if (str.length() == 0) {
            valid = false;
        }
        tagtype type = begin;
        // end tag
        if (str[0] == '/') {
            type = end;
            str = str.substr(1);
        }
        // stand-alone tag
        if (str[str.length() - 1] == '/') {
            str = str.substr(0, str.length() - 1);
            type = standalone;
        }
        // parse tag name
        int pos = str.find_first_of(' ');
        string name = pos == string::npos ? str : str.substr(0, pos);
        str = str.substr(name.length());
        // check for duplicate attributes
        if (duplicate(str)) {
            valid = false;
        }
        tags.push_back(tag(name, type));
    }
    // clear invalid case
    if (!valid) {
        tags.clear();
    }
    return ret;
}

// validate list of tags
bool validtags(vector<tag>& tags) {
    // empty list
    if (tags.size() == 0) {
        return false;
    }
    if (tags.size() == 1 && tags[0].type == standalone) {
        return true;
    }
    // no document tag
    if (tags[0].type != begin ||
        tags[tags.size() - 1].type != end ||
        tags[0].name != tags[tags.size() - 1].name) {
        return false;
    }
    // stack of tags
    vector<string> stack;
    stack.push_back(tags[0].name);
    for (int i = 1, m = tags.size() - 1; i < m; ++i) {
        tag atag = tags[i];
        if (atag.type == begin) {
            for (int j = 0; j < stack.size(); ++j) {
                if (atag.name == stack[j]) {
                    return false;
                }
            }
            stack.push_back(atag.name);
        } else if (atag.type == end) {
            if (atag.name != stack[stack.size() - 1]) {
                return false;
            }
            stack.pop_back();
            if (stack.size() == 0) {
                return false;
            }
        }
    }
    return true;
}

bool run() {
    vector<tag> tags;
    bool ret = readtags(tags);
    if (validtags(tags)) {
        cout << "well-formed" << endl;
    } else {
        cout << "non well-formed" << endl;
    }
    return ret;
}

int main() {
    tagcontent();
    while (run());
    return 0;
}
