#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main()
{
    map<string, int> wordmap;
    // 正确插入姿势
    wordmap.insert(pair<string, int>("hello", 1));
    wordmap.insert(pair<string, int>("wrold", 1));
    // 正确创建键值对姿势
    map<string, int>::iterator i = wordmap.find("hello");
    if (i != wordmap.end())
        i->second++;
    else
        wordmap.insert(pair<string, int>("hello", 1));
    for (auto i : wordmap)
        cout << i.first << '\t' << i.second << endl;
    return 0;
}