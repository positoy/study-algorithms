#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const char T[] = "ABCDEFGHIJASDFSFDSFHIJ";
const char P[] = "HIJ";

bool Tindex[100] = {false,};
unsigned long long TKeyIndex[100] = {0};

unsigned long long gPatternKey = 0;

void
arrangeTIndex() {
    const int stringLength = strlen(T);
    for (int i=0; i<stringLength; i++)
        Tindex[i] = T[i] - 'A';
    TKeyIndex[0] = gPatternKey;
    Tindex[0] = true;
}

unsigned long long
getPartKeyOfString(const char[] string, const int position, const int patternLength) {
    static bool TindexArranged = false;
    if (!TindexArranged) arrangeTIndex();

    if (Tindex[position]) return TKeyIndex[position];

    unsigned long long partKey = TKeyIndex[position-1];
    int multiplee = 1;
    for (int i=0; i<patternLength-1) {
        multiplee *= 2;
    }

    partKey -= (multiplee*(string[position-1]-'A'));
    partkey *=2;
    partKey += (string[position+stringLength-1]-'A');
    return partKey;
}

unsigned long long
getPatternKey(const char* pattern) {
    static unsigned long long patternKey = 0;
    static const int patternLength = strlen(pattern);

    if (patternKey) return patternKey;

    int multiplee = 1;
    for (int pickat=patternLength-1;pickat>=0;pickat--) {
        patternKey += (pattern[pickat] - 'A') * multiplee;
        multiplee *= 2;
    }

    gPatternKey = patternKey;
    return patternKey;
}

char*
getPartOfString(const int position, const char[] string, const int patternLength) {
    char* partOfString[100] = {0};
    int fillat = 0;
    for (fillat=0; fillat<patternLength; fillat++)
        partOfString[fillat] = string[fillat];
    partOfString[fillat] = '\0';
    return partOfString;
}

bool
patternKeyMatchPartKeyOfString(const char[] pattern, const char[] string, const int position) {
    if (getPatternKey(pattern) == getPartKeyOfString(string, position, patternLength)) return true;
    return false;
}

bool
isPatternIncludedInStringNTimes(const char* pattern, const char* string, int *n, int positionArr[]) {
    const int strLength = strlen(string);
    const int patternLength = strlen(pattern);
    unsigned long long patternKey = getPatternKey(pattern);

    int Ntimes = 0;
    for (int i=0; i<strLength-patternLength+1; i++) {
        if (patternKeyMatchPartKeyOfString(pattern, string, i) && 0 == strcmp(pattern, getPartOfString(i, string, patternLength))) {
            positionArr[Ntimes] = i;
            Ntimes++;
        }
    }

    *n = Ntimes;
    return true;
}

int main()
{
    int n = 0;
    int positionArr[100] = {0};
    if (isPatternIncludedInStringNTimes(P, T, &n, positionArr)) {
        std::cout << "pattern is included in the string " << n << " times." << std::endl;
        for (int i=0; i<n; i++) std::cout << "position : " << positionArr[i] << std::endl;
    } else {
        std::cout << "pattern is not included in the string." << std::endl;
    }
}
