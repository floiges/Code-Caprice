//
//  main.cpp
//  69 Sqrt
//
//  Created by 刘亚东 on 2024/2/4.
//
// 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
// 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被舍去 。
// 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

#include <iostream>

class Solution {
public:
    static int mySqrt(int x) {
        int left = 0;
        int right = x, ans = -1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if ((long long)middle * middle <= x) {
                ans = middle;
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << Solution::mySqrt(4) << std::endl;
    std::cout << Solution::mySqrt(8) << std::endl;
    return 0;
}
