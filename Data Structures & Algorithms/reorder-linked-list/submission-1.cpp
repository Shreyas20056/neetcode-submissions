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
        vector<ListNode*> nodes;
        ListNode* temp=head;
        while(temp){
            nodes.push_back(temp);
            temp=temp->next;
        }
        int n=nodes.size();
        int i=0,j=nodes.size()-1;
        while(i<j){
            nodes[i]->next=nodes[j];
            i++;
            if(i>=j) break;
            nodes[j]->next=nodes[i];
            j--;
        }
        nodes[i]->next=nullptr;
        return;
    }
};
