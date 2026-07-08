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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* merged_head;
        // ListNode* p = head1;
        // while(p != NULL){
        //     cout<<p->val<<" -> ";
        //     p = p->next;
        // }
        // cout<<"second";
        // p = head2;
        // while(p != NULL){
        //     cout<<p->val<<" -> ";
        //     p = p->next;
        // }
        
        if(head1->val >head2->val){
            merged_head = head2;
            head2 = head2->next;
        }else{
            merged_head = head1;
            head1 = head1->next;
        }
        ListNode* tracker = merged_head;
        while(head1 != NULL && head2 != NULL){
            if(head1->val >head2->val){
                tracker->next = head2;
                tracker = tracker->next;
                head2 = head2->next;
            }else{
                tracker->next = head1;
                tracker = tracker->next;
                head1 = head1->next;
            }
        }
        if(head1 != NULL){
            tracker->next = head1;
        }
        else if(head2 != NULL){
            tracker->next = head2;
        }
        // p = merged_head;
        // cout<< "after merge";
        //  while(p != NULL){
        //     cout<<p->val<<" -> ";
        //     p = p->next;
        // }
        // cout<<endl<<endl;
        return merged_head;
    }
    ListNode* ms(ListNode* &head){
        if(head == NULL || head->next == NULL)return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* head2 = slow->next;
        slow->next = NULL;
        ms(head);
        ms(head2);
        head = merge(head,head2);
        return head;
    }
    ListNode* sortList(ListNode* head) {
        return ms(head);
       
        
    }
};