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
    void rotate(ListNode* & head){
        ListNode* temp = head;
        if(temp == NULL || temp->next == NULL) return;
        ListNode* prev = NULL;
        while(temp->next != NULL){
            prev = temp;
            temp = temp ->next;
                
        }
        prev->next = NULL;
        temp->next = head;
        head = temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(temp == NULL)return head;
        int size =0;
        while(temp != NULL){
            temp = temp ->next;
            size++;
        }
        k = k%size;
        for(int i =0; i<k;i++){
            rotate(head);
        }
        return head;
    }
};
