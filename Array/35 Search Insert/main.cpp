//
//  main.cpp
//  35 Search Insert
//
//  Created by 刘亚东 on 2024/1/30.
//

// 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
// 请必须使用时间复杂度为 O(log n) 的算法。
// nums 数组无重复元素

#include <iostream>

using std::vector;

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; i++) {
            // 分别处理如下三种情况
            // 目标值在数组所有元素之前
            // 目标值等于数组中某一个元素
            // 目标值插入数组中的位置
            if (nums[i] >= target) { // 一旦发现大于或者等于target的num[i]，那么i就是我们要的结果
                return i;
            }
        }
        // 目标值在数组所有元素之后的情况
        return size; // 如果target是最大的，或者 nums为空，则返回nums的长度
    }
};

class Solution2 {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;  // 定义 target 在左闭右闭区间 [left, right]
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right]，return  right + 1
        // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
        return right + 1;
    }
};

class Solution3 {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n;  // 定义 target 在左闭右闭区间 [left, right)
        while (left < right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle; // target 在左闭右闭区间 [left, middle)
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle;
            }
        }
        // 分别处理如下四种情况
        // 目标值在数组所有元素之前  [0, -1]
        // 目标值等于数组中某一个元素  return middle;
        // 目标值插入数组中的位置 [left, right)，return  right
        // 目标值在数组所有元素之后的情况 [left, right)， 因为是右闭区间，所以 return right
        return right;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector vec = {1, 3, 5, 6};
    
    std::cout << Solution3::searchInsert(vec, 5) << std::endl;
    std::cout << Solution3::searchInsert(vec, 2) << std::endl;
    std::cout << Solution3::searchInsert(vec, 7) << std::endl;
    std::cout << Solution3::searchInsert(vec, 0) << std::endl;
    return 0;
}
