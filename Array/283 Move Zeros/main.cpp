//
//  main.cpp
//  283 Move Zeros
//
//  Created by 刘亚东 on 2024/2/7.
//
// 给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
// 请注意 ，必须在不复制数组的情况下原地对数组进行操作。

#include <iostream>

using std::vector;

class Solution {
public:
    static void removeZeros(vector<int>& nums) {
        int size = static_cast<int>(nums.size());
        if (size <= 1) return;
        
        int fast = size - 2;
        int slow = size - 1;
        while (fast >= 0) {
            if (nums[fast] == 0) {
                nums[slow--] = nums[fast];
            }
            fast--;
        }
        
        for (auto i: nums)
            std::cout << i << ' ';
        
        std::cout << "\n";
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector test1 = {0, 1, 0, 3, 12};
    Solution::removeZeros(test1);
    
    vector test2 = {0};
    Solution::removeZeros(test2);
    return 0;
}
