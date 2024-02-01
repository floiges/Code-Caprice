//
//  main.cpp
//  34 Find First And Last Position
//
//  Created by 刘亚东 on 2024/1/31.
//

// 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。
// 如果数组中不存在目标值 target，返回 [-1, -1]。

// 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

// 寻找target在数组里的左右边界，有如下三种情况：

// 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
// 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
// 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}

#include <iostream>

using std::vector;

class Solution {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);
        // 情况一
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // 情况三
        if (rightBorder - leftBorder > 1) {
            return {leftBorder + 1, rightBorder - 1};
        }
        // 情况二
        return {-1, -1};
    }
private:
    // 二分查找，寻找target的右边界（不包括target）
    // 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
    static int getRightBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1); // 左闭右闭区间 [left, right]
        int rightBorder = -2; // 记录一下rightBorder没有被赋值的情况
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else {  // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                left = middle + 1;
                rightBorder = left;
            }
        }
        return rightBorder;
    }

    // 二分查找，寻找target的左边界leftBorder（不包括target）
    // 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
    static int getLeftBorder(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        int leftBorder = -2;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] >= target) { // 寻找左边界，就要在nums[middle] == target的时候更新right
                right = middle - 1;
                leftBorder = right;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector vec = {5, 7, 7, 8, 8, 10};
    auto results = Solution::searchRange(vec, 8);
    for (auto i: results)
        std::cout << i << ' ';
    
    std::cout << "\n";
    
    auto results1 = Solution::searchRange(vec, 6);
    for (auto i: results1)
        std::cout << i << ' ';
    
    std::cout << "\n";
    
    auto results2 = Solution::searchRange(vec, 0);
    for (auto i: results2)
        std::cout << i << ' ';
    
    std::cout << "\n";
    
    return 0;
}
