/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return head;
        ListNode* tail = head;
        int count = 1;
        while (tail->next && ++count)
            tail = tail->next;
        
        ListNode* node = head;
        
        k %= count;
        if (k == 0) return head;
        count -= k;
        while (--count) {
            node = node->next;
        }
        ListNode* newHead = node->next;
        node->next = NULL;
        tail->next = head;
        
        return newHead;
    }
};