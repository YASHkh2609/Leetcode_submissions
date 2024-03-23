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
    void reorderList(ListNode* head) {
        if(head->next==NULL)return;
        vector<ListNode*>nodes;
        ListNode* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int i=1, j=nodes.size()-1, cnt=0;
        head->next=NULL;
        while(i<=j){
            if(cnt%2==0){
                if(j==nodes.size()-1){
                    head->next=nodes[j];
                    temp=head->next;
                }
                else{
                    temp->next=nodes[j];
                    temp=temp->next;
                }
                j--;
            }
            else{
                temp->next=nodes[i];
                temp=temp->next;
                i++;
            }
            cnt++;
        }
        temp->next=NULL;
    }
};