#include <iostream>
#include <vector>
using namespace std;

vector<int> plusOne(vector<int> &digits)
{
    int size = digits.size();
    bool isOver = false;
    for (int i = size - 1; i >= 0; i--)
    {
        if (digits[i] == 9)
            digits[i] = 0;
        else
        {
            digits[i]++;
            isOver = true;
            break;
        }
    }
    if (!isOver) // 需要增大数组
        digits.insert(digits.begin(), 1);
    return digits;
}

int main()
{
    return 0;
}