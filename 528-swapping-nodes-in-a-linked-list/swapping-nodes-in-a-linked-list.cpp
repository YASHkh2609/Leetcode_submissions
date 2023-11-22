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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int len=0;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        int cnt=1;
        while(cnt<=len-k){
            fast=fast->next;
            cnt++;
        }
        cnt=1;
        while(cnt<k){
            slow=slow->next;
            cnt++;
        }
        swap(slow->val,fast->val);
        return head;
    }
};