/**
 * ZOJ 2247 Magic Trick
 *
 * 2005/05/08 By adai
 */

#include <iostream>
using namespace std;

#define for if(0); else for

char value[14] = "123456789TJQK";
char suit[5] = "HCDS";
int a[3], num[3];

char card[4][3];

void Run() {
  for (int i = 0; i < 4; ++i) cin >> card[i];
  for (int i = 1; i < 4; ++i) {
    int tmp = 0;
    for (int j = 0; j < 4; ++j) {
      if (suit[j] == card[i][1]) {
				tmp = j * 100;
				break;
      }
    }
    for (int j = 0; j < 13; ++j) {
      if (value[j] == card[i][0]) {
				tmp += j;
				break;
      }
    }
    num[i - 1] = tmp;
  }
  int m1, m2, m3;
  m1 = m3 = 0;
  for (int i = 1; i < 3; ++i) {
    if (num[i] < num[m1]) {
      m1 = i;
    }
    if (num[i] > num[m3]) {
      m3 = i;
    }
  }
  m2 = 3 - m1 - m3;
  a[m1] = 0, a[m2] = 1, a[m3] = 2;
  int mm;
  if (a[0] == 0) mm = 1;
  else if (a[0] == 1) mm = 3;
  else mm = 5;
  if (a[1] > a[2]) ++mm;
  int index;
  for (index = 0; index < 13; ++index) {
    if (value[index] == card[0][0]) break;
  }
  index = (index + mm) % 13;
  cout << value[index] << card[0][1] << endl;
}

int main() {
  int kase;
  cin >> kase;
  while (kase--) {
    Run();
  }
  return 0;
}

