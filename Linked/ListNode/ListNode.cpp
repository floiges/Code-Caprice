//
//  ListNode.cpp
//  ListNode
//
//  Created by 刘亚东 on 2024/5/20.
//

#include <stdio.h>

struct ListNode {
   int val;
   ListNode *next;
   ListNode() : val(0), next(nullptr) {}
   ListNode(int x) : val(x), next(nullptr) {}
   ListNode(int x, ListNode *next) : val(x), next(next) {}
};
