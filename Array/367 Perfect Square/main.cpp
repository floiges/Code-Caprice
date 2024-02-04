//
//  main.cpp
//  367 Perfect Square
//
//  Created by 刘亚东 on 2024/2/4.
//
// 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
// 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
// 不能使用任何内置的库函数，如  sqrt 。

#include <iostream>

class Solution {
public:
    static bool isPerfectSquare(int num) {
        int left = 0, right = num, ans = false;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            long long sqrt = (long long)middle * middle;
            if (sqrt < num) {
                left = middle + 1;
            } else if (sqrt > num) {
                right = middle - 1;
            } else {
                ans = true;
                break;
            }
        }
        return ans;
    }
};

// 方法二：牛顿迭代法，暂时先不考虑，看着迷糊

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution::isPerfectSquare(16) << std::endl;
    std::cout << Solution::isPerfectSquare(14) << std::endl;
    return 0;
}
