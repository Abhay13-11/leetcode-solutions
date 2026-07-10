/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) return NULL;
        queue<Node*> qt;
        qt.push(root);
        
        while(!qt.empty())
        {
            int n=qt.size();
            for(int i=0;i<n;i++){
            Node* node=qt.front();
            qt.pop();
            
            if(i==n-1 ||qt.empty()) node->next=NULL;
            else node->next=qt.front();
            if(node->left) qt.push(node->left);
            if(node->right) qt.push(node->right);
            }
        }
        return root;
    }
};