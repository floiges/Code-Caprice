//
//  main.cpp
//  541 Reverse Str
//
//  Created by 刘亚东 on 2024/7/22.
//

// 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
// 如果剩余字符少于 k 个，则将剩余字符全部反转。
// 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
// s 仅由小写英文组成

#include <iostream>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
    
    string reverseStr(string s, int k) {
        int size = static_cast<int>(s.size());
        for (int i = 0; i < size; i += (2 * k)) {
            // 1 每隔 2k 个字符的前 k 个字符进行反转
            // 2 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= size) {
                reverse(s, i, i + k - 1);
                continue;
            }
            
            // 3 剩余字符少于 k 个，则将剩余字符全部反转
            reverse(s, i, size - 1);
        }
        
        return s;
    }
    
    string reverseStr2(string s, int k) {
           int n = static_cast<int>(s.size()), pos = 0;
           while (pos < n) {
               //剩余字符串大于等于k的情况
               if (pos + k < n) std::reverse(s.begin() + pos, s.begin() + pos + k);
               //剩余字符串不足k的情况
               else std::reverse(s.begin() + pos, s.end());
               pos += 2 * k;
           }
           return s;
       }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
