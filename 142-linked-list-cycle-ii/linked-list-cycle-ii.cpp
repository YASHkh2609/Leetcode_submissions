/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // map<int,pair<int, ListNode*>>mpp;
        // int flag=0;
        // ListNode* temp=head;
        // while(flag==0){
        //     if(mpp.find({{temp->val,temp->next}})==mpp.end()){
        //         mpp.insert({temp->data,temp->next});
        //         temp=temp->next;
        //     }
        //     else{ 
        //         flag=1;
        //         return temp;
        //     }
        // }
        // return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* entry=head;
        int flag=0;
        if(head==NULL || head->next==NULL)return NULL;

        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                while(slow!=entry){
                    slow=slow->next;
                    entry=entry->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};