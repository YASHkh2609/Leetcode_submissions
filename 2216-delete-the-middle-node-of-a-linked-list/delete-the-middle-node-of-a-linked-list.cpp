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
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next==NULL)return NULL;
        else if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
        ListNode* start=new ListNode();
        start->next=head;
        ListNode* temp=start;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            temp=temp->next;
            slow=slow->next;
            fast=fast->next->next;
        }

        temp->next=slow->next;
        slow->next=NULL;
        delete(slow);
        return head;


    }
};