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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;

        for(int i=1; i<n; i++) p2 = p2->next;

        ListNode* prev = nullptr;

        while(p2->next){
            prev = p1;
            p1 = p1->next;
            p2 = p2->next;
        }

        if (prev) prev->next = p1->next;
        else head = p1->next;

        delete p1;

        return head;
    }
};