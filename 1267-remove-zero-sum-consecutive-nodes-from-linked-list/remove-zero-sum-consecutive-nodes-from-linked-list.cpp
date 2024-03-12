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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // ListNode* temp=head;
        // vector<int>v;
        // while(temp!=NULL){
        //     v.push_back(temp->val);
        //     temp=temp->next;
        // }
        // int i=0;
        // while(i<v.size()){
        //     int sum=0;
        //     bool flag=false;
        //     for(int j=i;j<v.size();j++){
        //         sum+=v[j];
        //         if(sum==0){
        //             for(int k=i;k<=j;k++){
        //                 v[k]=1001;
        //             }
        //             i=j+1;
        //             flag=true;
        //             break;
        //         }
        //     }
        //     if(!flag)i++;
        // }
        // ListNode* start=new ListNode();
        // ListNode * cur;
        // for(int i=0;i<v.size();i++){
        //     if(v[i]!=1001){
        //         if(start->next==NULL)
        //         {
        //             ListNode* temp = new ListNode(v[i]);
        //             start->next=temp;
        //             cur=start->next;
        //         }
        //         else{
        //             cur->next= new ListNode(v[i]);
        //             cur=cur->next;
        //         }
        //     }
        // }
        // return start->next;
        ListNode * start = new ListNode();
        start->next=head;
        ListNode * prev=start;
        ListNode* i= head, *j;
        while(i!=NULL){
            int sum=0;
            j=i;
            bool flag=false;
            while(j!=NULL){
                sum+=j->val;
                if(sum==0){
                    flag=true;
                    if(i==head){
                        start->next=j->next;
                        i=j->next;
                        j->next=NULL;
                        break;
                    }
                    else{
                        prev->next=j->next;
                        i=j->next;
                        j->next=NULL;
                        break;
                    }
                }
                else{
                    j=j->next;
                }
            }
            if(!flag){
                prev=i;
                i=i->next;
            }
        }
        return start->next;
    }
};