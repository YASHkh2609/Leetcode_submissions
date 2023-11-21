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
    ListNode* reverse(ListNode* Head){
        ListNode* temp=NULL;
        ListNode* next=NULL;
        while(Head!=NULL){
            next=Head->next;
            Head->next=temp;
            temp=Head;
            Head=next;
        }
        return temp;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode * temp=slow->next;
        temp=reverse(temp);
        fast=head;
        while(temp!=NULL){
            if(fast->val==temp->val){
                fast=fast->next;
                temp=temp->next;
            }
            else return false;
        }
        return true;
    }
};