/**
 * @date 2025/1/5
 * @author 2mu
 * @brief medium 设计一个 ATM 机器
 *
 * 1. 模拟
 * 主要注意取钱的处理，必须是先取出大面值，并且能取多少，就去多少，但是又不能超过用户金额。
 *
 * 时间复杂度: O(nk)
 * 空间复杂度: O(k)
 *
 */

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class ATM
{
private:
    std::map<int, int> m_balance;
    std::vector<int> face_value_vct = {20, 50, 100, 200, 500};

public:
    ATM()
    {
        std::vector<int> vec{20, 50, 100, 200, 500};
        for (int val : vec)
        {
            m_balance[val] = 0;
        }
    }

    void deposit(vector<int> banknotesCount)
    {
        auto iter = m_balance.begin();
        for (int i = 0; i < banknotesCount.size(); ++i)
        {
            iter->second += banknotesCount[i];
            ++iter;
        }
    }

    vector<int> withdraw(int amount)
    {
        std::vector<int> result(5, 0);

        for (int i = result.size() - 1; i >= 0; --i)
        {
            int face_value = face_value_vct[i];

            // 大面值最多可以取几张
            int count = min(m_balance[face_value], amount / face_value);

            // 更新剩余需要取的钱
            amount -= face_value * count;
            result[i] = count;
        }
        if (amount > 0)
            return {-1};

        // 完整取完钱之后，再统一减去余额
        auto iter = m_balance.begin();
        for(int i = 0; i < result.size(); ++i)
        {
            iter->second -= result[i];
            ++iter;
        }
        return result;
    }
};

int main()
{
    ATM atm;
    std::vector<int> vct = {0,10,0,3,0};
    atm.deposit(vct);
    vct = atm.withdraw(500);

    for(auto val : vct)
        std::cout << val << '\t';
    return 0;
}
