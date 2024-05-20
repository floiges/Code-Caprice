//
//  LinkedNode.hpp
//  Linked
//
//  Created by 刘亚东 on 2024/5/14.
//

#ifndef LinkedNode_hpp
#define LinkedNode_hpp

#include <stdio.h>

struct LinkedNode {
   int val;
   LinkedNode *next;
   LinkedNode() : val(0), next(nullptr) {}
   LinkedNode(int x) : val(x), next(nullptr) {}
   LinkedNode(int x, LinkedNode *next) : val(x), next(next) {}
};

#endif /* LinkedNode_hpp */
