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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode* prev_left = (left == 1) ? nullptr : head;
        ListNode* prev_right = head;

        for(int i=1; i<left-1; i++) prev_left = prev_left->next;
        for(int i=1; i<right-1; i++) prev_right = prev_right->next;

        ListNode* left_node = prev_left ? prev_left->next : head;
        ListNode* right_node = prev_right->next;
        ListNode* post_left = left_node->next;
        ListNode* post_right = right_node->next;

        // handle adjacent nodes
        if (post_left == right_node) {
            if (prev_left) prev_left->next = right_node;
            else head = right_node;

            right_node->next = left_node;
            left_node->next = post_right;
            return head;
        }

        if (prev_left) prev_left->next = right_node;
        else head = right_node;

        right_node->next = post_left;
        prev_right->next = left_node;
        left_node->next = post_right;
       
        return reverseBetween(head, left + 1, right - 1);
    }
};