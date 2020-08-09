/*****************************************************************************
 * @date 2020/6/29
 * @author reddragon
 * @description: 剑指offer 滑动窗口的最大值
 * 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，
 * 他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个：
 *  {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}，
 *  {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 * 
 * 首先队列必须是单调的，然后注意A<B && num[A] < num[B]的话，A就没有存在的意义了，
 * 因为B入队列了，说明B在区间内，输出肯定不会是比num[B]小的num[A]，只能是num[B]
 * 所以可以删除A。最后注意最大值总会出界，所以要判断什么时候删除最大值。i-dq.front == size
 * 单调队列还是挺有意思的。时间复杂度是O(n),空间复杂度：O(n)
 *****************************************************************************/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (num.empty() || size == 1)
        return num;
    vector<int> ans;
    if (num.size() < size || size == 0)
        return ans;
    deque<int> dq; //单调递减队列，最大的元素在front
    for (unsigned int i = 0; i < size; i++)
    {
        // 当前元素大于dq最小的元素，删除dq最小的元素
        while (!dq.empty() && num[i] > num[dq.back()])
            dq.pop_back();
        dq.push_back(i);
    }
    for (size_t i = size; i < num.size(); i++)
    {
        ans.push_back(num[dq.front()]);
        // 当前元素大于dq最小的元素，删除dq最小的元素
        while (!dq.empty() && num[i] > num[dq.back()])
            dq.pop_back();
        dq.push_back(i);
        // 如果front已经不在区间内，要pop
        if (i - dq.front() == size)
            dq.pop_front();
    }
    ans.push_back(num[dq.front()]);
    return ans;
}

/*****************************************************************
暴力法：时间复杂度是O(n*k)n是数组长度，k是区间个数
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    if(num.empty() || size == 1)
        return num;
    vector<int> ans;
    if(num.size() < size || size == 0)
        return ans;
    for(size_t i = 0; i <= num.size() - size; i++)
    {
        int max = num[i];
        for(int j = 1; j < size; j++)
        {
            if(num[i+j] > max)
                max = num[i + j];
        }
        ans.push_back(max);
    }
    return ans;
}
// 比暴力还蠢的方法都给我过了。。。。。时间复杂度是O(n*n*logn)
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
    if(num.empty() || size == 1)
        return num;
    vector<int> ans;
    auto head = num.begin(),tail = num.begin();
    for(int i = 0; i < size; i++)
        tail++;
    for(size_t i = size - 1; i < num.size(); i++)
    {
        vector<int> temp(head,tail);
        sort(temp.rbegin(),temp.rend());
        ans.push_back(temp[0]);
        head++;
        tail++;
    }
    return ans;
}
**********************************************************************/

int main()
{
    vector<int> num{2, 3, 4, 2, 6, 2, 5, 1};
    num = maxInWindows(num, 3);
    for (auto i : num)
        cout << i << '\t';
    return 0;
}
