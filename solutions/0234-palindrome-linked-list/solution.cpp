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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* prev = NULL;
        ListNode* curr = slow;
        
        while(curr != NULL){
            ListNode* next_node= curr->next;
            curr ->next = prev;
            prev = curr;
            curr = next_node;
            
        }
        while(prev != NULL){
            if(prev->val != head->val)return false;
            else{
                prev = prev->next;
                head = head->next;

            }
        }
        return true;
    //     if(head == NULL)return true;
    //     if(head ->next == NULL)return true;
    //     long long  num =0;
    //     ListNode* temp = head;
    //     while(temp != NULL){
    //         num = (num*10) +temp->val;
    //         temp= temp->next;
    //     }
    //     long long rev =0;
    //     long long tem1 =num;
    //     while(tem1 >0){
    //         rev = rev*10 +tem1%10;
    //         tem1 /= 10;
    //     }
    //    // cout<<num<<" "<<rev;
    //     return num == rev;
    }
};
