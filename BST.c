#include <stdio.h>
#include <stdlib.h>

// Define BST Node
struct Node
{
int key;
struct Node *left, *right;
};
// Create a new node
struct Node* newNode(int item)
{
struct Node* temp = malloc(sizeof(struct Node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
// Insert into BST
struct Node* insertElement(struct Node* root, int key)
{
if (root == NULL)
return newNode(key);
if (key < root->key)
root->left = insertElement(root->left, key);
else if (key > root->key)
root->right = insertElement(root->right, key);
return root;
}
// Find the node with minimum value (used in deletion)
struct Node* minValueNode(struct Node* node)
{
struct Node* current = node;
while (current && current->left != NULL)
current = current->left;
return current;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int key)
{
if (root == NULL)
return root;
if (key < root->key)
root->left = deleteNode(root->left, key);
else if (key > root->key)
root->right = deleteNode(root->right, key);
else
{
// Case 1: No child
if (root->left == NULL && root->right == NULL)

{
free(root);
return NULL;
}
// Case 2: One child
else if (root->left == NULL)

{

struct Node* temp = root->right;
free(root);
return temp;
}

else if (root->right == NULL)
{

struct Node* temp = root->left;
free(root);
return temp;
}
// Case 3: Two children
struct Node* temp = minValueNode(root->right);
root->key = temp->key;
root->right = deleteNode(root->right, temp->key);
}
return root;
}

// Search for an element in BST
struct Node* searchElement(struct Node* root, int key)
{
if (root == NULL || root->key == key)
return root;
if (key < root->key)
return searchElement(root->left, key);
else
return searchElement(root->right, key);
}
// Display inorder traversal (to check tree contents)
void inorderTraversal(struct Node* root)
{
if (root)
{
inorderTraversal(root->left);
printf("%d ", root->key);
inorderTraversal(root->right);
}
}
int main()
{
struct Node* tree = NULL;
struct Node* ptr;
int choice, val;
while (1)
{
printf("\n--- Binary Search Tree Menu ---\n");
printf("1. Insert\n2. Delete\n3. Search\n4. Display (Inorder)\n5.Exit\n");
printf("Enter choice: ");
scanf("%d", &choice);

switch (choice)

{
case 1:
printf("\nEnter the value to insert: ");
scanf("%d", &val);
tree = insertElement(tree, val);
break;
case 2:
printf("\nEnter the value to delete: ");
scanf("%d", &val);
tree = deleteNode(tree, val);
break;
case 3:
printf("\nEnter the value to search: ");
scanf("%d", &val);
ptr = searchElement(tree, val);
if (ptr)
printf("\nElement %d found in the tree.", val);
else
printf("\nElement %d not found in the tree.", val);
break;
case 4:
printf("\nInorder Traversal: ");
inorderTraversal(tree);
printf("\n");
break;
case 5:
exit(0);
default:
printf("\nInvalid choice!");
}
}
return 0;
}
