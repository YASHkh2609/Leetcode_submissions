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
    ListNode* reverse(ListNode* head,ListNode* temp, ListNode*next){
        if(head==NULL){
            return temp;
        }
        next=head->next;
        head->next=temp;
        return reverse(next, head, next);

    }
    ListNode* reverseList(ListNode* head) {
        ListNode * temp=NULL;
        ListNode * next=NULL;
        // while(head!=NULL){
        //     next=head->next;
        //     head->next=temp;
        //     temp=head;
        //     head=next;
        // }

        return reverse(head, temp, next);
    }
};