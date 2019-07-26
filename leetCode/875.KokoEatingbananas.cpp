#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

class Solution {
private:
    vector<int> gPiles;
    int gH;

public:
    int binsearch(int lowSpeed, int highSpeed) {

        if (lowSpeed > highSpeed) return -1;
        int nowSpeed = (lowSpeed + highSpeed) / 2;

        int nowH = 0;
        for (auto ps : gPiles)
            nowH += ((ps/nowSpeed) + (ps%nowSpeed ? 1 : 0));

        int possibleSpeed = -1;
        if (nowH < gH) {
            possibleSpeed = binsearch(lowSpeed, nowSpeed-1);
            return (possibleSpeed != -1 ? possibleSpeed : nowSpeed);

        } else if (nowH > gH) {
            possibleSpeed = binsearch(nowSpeed+1, highSpeed);
            return (possibleSpeed != -1 ? possibleSpeed : -1);

        } else {
            int retSpeed = -1;
            if (lowSpeed == highSpeed) return nowSpeed;

            possibleSpeed = binsearch(lowSpeed, nowSpeed-1);
            if (possibleSpeed == -1) retSpeed = nowSpeed;
            else if (possibleSpeed < nowSpeed) retSpeed = possibleSpeed;

            return retSpeed;
        }
    }

    int minEatingSpeed(vector<int>& piles, int H) {
        gPiles = piles, gH = H;
        int pileLength=-1, pileMin=1500000000, pileMax=0;

        pileLength = piles.size();
        for (auto ps : piles) {
            if (ps < pileMin) pileMin = ps;
            if (ps > pileMax) pileMax = ps;
        }

        if (H == pileLength) return pileMax;
        
        return binsearch(1, pileMax-1);
    }
};

/***
Input: piles = [3,6,7,11], H = 8
Output: 4
Example 2:

Input: piles = [30,11,23,4,20], H = 5
Output: 30
Example 3:

Input: piles = [30,11,23,4,20], H = 6
Output: 23
 */
int main()
{
    //     vector<int> tc = {122890061, 438301112, 257983174, 614414075, 602060597, 391389864, 140358431, 117439906, 992360201, 246252220};
    // int H = 33212669;
    // vector<int> tc = {3,6,7,11};
    // int H = 8;
    // // vector<int> tc = {30,11,23,4,20};
    // // int H = 5;
    // vector<int> tc = {30,11,23,4,20};
    // int H = 6;
    vector<int> tc = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
    int H = 823855818;

    // int speed = 118;
    // int time = 0;
    // for (auto t : tc)
    //     time += ((t/speed) + ((t%speed) ? 1 : 0));
    // std::cout << time << std:: endl;

    Solution s;
    std::cout << s.minEatingSpeed(tc, H) << std::endl;



}
