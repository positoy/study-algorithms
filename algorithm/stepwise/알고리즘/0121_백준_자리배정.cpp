#include <iostream>
using namespace std;

#define UP		1
#define RIGHT	2
#define DOWN	3
#define LEFT	4

bool occupy[1100][1100];
int main()
{
	int C,R,K;
	cin >> C >> R >> K;

	for (int i=0; i<=C+1; i++) {
		occupy[i][0] = true;
		occupy[i][R+1] = true;
	}
	for (int i=1; i<=R; i++) {
		occupy[0][i] = true;
		occupy[C+1][i] = true;
	}

	int x,y,direction;
	x=y=1;
	occupy[1][1] = true;
	direction = UP;

	// 앉을 수 없는 경우
	if (K > C*R) {
		cout << 0;

	} else {

		for (int i=1; i<K; i++) {

			switch (direction) {
				case UP:
					y++;
					if (occupy[x][y] == true) {
						y--;
						x++;
						direction = RIGHT;
					}
					occupy[x][y] = true;
					break;

				case RIGHT:
					x++;
					if (occupy[x][y] == true) {
						x--;
						y--;
						direction = DOWN;
					}
					occupy[x][y] = true;
					break;

				case DOWN:
					y--;
					if (occupy[x][y] == true) {
						y++;
						x--;
						direction = LEFT;
					}
					occupy[x][y] = true;
					break;

				case LEFT:
					x--;
					if (occupy[x][y] == true) {
						x++;
						y++;
						direction = UP;
					}
					occupy[x][y] = true;
					break;
			}
		}

		cout << x << ' ' << y;
	}

}
