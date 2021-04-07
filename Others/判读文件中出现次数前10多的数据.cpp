/********************************************************************************************
 * @author reddragon
 * @date 2021/4/7
 * @brief 判断文件中出现次数前10多的数据
 * 
 * 这里是判断出现次数前10多的string.
 * 
 * 没想到笔试会考这种题目. 
 * 后面还有一题限制了内容和磁盘空间, 估计是要使用多线程求解.
 ********************************************************************************************/
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void down(vector<string>& strArr, vector<int>& count, int idx)
{
    int sz = count.size();
    while(idx*2+1 < sz)
    {
        int left = 2*idx + 1;
        int right = 2*idx + 2;
        int maxIdx = idx;
        if(count[maxIdx] < count[left])
            maxIdx = left;
        if(right < sz && count[maxIdx] < count[right])
            maxIdx = right;
        if(maxIdx == idx)
            return;
        swap(strArr[idx], strArr[maxIdx]);
        swap(count[idx], count[maxIdx]);
        idx = maxIdx;
    }
}

int main()
{
    string path = "test.txt";
    ifstream fin(path);
    unordered_map<string, int> ma;
    string str;
    vector<int> count;
    vector<string> strArr;
    while(fin >> str)
    {
        auto item = ma.find(str);
        if(item != ma.end())
        {
            ++count[item->second];
        }
        else
        {
            strArr.push_back(str);
            count.push_back(1);
            ma.insert(pair<string, int>(str, count.size() - 1));
        }
    }
    fin.close();
    // 堆排序
    int idx = count.size() / 2 + 1;
    while(idx >= 0)
    {
        down(strArr, count, idx);
        --idx;
    }
    for(int i = 0; i < 10; ++i)
    {
        cout << strArr[0] << " 出现次数为: " << count[0] << endl;
        int sz = count.size();
        swap(strArr[0], strArr[sz - 1]);
        swap(count[0], count[sz - 1]);
        strArr.pop_back();
        count.pop_back();
        down(strArr, count, 0);
    }
    return 0;
}