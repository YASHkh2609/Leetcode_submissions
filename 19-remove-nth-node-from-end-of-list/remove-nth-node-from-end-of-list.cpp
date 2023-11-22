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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //Brute Force TC: O(2N)
        // ListNode* temp=head;
        // int len=0;
        // while(temp!=NULL){
        //     len++;
        //     temp=temp->next;
        // }
        // int pos=len-n+1;
        // if(pos==1){
        //     ListNode* temp1=head;
        //     head=head->next;
        //     temp1->next=NULL;
        //     delete(temp1);
        //     return head;
        // }
        // ListNode* prev=head;
        // ListNode* cur=head->next;
        // int cnt=2;
        // while(cnt<pos){
        //     prev=cur;
        //     cur=cur->next;
        //     cnt++;
        // }
        // prev->next=cur->next;
        // cur->next=NULL;
        // delete(cur);
        // return head;
        
        //Optimal Solution
        if(head->next==NULL)return NULL;
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* slow=start;
        ListNode* fast=start;
        int cnt=0;
        while(cnt<n){
            fast=fast->next;
            cnt++;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        slow->next=slow->next->next;
        return start->next;
    }
};