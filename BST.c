#include <stdio.h>
   struct node{
   	struct node *left;
   	struct node *right;
   	int data;
   };
   struct node * newNode(int value){
   		struct node * temp = (struct node * )malloc(sizeof(struct node));
   		temp->left = NULL;
   		temp->right = NULL;
   		temp->data = value;
   		return temp;
   }
   struct node* insert(struct node* root, int data)
    {
        if (root == NULL)    //If the tree is empty, return a new,single node
            return newNode(data);
        else
        {
            //Otherwise, recur down the tree 
            if (data <= root->data)
                root->left  = insert(root->left, data);
            else
                root->right = insert(root->right, data);
            //return the (unchanged) root pointer 
            return root;
        }
    }
    void preOrderTraversal(struct node *root){
    	if(root == NULL)
    		return;
    	printf("%d\n", root->data);
    	preOrderTraversal(root->left);
    	preOrderTraversal(root->right);
    }
    struct node *find(struct node *root, int x){
    	if(root == NULL)
    		return NULL;
    	else if(x < root->data)
    		return find(root->left, x);
    	else if(x > root->data)
    		return find(root->right, x);
    	else
    		return root;
    }
    
int main()
{
    int n, temp, q, result = 0, i;
    scanf("%d", &n);
    struct node *root;
    for(i = 0; i < n; i++){
    	scanf("%d", &temp);
    	root = insert(root, temp);
    }
    scanf("%d", &q);
    preOrderTraversal(find(root, q));
   
    return 0;
}
