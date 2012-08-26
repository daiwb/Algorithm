/*
 * ZJU 1667 Die Game
 * 00:00.01 836k
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num;
	while (cin >> num && num)
	{
		int face[3] = {1, 2, 3};	//represent top, north, west
		int tmp[3];
		char cmd[10];
		while (num--)
		{
			cin >> cmd;
			if (cmd[0] == 'e') {
				tmp[0] = face[2];
				tmp[1] = face[1];
				tmp[2] = 7 - face[0];
				memcpy(face, tmp, sizeof(tmp));
			}
			else if (cmd[0] == 's') {
				tmp[0] = face[1];
				tmp[1] = 7 - face[0];
				tmp[2] = face[2];
				memcpy(face, tmp, sizeof(tmp));
			}
			else if (cmd[0] == 'w') {
				tmp[0] = 7 - face[2];
				tmp[1] = face[1];
				tmp[2] = face[0];
				memcpy(face, tmp, sizeof(tmp));
			}
			else {
				tmp[0] = 7 - face[1];
				tmp[1] = face[0];
				tmp[2] = face[2];
				memcpy(face, tmp, sizeof(tmp));
			}
		}
		cout << face[0] << endl;
	}
	return 0;
}
