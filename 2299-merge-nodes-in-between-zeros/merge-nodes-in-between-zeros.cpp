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
        ListNode * tobeModified = head->next;
        ListNode * cur = tobeModified->next;
        int sum=0;
        while(cur!=NULL){
            if(cur->val!=0){
                sum+=cur->val;
                cur=cur->next;

            }
            else{
                tobeModified->val+=sum;
                tobeModified->next=cur->next;
                if(tobeModified->next==NULL)break;
                tobeModified=tobeModified->next;
                cur=tobeModified->next;
                sum=0;
            }
        }
        return head->next;
    }
};