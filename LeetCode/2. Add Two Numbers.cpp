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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* current = head;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        int carry = 0;

        while(node1 != nullptr || node2 != nullptr || carry != 0){
            int val1 = node1 != nullptr? node1->val : 0;
            int val2 = node2 != nullptr? node2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            if(sum>9){
                carry = 1;
                sum-=10;
            }

            if(head == nullptr){
                head = new ListNode(sum);
                current = head;
            }else{
                current->next = new ListNode(sum);
                current = current->next;
            }

            node1 = node1 != nullptr ? node1->next : node1;
            node2 = node2 != nullptr ? node2->next : node2;
        }
        
        return head;
    }
};