//zju 2104 Let the Balloon Rise

#include <iostream>
#include <cstring>
using namespace std;

char name[1000][16];
int num[1000];

int main()
{
	int n;
	while(1)
	{
		cin >> n;
		if(n == 0) break;
		char input[16];
		int i, index = 0;
		for(int t = 0; t < n; t ++)
		{
			cin >> input;
			for(i = 0; i < index; i ++){
				if(strcmp(name[i], input) == 0){
					num[i] ++;
					break;
				}
			}
			if(i == index){
				strcpy(name[i], input);
				num[i] = 1;
				index ++;
			}
		}
		int mark, max = 0;
		for(i = 0; i < index; i ++){
			if(num[i] > max){
				max = num[i];
				mark = i;
			}
		}
		cout << name[mark] << endl;
	}
	return 0;
}