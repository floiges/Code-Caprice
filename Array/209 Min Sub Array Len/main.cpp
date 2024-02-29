//
//  main.cpp
//  209 Min Sub Array Len
//
//  Created by 刘亚东 on 2024/2/21.
//
// 给定一个含有 n 个正整数的数组和一个正整数 target 。
// 找出该数组中满足其总和大于等于 target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

#include <iostream>

using std::vector;

// 暴力循环
class Solution {
public:
    static int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX; //  最终的结果
        int sum = 0; // 子序列的数值之和
        int subLength = 0; // 子序列的长度
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; i++) { // 设置子序列起点为 i
            sum = 0;
            for (int j = i; j < size; j++) { // 设置子序列中止位置为 j
                sum += nums[j];
                if (sum >= s) { // 一旦发现子序列和超过了 s，更新 result
                    subLength = j - i + 1;
                    result = result < subLength ? result : subLength;
                    break; // 因为我们是要找符合条件最短的子序列，所以条件符合就 break
                }
            }
        }
        // 如果 result 没有被赋值，返回 0
        return result == INT32_MAX ? 0 : result;
    }
};

// 滑动窗口
// 滑动窗口，就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果
// 在本题中实现滑动窗口，主要确定如下三点：

// 窗口内是什么？
// 如何移动窗口的起始位置？
// 如何移动窗口的结束位置？

// 窗口就是 满足其和 ≥ s 的长度最小的 连续 子数组。
// 窗口的起始位置如何移动：如果当前窗口的值大于s了，窗口就要向前移动了（也就是该缩小了）。
// 窗口的结束位置如何移动：窗口的结束位置就是遍历数组的指针，也就是for循环里的索引。

// 滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置。从而将O(n^2)暴力解法降为O(n)

// 最小滑窗
class Solution2 {
public:
    static int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int sum = 0; // 滑动窗口数值之和
        int i = 0; // 滑动窗口起始位置
        int subLength = 0; // 滑动窗口的长度
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            // 注意这里使用 while， 每次更新 i（起始位置），并不断比较子序列是否符合条件
            while (sum >= s) {
                subLength = (j - i + 1); // 取子序列长度
                result = result < subLength ? result : subLength;
                sum -= nums[i++]; // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
            }
        }
        
        // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
        return result == INT32_MAX ? 0 : result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector test1 = {2, 3, 1, 2, 4, 3};
    vector test2 = {1, 4, 4};
    vector test3 = {1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << Solution2::minSubArrayLen(7, test1) << std::endl;
    std::cout << Solution2::minSubArrayLen(4, test2) << std::endl;
    std::cout << Solution2::minSubArrayLen(11, test3) << std::endl;
    return 0;
}
