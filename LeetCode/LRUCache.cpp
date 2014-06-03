#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>
#include <cstring>
#include <unordered_map>
#include <list>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,c) for(typeof((c).begin())it=(c).begin();it!=(c).end();++it)
#define CLR(x) memset((x),0,sizeof((x)))
#define MP make_pair
#define MPI make_pair<int, int>
#define PB push_back
typedef long long LL;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PI;

class LRUCache{
public:
    struct CacheEntry
    {
    public:
        int key;
        int value;
        CacheEntry(int k, int v) :key(k), value(v) {}
    };

    unordered_map<int, list<CacheEntry>::iterator> m_map;
    list<CacheEntry> m_LRU_cache;
    int m_capacity;

    LRUCache(int capacity) {
        m_capacity = capacity;
    }

    int get(int key) {
        if (m_map.find(key) == m_map.end()) return -1;
        MoveToHead(key);
        return m_map[key]->value;
    }

    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()) {
            CacheEntry newItem(key, value);
            if (m_LRU_cache.size() >= m_capacity)
            {
                m_map.erase(m_LRU_cache.back().key);
                m_LRU_cache.pop_back();                
            }
            
            m_LRU_cache.push_front(newItem);
            m_map[key] = m_LRU_cache.begin();
            return;
        }
        
        m_map[key]->value = value;
        MoveToHead(key);
    }

    void MoveToHead(int key) 
    {
        auto updateEntry = *m_map[key];
        m_LRU_cache.erase(m_map[key]);
        m_LRU_cache.push_front(updateEntry);
        m_map[key] = m_LRU_cache.begin();
    }
};

int main() {
    return 0;
}
