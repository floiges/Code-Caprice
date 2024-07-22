//
//  main.cpp
//  344 Revert String
//
//  Created by 刘亚东 on 2024/7/22.
//

// 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
// 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
// s[i] 都是 ASCII 码表中的可打印字符

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // 双指针
    void revertString(vector<char>& s) {
        int size = static_cast<int>(s.size());
        for (int i = 0, j = size - 1; i < size / 2; i++, j--) {
            swap(s[i], s[j]);
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
