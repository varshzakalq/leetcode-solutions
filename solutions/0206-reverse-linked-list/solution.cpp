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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head ->next;
        ListNode* p3 = head->next->next;
        while(p3!= NULL){
            
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3->next;

        }
        head->next = NULL;
        p2->next =p1;
        head = p2;
        return head;
        
    }
};
