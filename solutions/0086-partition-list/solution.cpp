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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head->next == NULL)return head;
        ListNode* less = new ListNode(0);
        ListNode* t1= less;
        ListNode* greater = new ListNode(0);
        ListNode* t2 = greater;

        ListNode* t = head;
        while(t != NULL){
            if(t->val >=x){
                t2->next = new ListNode(t->val);

                t2 =t2->next;
            }
            else{
                t1->next = new ListNode(t->val);
                t1 =t1->next;
            }
            t = t->next;
        }
        
        
        t1->next = greater->next;
        head = less->next;
        delete(greater);
        delete(less);
        return head;

    }
};
