/****************************************************
 * @author redragon
 * @date 2020/7/22
 * @brief medium
 * 直接使用next_permutation()解的
 ***************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string getPermutation(int n, int k)
{
    vector<int> arr(n);
    int i = 1;
    while (i <= n)
    {
        arr[i - 1] = i;
        i++;
    }
    i = 1;
    while (i < k && next_permutation(arr.begin(), arr.end()))
        i++;
    string ans;
    for (size_t i = 0; i < arr.size(); i++)
        ans += arr[i] + '0';
    return ans;
}

int main()
{
    cout << getPermutation(3, 3) << endl;
    return 0;
}