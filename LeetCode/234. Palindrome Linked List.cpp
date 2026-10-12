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
    bool isPalindrome(ListNode* head) {
        if( !head ) return true;

        ListNode* tempNode = head;
        vector<int> values;

        while( tempNode ){
            values.push_back(tempNode->val);
            tempNode = tempNode->next;
        }

        for( int i=0, j=values.size()-1; i <= j; i++, j-- ){
            if(values[i] != values[j]) return false;
        }

        return true;
    }
};