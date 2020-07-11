#include <iostream>
#include <stack>
using namespace std;

typedef struct _location {
	int x,y;
} LOCATION;

int main()
{
	int T,N;
	int height[102][102];
	bool flood[102][102];
	
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		int max_count = 0;
		int max_rain = 0;

		// input
		cin >> N;
		for (int i=1; i<=N; i++)
		for (int j=1; j<=N; j++)
		{
			cin >> height[i][j];
			max_rain = (height[i][j] > max_rain) ? height[i][j] : max_rain;
		}

		// process
		stack<LOCATION> st;

		// 비가 내림
		for (int rain=1; rain<max_rain; rain++)
		{
			int count = 0;
			
			// 재검을 위해서 flood[][] 초기화
			for (int i=0; i<=N+1; i++)
			for (int j=0; j<=N+1; j++)
			{
				// 테두리 또는 잠김
				if (i==0 || i==N+1 || j==0 || j==N+1 || height[i][j] <= rain)
					flood[i][j] = true;
				else
					flood[i][j] = false;
			}

			// 지역 순회
			for (int i=1; i<=N; i++)
			for (int j=1; j<=N; j++)
			{
				// 잠기지 않았으면
				if (flood[i][j] == false)
				{
					// 스택에 넣고
					LOCATION loc = {i, j};
					st.push(loc);
					flood[loc.x][loc.y] = true;

					// 스택이 빌 때까지 안전영역 넓히기
					while(st.empty() != true)
					{
						loc = st.top();
						st.pop();
						
						LOCATION sideLoc;
						if (flood[loc.x + 1][loc.y] == false)
						{
							sideLoc.x = loc.x + 1;
							sideLoc.y = loc.y;
							st.push(sideLoc);
							flood[sideLoc.x][sideLoc.y] = true;
						}
						if (flood[loc.x - 1][loc.y] == false)
						{
							sideLoc.x = loc.x - 1;
							sideLoc.y = loc.y;
							st.push(sideLoc);
							flood[sideLoc.x][sideLoc.y] = true;
						}
						if (flood[loc.x][loc.y + 1] == false)
						{
							sideLoc.x = loc.x;
							sideLoc.y = loc.y + 1;
							st.push(sideLoc);
							flood[sideLoc.x][sideLoc.y] = true;
						}
						if (flood[loc.x][loc.y - 1] == false)
						{
							sideLoc.x = loc.x;
							sideLoc.y = loc.y - 1;
							st.push(sideLoc);
							flood[sideLoc.x][sideLoc.y] = true;
						}
					}

					count++;
					max_count = (count > max_count) ? count : max_count;
				}
			}
		}
		
		cout << "#testcase" << t << endl;
		cout << max_count << endl;
	}
}
