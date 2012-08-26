//ac

#include <iostream>
#include <vector>
using namespace std;

class song {
public:
  int id;
  double value;
  song(int mId, double mValue) : id(mId), value(mValue) {}
  bool operator<(const song& rhs) const {
    return value < rhs.value;
  }
};

int n, idx;

void run() {
  vector<song> mm;
  for (int i = 0; i < n; ++i) {
    double len, fre;
    cin >> idx >> len >> fre;
    mm.push_back(song(idx, len / fre));
  }
  sort(mm.begin(), mm.end());
  cin >> idx;
  cout << mm[idx - 1].id << endl;
}

int main() {
  while (cin >> n) {
    run();
  }
  return 0;
}
