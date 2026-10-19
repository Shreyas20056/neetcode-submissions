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
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val<=l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        if(l1!=nullptr){
            curr->next=l1;
        }else{
            curr->next=l2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        int k=lists.size();
        while(k>1){
            int i=0;
            for(int j=0;j<k/2;j++){
                lists[i]=merge(lists[2*j],lists[2*j+1]);
                i++;
            }
            if(k%2==1){
                lists[i]=lists[k-1];
                i++;
            }
            k=i;
        }
        return lists[0];
    }
};
