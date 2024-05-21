//
//  main.cpp
//  24 Swap Pairs
//
//  Created by 刘亚东 on 2024/5/21.
//

// 给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

#include <iostream>
#include "ListNode.cpp"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 虚拟头结点
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next;
            ListNode* tmp1 = cur->next->next->next;
            
            cur->next = cur->next->next;
            cur->next->next = tmp;
            cur->next->next->next = tmp1;
            
            cur = cur->next->next; // 移动两位
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
