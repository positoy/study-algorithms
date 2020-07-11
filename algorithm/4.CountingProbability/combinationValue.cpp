#include <iostream>

class Combi {
public:
    Combi() : count() {}
    unsigned long long run(int x, int y) {
        count = 0;
        return logic(x, y);
    }
    inline void increaseCount() { count++; }
    int getCount() { return count; }
private:
    virtual unsigned long long logic(int x, int y) = 0;
    int count;
};

class RecursiveCombi : public Combi {
private:
    virtual unsigned long long logic(int x, int y) {
        increaseCount();
        if (y == 0 || x == y)
            return 1;
        return logic(x-1,y-1) + logic(x-1,y);
    }
};

class MemoizationCombi : public Combi {
public:
    MemoizationCombi() : memo{0} {
        for (int i=0; i<1024; i++)
            memo[i][0] = memo[i][i] = 1;
    }
private:
    unsigned long long memo[1024][1024];
    virtual unsigned long long logic(int x, int y) {
        unsigned long long &currentValue = memo[x][y];
        if (!currentValue)
        {
            increaseCount();
            unsigned long long left = logic(x-1,y-1);
            unsigned long long right = logic(x-1, y);
            currentValue = left + right;
        }
        return currentValue;
    }
};

class DynamicCombi : public Combi {
public:
    DynamicCombi() : memo{0} {
        for (int i=0; i<1024; i++)
        for (int j=0; j<1024; j++)
        {
            if (j > i)
                break;
            else if (i == 0 || j == 0 || i == j)
                memo[i][j] = 1;
            else
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j];
        }
    }
private:
    unsigned long long memo[1024][1024];
    virtual unsigned long long logic(int x, int y) {
        increaseCount();
        return memo[x][y];
    }
};

int main()
{
    int x,y;
    Combi *dcombi = new DynamicCombi();
    Combi *mcombi = new MemoizationCombi();
    Combi *rcombi = new RecursiveCombi();

    do {
        std::cout << "enter : ";
        std::cin >> x >> y;
        std::cout << dcombi->run(x,y) << '(' << dcombi->getCount() << ") / " << std::flush;
        std::cout << mcombi->run(x,y) << '(' << mcombi->getCount() << ") / " << std::flush;
        std::cout << rcombi->run(x,y) << '(' << rcombi->getCount() << ")" << std::endl; 
    } while(1);
}
