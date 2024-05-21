//
//  main.cpp
//  19 Remove Nth From End
//
//  Created by 刘亚东 on 2024/5/21.
//

// 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

#include <iostream>
#include "ListNode.cpp"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        
        fast = fast->next; // fast 再提前走一步，因为需要让 slow 指向删除结点的上一个结点
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next;
        
        return dummyHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
