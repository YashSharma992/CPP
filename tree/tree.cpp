#include<bits/stdc++.h>
#include<queue>
using namespace std;
struct node{
    char val;
    node*left;
    node*right;
    node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};
int countNodes(node*root){
    if(root==NULL)
    return 0;
    return 1+countNodes(root->left)+countNodes(root->right);
}
int countleaf(node*root){
    if(root==NULL)
    return 0;
    if(!root->left&&!root->right){
        return 1;
    }
    return countleaf(root->left)+countleaf(root->right);

}
int twochildnode(node*root){
    if(root==NULL)
    return 0;
    if(root->left!=NULL&&root->right!=NULL)
    return 1+twochildnode(root->left)+twochildnode(root->right);
    else
    return twochildnode(root->left)+twochildnode(root->right);
}
int onechildnode(node*root){
    if(root==NULL)
    return 0;
    if((root->left==NULL&&root->right!=NULL)||(root->left!=NULL&&root->right==NULL))
    return 1+onechildnode(root->left)+onechildnode(root->right);
    else
    return onechildnode(root->left)+onechildnode(root->right);
}
void preorder(node*root){
    if (root == NULL) {
        return;
    }
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node*root){
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void postorder(node*root){
    if (root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->val<<" ";
    
}
int height(node*root){
    if(root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}
node*insert(node*root,char val){
    if(!root){
        root=new node(val);
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }
        else{
            temp->left=new node(val);
            return root;
        }
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        else{
            temp->right=new node(val);
            return root;
        }
    }
}
node*cbt(node*root,char &val,queue<node*> &q){
    node*nn=new node(val);
    if(root==NULL)
    {
        root=nn;
        q.push(root);
        return root;
    }
    node*curr=q.front();
    if(curr->left==NULL)
    curr->left=nn;
    else if(curr->right==NULL)
    {
        curr->right=nn;
        q.pop();
    }
    q.push(nn);
    return root;
}
node* deleteNode(node* root, char key) {
    if (root == NULL)
        return NULL;

    if (!root->left && !root->right) {
        if (root->val == key) {
            delete root;
            return NULL;
        }
        return root;
    }

    queue<node*> q;
    q.push(root);

    node* del = NULL;
    node* curr = NULL;
    node* parent = NULL;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        if (curr->val == key)
            del = curr;

        if (curr->left) {
            parent = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent = curr;
            q.push(curr->right);
        }
    }

    if (del == NULL)
        return root;

    del->val = curr->val;

    if (parent->left == curr)
        parent->left = NULL;
    else
        parent->right = NULL;

    delete curr;

    return root;
}
bool isFullTree(node* root) {
        if(root==NULL)
        return 1;
        if(root->left==NULL&&root->right==NULL)
        return 1;
        if(root->left!= NULL&&root->right!= NULL){
            return isFullTree(root->left)&&isFullTree(root->right) ;
        }
        return 0;
}
vector<vector<char>>levelorder(node*root){
    vector<vector<char>>ans;
    if(root==NULL)
    return ans;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        vector<char>v;
        int level=q.size();
        for(int i=0;i<level;i++){
            node*curr=q.front();
            q.pop();
            v.push_back(curr->val);
            if(curr->left!=NULL)
            q.push(curr->left);
            if(curr->right!=NULL)
            q.push(curr->right);
        }
        ans.push_back(v);
    }
    return ans;
}
int main(){
    node*root=new node('A');
    root->left=new node('B');
    root->right=new node('C');
    root->left->left=new node('D');
    root->left->right=new node('E');
    cout<<countNodes(root)<<endl;
    cout<<countleaf(root)<<endl;
    cout<<twochildnode(root)<<endl;
    cout<<onechildnode(root)<<endl;
    preorder(root);
    cout << endl;

    inorder(root);
    cout << endl;

    postorder(root);
    cout << endl;
    cout<<height(root)<<endl;
    insert(root,'F');
    
    inorder(root);
    cout << endl;

    vector<vector<char>> ans = levelorder(root);

    for(auto level : ans){
        for(char x : level){
            cout << x << " ";
        }
        cout << endl;
    }
    int n;
    cin >> n;
    vector<char> arr(n);
    for(int i=0;i<n;i++)
    cin >> arr[i];
    queue<node*>q;
    for(int i=0;i<n;i++){
        cbt(root,arr[i],q);
    }
}