//
//  main.cpp
//  454 Four Sum Count
//
//  Created by 刘亚东 on 2024/7/9.
//

// 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
// 0 <= i, j, k, l < n
// nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 方法一：分组+哈希表

// 将数组分成两部分，A、B 为一组，C、D 为另外一组

// 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
// 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
// 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
// 再遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
// 最后返回统计值 count 就可以了

class Solution {
public:
    static int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        // key: a+b 的数值，value：a+b 数值出现的次数
        // 遍历 A 和 B 数组，统计两个数组元素之和，和出现的次数，放到 map 中
        unordered_map<int, int> umap;
        
        for (int a : A) {
            for (int b : B) {
                umap[a + b]++;
            }
        }
        
        int count = 0; // 统计 a+b+c+d=0 出现的次数
        // 遍历 C 和 D 数组，找到如果 0-(c+d) 在 map 中出现过的话，就把 map 中 key 对应的 value 统计出来
        for (int c : C) {
            for (int d : D) {
                if (umap.find(0 - (c + d)) != umap.end()) {
                    count += umap[0 - (c + d)];
                }
            }
        }
        
        return count;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
