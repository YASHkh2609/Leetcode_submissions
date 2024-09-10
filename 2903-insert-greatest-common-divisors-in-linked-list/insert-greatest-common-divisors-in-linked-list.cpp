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
private:
    int GCD(int a, int b){ 
        // Find Minimum of a and b 
        int result = min(a, b); 
        while (result > 0) { 
            if (a % result == 0 && b % result == 0) { 
                break; 
            } 
            result--; 
        } 
    
        // Return gcd of a and b 
        return result; 
    }
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* prev= head;
        ListNode* cur=head->next;

        while(cur!=NULL){
            int gcd = GCD(prev->val, cur->val);
            ListNode* temp = new ListNode(gcd);
            
            prev->next=temp;
            temp->next=cur;

            prev=cur;
            cur=cur->next;
        }
        return head;
    }
};