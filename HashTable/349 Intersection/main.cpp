//
//  main.cpp
//  349 Intersection
//
//  Created by 刘亚东 on 2024/7/5.
//

// 给定两个数组 nums1 和 nums2 ，返回 它们的交集。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
// 要注意，使用数组来做哈希的题目，是因为题目都限制了数值的大小。
// 而这道题目没有限制数值的大小，就无法使用数组来做哈希表了。
// 而且如果哈希值比较少、特别分散、跨度非常大，使用数组就造成空间的极大浪费。

// 这道题目，主要要学会使用一种哈希数据结构：unordered_set，这个数据结构可以解决很多类似的问题。

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set; // 存放结果
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        
        for (int num : nums2) {
            // 发现 nums2 的元素 在 nums_set 里又出现
            if (nums_set.find(num) != nums_set.end()) {
                result_set.insert(num);
            }
        }
        
        // 时间复杂度: O(n + m) m 是最后要把 set转成vector
        return vector<int>(result_set.begin(), result_set.end());
    }
};

// 题目限制了数值范围
// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000
// 可以使用数组来做哈希表
class Solution2 {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result_set;
        int hash[1005] = {0};
        for (int num : nums1) {
            hash[num] = 1;
        }
        
        for (int num : nums2) {
            if (hash[num] == 1) {
                result_set.insert(num);
            }
        }
        
        return vector<int>(result_set.begin(), result_set.end());
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
