/********************************************************************************************
 * @author reddragon
 * @date 2021/1/14
 * @brief medium LRU算法实现
 * 
 * 1，哈希表 + 双向链表
 * 题目要求是get和put的操作都是O(1), get操作很容易想到是一个hashmap。然后由于要实现，
 * 优先级的变化，又要是O(1)复杂度，那么只有链表可以完成了
 * 
 * 时间复杂度：O(1)       空间复杂度：O(m)
 ********************************************************************************************/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;
class LRUCache
{
private:
    int ca;
    unordered_map<int, int> ma;
    list<int> key_ls; // 根据优先级保存key，优先级被删除的放在后面
public:
    LRUCache(int capacity)
        : ca(capacity),
          ma(unordered_map<int, int>()),
          key_ls(list<int>()) {}

    int get(int key)
    {
        if (ma.find(key) != ma.end())
        {
            key_ls.remove(key);
            key_ls.push_front(key);
            return ma[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        // 如果已经存在，就是更新value和优先级
        if (ma.find(key) != ma.end())
        {
            ma[key] = value;
            key_ls.remove(key);
            key_ls.push_front(key);
            return;
        }

        if (ma.size() < ca)
        {
            key_ls.push_front(key);
            ma.insert(pair<int, int>(key, value));
        }
        else
        { // 删除
            ma.erase(key_ls.back());
            key_ls.pop_back();
            ma.insert(pair<int, int>(key, value));
            key_ls.push_front(key);
        }
        return;
    }
};

int main()
{
    LRUCache LRU(3);
    LRU.put(1, 1);
    LRU.put(2, 2);
    LRU.get(1);
    LRU.put(3, 3);
    LRU.get(2);
    LRU.put(4, 4);
    LRU.get(1);
    LRU.get(3);
    LRU.get(4);
    return 0;
}