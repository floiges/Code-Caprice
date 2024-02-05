//
//  main.cpp
//  27 Remove Element
//
//  Created by 刘亚东 on 2024/2/4.
//
// 给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
// 不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
// 元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

#include <iostream>
#include <algorithm>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // 使用迭代器遍历vector
        for (auto it = nums.begin(); it != nums.end();) {
           if (*it == val) {
               it = nums.erase(it); // 使用erase()删除元素并获取下一个有效迭代器
           } else {
               ++it; // 移动到下一个元素
           }
        }
        return static_cast<int>(nums.size());
    }
};

// 暴力循环
class Solution2 {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = static_cast<int>(nums.size());
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 发现需要移除的元素，将数组集体向前移动一位
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--; // 因为下标i以后的数值都向前移动了一位，所以i也向前移动一位
                size--; // 此时数组的大小-1
            }
        }
        return size;
    }
};

// 高端了 双指针
// 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
// 慢指针：指向更新 新数组下标的位置
class Solution3 {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        int size = static_cast<int>(nums.size());
        for (int fastIndex = 0; fastIndex < size; fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex++] = nums[fastIndex];
            }
        }
        return slowIndex;
    }
};

/**
* 相向双指针方法，基于元素顺序可以改变的题目描述改变了元素相对位置，确保了移动最少元素
* 时间复杂度：O(n)
* 空间复杂度：O(1)
*/
class Solution4 {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = static_cast<int>(nums.size() - 1);
        while (leftIndex <= rightIndex) {
            // 找左边等于 val 的元素
            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
                ++leftIndex;
            }
            // 找右边边不等于 val 的元素
            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
                --rightIndex;
            }
            // 将右边不等于 val 的元素覆盖左边等于 val 的元素
            if (leftIndex < rightIndex) {
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex; // leftIndex 一定指向了最终数组末尾的下一个元素
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {3, 2, 2, 3};
//    std::cout << Solution().removeElement(nums, 3) << std::endl;
//    std::cout << Solution2().removeElement(nums, 3) << std::endl;
    std::cout << Solution4().removeElement(nums, 3) << std::endl;
    
    vector<int> nums1 = {0, 1, 2, 2, 3, 0, 4, 2};
//    std::cout << Solution().removeElement(nums1, 2) << std::endl;
//    std::cout << Solution2().removeElement(nums1, 2) << std::endl;
    std::cout << Solution4().removeElement(nums, 3) << std::endl;
    return 0;
}
