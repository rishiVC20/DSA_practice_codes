#include <iostream>
#include<queue>
using namespace std;

class Node{
    public: int data;
            Node* left;
            Node* right;
            Node(int d){
                this->data = d;
                this->left = NULL;
                this->right = NULL;
            }
};

Node* insertToBST(Node* root, int d){
    //base case
    if (root == NULL){
        root = new Node(d);
        return root; 
    }
    if (d > root->data){
        //right part
        root->right = insertToBST(root->right, d);
    }
    else{
        //left part
        root->left = insertToBST(root->left, d);
    }

    return root;

}

void takeInput(Node* &root){
    int data;
    cin>>data;
    while (data != -1)
    {
        /* code */
        root = insertToBST(root,data);
        cin>>data;
    }
    
}

void postOrder(Node* root){
    //base case
    if (root == NULL)
        return;

     
    postOrder(root->left);   
    postOrder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node* root){
    if (root == NULL)
        return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);     
}

void preOrder(Node* root){
    //base case
    if (root == NULL)
        return;

    cout<<root->data<<" "; 
    preOrder(root->left);   
    preOrder(root->right); 
}

void levelOrderTraversal(Node* root){
    queue <Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if (temp == NULL){
            //purana level complete traverse krna
            cout<<endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* minVal(Node* root){
    Node* temp = root;
    while (temp->left != NULL)
    {
        /* code */
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root){
    Node* temp = root;
    while (temp->right != NULL)
    {
        /* code */
        temp = temp->right;
    }
    return temp;
}

Node* deleteFromBST(Node* root, int val)
{
    //base case
    if (root == NULL)
        return NULL;

    if (root->data == val)
    {
        //0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        //1 child (left)
        if (root->left != NULL && root->right == NULL)
        {
            Node* temp = root->left;
            delete root;
            return temp;
        } 
        //1 child (right)
        if (root->left == NULL && root->right != NULL)
        {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        //2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right)->data; 
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    } 
    else if (root->data > val)
    {
        //left part me jao
        root->left = deleteFromBST(root->left, val);
    }   
    else{
        root->right = deleteFromBST(root->right, val);
    }
}

int main(){
    Node* root = NULL;
    cout<<"Enter data to create BST "<<endl;
    takeInput(root);
    
    cout<<"Printing the BST "<<endl;
    inorder(root);
    cout<<endl;
    
    cout<<"Printing in inorder"<<endl;
    inorder(root);
    cout<<endl;
    
    cout<<"Printing in postorder"<<endl;
    postOrder(root);
    cout<<endl;
    
    cout<<"Printing in preorder"<<endl;
    preOrder(root);
    cout<<endl;

    cout<<"Printing in level order traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;

    cout<<"Minimum value is "<<minVal(root)->data<<endl;

    cout<<"Maximum value is "<<maxVal(root)->data<<endl;

    root = deleteFromBST(root, 30);
    
    cout<<"Printing in level order traversal"<<endl;
    levelOrderTraversal(root);
    cout<<endl;


return 0;
}