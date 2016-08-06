#include <iostream>
#include <vector>
using namespace std;

vector<int> pocket;
int T,N;
int GP, GC, GF;
int food[21][3];
bool fit;

inline void put(int target)
{
	if (target == N+1)
	{
		int size, sum;
		size = pocket.size();
		
		// 단백질
		sum = 0;
		for (int i=0; i<size; i++)
			sum += food[pocket[i]][0];

		if (sum == GP)
		{
			// 탄수화물
			sum = 0;
			for (int i=0; i<size; i++)
				sum += food[pocket[i]][1];

			if (sum == GC)
			{
				// 탄수화물
				sum = 0;
				for (int i=0; i<size; i++)
					sum += food[pocket[i]][2];

				if (sum == GF)
					fit = true;
			}
		}
	}
	else
	{
		pocket.push_back(target);
		put(target+1);

		pocket.pop_back();
		put(target+1);
	}
}

int main()
{
	cin >> T;

	for (int i=1; i<=T; i++)
	{
		cin >> GP >> GC >> GF;
		cin >> N;

		for (int j=1; j<=N; j++)
			cin >> food[j][0] >> food[j][1] >> food[j][2];

		fit = false;
		put(1);

		cout << "#testcase" << i << endl;
		if (fit)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}
