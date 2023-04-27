#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

//search
struct node* searchBST (struct node* node , int data){
    if (data == node->key ){
        return node;
    }
    if (data > node->key and node->right != nullptr){
        return searchBST(node->right , data);
    }
    else if (data < node->key and node->left != nullptr){
        return searchBST(node->left , data);
    }
    else {
        return nullptr;
    }
}

//find previous node
struct node* prevNode (node*root , node* node ){
    //used to get the previous node of a desired node
    if (root->right == node){
        return root;
    }
    else if (root->left == node){
        return root;
    }
    if (node->key > root->key and root->right != nullptr){
        return prevNode(root->right , node);
    }
    else if (node->key < root->key and root->left != nullptr){
        return prevNode(root->left , node);
    }
    else {
        return root;
    }
}

//maximum element
struct node* maxElement (node* node ){
    auto ptr = node->left;
    while (ptr->right != nullptr){
        ptr = ptr->right;
    }
    return ptr;
}

// Inorder traversal
void traverseInOrder(struct node *root) {
        if (root == NULL){
            return ;
        }
        traverseInOrder(root->left);
        ::printf("%i ", root->key );
        traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (node == nullptr) {
        node = new struct node();
        node->key = key;
        return node;
    }
    if ( key > node->key){
        node->right = insertNode(node->right , key);
    }
    else if ( key < node->key){
        node->left =insertNode(node->left , key);
    }
    else if (key == node->key){
        return node;
    }
    return node;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key) {
    node* ptr = searchBST(root , key);
    node* previousPtr = prevNode(root, ptr);
        //if the element is not in the tree
        if (ptr == nullptr){
            return root;
        }

        //deletion if the node is a leaf ;
        if (ptr->left == nullptr and ptr->right == nullptr) {
            if (previousPtr->left == ptr){
                previousPtr->left = nullptr;
            }
            if (previousPtr->right == ptr){
                previousPtr->right = nullptr;
            }
            return root;
        }

            //deletion if the node has only one child;
        else if (ptr->left != nullptr xor  ptr->right != nullptr){
            if (previousPtr->left == ptr and ptr->left != nullptr){
                previousPtr->left = ptr->left;
            }
            if (previousPtr->left ==ptr and ptr->right != nullptr){
                previousPtr->left = ptr->right;
            }
            if (previousPtr->right == ptr and ptr->left != nullptr){
                previousPtr->right = ptr->left;
            }
            if (previousPtr->right == ptr and ptr->right != nullptr){
                previousPtr->right = ptr->right;
            }
            return root;
        }

            //deletion if the node has 2 children ;
        else if (ptr->right != nullptr and ptr->left != nullptr) {
            auto maxOnLeft = maxElement(ptr);
            auto prev = prevNode(ptr, maxOnLeft);
            ptr->key = maxOnLeft->key;
            prev->right = nullptr;
            return root;
        }
}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }
  
  traverseInOrder(root);
}