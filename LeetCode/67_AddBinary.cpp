#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    string s;
    int i = a.length() - 1, j = b.length() - 1;
    int bit = 0; // bit是进位
    while (i >= 0 || j >= 0)
    {
        if (i >= 0)
            bit += a[i] - '0';
        if (j >= 0)
            bit += b[j] - '0';
        if (bit == 3)
        {
            s.insert(s.begin(), '1');
            bit = 1;
        }
        else if (bit == 2)
        {
            s.insert(s.begin(), '0');
            bit = 1;
        }
        else if (bit == 1)
        {
            s.insert(s.begin(), '1');
            bit = 0;
        }
        else
            s.insert(s.begin(), '0');
        i--;
        j--;
    }
    if (bit == 1)
        s.insert(s.begin(), '1');
    return s;
}

int main()
{
    cout << addBinary("1010", "1011");
}