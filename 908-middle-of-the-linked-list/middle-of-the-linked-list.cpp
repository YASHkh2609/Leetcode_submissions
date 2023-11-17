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
    ListNode* middleNode(ListNode* head) {
        // ListNode* temp=head;
        // int len=0;
        // while(temp!=NULL){
        //     len++;
        //     temp=temp->next;
        // }
        // temp=head;
        // if(len%2!=0){
        //     for(int i=1;i<(len+1)/2;i++){
        //         temp=temp->next;
        //     }
        // }
        // else{
        //     for(int i=1;i<(len)/2+1;i++){
        //         temp=temp->next;
        //     }
        // }
        // return temp;
        ListNode * slow=head;
        ListNode * fast=head;
        while(fast->next!=NULL && fast!=NULL ){
            slow=slow->next;
            fast=fast->next->next;
            if(fast==NULL)return slow;
        }
        return slow;
    }
};