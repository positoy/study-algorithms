/**
 * https://algospot.com/judge/problem/read/BOARDCOVER
 */

#include <iostream>
#include <cstdio>

int testcase,H,W,BOXSIZE,countWhite;
bool space[22][22] = {false};

void init() {
    for (int i=0; i<22; i++) for (int j=0; j<22; j++) space[i][j] = false;
    countWhite = 0;
}

bool fitable(int y, int x, int direction) {
    switch (direction)
    {
        case 0: return space[y][x] && space[y+1][x] && space[y+1][x+1];
        case 1: return space[y-1][x] && space[y][x] && space[y][x+1];
        case 2: return space[y-1][x-1] && space[y][x-1] && space[y][x];

        case 3: return space[y][x] && space[y][x-1] && space[y-1][x-1];
        case 4: return space[y][x+1] && space[y][x] && space[y+1][x];
        case 5: return space[y-1][x+1] && space[y-1][x] && space[y][x];

        case 6: return space[y][x] && space[y-1][x] && space[y-1][x-1];
        case 7: return space[y+1][x] && space[y][x] && space[y][x-1];
        case 8: return space[y+1][x+1] && space[y][x+1] && space[y][x];

        case 9: return space[y][x] && space[y][x+1] && space[y-1][x+1];
        case 10: return space[y][x-1] && space[y][x] && space[y-1][x];
        case 11: return space[y+1][x-1] && space[y+1][x] && space[y][x];
    }
    return false;
}

const bool spaceWhite = true;
const bool spaceBlack = false;
void fill(int y, int x, int direction, bool spaceColor)
{
    switch (direction)
    {
        case 0: space[y][x] = space[y+1][x] = space[y+1][x+1] = spaceColor; break;
        case 1: space[y-1][x] = space[y][x] = space[y][x+1] = spaceColor; break;
        case 2: space[y-1][x-1] = space[y][x-1] = space[y][x] = spaceColor; break;

        case 3: space[y][x] = space[y][x-1] = space[y-1][x-1] = spaceColor; break;
        case 4: space[y][x+1] = space[y][x] = space[y+1][x] = spaceColor; break;
        case 5: space[y-1][x+1] = space[y-1][x] = space[y][x] = spaceColor; break;

        case 6: space[y][x] = space[y-1][x] = space[y-1][x-1] = spaceColor; break;
        case 7: space[y+1][x] = space[y][x] = space[y][x-1] = spaceColor; break;
        case 8: space[y+1][x+1] = space[y][x+1] = space[y][x] = spaceColor; break;

        case 9: space[y][x] = space[y][x+1] = space[y-1][x+1] = spaceColor; break;
        case 10: space[y][x-1] = space[y][x] = space[y-1][x] = spaceColor; break;
        case 11: space[y+1][x-1] = space[y+1][x] = space[y][x] = spaceColor; break;
    }
}

int tryFill(int position, int countWhite)
{
    if (countWhite == 0)
        return 1;

    bool found = false;
    for (; !found && position <= BOXSIZE; position++)
        if (space[position/W+1][position%W]) {
            found = true;
            break;
        }

    int targetY = position/W+1;
    int targetX = position%W;
    // std::cout << "found" << targetY << "," << targetX << std::endl;

    if (targetY > H && targetX > W && countWhite != 0)
        return 0;

    int countFill = 0;
    for (int direction=0; direction<12; direction++) {
        if (fitable(targetY, targetX, direction)) {
            // std::cout << "fit " << targetY << "," << targetX << " direction " << direction << std::endl;
            fill(targetY, targetX, direction, spaceBlack);
            countFill += tryFill(position+1, countWhite - 3);
            fill(targetY, targetX, direction, spaceWhite);
        }
    }

    return countFill;
}

int main()
{
    // freopen("./boardcover.input", "r", stdin);
    std::cin >> testcase;
    for (int i=0; i<testcase; i++)
    {
        // input
        init();
        std::cin >> H >> W;
        BOXSIZE = H*W;
        char c;
        for (int i=1; i<=H; i++)
        for (int j=1; j<=W; j++)
        {
            std::cin >> c;
            if (c == '.') {
                space[i][j] = true;
                countWhite++;
            }
        }

        // process
        if (countWhite % 3 != 0)
            std::cout << 0 << std::endl;    
        else
            std::cout << tryFill(1,countWhite) << std::endl;
    }
}
