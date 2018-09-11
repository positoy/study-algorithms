#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

bool allMatched(const int& numchildren, bool (&isChildMatched)[10]) {
    bool ret = true;
    for (int i=0; i<numchildren; i++)
        ret &= isChildMatched[i];
    return ret;
}

int howMany(const int& numchildren, bool (&isChildMatched)[10], vector<pair<int,int> >& friendPairs)
{
    if (allMatched(numchildren, isChildMatched))
        return 1;
    if (friendPairs.size() == 0)
        return 0;

    int ret = 0;
    pair<int,int> p = friendPairs.back();
    friendPairs.pop_back();

    if (!isChildMatched[p.first] && !isChildMatched[p.second]) {
        int ret = 0;
        isChildMatched[p.first] = isChildMatched[p.second] = true;
        ret += howMany(numchildren, isChildMatched, friendPairs);
        isChildMatched[p.first] = isChildMatched[p.second] = false;
        ret += howMany(numchildren, isChildMatched, friendPairs);
        friendPairs.push_back(p);
        return ret;
    }
    else {
        int ret = howMany(numchildren, isChildMatched, friendPairs);
        friendPairs.push_back(p);
        return ret;
    }
}

int main()
{
    freopen("./picnic.input", "r", stdin);

    int numcase, numchildren, numpairs;
    vector<pair<int,int> > friendPairs;

    cin >> numcase;
    for (int i=0; i<numcase; i++) {
        cin >> numchildren >> numpairs;
        for (int a,b,j=0; j<numpairs; j++) {
            cin >> a >> b;
            friendPairs.push_back(std::make_pair(a,b));
        }

        bool isChildMatched[10] = {false};
        cout << howMany(numchildren, isChildMatched, friendPairs) << endl;
        friendPairs.clear();

    }
}
