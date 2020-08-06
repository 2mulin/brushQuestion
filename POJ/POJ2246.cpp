#include <iostream>
#include <stack>
using namespace std;

class Matrix
{
private:
    int row;
    int col;

public:
    Matrix() = default;
    Matrix(int x, int y)
    {
        init(x, y);
    }
    void init(int x, int y)
    {
        row = x;
        col = y;
    }
    inline int getRow() const
    {
        return row;
    }
    inline int getCol() const
    {
        return col;
    }
    ~Matrix() = default;
};

int main()
{
    int n;
    cin >> n;
    Matrix *arr = new Matrix[n];
    for (int i = 0; i < n; i++)
    {
        char ch;
        int row, col;
        cin >> ch >> row >> col;
        arr[i].init(row, col);
    }
    // 读取多余的换行符

    string str;
    // 模拟
    while (cin >> str)
    {
        bool flag = true; // 是否可以运算
        long long ans = 0;
        stack<char> optr;
        stack<Matrix> oped;
        for (int i = 0; i < str.size(); i++)
        {
            // 操作数
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                oped.push(arr[str[i] - 'A']);
            }
            // 操作符
            else
            {
                if (str[i] == '(')
                {
                    optr.push(str[i]);
                }
                else if (str[i] == ')')
                {
                    // 运算操作数栈顶两个数
                    Matrix m1 = oped.top();
                    oped.pop();
                    Matrix m2 = oped.top();
                    oped.pop();
                    // 出一个左括号
                    optr.pop();
                    if (m2.getCol() != m1.getRow())
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        ans += m2.getCol() * m2.getRow() * m1.getCol();
                        oped.push(Matrix(m2.getRow(), m1.getCol()));
                    }
                }
                else
                {
                    optr.pop();
                }
            }
        }
        if (flag)
        {
            cout << ans << endl;
        }
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}