#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
	ifstream input(argv[1]);
    
	int n;
	input >> n;
    
	for (int i = 1; i <= n; ++i) {
		if (i % 15 == 0) cout << "Hop" << endl;
		else if (i % 3 == 0) cout << "Hoppity" << endl;
		else if (i % 5 == 0) cout << "Hophop" << endl;
	}
    
	return 0;
}
