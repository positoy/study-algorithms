#include <iostream>
#include <string>
using namespace std;

char arr[][7] = {
    {0,0,0,0,0,0,0},
    {0,'N','N','N','N','S', 0},
    {0,'N','E','E','E','N', 0},
    {0,'N','E','Y','E','N', 0},
    {0,'N','E','E','E','N', 0},
    {0,'N','N','N','N','N', 0},
    {0,0,0,0,0,0,0},
};

bool checked[7][7] = {
    {true, true, true, true, true, true, true},
    {true, false, false, false, false, false, true},
    {true, false, false, false, false, false, true},
    {true, false, false, false, false, false, true},
    {true, false, false, false, false, false, true},
    {true, false, false, false, false, false, true},
    {true, true, true, true, true, true, true},
};

int dy[8] ={-1,-1,-1,0,0,1,1,1};
int dx[8] = {-1,0,1,-1,1,-1,0,1};

bool inRange(int y, int x) {
    return (y < 6 && y > 0) && (x < 6 && x > 0);
}

bool hasWord1(int y, int x, std::string word) {
    static std::string currentWord;
    if (checked[y][x] == true) return false;
    if (arr[y][x] != word[currentWord.length()]) return false;

    if (currentWord.append(1,arr[y][x]).compare(word) == 0) return true;
    checked[y][x] = true;
    bool ret = hasWord1(y-1,x-1,word) || hasWord1(y-1,x,word) || hasWord1(y-1,x+1,word) ||
            hasWord1(y,x-1,word) || hasWord1(y,x+1,word) ||
            hasWord1(y+1,x-1,word) || hasWord1(y+1,x,word) || hasWord1(y+1,x+1,word);
    checked[y][x] = false;
    currentWord.pop_back();
    return ret;
}

bool hasWord(int y, int x, const std::string& word) {
    if (!inRange(y,x)) return false;
    if (arr[y][x] != word[0]) return false;
    if (word.length() == 1) return true;

    checked[y][x] = true;
    int nextY,nextX;
    for (int i=0; i<8; i++) {
        nextY = y + dy[i];
        nextX = x + dx[i];
        if (hasWord(nextY, nextX, word.substr(1)))
            return true;
    }
    checked[y][x] = false;
    return false;
}

int main()
{
    for (int i=1; i<=5; i++)
    for (int j=1; j<=5; j++) {
        if (hasWord(i,j, "YES")) {
            std::cout << "found at " << i << ',' << j << std::endl;
        }
    }
}
