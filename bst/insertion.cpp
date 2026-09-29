#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node*left;
    node*right;
    node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
node* insertIntoBST(node* root, int val) {
        if(root==NULL){
            node* NN=new node(val);
            return NN;
        }
        if(root->val>val){
        root->left=insertIntoBST(root->left,val);
        }
        else
        root->right=insertIntoBST(root->right,val);

        return root;
}
bool search(node*root,int val){
    if(root==NULL){
        return 0;
    }
    if(root->val==val)
    return 1;
    
    if(root->val>val){
        return search(root->left,val);
    }
    else
    return search(root->right,val);
}
node*findmin(node*root){
    while(root&&root->left){
        root=root->left;
    }
    return root;
}
node*deleteNode(node*root,int key){
    if(!root)
    return NULL;
    if(root->val>key){
        root->left=deleteNode(root->left,key);
    }
    else if(root->val<key){
        root->right= deleteNode(root->right,key);
    }
    else{
        if(!root->left){
            node*temp=root->right;
            delete(root);
            return temp;
        }
        if(!root->right){
            node*temp=root->left;
            delete(root);
            return temp;
        }
        node*successor=findmin(root->right);
        root->val=successor->val;
        root->right=deleteNode(root->right,successor->val);
    }
    return root;
}
void inorder(node*root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
int main(){
    node*root=new node(10);
    insertIntoBST(root,9);
    //insertIntoBST(root,13);
    insertIntoBST(root,6);
    insertIntoBST(root,2);
    inorder(root);
    cout<<endl;
    bool ans=search(root,10);
    cout<<ans<<endl;
    root=deleteNode(root,10);
    inorder(root);
}