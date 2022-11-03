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
    ListNode* reverseLinkedList(ListNode* head) {
        if (head == NULL) return NULL;
        
        ListNode* prev = NULL, *curr = head;
        
        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        ListNode* mid = head, *hare = head;
        
        while (hare && hare->next) {
            hare = hare->next->next;
            if (hare)
                mid = mid->next;
        }
        ListNode* node = reverseLinkedList(mid->next);
        mid->next = NULL;
        ListNode* main = head;
        while (main && node)
        {
            ListNode* temp = main->next;
            main->next = node;
            ListNode* temp2 = node->next;
            node->next = temp;
            node = temp2;
            main = temp;
        }
    }
};

 