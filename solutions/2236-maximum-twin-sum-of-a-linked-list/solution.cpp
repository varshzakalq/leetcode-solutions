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
    int pairSum(ListNode* head) {
        auto p1= head;
        int sum =INT_MIN;
        vector<int>v;
        while(p1 != NULL){
            v.push_back(p1->val);
            p1 = p1->next;
        }
        int i =0;
        int j= v.size()-1;
        while(i<j){
            int s = v[i]+v[j];
            if(s>sum)sum =s;
            i++;
            j--;
        }
        return sum;

    }
};
