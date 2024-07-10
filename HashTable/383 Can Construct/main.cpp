//
//  main.cpp
//  383 Can Construct
//
//  Created by 刘亚东 on 2024/7/10.
//

// 赎金信:
// 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
// 如果可以，返回 true ；否则返回 false 。
// magazine 中的每个字符只能在 ransomNote 中使用一次。
// ransomNote 和 magazine 由小写英文字母组成

// 注：
// 第一点“为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思”  这里说明杂志里面的字母不可重复使用。
// 第二点 “你可以假设两个字符串均只含有小写字母。” 说明只有小写字母，这一点很重要

#include <iostream>
#include <vector>

using namespace std;

// 直接暴力循环
class Solution {
public:
    static bool canConstruct(string ransomNote, string magazine) {
        for (int i = 0; i < magazine.length(); i++) {
            for (int j = 0; j < ransomNote.length(); j++) {
                // 在 ransomNote 中找到和 magazine 相同的字符
                if (magazine[i] == ransomNote[j]) {
                    // 这个删除操作也是费时的
                    ransomNote.erase(ransomNote.begin() + j); // ransomNote 中删除这个字符
                    break;
                }
            }
        }
        
        // 如果 ransomNote 为空，则说明 magazine 的字符可以组成 ransomNote
        if (ransomNote.length() == 0) {
            return true;
        }
        
        return false;
    }
};

// 字符统计
// 只需要满足字符串 magazine 中的每个英文字母 (’a’-’z’) 的统计次数都大于等于 ransomNote 中相同字母的统计次数即可。
// 如果字符串 magazine 的长度小于字符串 ransomNote 的长度，则我们可以肯定 magazine 无法构成 ransomNote，此时直接返回 false。
// 首先统计 magazine 中每个英文字母 a 的次数 cnt[a]，再遍历统计 ransomNote 中每个英文字母的次数，如果发现 ransomNote 中存在某个英文字母 c 的统计次数大于 magazine 中该字母统计次数 cnt[c]，则此时我们直接返回 false。
class Solution2 {
public:
    static bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }
        
        vector<int> cnt(26);
        for (auto & c : magazine) {
            cnt[c - 'a']++;
        }
        
        for (auto & c : ransomNote) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string ransomNote = "aa";
    string magazine = "aab";
    
    std::cout << Solution2::canConstruct(ransomNote, magazine) << std::endl;
    return 0;
}
