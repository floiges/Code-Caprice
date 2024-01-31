//
//  main.cpp
//  Binary Search
//
//  Created by 刘亚东 on 2024/1/30.
//

// 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
// 重点：1、数组有序；2、nums 中的所有元素是不重复的

#include <iostream>

using std::vector;

// 左闭右闭区间
class Solution1 {
public:
    static int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size() - 1);
        while (left <= right) {
            int middle = left + ((right - left) / 2); // 防止溢出 等同于(left + right)/2
            if (nums[middle] > target) {
                right = middle - 1; // [left, middle - 1]
            } else if (nums[middle] < target) {
                left = middle + 1; // [middle + 1, right]
            } else {
                return middle;
            }
        }
        
        return -1;
    }
};

// 左闭右开区间
class Solution2 {
public:
    static int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int>(nums.size());
        while (left < right) {
            int middle = left + ((right - left) >> 1);
            if (nums[middle] > target) {
                right = middle; // [left, middle)
            } else if (nums[middle] < target) {
                left = middle + 1; // [middle + 1, right)
            } else {
                return middle;
            }
        }
        
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector vec = {-1, 0, 3, 5, 9, 12};
    
    std::cout << Solution1::search(vec, 9) << std::endl;
    std::cout << Solution1::search(vec, 2) << std::endl;
    
    std::cout << Solution2::search(vec, 9) << std::endl;
    std::cout << Solution2::search(vec, 2) << std::endl;
    return 0;
}
