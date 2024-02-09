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
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n){
        ListNode* end = head;
        ListNode* start = head;
        ListNode* temp = head;
        int cnt = 0;
        while(end){
            cnt++;
            end = end->next;
        }
        if(cnt-n == 0){
            head = head->next;
            delete start;
            return head;
        }
        int i = 1;
        while(start && i<cnt-n){
            i++;
            start = start->next;
            temp = temp->next;
        }
        start->next = start->next->next;
        return head;
    }
};