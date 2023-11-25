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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL && list2==NULL)return NULL;
        else if(list1==NULL)return list2;
        else if(list2==NULL)return list1;
        // ListNode * temp1=list1;
        // ListNode* temp2=list2;
        // ListNode* buffer;
        ListNode* head=new ListNode();
        ListNode* anshead=NULL;
        // while(temp1!=NULL && temp2!=NULL){
        //     if(temp1->val<temp2->val){
        //         buffer=temp1->next;
        //         temp1->next=temp2;
        //         if(head==NULL){
        //             head=temp1;
        //         }
        //         temp1=buffer;
        //     }
        //     else{
        //         buffer=temp2->next;
        //         temp2->next=temp1;
        //         if(head==NULL){
        //             head=temp2;
        //         }
        //         temp2=buffer;
        //     }
        // }
        while(list1!=NULL && list2!=NULL){
            if(list1->val<= list2->val){
                head->next=list1;
                list1=list1->next;
                head=head->next;
                if(anshead==NULL)anshead=head;
            }
            else{
                head->next=list2;
                list2=list2->next;
                head=head->next;
                if(anshead==NULL)anshead=head;
            }
        }
        if(list1==NULL)head->next=list2;
        else if(list2==NULL)head->next=list1;
        return anshead;
    }
};