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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* temp = head;
        if(temp == NULL)return head;
        if(temp->next == NULL && n ==1){
            delete(temp);
            return NULL;
        }
        while(temp != NULL){
            length++;
            temp = temp->next;
        }
        int target = length -n;
        if(target == 0){
            delete(temp);
            return head->next;
        }
        int count = 1;
        temp = head;
        while(count != target){
            count++;
            temp = temp->next;
        }
        ListNode* dust = temp->next;
        if(temp->next ->next == NULL){
            temp ->next = NULL;
        }
        else{
            temp ->next = temp->next ->next;
        }
        delete(dust);
        return head;
    }
};
