//
//  main.cpp
//  59 GenerateMatrix
//
//  Created by 刘亚东 on 2024/3/18.
//
///
/// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
/// 螺旋矩阵
/// 例：n = 3
/// 输出：[[1,2,3],[8,9,4],[7,6,5]]
///
/// 本题并不涉及到什么算法，就是模拟过程，但却十分考察对代码的掌控能力。
///
/// 模拟顺时针画矩阵的过程:

/// 填充上行从左到右
/// 填充右列从上到下
/// 填充下行从右到左
/// 填充左列从下到上
/// 由外向内一圈一圈这么画下去。
///
///
/// 这里一圈下来，我们要画每四条边，这四条边怎么画，每画一条边都要坚持一致的左闭右开，或者左开右闭的原则，即坚持循环不变量原则，这样这一圈才能按照统一的规则画下来。
///

#include <iostream>

using std::vector;

class Solution {
public:
    static vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 定义二维数组
        
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2;  // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边届收缩一位
        int i, j;
        while (loop--) {
            i = startx;
            j = starty;
            
            // 下面四个 for 就是模拟转了一圈
            // 模拟填充上行从左到右（左闭右开）
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            
            // 模拟填充右列从上到下
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            
            // 模拟填充下行从右到左
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            
            // 模拟填充做列从下到上
            for (; i > startx; i--) {
                res[i][j] = count++;
            }
            
            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;
            
            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }
        
        // 如果 n 为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}