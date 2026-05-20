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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = head;
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* even = odd ->next;
        ListNode* evencopy = even;
        int zipper = 1;
        while(odd->next!= NULL && even->next != NULL){
            if(zipper ==0){
                zipper ++;
                even->next = odd->next;
                even = even->next;
            }
            else {
                odd->next = even->next;
                odd = odd->next;
                zipper --;
            }
           
       }
        odd->next = evencopy;
        even->next = NULL;
        return head;
    }
};
