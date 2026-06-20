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
    int getnext(ListNode* &a){
        if(a == NULL){
            return 0;
        }
        else if(a->next == NULL){
            a = NULL;
            return 0;
        }
        else{
            a = a->next;
            return a->val;
        }   
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* head =new ListNode();
        ListNode* ans = head ;
        int carry =0;
        while(a!= NULL || b != NULL || carry != 0){
            
            int val1 = (a == NULL)? 0: a->val;
            int val2 = (b== NULL)? 0:b->val;
            
            ans->val = (val1+val2+carry)%10;
            carry = (val1+val2+carry)/10;
            if((a!= NULL &&a->next != NULL) ||(b != NULL&& b->next != NULL)|| carry != 0)
                ans->next= new ListNode();
            a = (a== NULL)? a:a->next;
            b = (b== NULL)? b:b->next;
            ans = ans->next;
        }
        
        return head;
    }
};
