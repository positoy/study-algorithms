#include <iostream>

int matrixNum;
int matrixItems[1024] = {0};
int matrixCost[1024][1024] = {0};
//20 1 30 10 10
void init() {
    for (int i=0; i<1024; i++)
    for (int j=0; j<1024; j++)
    {
        matrixCost[i][j] = 0x9999999;
    }
    
}
int minCost(int i, int j)
{
    if (j-i < 2)
        return 0;
    
    int &minValue = matrixCost[i][j];
    int newValue;
    for (int k=i+1; k<j; k++) {
        std::cout << "before: " << minValue << '.' << newValue << std::endl;
        newValue = minCost(i,k-1) + minCost(k+1,j) + matrixItems[k-1]*matrixItems[k]*matrixItems[k+1];
        minValue = newValue < minValue ? newValue : minValue;
        std::cout << "after: " << minValue << '.' << newValue << std::endl;
    }
    return minValue;
}

int main()
{
    std::cin >> matrixNum;
    for (int i=0; i<matrixNum+1; i++)
        std::cin >> matrixItems[i];
    std::cout << "minimum cost: " << minCost(0,matrixNum) << std::endl;
}
