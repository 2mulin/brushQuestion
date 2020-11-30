/********************************************************************************************
 * @author reddragon
 * @date 2020/11/30
 * @brief 堆中的路径
 * 
 * 1. 建堆
 * 不是将一个数组改成堆，而是一个一个输入的时候，建立一个堆，所以先读取输入，而后改成堆
 * 答案不是一样的。
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> MyMakeHeap(int N)
{
    vector<int> heap;
    for(int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        heap.push_back(num);
        // 恢复堆(上滤)
        int pos = i;
        while(pos > 0)
        {
            int parent = (pos - 1)/2;
            if(heap[parent] > heap[pos])
            {
                swap(heap[parent], heap[pos]);
                pos = parent;
            }
            else
                break;
        }
    }
    return heap;
}

void heap_path(const vector<int>& heap,int pos)
{
    vector<int> ans;
    while(pos > 0)
    {
        ans.push_back(heap[pos]);
        pos = (pos - 1)/2;
    }
    ans.push_back(heap[0]);

    for(auto num = ans.begin(); num != ans.end() - 1; ++num)
        cout << *num << ' ';
    cout << *(ans.end() - 1) << endl;
}

int main()
{
    int N,M;
    while(cin >> N >> M)
    {
        vector<int> heap = MyMakeHeap(N);
        // make_heap(heap.begin(),heap.end(),greater<int>());
        
        for(int i = 0; i < M; ++i)
        {
            int num;
            cin >> num;
            heap_path(heap,num - 1);
        }
    }
    return 0;
}