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

    ListNode * getKthNode(ListNode* head, int k){
        ListNode* temp=head;
        int cnt=1;
        while(temp!=NULL && cnt<k){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    ListNode*  reverse(ListNode * head){
        ListNode * temp=NULL;
        ListNode *next= head->next;
        while(head!=NULL){
            next= head->next;
            head->next = temp;
            temp= head;
            head=next;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * temp, * nextNode, * prevNode;
        temp=head;
        while(temp!=NULL){
            ListNode * kthNode = getKthNode(temp,k);
            if(kthNode==NULL){
                if(prevNode)prevNode->next= temp;
                break;
            }
            nextNode=kthNode->next;
            kthNode->next=NULL;
            kthNode = reverse(temp);
            if(temp==head){
                head=kthNode;
            }
            else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=nextNode;
        }   
        return head;
    }
};