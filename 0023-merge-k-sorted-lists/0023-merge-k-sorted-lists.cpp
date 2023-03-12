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
    ListNode* sortedMerge(ListNode* a, ListNode* b){
        if(a==nullptr) return b;
        else if(b==nullptr) return a;
        ListNode* result;
        if(a->val<=b->val){
            result=a;
            result->next=sortedMerge(a->next,b);
        }
        else{
            result=b;
            result->next=sortedMerge(b->next,a);
        }
        return result;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0) return nullptr;
        int last=k-1;
        while(last!=0){
            int i=0;
            int j=last;
            while(i<j){
                lists[i]=sortedMerge(lists[i],lists[j]);
                
                i++;
                j--;
                
                if(i>=j){
                    last=j;
                }
            }
        }
        return lists[0];
    }
};