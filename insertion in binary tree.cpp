#include<bits/stdc++.h> 
  
struct Node 
{ 
    int key; 
    struct Node *left, *right, *parent; 
}; 
  
struct Node *newNode(int item) 
{ 
    struct Node *temp =  new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    temp->parent = NULL; 
    return temp; 
} 
   
void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("Node : %d, ", root->key); 
        if (root->parent == NULL) 
          printf("Parent : NULL \n"); 
        else
          printf("Parent : %d \n", root->parent->key); 
        inorder(root->right); 
    } 
} 
  

struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
    { 
        Node *lchild = insert(node->left, key); 
        node->left  = lchild; 
  
        lchild->parent = node; 
    } 
    else if (key > node->key) 
    { 
        Node *rchild = insert(node->right, key); 
        node->right  = rchild; 
  
        rchild->parent = node; 
    } 
  
    return node; 
} 


/*driver program
int main()
{
struct Node *root= NULL;
root= insert(root, 50);
insert(root, 30);
insert(root, 20);
insert(root, 40);
insert(root, 70);
insert(root, 60);
insert(root, 80);
return 0;
}
Output
 Node : 20, Parent : 30 
 Node : 30, Parent : 50 
 Node : 40, Parent : 30 
 Node : 50, Parent : NULL 
 Node : 60, Parent : 70 
 Node : 70, Parent : 50 
 Node : 80, Parent : 70
*/
