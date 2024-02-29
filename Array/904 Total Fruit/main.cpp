//
//  main.cpp
//  904 Total Fruit
//
//  Created by 刘亚东 on 2024/2/27.
//
// 你正在探访一家农场，农场从左到右种植了一排果树。这些树用一个整数数组 fruits 表示，其中 fruits[i] 是第 i 棵树上的水果 种类 。

// 你想要尽可能多地收集水果。然而，农场的主人设定了一些严格的规矩，你必须按照要求采摘水果：
// 你只有 两个 篮子，并且每个篮子只能装 单一类型 的水果。每个篮子能够装的水果总量没有限制。
// 你可以选择任意一棵树开始采摘，你必须从 每棵 树（包括开始采摘的树）上 恰好摘一个水果 。采摘的水果应当符合篮子中的水果类型。每采摘一次，你将会向右移动到下一棵树，并继续采摘。
// 一旦你走到某棵树前，但水果不符合篮子的水果类型，那么就必须停止采摘。
// 给你一个整数数组 fruits ，返回你可以收集的水果的 最大 数目。

// 最大滑窗
// 双指针和滑动窗口是有些许区别的。滑动窗口一句话就是右指针先出发，左指针视情况追赶右指针

// left 和 right 分别表示满足要求的窗口的左右边界，同时我们使用哈希表存储这个窗口内的数以及出现的次数。
// 我们每次将 right 移动一个位置，并将 fruits[right] 加入哈希表。如果此时哈希表不满足要求（即哈希表中出现超过两个键值对），那么我们需要不断移动 left，并将 fruits[left] 从哈希表中移除，直到哈希表满足要求为止。
// 需要注意的是，将 fruits[left] 从哈希表中移除后，如果 fruits[left] 在哈希表中的出现次数减少为 0，需要将对应的键值对从哈希表中移除。

#include <iostream>
//#include <unordered_map>

using std::vector;
using std::unordered_map;
using std::max;

class Solution {
public:
    static int totalFruit(vector<int>& fruits) {
        int n = static_cast<int>(fruits.size());
        unordered_map<int, int> cnt;
        
        int left = 0, ans = 0;
        for (int right = 0; right < n; ++right) {
            ++cnt[fruits[right]];
            while (cnt.size() > 2) {
                auto it = cnt.find(fruits[left]);
                --it->second;
                if (it->second == 0) {
                    cnt.erase(it);
                }
                ++left;
            }
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> fruits = {1, 2, 1};
    vector<int> fruits2 = {0 ,1, 2, 2};
    vector<int> fruits3 = {1 ,2 ,3, 2, 2};
    
    std::cout << Solution::totalFruit(fruits) << std::endl;
    std::cout << Solution::totalFruit(fruits2) << std::endl;
    std::cout << Solution::totalFruit(fruits3) << std::endl;
    return 0;
}
