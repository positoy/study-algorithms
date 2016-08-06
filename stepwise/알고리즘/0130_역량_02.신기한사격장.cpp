#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t=1; t<=T; t++)
	{
		int score[8][8] = {0};
		int score_now = 0;
		int score_max = 0;

		// input
		for (int i=1; i<=6; i++)
		for (int j=1; j<=6; j++)
		{
			cin >> score[i][j];
		}
		
		// process
		score_max = 0;
		for (int i=1; i<=6; i++)
		for (int j=1; j<=6; j++)
		{
			score_now = score[i][j] + score[i-1][j] + score[i+1][j] + score[i][j-1] + score[i][j+1];
			score_max = (score_now > score_max) ? score_now : score_max;
		}

		// output
		cout << "#testcase" << t << endl;
		cout << score_max << endl;
	}
}
