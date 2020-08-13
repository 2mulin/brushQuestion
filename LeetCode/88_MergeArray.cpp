/*******************************************************************************
 * @author reddragon
 * @date 2020/8/11
 * @brief easy 有序数组合并
 * 最先想到的是归并排序的合并方法，但是需要用到O(N+M)的辅助空间
 * 然后发现这里的nums1的大小就是M+N，所以可以利用，只要从前往后，每次把最大的放到
 * nums1最后就可以了
 * 时间: O(M+N)     空间: O(1)
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int p1 = m - 1;
    int p2 = n - 1;
    int pos = m + n - 1;
    while(p1 >= 0 && p2 >= 0)
    {
        if(nums1[p1] > nums2[p2])
            nums1[pos--] = nums1[p1--];
        else
            nums1[pos--] = nums2[p2--];
    }
    while(p2 >= 0)
        nums1[pos--] = nums2[p2--];
    return;
}

// 最简单的思路，归并排序合并的思路。时间：O(N) 空间：O(N)
// void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
// {
//     vector<int> ans(m + n);
//     int p1 = 0;
//     int p2 = 0;
//     int i  = 0;
//     for (i = 0; p1 < m && p2 < n; i++)
//     {
//         if (nums1[p1] <= nums2[p2])
//             ans[i] = nums1[p1++];
//         else
//             ans[i] = nums2[p2++];
//     }
//     while(p1 < m)
//         ans[i++] = nums1[p1++];
//     while(p2 < n)
//         ans[i++] = nums2[p2++];
    
//     nums1 = ans;
//     return;
// }

int main()
{
    vector<int> nums1{1, 2, 3, 0, 0, 0};
    vector<int> nums2{2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    for(auto i : nums1)
        cout << i << '\t';
    return 0;
}