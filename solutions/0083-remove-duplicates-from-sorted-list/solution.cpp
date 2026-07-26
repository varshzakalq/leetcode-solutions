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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)return head;
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp != NULL){
            if(prev->val == temp->val){
                ListNode* t = temp;
                temp = temp->next;
                delete(t);
                prev->next = temp;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
