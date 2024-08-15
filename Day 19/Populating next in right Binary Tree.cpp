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
     if(root==nullptr)return root;
     Node* prev=nullptr;
     int level=0;
     queue<pair<Node*,int>> q;
     q.push({root,0});
     while(!q.empty()){
        Node* currNode = q.front().first;
        int currLevel = q.front().second;
        q.pop();
        if(currNode==nullptr)continue;
        q.push({currNode->left,currLevel+1});
        q.push({currNode->right,currLevel+1});
        if(currLevel==level && prev!=nullptr){
            prev->next=currNode;
        }
        level=currLevel;
        prev=currNode;
     }
     return root;
    }
};