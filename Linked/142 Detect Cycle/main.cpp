//
//  main.cpp
//  142 Detect Cycle
//
//  Created by 刘亚东 on 2024/5/22.
//

// 给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

// 如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。

// 不允许修改 链表。

#include <iostream>
#include "ListNode.cpp"

// 关键思想
// 两个指针的速度：

// slow 指针每次前进一步。
// fast 指针每次前进两步。
// 无环情况下的运动：

// 如果链表中没有环，fast 指针将最终到达链表的末尾（即指向 nullptr）。此时，slow 指针和 fast 指针永远不会相遇。
// 有环情况下的运动：

// 如果链表中有环，fast 指针最终会追上 slow 指针并与其相遇。这是因为 fast 指针的速度是 slow 指针的两倍。

// 数学解释
// 假设链表头到环的起点的距离为 a，环的长度为 b，slow 和 fast 指针在环内相遇时，slow 指针走了 x 步，则 fast 指针走了 2x 步。

// 在相遇点上：

// slow 指针走过的距离是 a + x
// fast 指针走过的距离是 a + 2x
// 由于 fast 指针在环内多走了一些圈数，我们可以写成：

// a + 2x = a + x + kb，其中 k 是一个非负整数，表示 fast 指针在环内绕过的圈数。
// 简化得：

// x = kb
// 这说明，当 slow 和 fast 相遇时，x 是环长度 b 的整数倍，意味着它们在环内的某个位置相遇。

// 为什么相遇说明有环？
// 当 slow 和 fast 指针相遇时：

// 说明 fast 指针已经在环内绕了至少一圈，slow 指针也在环内。
// 因为 fast 的速度是 slow 的两倍，所以如果链表中有环，fast 最终会追上 slow。
// 如果链表中没有环，fast 会走到链表末尾并指向 nullptr，而不会回到 slow。
// 因此，相遇的唯一解释是链表中存在环。

// 再找到环的入口
// 当 slow 和 fast 相遇后，我们可以通过以下步骤找到环的入口：

// 将 slow 指针移回链表头部，而 fast 指针保持在相遇点。
// 这两个指针每次前进一步，它们最终会在环的入口处相遇。这是因为：
// slow 指针从头到环入口的距离是 a。
// fast 指针从相遇点到环入口的距离也是 a（由于环内的长度特性，它们在一个圈之后会相遇在入口）。
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            // 快慢指针相遇，此时从 head 和 相遇点，同时查找直至相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = head;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2; // 环的入口
            }
        }
        
        return nullptr;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
