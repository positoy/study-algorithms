/**
 * https://algospot.com/judge/problem/submit/CLOCKSYNC
 * 
 * 1번째풀이시에로사항 : 문제를 잘 읽자. 불가능할 경우 -1을 리턴하자.
 */


#include <iostream>

int clocks[16]={0};
bool switchLinked[10][16] = {
    {1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,0,0,0,1,0,1,0,1,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0,1,0,0,0,1,1},
    {1,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
    {1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,1},
    {0,0,0,0,1,1,0,1,0,0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,1,1,1,0,0,0,1,0,0,0,1,0,0}
};

int minPushCount, pushCount;

bool allIndicateTwelve() {
    bool ret = true;
    for (int i=0; i<16; i++) 
        ret = (ret && (clocks[i] == 0));
    return ret;
}

inline void bumpSwitch(int targetSwitch) {
    for (int j=0; j<16; j++) {
        if (switchLinked[targetSwitch][j])
          clocks[j] = (clocks[j]+1)%4;
    }
    pushCount++;
}

void generateSwitchBump(int targetSwitch) {
    if (targetSwitch == 10) {
        if (allIndicateTwelve()) {
            minPushCount = ((minPushCount < pushCount) ? minPushCount : pushCount);
        }
        return;
    }

    generateSwitchBump(targetSwitch+1);
    for (int i=0; i<3; i++) {
        bumpSwitch(targetSwitch);
        generateSwitchBump(targetSwitch+1);
    }
    // recover
    bumpSwitch(targetSwitch);
    pushCount -=4;
}

int main()
{ 
    // freopen("clocksync.input", "r", stdin);
    int testcase = -1;
    std::cin >> testcase;

    for (int t=0; t<testcase; t++) {
        minPushCount = 99999999;
        pushCount = 0;
        for (int i=0; i<16; i++) {
            std::cin >> clocks[i];
            clocks[i] = (clocks[i]/3)%4;
        }

        generateSwitchBump(0);
        std::cout << ((minPushCount == 99999999) ? -1 : minPushCount) << std::endl;
    }
}
