/********************************************************************************************
 * @author reddragon
 * @date 2020/11/23
 * @brief 一元多项式的乘法和加法运算
 * 
 * 1.数组实现
 * 数组实现也不简单，因为格式的原因，都是细节上的东西。
 * 每个exp类的对象表示一个多项式，exp的arr[i]表示指数为i的项的系数
 * 2.链表实现
 * 没写
 * 时间复杂度：O(MAX*MAX)         空间复杂度：O(MAX)
 ********************************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 2000001;// 指数和系数最大值

class exp
{
private:
    vector<int> arr;
    int _size;// 表示多项式有几项
public:
    exp();
    exp(const exp&) = default;// 拷贝构造函数
    ~exp() = default;
    void print()const;
    void read(int n);
    int size()const
    {return _size;}
    // 加法和减法伴随着size的改变
    void resize(int n)
    {_size = n;}
    int& operator[](int n);// 接收指数，返回系数
    int operator[](int n)const;// const版本

    // 实现加法和乘法
    exp operator+(const exp& b)const;
    exp operator*(const exp& b)const;
};

exp::exp()
    :arr(vector<int>(MAX, 0)), _size(0)
{}
int& exp::operator[](int n)
{
    if(n < 0)
        return arr[abs(n)];
    else if(n == 0)
        return arr[0];
    else
        return arr[n + MAX/2];
}
int exp::operator[](int n)const
{
    if(n < 0)
        return arr[abs(n)];
    else if(n == 0)
        return arr[0];
    else
        return arr[n + MAX/2];
}
void exp::read(int n)
{
    for(int i = 0; i < n; ++i)
    {
        int a,b;// 系数和指数
        cin >> a >> b;
        (*this)[b] = a;
        ++_size;
    }
}
void exp::print()const
{
    int count = _size;
    if(count == 0)
    {
        cout << 0 << ' ' << 0;
        return;
    }
    for(int i = MAX/2; i >= 0 - MAX/2; --i)
    {
        if((*this)[i])
        {
            cout << (*this)[i] << ' ' << i;
            if(--count)
                cout << ' ';
            else
                break;
        }
    }
}

// 加法实现
exp exp::operator+(const exp& b)const
{
    exp res(*this);
    for(int i = 0 - MAX/2; i <= MAX/2; ++i)
    {
        if(b[i])
        {
            if(res[i] == 0)
                res.resize(res.size() + 1);
            res[i] = res[i] + b[i];
            if(res[i] == 0)
                res.resize(res.size() - 1);
        }
    }
    return res;
}

exp exp::operator*(const exp& b)const
{
    exp ans;
    for(int i = 0 - MAX/2; i <= MAX/2; ++i)
    {
        if((*this)[i])
        {
            exp temp;
            for(int j = 0 - MAX/2; j <= MAX/2; ++j)
            {
                if(b[j])
                {
                    if(temp[i + j] == 0)
                        temp.resize(temp.size() + 1);
                    temp[i + j] += (*this)[i] * b[j];
                    if(temp[i + j] == 0)
                        temp.resize(temp.size() - 1);
                }
            }
            ans = ans + temp;
        }
    }
    return ans;
}

int main()
{
    exp e1,e2;
    int n;
    cin >> n;
    e1.read(n);
    cin >> n;
    e2.read(n);

    // 运算
    exp e3 = e1 + e2;
    exp e4 = e1 * e2;
    e4.print();
    cout << endl;
    e3.print();
    cout << endl;
    return 0;
}