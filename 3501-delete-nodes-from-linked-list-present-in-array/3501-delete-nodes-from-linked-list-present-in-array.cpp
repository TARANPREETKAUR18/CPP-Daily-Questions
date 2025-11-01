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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // unordered_set<int> st(begin(nums), end(nums)); // inserted

        // //handling the head
        // while((head != NULL) && (st.find(head->val) != st.end())){
        //     ListNode* temp = head;
        //     head = head->next;
        //     delete(temp); // deleting the handling node
        // }
        // ListNode* curr = head;
        // while((curr != NULL) && (curr->next!=NULL)){
        //     if(st.find(curr->next->val) != st.end()){
        //         ListNode* temp = curr->next;
        //         curr->next = curr->next->next; //curr->next is updated
        //         delete(temp); // deleting hanging node
        //     }
        //     else{
        //         curr = curr->next;
        //     }
        // }
        // return head;
        unordered_set<int> st(begin(nums), end(nums));
        ListNode* prev = NULL;
        ListNode* curr = head;

        // TC->O(N)
        // SC->O(N)
        while (curr != NULL && st.count(curr->val)) {
            head = curr->next;
            curr = head;
        }

        while (curr != NULL) {
            int currVal = curr->val;
            if (!st.count(currVal)) {
                prev = curr;
                curr = curr->next;
            } else {
                prev->next = curr->next;
                curr = curr->next;
            }
        }
        return head;
    }
};