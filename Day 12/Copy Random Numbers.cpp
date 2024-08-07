/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    int findIndex(Node* head,Node* target){
        Node* temp=head;
        int ans=0;
        while(temp!=target){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    Node* getNode(Node* head,int target){
        Node* ans=nullptr,*temp=head;
        int curr=0;
        while(temp!=nullptr){
            if(curr==target)return temp;
            curr++;
            temp=temp->next;
        }
        return ans;
    }
    Node* copyRandomList(Node* head) {
        Node* ans=nullptr,*temp1=head,*ansTail=NULL;
        while(temp1!=NULL){
            Node* x = new Node(temp1->val);
            if(ans==NULL){
                ans=x;
                ansTail=x;
            }else{
                ansTail->next=x;
                ansTail=ansTail->next;
            }
            temp1=temp1->next;
        }
        Node* temp2=head;
        temp1=ans;
        while(temp1!=nullptr){
            if(temp2->random==nullptr){
                temp1->random==nullptr;
            }
            else{
                int index=findIndex(head,temp2->random);
                Node* currRandom = getNode(ans,index);
                temp1->random=currRandom;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return ans;
    }
};