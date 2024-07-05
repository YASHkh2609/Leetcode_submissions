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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* l, *mid, *r;
        l=head;
        mid=head->next;
        r=mid->next;
        int first=-1,prev= -1;
        int cur=-1;
        int midcnt=0;
        int minDist=INT_MAX;
        while(r!=NULL){
            if((mid->val<l->val && mid->val<r->val) || (mid->val>l->val && mid->val >r->val)){
                if(first==-1){
                    first = midcnt;
                    prev=midcnt;
                }
                else {
                    cur = midcnt;
                    minDist = min(minDist, cur - prev);
                    prev=cur;
                }
            }
            midcnt++;
            l=mid;
            mid=r;
            r=r->next;
        }
        int maxDist = cur - first;
        if(cur==-1)return{-1,-1};
        return {minDist, maxDist};
    }
};