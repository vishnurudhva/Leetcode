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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode* returnHead = head, *odd = head, *even = NULL, *evenHead = head->next;
        while (odd && odd->next) {
            if (!even) even = odd->next;
            else {
                even->next = odd->next;
                even = even->next;
            }
            odd->next = odd->next->next;
            if (odd->next) odd = odd->next;
            else break;
        }
        if (even) even->next = NULL;
        odd->next = evenHead;
        return returnHead;
    }
};