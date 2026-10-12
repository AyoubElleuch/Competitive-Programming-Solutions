/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(true){
            if(!fast) return nullptr;

            if(fast->next){
                fast = fast->next;
                fast = fast->next;
            }else{
                return nullptr;
            }

            slow = slow->next;

            if(slow == fast) break;
        }

        slow = head;

        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};