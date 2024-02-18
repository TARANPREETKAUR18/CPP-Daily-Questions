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
    // Approach - 
    // Step 1 - Reverse LL
    // Step 2 - If any node found less than max value node, remove that
    // Step 3 - reverse and return head
    ListNode * reverse(ListNode *head){
        ListNode * p = NULL, *q = NULL , *r = head;
        while(r){
            p = q;
            q = r;
            r = r->next;
            q->next = p;
        }
        head = q;
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        if(!head) return NULL;
        head = reverse(head);
        ListNode *curr = head , *prev = NULL;
        int data = curr->val;
        while(curr){    
            if(curr->val < data){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                data = max(data, curr->val);
                prev = curr;
                curr = curr->next;
            }
        }
        head = reverse(head);
        return head;
    }
};