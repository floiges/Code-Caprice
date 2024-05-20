//
//  main.cpp
//  206 Reverse List
//
//  Created by 刘亚东 on 2024/5/20.
//

// 给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

#include <iostream>
#include "ListNode.cpp"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* tmp;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while (cur) {
            tmp = cur->next; // 保存下一个结点
            cur->next = pre; // 翻转操作
            pre = cur;
            cur = tmp;
        }
        
        return pre;
    }
};

// 递归法
class Solution2 {
public:
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == nullptr) {
            return pre;
        }
        
        ListNode* temp = cur->next;
        cur->next = pre;
        
        return reverse(cur, temp);
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverse(nullptr, head);
    }
};

// 从后往前翻转
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        if (head->next == nullptr) {
            return head;
        }
        
        // 递归调用，翻转第二个结点开始往后的链表
        ListNode* last = reverseList(head->next);
        // 翻转头结点与第二个节点的指向
        head->next->next = head;
        // 此时的 head 节点为尾节点，next 需要指向 nullptr
        head->next = nullptr;
        return last;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
