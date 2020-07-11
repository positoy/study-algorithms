#include <iostream>
#include <string>
using namespace std;

static string jokbo[10] =
{
	"**** ** ** ****",
	"  *  *  *  *  *",
	"***  *****  ***",
	"***  ****  ****",
	"* ** ****  *  *",
	"****  ***  ****",
	"****  **** ****",
	"***  *  *  *  *",
	"**** ***** ****",
	"**** ****  ****"
};

string code[6];
string eachCode;

inline string extract(int parseIndex)
{	
	string component[6];
	
	for (int i = 1; i <= 5; i++) {
		component[i] = code[i].substr(parseIndex, 3);

		// 모자란 만큼 채우기
		int diff = 3 - component[i].length();
		switch (diff) {
		case 1:
			component[i] = component[i] + " ";
			break;
		case 2:
			component[i] = component[i] + "  ";
			break;
		}
	}

	// 컴포넌트 합쳐서 코드 만들기
	string eachcode = component[0] + component[1] + component[2] + component[3] + component[4] + component[5];
	
	return eachcode; 
}

inline int getNumber(string eachCode)
{
	// 코드 찾기
	if (eachCode == jokbo[0]) return 0;
	else if (eachCode == jokbo[1]) return 1;
	else if (eachCode == jokbo[2]) return 2;
	else if (eachCode == jokbo[3]) return 3;
	else if (eachCode == jokbo[4]) return 4;
	else if (eachCode == jokbo[5]) return 5;
	else if (eachCode == jokbo[6]) return 6;
	else if (eachCode == jokbo[7]) return 7;
	else if (eachCode == jokbo[8]) return 8;
	else if (eachCode == jokbo[9]) return 9;
	else return -1;
}

int main()
{
	int targetNumber = 0;
	getline(cin, code[1]);
	getline(cin, code[2]);
	getline(cin, code[3]);
	getline(cin, code[4]);
	getline(cin, code[5]);

	// 프레임 확인 & loop 시작
	for (int i = 0; i < 8; i++) {

		int parseIndex = 4 * i;
		if (code[1].length() > parseIndex &&
			code[2].length() > parseIndex &&
			code[3].length() > parseIndex &&
			code[4].length() > parseIndex &&
			code[5].length() > parseIndex) {

			// 추출
			eachCode = extract(parseIndex);

			// 코드 숫자 찾기
			int num = -1;
			if ((num = getNumber(eachCode)) == -1) {
				// 코드에 숫자 아닌 것 포함
				cout << "BOOM!!";
				return 0;
			}
			else {
				// 곱하기 10
				targetNumber *= 10;

				// 삽입
				targetNumber += num;
			}
		}
		else {
			break;
		}
	}

	// loop 끝 & 6의 배수인지 판정
	if (targetNumber % 6 == 0)
		cout << "BEER!!";
	else
		cout << "BOOM!!";
}
