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
        vector<int>criticalPoints;
        int midcnt=1;

        while(r!=NULL){
            if((mid->val<l->val && mid->val<r->val) || (mid->val>l->val && mid->val >r->val)){
                criticalPoints.push_back(midcnt);
            }
            midcnt++;
            l=mid;
            mid=r;
            r=r->next;
        }
        vector<int>ans(2, -1);
        if(criticalPoints.size()<2)return ans;
        int n=criticalPoints.size();
        ans[1] = criticalPoints[n-1] - criticalPoints[0];
        int minDist = INT_MAX;
        for(int i=0;i<n-1;i++){
            minDist = min(minDist, criticalPoints[i+1]-criticalPoints[i]);
        }
        ans[0] = minDist;
        return ans;
    }
};