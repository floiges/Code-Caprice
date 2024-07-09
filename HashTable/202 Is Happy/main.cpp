//
//  main.cpp
//  202 Is Happy
//
//  Created by 刘亚东 on 2024/7/5.
//

// 编写一个算法来判断一个数 n 是不是快乐数。

// 「快乐数」 定义为：

// 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
// 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
// 如果这个过程 结果为 1，那么这个数就是快乐数。
// 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。

// 例：
// 输入：n = 19
// 输出：true
// 解释：
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1


// 当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。
// 所以这道题目使用哈希法，来判断这个sum是否重复出现，如果重复了就是return false， 否则一直找到sum为1为止。

// 判断sum是否重复出现就可以使用unordered_set。

#include <iostream>
#include <unordered_set>

class Solution {
public:
    // 取数值各个位上的单数之和
    static int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }
    
    static bool isHappy(int n) {
        std::unordered_set<int> set;
        while (1) {
            int sum = getSum(n);
            if (sum == 1) {
                return true;
            }
            // 如果这个 sum 曾经出现过，说明已经陷入无限循环，立刻 return false
            if (set.find(sum) != set.end()) {
                return false;
            } else {
                set.insert(sum);
            }
            
            n = sum;
        }
    }
};

// 快慢指针
//使用 “快慢指针” 思想，找出循环：“快指针” 每次走两步，“慢指针” 每次走一步，当二者相等时，即为一个循环周期。
// 此时，判断是不是因为 1 引起的循环，是的话就是快乐数，否则不是快乐数。
//注意：此题不建议用集合记录每次的计算结果来判断是否进入循环，因为这个集合可能大到无法存储；
// 另外，也不建议使用递归，同理，如果递归层次较深，会直接导致调用栈崩溃。不要因为这个题目给出的整数是 int 型而投机取巧。

class Solution2 {
public:
    // 取数值各个位上的单数之和
    static int getSum(int n) {
        int sum = 0;
        while (n) {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        
        return sum;
    }
    
    static bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = getSum(slow);
            fast = getSum(fast);
            fast = getSum(fast);
        } while (slow != fast);
        
        // 如果 n 是一个快乐数，即没有循环，那么快跑者最终会比慢跑者先到达数字 1。
        // 如果 n 不是一个快乐的数字，那么最终快跑者和慢跑者将在同一个数字上相遇。
        return slow == 1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
