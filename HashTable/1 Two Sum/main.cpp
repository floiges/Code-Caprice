//
//  main.cpp
//  1 Two Sum
//
//  Created by 刘亚东 on 2024/7/8.
//

// 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
// 你可以按任意顺序返回答案。

// 再来看一下使用数组和set来做哈希法的局限。

// 数组的大小是受限制的，而且如果元素很少，而哈希值太大会造成内存空间的浪费。
// set是一个集合，里面放的元素只能是一个key，而两数之和这道题目，不仅要判断y是否存在而且还要记录y的下标位置，因为要返回x 和 y的下标。所以set 也不能用。
// 此时就要选择另一种数据结构：map ，map是一种key value的存储结构，可以用key保存数值，用value再保存数值所在的下标。



#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            // 遍历当前元素，并在 map 中寻找是否有匹配的 key
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return {iter->second, i};
            }
            
            // 如果没找到匹配对，就把访问过的元素和下标加入到 map 中
            map.insert(pair<int, int>(nums[i], i));
        }
        
        return {};
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
