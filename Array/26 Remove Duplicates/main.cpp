//
//  main.cpp
//  26 Remove Duplicates
//
//  Created by 刘亚东 on 2024/2/7.
//
// 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。
// 考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

// 更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
// 返回 k 。


#include <iostream>

using std::vector;

// 首先注意数组是有序的，那么重复的元素一定会相邻。
// 要求删除重复元素，实际上就是将不重复的元素移到数组的左侧
// 双指针
class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        if (size == 0) {
            return 0;
        }
        
        int fast = 1, slow = 1;
        while (fast < size) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                ++slow;
            }
            ++fast;
        }
        return slow;
    }
};

int main(int argc, const char * argv[]) {
    vector test1 = {1, 1, 2};
    std::cout << Solution::removeDuplicates(test1) << std::endl;
    
    vector test2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    std::cout << Solution::removeDuplicates(test2) << std::endl;
    return 0;
}
