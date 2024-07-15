//
//  main.cpp
//  15 Three Sum
//
//  Created by 刘亚东 on 2024/7/12.
//

// 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。

// 请你返回所有和为 0 且不重复的三元组。

// 注意：答案中不可以包含重复的三元组。

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 哈希解法
// 两层for循环就可以确定 a 和b 的数值了，可以使用哈希法来确定 0-(a+b) 是否在 数组里出现过，其实这个思路是正确的，但是我们有一个非常棘手的问题，就是题目中说的不可以包含重复的三元组。
// 把符合条件的三元组放进vector中，然后再去重，这样是非常费时的，很容易超时

// 「不重复」的本质是什么？我们保持三重循环的大框架不变，只需要保证：
// 第二重循环枚举到的元素不小于当前第一重循环枚举到的元素；
// 第三重循环枚举到的元素不小于当前第二重循环枚举到的元素。
// 也就是说，我们枚举的三元组 (a,b,c) 满足 a≤b≤c，保证了只有 (a,b,c) 这个顺序会被枚举到，而 (b,a,c)、(c,b,a)       等等这些不会，这样就减少了重复。要实现这一点，我们可以将数组中的元素从小到大进行排序，随后使用普通的三重循环就可以满足上面的要求。

// 同时，对于每一重循环而言，相邻两次枚举的元素不能相同，否则也会造成重复。举个例子，如果排完序的数组为

// [0, 1, 2, 2, 2, 3]
//  ^  ^  ^
// 我们使用三重循环枚举到的第一个三元组为 (0,1,2)，如果第三重循环继续枚举下一个元素，那么仍然是三元组 (0,1,2)，产生了重复。因此我们需要将第三重循环「跳到」下一个不相同的元素，即数组中的最后一个元素 3，枚举三元组 (0,1,3)。

class Solution {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        // 找出 a + b + c = 0
        // a = nums[i], b = nums[j], c = -(a + b)
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后 如果第一个元素已经大于0，那么不可能凑成三元组
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) { // 三元组元素 a 去重
                continue;
            }
            
            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++) {
                if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
                    // 三元组元素 b 去重
                    continue;
                }
                int c = 0 - (nums[i] + nums[j]);
                if (set.find(c) != set.end()) {
                    result.push_back({ nums[i], nums[j], c});
                    set.erase(c); // 三元组元素c去重
                } else {
                    set.insert(nums[j]);
                }
            }
        }
        
        return result;
    }
};

// 双指针法
class Solution2 {
public:
    static vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        
        // 找出 a + b + c = 0;
        // a = nums[i], b = nums[left], c = nums[right]
        for (int i = 0; i < nums.size(); i++) {
            // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
            if (nums[i] > 0) {
                return result;
            }
            
            // 错误去重 a 方法，将会漏掉-1,-1,2 这种情况
            // 我们要做的是 不能有重复的三元组，但三元组内的元素是可以重复的！
            /*
            if (nums[i] == nums[i + 1]) {
                continue;
            }
            */
            // 正确去重 a 方法
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int left = i + 1;
            int right = static_cast<int>(nums.size() - 1);
            while (right > left) {
                // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                /*
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;
                */
                if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                } else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                } else {
                    result.push_back({nums[i], nums[left], nums[right]});
                    // 去重逻辑应该放在找到一个三元组之后，对 b 和 c 去重
                    while (right > left && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    while (right > left && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    
                    // 找到答案时，双指针同时收缩
                    right--;
                    left++;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<int> v1 = {-1, 0, 1, 2, -1, -4};
//    vector<int> v1 = {0, 1, 1};
//    vector<int> v1 = {0, 0 ,0};
    vector<int> v1 = {-2, 0, 1, 1, 2};
    vector<vector<int>> res = Solution2::threeSum(v1);
    
    // 使用范围基的 for 循环打印二维 vector
    for (const auto& row : res) {
        for (const auto& value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl; // 每行后换行
    }
    return 0;
}
