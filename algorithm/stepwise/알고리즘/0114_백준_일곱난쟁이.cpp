#include <iostream>
using namespace std;

int list[10];
int pointer;
int sum;
int main()
{
	// input
	for (int i = 1 ; i < 10; i++)
		cin >> list[i];

	// sort
	int temp;
	for(int i = 9 ; i > 1; i--) {
		for(int j = 1 ; j < i; j++) {
			if(list[j] > list[j+1]) {
				temp = list[j+1];
				list[j+1] = list[j];
				list[j] = temp;
			}
		}
	}

	// process
	for (int i=9; i>1; i--) {
		for (int j=i-1; j>0; j--) {
			sum = 0;
			for (pointer=1; pointer<10; pointer++) {
				if (pointer != i && pointer != j)
					sum += list[pointer];
			}


			
			if (sum == 100) {
				// output
				for (pointer=1; pointer<10; pointer++) {
					if (pointer != i && pointer != j)
						cout << list[pointer] << endl;
				}
			
				return 0;
			}
		}
	}
}