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
        if(!head || (head->next == nullptr)) return head;

        // when k is too large, reduce the number of rotation
        int length = 1;
        ListNode* current = head;
        while (current->next) {
            current = current->next;
            ++length;
        }
        k %= length;

        while(k--){
            ListNode* slow = head;
            ListNode* fast = head->next;

            // find the last two nodes
            while(fast->next != nullptr){
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = head;
            slow->next = nullptr;
            head = fast;
        }

        return head;
    }
};