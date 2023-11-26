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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)return head;
        ListNode * prev=head;
        ListNode * cur=head->next;
        while(cur!=NULL){
            if(prev->val!=cur->val){
                prev=cur;
                cur=cur->next;
            }
            else{
                while(cur!=NULL && cur->val==prev->val){
                    cur=cur->next;
                }
                if(cur==NULL){
                    prev->next=NULL;
                    break;
                }
                prev->next=cur;
                prev=cur;
                cur=cur->next;
            }
        }
        return head;
    }
};