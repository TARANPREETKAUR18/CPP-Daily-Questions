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
        if(!head) return head;
        ListNode* t = head;
        int len = 0;
        while(t){
            len++;
            t = t -> next;
        }
        k = k % len;
        ListNode* slow = head;
        ListNode* fast = head;
        vector<int> temp;
        for(int i = 0; i < k; i++){
            fast = fast -> next;
            if(!fast) fast = head;
        }
        for(int i = 0; i < k; i++){
            temp.push_back(fast -> val);
            fast -> val = slow -> val;
            fast = fast -> next;
            slow = slow -> next;
            if(!fast) fast = head;
            if(!slow) slow = head;
        }
        int i = 0;
        while(fast != slow){
            temp.push_back(fast -> val);
            fast -> val = temp[i++];
            fast = fast -> next;
            if(!fast) fast = head;
        }
        return head;
    }
};