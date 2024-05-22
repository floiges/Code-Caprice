//
//  main.cpp
//  0207 Get Intersection Node
//
//  Created by 刘亚东 on 2024/5/22.
//

// 给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
// 题目数据 保证 整个链式结构中不存在环。

// 注意，函数返回结果后，链表必须 保持其原始结构 。

#include <iostream>
#include "ListNode.cpp"

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        
        int lenA = 0, lenB = 0;
        while (curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        
        while (curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        
        curA = headA;
        curB = headB;
        // 让 curA 为最长链表的头，lenA 为其长度
        if (lenB > lenA) {
            std::swap(lenA, lenB);
            std::swap(curA, curB);
        }
        
        // 求长度差
        int gap = lenA - lenB;
        // 让 curA 和 curB 在同一起点上（末尾位置的对齐）
        while (gap--) {
            curA = curA->next;
        }
        
        // 遍历，判断相同
        while (curA != nullptr) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
