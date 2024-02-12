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
    ListNode* mergeFunction(ListNode* temp1, ListNode* temp2){
        if(!temp1) return temp2;
        if(!temp2) return temp1;
        ListNode* ans = new ListNode(-1);
        ListNode* move = ans;
        while(temp1 && temp2){
            if(temp1->val < temp2->val){
                ans->next = temp1;
                ans = ans->next;
                temp1 = temp1->next;
            }
            else{
                ans->next = temp2;
                ans = ans->next;
                temp2 = temp2->next;
            }
        }
        while(temp1){
            ans->next = temp1;
            ans = ans->next;
            temp1 = temp1->next;
        }
        while(temp2){
            ans->next = temp2;
            ans = ans->next;
            temp2 = temp2->next;
        }
        return move->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists){
        ListNode* ans = new ListNode(-100000);
        for(int i = 0; i < lists.size(); i++) ans = mergeFunction(ans, lists[i]);
        return ans->next;
    }
};