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
    ListNode* partition(ListNode* head, int x) {
        ListNode less_head(0);
        ListNode greater_head(0);
        ListNode* less = &less_head;
        ListNode* greater = &greater_head;
        ListNode*curr=head;
        while(curr!=nullptr){
            if(curr->val <x){
                less->next=curr;
                less=less->next;
            }
            else{
                greater->next=curr;
                greater=greater->next;
            }
            curr=curr->next;
        }
        greater->next = nullptr;
        less->next = greater_head.next;
        
        return less_head.next;
    }
};