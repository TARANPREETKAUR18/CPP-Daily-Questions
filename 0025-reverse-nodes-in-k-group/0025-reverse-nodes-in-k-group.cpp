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
    int getLength(ListNode* head) {
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL) {
                temp = temp -> next; 
                len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count=0;
        int len =getLength(head);
        if(head==NULL||k>len) return head;
        ListNode* prev=NULL;
        ListNode* curr=head;
        ListNode* forward =curr->next;
        while(count<k){
            forward =curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
            count++;
        }
        if(forward!=NULL) head->next=reverseKGroup(forward,k);
        return prev; 
    }
};