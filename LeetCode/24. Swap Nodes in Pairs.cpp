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
    ListNode* swapPairs(ListNode* head) {
        if(!head || head->next == nullptr) return head;

        ListNode* result = head->next;
        ListNode* prev = nullptr;
        ListNode* current = head;

        while(current && current->next){
            prev = current;
            current = current->next;
            ListNode* next = current->next;
            current->next = prev;
            prev->next = (next && next->next) ? next->next : next;
            current = next;
        }

        return result;
    }
};