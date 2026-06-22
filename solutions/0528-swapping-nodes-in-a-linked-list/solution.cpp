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
    ListNode* swapNodes(ListNode* head, int k) {
        int length = 0;
        ListNode* kth_begin =NULL;
        ListNode* kth_end=NULL;
        ListNode* temp = head;
        if(temp == NULL||temp->next == NULL ) return head;
        while(temp != NULL){
            length ++;
            if(length == k){
                kth_begin=temp;
            }
            temp = temp->next;
        }
        int target = length - k;
        int count =0;
        temp = head;
        while(count!= target){
            count++;
            temp = temp->next;
        }
        kth_end=temp;
        int t = kth_end->val;
        kth_end->val = kth_begin->val;
        kth_begin->val = t;
        return head;
    }
};
