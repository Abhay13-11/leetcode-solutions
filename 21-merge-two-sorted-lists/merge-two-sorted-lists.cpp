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
    ListNode* mergeTwoLists(ListNode* h1, ListNode* h2) {
                    if(h1==NULL) return h2;
                    if(h2==NULL) return h1;
                    if(h1->val>h2->val) return mergeTwoLists(h2,h1);
                    ListNode* head=h1;
                    while(h1!=NULL && h2!=NULL)
                    {
                        ListNode* temp=NULL;
                        while(h1!=NULL && h1->val<=h2->val)
                        {
                            temp=h1;
                            h1=h1->next;
                        }
                        temp->next=h2;
                        swap(h1,h2);
                    }
                    return head;
        
    }
};