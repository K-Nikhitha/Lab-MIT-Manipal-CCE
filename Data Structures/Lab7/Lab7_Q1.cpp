#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Node{
    public:
        int data;
        Node *lc, *rc;
};

class Tree{
    Node *root;
    public:
        Tree(){
        root=NULL;
        }
        Node* create(){
            cout<<"Use -1 to break."<<endl;
            Node *temp= new Node;
            if(root==NULL) root = temp;
            int val;
            cout<<"Enter the value: ";
            cin>>val;
            if(val==-1) return NULL;
            temp->data = val;
            cout<<"Left child of "<<temp->data<<": ";
            temp->lc = create();
            cout<<"Right child of "<<temp->data<<": ";
            temp->rc = create();
        }
        void iterativePreorder(){
            stack <Node*> S;
            Node *curr= root;
            cout<<"Iterative Preorder Traversal: ";
            if(root==NULL) return;
            S.push(curr);
            while(!S.empty()){
                curr = S.top();
                S.pop();
                cout<<curr->data<<' ';
                if(curr->rc) S.push(curr->rc);
                if(curr->lc) S.push(curr->lc);
            }
            cout<<endl;
        }
        void iterativeInorder(){
            stack <Node*> S;
            Node *curr=root;
            cout<<"Iterative Inorder Traversal: ";
            if(root==NULL) return;
            while(curr!=NULL || !S.empty()){
                while(curr!=NULL){
                    S.push(curr);
                    curr = curr->lc;
                }
                curr = S.top();
                S.pop();
                cout<<curr->data<<' ';
                curr = curr->rc;
            }
            cout<<endl;
        }
        void iterativePostorder(){
            stack <Node*> S;
            Node *curr=root;
            cout<<"Iterative Postorder Traversal: ";
            if(root==NULL) return;
            do{
                while(curr){
                    if(curr->rc) S.push(curr->rc);
                    S.push(curr);
                    curr = curr->lc;
                }
                curr = S.top();
                S.pop();
                if(curr->rc && S.top()==curr->rc){
                    S.pop();
                    S.push(curr);
                    curr = curr->rc;
                }
                else{
                    cout<<curr->data<<' ';
                    curr = NULL;
                }
            }while(!S.empty());
            cout<<endl;
        }
        int countleafs(Node *node){
            static int count=0;
            if(node == NULL){
                count++;
                return 0;
            }
            countleafs(node->lc);
            countleafs(node->rc);
            return count;
        }
        void leafs(){
            cout<<"Leafs present: "<<countleafs(root)/2<<endl;
        }

};

int main(){
    Tree T;
    int choice, loc, elem, x;
    while(1){
        cout<<"1. Create a binary tree"<<endl;
        cout<<"2. inorder"<<endl;
        cout<<"3. postorder"<<endl;
        cout<<"4. predorder"<<endl;
        cout<<"4. number of leaf nodes"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>x;
        if(x==0) break;
        switch(x){
            case 1:
                T.create();
                break;
            case 2:
                T.iterativeInorder();
                break;
            case 3:
                T.iterativePostorder();
                break;
            case 4:
                T.iterativePreorder();
                break;
            case 5:
                T.leafs();
                break;
            case 6:
                cout<<"Exit";
                return 0;
            default:
                cout<<"Invalid option.\n";
                break;
        }
    }
    return 0;
}
