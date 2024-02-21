//
//  main.cpp
//  844 Backspace Compare
//
//  Created by 刘亚东 on 2024/2/18.
//
// 给定 s 和 t 两个字符串，当它们分别被输入到空白的文本编辑器后，如果两者相等，返回 true 。# 代表退格字符。
// 注意：如果对空文本输入退格字符，文本继续为空。

#include <iostream>
#include <string>

using std::string;

// 双指针
// 一个字符是否会被删掉，只取决于该字符后面的退格符，而与该字符前面的退格符无关。因此当我们逆序地遍历字符串，就可以立即确定当前字符是否会被删掉。
// 具体地，我们定义 skip 表示当前待删除的字符的数量。每次我们遍历到一个字符：
// 若该字符为退格符，则我们需要多删除一个普通字符，我们让 skip 加 1；
// 若该字符为普通字符：

// 若 skip 为 0，则说明当前字符不需要删去；
// 若 skip 不为 0，则说明当前字符需要删去，我们让 skip 减 1。
// 这样，我们定义两个指针，分别指向两字符串的末尾。每次我们让两指针逆序地遍历两字符串，直到两字符串能够各自确定一个字符，然后将这两个字符进行比较。
// 重复这一过程直到找到的两个字符不相等，或遍历完字符串为止。
class Solution {
public:
    static bool backspaceCompare(string s, string t) {
        //设置两个指针的位置，定义跳过次数机会变量
        int i = static_cast<int>(s.length() - 1), j = static_cast<int>(t.length() - 1);
        int skipS = 0, skipT = 0;
        
        while (i >= 0 || j >= 0) {
            while (i >= 0) {
                //如果i是井号跳过次数+1，就不用拿井号前面那个数字比较，通过这个循环来找下一个比较的数
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS > 0) {
                    skipS--;
                    i--;
                } else {
                    break;
                }
            }
            
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT > 0) {
                    skipT--;
                    j--;
                } else {
                    break;
                }
            }
            
            //如果i和j没越过边界，那就看看i，j所指向的值是否相等
            if (i >= 0 && j >= 0) {
                if (s[i] != t[j]) {
                    return false;
                }
            } else {
                //这里能够进去代表i或者j有一个或者两个越界了，
                //那什么情况会进入？假如现在你的i和j后面的数字都比较过了，都是相等的‘
                //但如果i找不到下一位的时候，找不到了，并且j能够找到下一个要比较的数字的时候，就证明两个数组不相等，返回false
                if (i >= 0 || j >= 0) {
                    return false;
                }
            }
            
            i--;
            j--;
        }
        
        
        return true;
    }
};

// 将给定的字符串中的退格符和应当被删除的字符都去除，还原给定字符串的一般形式。然后直接比较两字符串是否相等即可。
// 具体地，我们用栈处理遍历过程，每次我们遍历到一个字符：
// 如果它是退格符，那么我们将栈顶弹出；
// 如果它是普通字符，那么我们将其压入栈中。
class Solution2 {
public:
    static bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }
    
private:
    static string build(string str) {
        string ret;
        for (char ch : str) {
            if (ch != '#') {
                ret.push_back(ch);
            } else if (!ret.empty()) {
                ret.pop_back();
            }
        }
        return ret;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    string s = "ab#c";
    string t = "ad#c";
    
    std::cout << Solution2::backspaceCompare(s, t) << std::endl;
    
    string s1 = "ab##";
    string t1 = "c#d#";
    
    std::cout << Solution2::backspaceCompare(s1, t1) << std::endl;
    return 0;
}
