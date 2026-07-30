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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comp =[](ListNode* a,ListNode* b){
            return a->val >b->val;
        };
        priority_queue<ListNode*,vector<ListNode*>,decltype(comp)>pq(comp);
        for(ListNode*node : lists){
            if(node!=NULL){
                pq.push(node);
            }
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            tail->next = minNode;
            tail = tail->next;

            if (minNode->next != nullptr) {
                pq.push(minNode->next);
            }
        }

        return dummy.next;
    }
};