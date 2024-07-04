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
    ListNode* mergeNodes(ListNode* head) {
        ListNode * temp = new ListNode(-1);
        ListNode * copy =temp;
        ListNode * cur = head->next;
        ListNode* prev=head;
        int sum=0;
        while(cur!=NULL){
            if(cur->val!=0){
                sum+=cur->val;
            }
            else{
                ListNode * newNode = new ListNode(sum);
                temp->next=newNode;
                temp=temp->next;
                sum=0;
            }
            prev=cur;
            cur=cur->next;
        }
        return copy->next;
    }
};