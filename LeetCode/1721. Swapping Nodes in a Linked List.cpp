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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fast = head;
        ListNode* slow = head;

        for(int i=0; i<k-1; i++){
            fast = fast->next;
        }
        
        ListNode* kth_beg = fast;

        // find the kth node from the end
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* kth_end = slow;

        int temp = kth_beg->val;
        kth_beg->val = kth_end->val;
        kth_end->val = temp;

        return head;
    }
};