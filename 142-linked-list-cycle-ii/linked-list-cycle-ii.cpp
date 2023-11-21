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
        //Brute Force using extra space
        unordered_set<ListNode*>st;
        ListNode* temp=head;
        while(temp!=NULL){
            if(st.find(temp)!=st.end())return temp;
            st.insert(temp);
            temp=temp->next;
        }
        return NULL;
        //optimal by slow and fast pointer approach
        // ListNode* slow=head;
        // ListNode* fast=head;
        // ListNode* entry=head;
        // int flag=0;
        // if(head==NULL || head->next==NULL)return NULL;

        // while(fast->next!=NULL && fast->next->next!=NULL){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         while(slow!=entry){
        //             slow=slow->next;
        //             entry=entry->next;
        //         }
        //         return slow;
        //     }
        // }
        // return NULL;
    }
};