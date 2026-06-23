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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> qt;

        for(auto &head : lists)
        {
            while(head!=NULL)
            {
                qt.push(head->val);
                head=head->next;
            }
        }
        if(qt.size()==0) return NULL;
        ListNode* head=new ListNode(qt.top());
        ListNode* temp=head;
        qt.pop();
        while(!qt.empty())
        {
            temp->next=new ListNode(qt.top());
            temp=temp->next;
            qt.pop();
        }
        return head;
    }
};