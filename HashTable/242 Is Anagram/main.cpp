//
//  main.cpp
//  242 Is Anagram
//
//  Created by 刘亚东 on 2024/5/23.
//

// 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

// 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。

#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // 异位词等价于【两个字符串排序后相等】
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        
        return s == t;
    }
};

class Solution2 {
public:
    bool isAnagram(string s, string t) {
        // 数组就是一个简单的哈希表，定义大小为26的数组
        // 因为字符a到字符z的ASCII也是26个连续的数值
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++) {
            // 不需要记住字符 a 的 ASCII，只要求出一个相对数值就可以了
            record[s[i] - 'a']++;
        }
        
        for (int i = 0; i < t.size(); i++) {
            record[t[i] - 'a']--;
        }
        
        // 如果 record 数组中的元素都为0，则代表两个字符串是异位词
        for (int i = 0; i < 26; i++) {
            if (record[i] != 0) {
                return false;
            }
        }
        
        return true;
    }
};

/// 处理 Unicode 字符串的异位词检查，需要考虑到 Unicode 字符集中的字符远不止 26 个英文字母，并且它们的编码也不是连续的。
/// 因此，不能简单地使用一个大小为 26 的数组来作为哈希表。相反，我们需要使用一个能够容纳更广泛字符的哈希表结构，比如 std::map 或 std::unordered_map
///

class Solution3 {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> charCount;
        
        // 计算第一个字符串中每个字符的计数
        for (char c : s) {
            charCount[c]++;
        }
        
        // 检查第二个字符串是否满足异位词条件
        for (char c : t) {
            // 如果字符不在 map 中或计数为负，不是异位词
            if (charCount.find(c) == charCount.end() || charCount[c] < 1) {
                return false;
            }
            
            charCount[c]--;
        }
        
        // 如果 map 中所有的计数都为 0，则两个字符串是异位词
        // const auto &pair 是一种在循环中遍历 std::pair 对象的方式，通常用在遍历 std::map、std::unordered_map 或其他关联容器时
        // const：表示这个 pair 对象是常量，不能在循环中被修改。
        // auto：是 C++11 引入的类型推导关键字，它让编译器自动推断变量的类型。在这里，它将根据容器中的元素类型来推断 pair 的确切类型。
        // &：表示我们正在引用元素，而不是复制元素。这可以提高效率，因为我们不需要为循环中的每个元素创建副本。
        for (const auto &pair : charCount) {
            if (pair.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
