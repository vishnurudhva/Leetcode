/* REFER LEETCODE FOR IMAGE EXAMPLES
Given the head of a singly linked list, return true if it is a palindrome.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/


class Solution {
public:
    int ListLength(ListNode* head){
        int length = 0;
        while(head != NULL){
            head = head->next;
            length++;
        }
        return length;
    }
    bool isPalindrome(ListNode* head) {
        int size = ListLength(head);
        if(size == 0 || size == 1)
            return true;
        if(size == 2 && head->val == head->next->val)
            return true;
        if(size == 2 && head->val != head->next->val)
            return false;
        ListNode* temp = NULL;     
        ListNode* offset = head;
        ListNode* rev;
        
        for(int i = 0; i < size / 2; i++){
            rev = offset->next;
            offset->next = temp;
            temp = offset;
            offset = rev;
        }
        if(size % 2 == 1)
            offset = offset->next;
        
        while(offset != NULL){
            if(offset->val != temp->val)
                return false;
            offset = offset->next;
            temp = temp->next;
        }
        
        return true;
        
    }
};