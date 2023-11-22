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
    void PutAtEnd(ListNode* &head, ListNode* &prev, ListNode* &tail){
        ListNode* cur=prev->next;
        prev->next=cur->next;
        cur->next=NULL;
        prev=prev->next;
        tail->next=cur;
        tail=tail->next;
        return;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return head;
        // ListNode* tail=head;
        // while(tail->next!=NULL){
        //     tail=tail->next;
        // }
        // ListNode* temp=head;
        // ListNode* second_node=head->next;
        // PutAtEnd(head,temp,tail);
        // while(temp!=second_node && temp->next!=second_node){
        //     PutAtEnd(head,temp,tail);
        // }
        // return head;
        ListNode* odd=head;
        ListNode* even=head->next;
        ListNode* evenhead=even;

        while(even!=NULL && even->next!=NULL){
            odd->next=odd->next->next;
            odd=odd->next;

            even->next=even->next->next;
            even=even->next;
        }
        odd->next=evenhead;
        return head;
    }
};