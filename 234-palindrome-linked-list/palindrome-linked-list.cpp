class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL)
            return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if(fast != NULL) {  
            slow = slow->next;
        }

        ListNode* prev = NULL;
        while(slow) {
            ListNode* nextNode = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextNode;
        }

        ListNode* first = head;
        ListNode* second = prev;

        while(second) {
            if(first->val != second->val)
                return false;
            first = first->next;
            second = second->next;
        }

        return true;
    }
};