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

// Traversals
void inorderTraversal(struct Node* root) 
{
    if (root) 
	{
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

void preorderTraversal(struct Node* root) 
{
    if (root) 
	{
        printf("%d ", root->key);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

void postorderTraversal(struct Node* root) 
{
    if (root) 
	{
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->key);
    }
}

// Find smallest element
struct Node* findSmallestElement(struct Node* root) 
{
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Find largest element
struct Node* findLargestElement(struct Node* root) 
{
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

// Find inorder successor (smallest in right subtree)
struct Node* minValueNode(struct Node* node) 
{
    struct Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

struct Node* deleteNode(struct Node* root, int key) 
{
    if (root == NULL)
        return root;

    // Traverse the tree
    if (key < root->key) 
	{
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->key) 
	{
        root->right = deleteNode(root->right, key);
    }
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
        root->key = temp->key;  // Copy inorder successor's value
        root->right = deleteNode(root->right, temp->key);
    }

    return root;
}

// Count total nodes
int totalNodes(struct Node* root) 
{
    if (root == NULL)
        return 0;

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

// Count external (leaf) nodes
int totalExternalNodes(struct Node* root) 
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 1;

    return totalExternalNodes(root->left) + totalExternalNodes(root->right);
}

// Count internal nodes
int totalInternalNodes(struct Node* root) 
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;

    return 1 + totalInternalNodes(root->left) + totalInternalNodes(root->right);
}

// Height of the tree
int Height(struct Node* root) 
{
    if (root == NULL)
        return 0;

    int lh = Height(root->left);
    int rh = Height(root->right);

    return (lh > rh ? lh : rh) + 1;
}

// Delete entire tree
struct Node* deleteTree(struct Node* root) 
{
    if (root == NULL)
        return NULL;

    deleteTree(root->left);
    deleteTree(root->right);
    free(root);

    return NULL;
}

int main() 
{
    struct Node* tree = NULL;
    struct Node* ptr;
    int choice, val;

    while (1) 
	{
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n");
        printf("5. Find Smallest\n6. Find Largest\n7. Delete Node\n8. Total Nodes\n");
        printf("9. Total External Nodes\n10. Total Internal Nodes\n11. Height of Tree\n12. Delete Entire Tree\n13. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) 
		{
            case 1:
                printf("\nEnter the value of the new node: ");
                scanf("%d", &val);
                tree = insertElement(tree, val);
                break;

            case 2:
                printf("\nPreorder Traversal: ");
                preorderTraversal(tree);
                printf("\n");
                break;

            case 3:
                printf("\nInorder Traversal: ");
                inorderTraversal(tree);
                printf("\n");
                break;

            case 4:
                printf("\nPostorder Traversal: ");
                postorderTraversal(tree);
                printf("\n");
                break;

            case 5:
                ptr = findSmallestElement(tree);
                if (ptr)
                    printf("\nSmallest element is: %d", ptr->key);
                else
                    printf("\nTree is empty!");
                break;

            case 6:
                ptr = findLargestElement(tree);
                if (ptr)
                    printf("\nLargest element is: %d", ptr->key);
                else
                    printf("\nTree is empty!");
                break;

            case 7:
                printf("\nEnter the element to be deleted: ");
                scanf("%d", &val);
                tree = deleteNode(tree, val);
                break;

            case 8:
                printf("\nTotal no. of nodes = %d", totalNodes(tree));
                break;

            case 9:
                printf("\nTotal no. of external nodes = %d", totalExternalNodes(tree));
                break;

            case 10:
                printf("\nTotal no. of internal nodes = %d", totalInternalNodes(tree));
                break;

            case 11:
                printf("\nHeight of the tree = %d", Height(tree));
                break;

            case 12:
                tree = deleteTree(tree);
                printf("\nTree deleted.");
                break;

            case 13:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}
