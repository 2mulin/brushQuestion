/********************************************************************************************
 * @author reddragon
 * @date 2021/2/1
 * @brief medium 实现前缀树
 * 
 * 1.实现前缀树
 * 学习了一个新的数据结构，“ 前缀树 ”
 * 主要的目的是为了减少存饭具有相同前缀的字符串，所占用的内存。以及
 * 能够快速查找字符串是否存在的一种数据结构。
 * 
 * 时间复杂度：O(n)		空间复杂度：O(n)
 ********************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

class Trie {
private:
    Trie* next[26];
    int flag;// 单词标记
	
public:
    /** Initialize your data structure here. */
    Trie() {
        flag = 0;
        for(int i = 0; i < 26; ++i)
            next[i] = nullptr;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) 
	{
		auto it = word.begin();
		Trie* p = this;
		while(it != word.end())
		{
			int pos = *it - 'a';
			++it;
			// 需要判断这个char是否出现过
			if(p->next[pos] == nullptr)
				p->next[pos] = new Trie();
			p = p->next[pos];
		}
		p->flag += 1;// 单词结尾
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		auto it = word.begin();
		Trie* p = this;
		while(it != word.end())
		{
			int pos = *it - 'a';
			++it;
			if(p->next[pos] == nullptr)
				return false;
			p = p->next[pos];
		}
		// 判断是不是单词结尾
		if(p->flag == 0)
			return false;
		return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
		auto it = prefix.begin();
		Trie* p = this;
		while(it != prefix.end())
		{
			int pos = *it - 'a';
			++it;
			if(p->next[pos] == nullptr)
				return false;
			p = p->next[pos];
		}
		// 无需判断是否单词结尾
		return true;
    }
};

int main()
{
	Trie *trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple") << endl;   // 返回 true
	cout << trie->search("app") << endl;     // 返回 false
	cout << trie->startsWith("app") << endl; // 返回 true
	trie->insert("app");   
	cout << trie->search("app") << endl;     // 返回 true
    return 0;
}