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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int k=nodes.size();
        int index=k-n;
        if(index<0) return nullptr;
        if(index==0) return head->next;
        nodes[index-1]->next=nodes[index]->next;
        return head;
    }
};
