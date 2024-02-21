//
//  main.cpp
//  977 Sorted Squares
//
//  Created by 刘亚东 on 2024/2/21.
//
// 给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。



#include <iostream>

using std::vector;

// 暴力排序 O(n + nlogn)
class Solution {
public:
    static vector<int> sortedSquares(vector<int>& A) {
        int size = static_cast<int>(A.size());
        for (int i = 0; i < size; i++) {
            A[i] *= A[i];
        }
        sort(A.begin(), A.end()); // 快读排序
        return A;
    }
};

// 双指针
// 数组其实是有序的， 只不过负数平方之后可能成为最大数了。
// 那么数组平方的最大值就在数组的两端，不是最左边就是最右边，不可能是中间。
// 此时可以考虑双指针法了，i指向起始位置，j指向终止位置。
// 定义一个新数组result，和A数组一样的大小，让 k 指向result数组终止位置。
// 如果A[i] * A[i] < A[j] * A[j] 那么result[k--] = A[j] * A[j]; 。
// 如果A[i] * A[i] >= A[j] * A[j] 那么result[k--] = A[i] * A[i]; 。
// O(n)
class Solution2 {
public:
    static vector<int> sortedSquares(vector<int>& A) {
        int last = static_cast<int>(A.size() - 1);
        int k = last;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = last; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j]) {
                result[k--] = A[j] * A[j];
                j--;
            } else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums = {-4, -1, 0, 0, 3, 10};
    auto results = Solution2::sortedSquares(nums);
    
    for (auto i: results)
        std::cout << i << ' ';
    
    std::cout << "\n";
    return 0;
}
