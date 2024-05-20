//
//  main.cpp
//  203 Remove Elements
//
//  Created by 刘亚东 on 2024/5/14.
//

#include <iostream>
#include "LinkedNode.hpp"

class Solution {
public:
    static LinkedNode* removeElements(LinkedNode* head, int val) {
        // 设置一个虚拟头结点在进行移除节点操作
        LinkedNode* dummyHead = new LinkedNode(0);
        dummyHead->next = head;
        
        LinkedNode* cur = dummyHead;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                LinkedNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};

// 递归
class Solution2 {
public:
    static LinkedNode* removeElements(LinkedNode* head, int val) {
        if (head == nullptr) return head;
        
        head->next = removeElements(head->next, val);
        
        if (head->val == val) {
            LinkedNode* nextNode = head->next; // 保存下一个节点的指针
            delete head; // 删除头节点
            return nextNode; // 返回新的头节点
        } else {
            return head;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
