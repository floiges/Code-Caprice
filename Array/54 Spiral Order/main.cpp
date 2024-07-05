//
//  main.cpp
//  54 Spiral Order
//
//  Created by 刘亚东 on 2024/3/21.
//
///
/// 给你一个 m 行 n 列的矩阵 matrix，请按照 顺时针螺旋顺序，返回矩阵中的所有元素
/// 同 LCR 146.螺旋遍历二维数组
/// 模拟类的题目在数组中很常见，不涉及到什么算法，就是单纯的模拟

#include <iostream>
#include <vector>

using std::vector;

/**
 *  1、首先设定上下左右边界
 *  2、其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界*
 *  3、判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
 *  4、若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
 *  5、不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
 */
class Solution {
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        if (matrix.empty()) {
            return ans;
        }
        
        int u = 0; // 赋值上下左右边界
        int d = static_cast<int>(matrix.size() - 1);
        int l = 0;
        int r = static_cast<int>(matrix[0].size() - 1);
        
        while (true) {
            for (int i = l; i <= r; ++i) ans.push_back(matrix[u][i]); // 向右移动直到最右
            if (++u > d) break; // 重新设置上边界，若上边界大于下边届，则遍历完成
            for (int i = u; i <= d; ++i) ans.push_back(matrix[i][r]); // 向下
            if (--r < l) break; // 重新设定右边界
            for (int i = r; i >= l; --i) ans.push_back(matrix[d][i]); // 向左
            if (--d < u) break; // 重新设置下边界
            for (int i = d; i >= u; --i) ans.push_back(matrix[i][l]); // 向上
            if (++l > r) break; // 重新设定左边届
        }
        
        return ans;
    }
};

/**
 * 可以模拟螺旋矩阵的路径。初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，顺时针旋转，进入下一个方向。

 * 判断路径是否进入之前访问过的位置需要使用一个与输入矩阵大小相同的辅助矩阵 visited，其中的每个元素表示该位置是否被访问过。当一个元素被访问时，将 visited 中的对应位置的元素设为已访问。

 * 如何判断路径是否结束？由于矩阵中的每个元素都被访问一次，因此路径的长度即为矩阵中的元素数量，当路径的长度达到矩阵中的元素数量时即为完整路径，将该路径返回。
 */
class Solution2 {
private:
    static constexpr int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
public:
    static vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return  {};
        }
        
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        vector<int> order(total);
        
        int row = 0, column = 0;
        int directionIndex = 0;
        for (int i = 0; i < total; i++) {
            order[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[directionIndex][0];
            int nextColumn = column + directions[directionIndex][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >=columns || visited[nextRow][nextColumn]) {
                directionIndex = (directionIndex + 1) % 4;
            }
            row += directions[directionIndex][0];
            column += directions[directionIndex][1];
        }
        
        return  order;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>>matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    vector<int>ans = Solution2::spiralOrder(matrix);
    
    for (auto i: ans)
        std::cout << i << ' ';
    
    std::cout << "\n";
    return 0;
}
