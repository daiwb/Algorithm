/*
 * zju 2212 Argus
 * 00:00.12 568k
 * Heap Sort
 * 2004.11.18 by adai
 */

#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

#ifdef WIN32
#define for if(0); else for
#endif

class mm {
public:
	int num;
	int time;
	mm() {}
	mm(int n_num, int n_time) {
		num = n_num;
		time = n_time;
	}
	mm &operator = (const mm &cc){
		num = cc.num;
		time = cc.time;
		return *this;
	}
};

int cmp(const void *t1, const void *t2) {
	mm *a, *b; 
	a = (mm *)t1;
	b = (mm *)t2;
	if ((*a).time > (*b).time) return 1;
	if ((*a).time < (*b).time) return -1;
	return (*a).num - (*b).num;
} 

int cmp(mm a, mm b) {
	if (a.time > b.time) return 1;
	if (a.time < b.time) return -1;
	return a.num - b.num;
} 

int num[3000], period[3000];
mm v[10001];

int main() {
	int index = 0;
	for (index = 0; ; index ++) {
		char temp[10];
		scanf("%s", temp);
		if (strcmp(temp, "#") == 0) break;
		scanf("%d %d", &num[index], &period[index]);
	}

	int k;
	scanf("%d", &k);

	v[0] = mm(0, 0);
	int number = 0;		//current number of elements in array
	for (int i = 0; i < index; i ++) {
		int t_num = num[i], t_time;
		for (int j = 1; ; j ++) {
			t_time = period[i] * j;
			if (number < k) {
				number ++;
				v[number] = mm(t_num, t_time);
				mm rc = v[number];
				int s = number;
				for (int ii = number / 2; ii > 0; ii /= 2) {
					if (cmp(rc, v[ii]) > 0) v[s] = v[ii];
					else break;
					s = ii;
				}
				v[s] = rc;
			}
			else {
				mm temp(t_num, t_time);
				if (cmp(temp, v[1]) > 0) break;
				else {
					v[1] = temp;
					int s = 1;
					mm rc = v[1];
					for (int ii = s * 2; ii <= number; ii *= 2) {
						if (ii < number && (cmp(v[ii], v[ii + 1]) < 0)) ii ++;
						if (cmp(rc, v[ii]) > 0) break;
						else v[s] = v[ii];
						s = ii;
					}
					v[s] = rc;
				}
			}
		}
	}
	
	qsort(v, number + 1, sizeof(v[0]), cmp);
	for (int i = 1; i <= number; i ++) printf("%d\n", v[i].num);

	return 0;
}

/*
 * Priority Queue
*/

/*
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

#define for if(0); else for

class query {
public:
  int num;
  int t;
  query(int n1, int t1) : num(n1), t(t1) {}
  bool operator<(const query& rhs) const {
    if (t != rhs.t) return t < rhs.t;
    return num < rhs.num;
  }
};

int main() {
  vector<int> num, inteval;
  int cnt = 0;
  while (1) {
    char str[100];
    scanf("%s", str);
    if (strcmp(str, "#") == 0) break;
    int a, b;
    scanf("%d %d", &a, &b);
    num.push_back(a), inteval.push_back(b);
    ++cnt;
  }
  int k;
  scanf("%d", &k);
  priority_queue<query> mm;
  for (int i = 0; i < cnt; ++i) {
    if (i == 0) {
      for (int j = 1; j <= k; ++j) {
	mm.push(query(num[i], inteval[i] * j));
      }
    } else {
      for (int j = 1; j <= k; ++j) {
	query tmp(num[i], inteval[i] * j);
	if (mm.top() < tmp) {
	  break;
	} else {
	  mm.pop();
	  mm.push(tmp);
	}
      }
    }
  }
  deque<int> out;
  while (!mm.empty()) {
    query tmp = mm.top();
    out.push_front(tmp.num);
    mm.pop();
  }
  for (int i = 0; i < k; ++i) {
    printf("%d\n", out[i]);
  }
  return 0;
}

*/