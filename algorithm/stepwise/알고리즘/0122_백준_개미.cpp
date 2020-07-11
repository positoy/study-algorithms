#include <iostream>
using namespace std;

typedef struct _speed {
	int x,y;
} SPEED;

struct _ant {
	int x,y, direction;
	SPEED speed;
} ant;

SPEED direction[4] = {
	{1,1},
	{1,-1},
	{-1,-1},
	{-1,1}
};

int main()
{
	int w,h,p,q,t;
	bool changed;
	cin >> w >> h >> p >> q >> t;

	ant.x = p;
	ant.y = q;
	ant.direction = 0;
	ant.speed.x = direction[ant.direction].x;
	ant.speed.y = direction[ant.direction].y;

	for (int i=0; i<t; i++) {
		// 각 방향에 대해 부딪힌 벽이 있으면 방향 재설정
		changed = false;
		switch (ant.direction) {
			case 0:
				if (ant.y == h)
					if (ant.x == w) ant.direction = 2;
					else ant.direction = 1;
				else if (ant.x == w)
					ant.direction = 3;


				if (ant.direction != 0) changed = true;
				break;

			case 1:
				if (ant.y == 0) 
					if (ant.x == w) ant.direction = 3;
					else ant.direction = 0;
				else if (ant.x == w)
					ant.direction = 2;
			
				if (ant.direction != 1) changed = true;
			break;

			case 2:
				if (ant.y == 0)
					if (ant.x == 0) ant.direction = 0;
					else ant.direction = 3;
				else if (ant.x == 0)
					ant.direction = 1;
			
				if (ant.direction != 2) changed = true;
			break;


			case 3:
				if (ant.y == h)
					if (ant.x == 0) ant.direction = 1;
					else ant.direction = 2;
				else if (ant.x == 0)
					ant.direction = 0;
			
				if (ant.direction != 3) changed = true;
			break;

		}

		if (changed) {
			ant.speed.x = direction[ant.direction].x;
			ant.speed.y = direction[ant.direction].y;
		}

		// 움직이고
		ant.x += ant.speed.x;
		ant.y += ant.speed.y;
		cout << '(' << ant.x << ',' << ant.y << ')' << endl;
	}

	cout << ant.x << ' ' << ant.y;
}
