/********************************************************************************************
 * @author reddragon
 * @date 2020/10/31
 * @brief POJ 布尔表达式
 * 
 * 1. 递归
 * 其实没有太用到递归，递归的题解看了下，其实就是（）是一种表达式，|和&算一种，！算一种
 * 三个函数，然后（）内可能又|&，就是递归调用。
 * 
 * 我觉得不太像递归，实际还是按照优先级来的。
 * 
 * 所以我的思路是按照优先级来，一个函数专门处理括号，一个函数专门处理！
 * 最后一个函数处理没有()和！的表达式，那最后一个函数就是从前往后算一遍就行了。
 * 
 * 注意一些细节：比如！！！！！可能是多个连在一起的。
 * 
 * 时间复杂度：O(N)        空间复杂度：O(N)
 ********************************************************************************************/
#include <iostream>
#include <string>
#include <stack>
using std::string;
using std::stack;
using std::cout;
using std::cin;

// 调用这个函数之前需要确保没有(),没有！
bool boolExp(string s)
{
    // 递归基
    if(s.size() == 1)
    {
        if(s[0] == 'V')
            return true;
        else
            return false;
    }
    int pos = s.size() - 1;// 末尾元素
    // 处理:由于已经处理了所有括号，
    switch (s[pos])
    {
    case 'V':
    {
        if(s[pos - 1] == '|')
            return boolExp(string(s.begin(), s.end() - 2)) | true;// 前面是true，后面就不用算了
        else
            return boolExp(string(s.begin(), s.end() - 2)) & true;
        break;
    }
    case 'F':
    {
        if(s[pos - 1] == '|')
            return boolExp(string(s.begin(), s.end() - 2)) | false;
        else
            return boolExp(string(s.begin(), s.end() - 2)) & false;
        break;
    }
    default:
        cout << "格式错误" << std::endl;
        break;
    }
    return false;
}

// 去除！符号
string rm(string exp)
{
    string ans;
    // 去掉 '！'号
    for(size_t i = 0; i < exp.size(); ++i)
    {
        if(exp[i] == '!')
        {
            // 防止多个!!!!!!
            int count = 0;
            while(exp[i] == '!')
            {
                ++i;
                ++count;
            }
            if(count % 2 == 0)
            {
                ans.push_back(exp[i]);
                continue;
            }

            if(exp[i] == 'V')
                ans.push_back('F');
            else
                ans.push_back('V');
            continue;
        }
        ans.push_back(exp[i]);
    }
    return ans;
}

// 得到去除括号的表达式
string rmBracket(string s)
{
    stack<string> st;
    string ans;
    for(size_t i = 0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            st.push(ans);
            ans.clear();// 清空当前所有内容
            continue;
        }
        if(s[i] == ')')
        {
            char ch;
            ans = rm(ans);
            if(boolExp(ans))
                ch = 'V';
            else
                ch = 'F';
            ans = st.top();st.pop();
            ans.push_back(ch);
            continue;
        }
        ans.push_back(s[i]);
    }
    return ans;
}

int main()
{
    string s;
    int i = 1;
    while(getline(cin, s))
    {
        string exp;
        for(size_t i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ')
                continue;
            exp.push_back(s[i]);
        }
        exp = rmBracket(exp);// 去掉（）
        exp = rm(exp);// 去除！
        char ans = 'F';
        if(boolExp(exp))
            ans = 'V';
        cout << "Expression " << i << ": " << ans << std::endl;
        i++;
    }
    return 0;
}