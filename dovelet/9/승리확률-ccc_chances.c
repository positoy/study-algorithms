/**
 * 9계단 - 승리확률 - ccc-chances
 *
 */

#include <stdio.h>

int i;
int played[7] = {0};

int score[5] = {0};

int T,G,A,B,SA,SB;
int winningCount = 0;

int main()
{
	scanf("%d %d", &T, &G);
	for (i=0; i<G; i++)
	{
		scanf("%d %d %d %d", &A, &B, &SA, &SB);

		int result;

		if (SA > SB) {
			result = 1;
			score[A] += 3;

		} else if (SA < SB) {
			result = 2;
			score[B] += 3;

		} else {
			result = 3;
			score[A] += 1;
			score[B] += 1;

		}

		switch(10*A + B)
		{
			case 12: played[1] = result; break;
			case 13: played[2] = result; break;
			case 14: played[3] = result; break;
			case 23: played[4] = result; break;
			case 24: played[5] = result; break;
			case 34: played[6] = result; break;
		}
	}

	calcScore(1);
	printf("%d", winningCount);
}

int calcScore(int game)
{
	if (game == 7)
	{
		int loseTeam = 0;
		for (i=1; i<5; i++)
		{
			if (score[T] > score[i])
				loseTeam++;
		}

		if (loseTeam == 3)
			winningCount++;

		return;
	}

	int a,b;
	switch (game)
	{
		case 1: a=1, b=2; break;
		case 2: a=1, b=3; break;
		case 3: a=1, b=4; break;
		case 4: a=2, b=3; break;
		case 5: a=2, b=4; break;
		case 6: a=3, b=4; break;
	}

	int result = played[game];

	if (played[game] == 0)
	{
		// WIN
		score[a] += 3;
		calcScore(game + 1);
		score[a] -= 3;

		// LOSE
		calcScore(game + 1);

		// DRAW
		score[a] += 1;
		score[b] += 1;
		calcScore(game + 1);
		score[a] -= 1;
		score[b] -= 1;
	}
	else
	{
		calcScore(game + 1);
	}

}
