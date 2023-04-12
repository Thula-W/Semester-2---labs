#include <iostream>
using namespace  std;

struct node {
    int data;
    node* left;
    node* right;
};

struct node* addNode (int data){
    auto node = new struct node;
    node->left = nullptr;
    node->right = nullptr;
    node->data = data;
    return node;
}

class binarySearchTree {
public:
    node* root ;
    explicit binarySearchTree (int data){
        this->root = addNode(data);
    }

    node* addElements(struct node* root , int data){
        if (root == nullptr){
            root =  addNode(data);
            return root;
        }
        if ( data > root->data){
            root->right = addElements(root->right , data);
        }
        else if ( data < root->data){
            root->left = addElements(root->left , data);
        }
        else if (data == root->data){
            return root;
        }
        return root;
    }

    void inOrderDisplay (struct node* node){
        if (node == NULL){
            return ;
        }
        inOrderDisplay(node->left);
        ::printf("%i ", node->data );
        inOrderDisplay(node->right);
    }

    void preOrderDisplay (struct node* node){
        if (node == NULL){
            return ;
        }
        ::printf("%i " , node->data);
        preOrderDisplay(node->left);
        preOrderDisplay(node->right);
    }

    void postOrderDisplay (struct node* node){
        if (node== nullptr){
            return;
        }
        postOrderDisplay(node->left);
        postOrderDisplay(node->right);
        ::printf("%i " , node->data);
    }

    struct node* searchBST (struct node* node , int data){
        if (data == node->data ){
            return node;
        }
        if (data > node->data and node->right != nullptr){
            return searchBST(node->right , data);
        }
        else if (data < node->data and node->left != nullptr){
            return searchBST(node->left , data);
        }
        else {
            return nullptr;
        }
    }

    node* deleteElement (int data){
        node* ptr  = searchBST(this->root,data);
        node* previousPtr= prevNode(this->root , ptr);
        //if the element is not in the tree
        if (ptr == nullptr){
            return this->root;
        }

        //deletion if the node is a leaf ;
        if (ptr->left == nullptr and ptr->right == nullptr) {
            if (previousPtr->left == ptr){
                previousPtr->left = nullptr;
            }
            if (previousPtr->right == ptr){
                previousPtr->right = nullptr;
            }
            return this->root;
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
            return this->root;
        }

        //deletion if the node has 2 children ;
        else if (ptr->right != nullptr and ptr->left != nullptr){
            auto maxOnLeft = maxElement(ptr);
            auto prev = prevNode(ptr , maxOnLeft);
            ptr->data = maxOnLeft->data;
            prev->right = nullptr;
            return this->root;
        }
    }

private:
    struct node* prevNode (node*root , node* node ){
    //used to get the previous node of a desired node
        if (root->right == node){
            return root;
        }
        else if (root->left == node){
            return root;
        }
        if (node->data > root->data and root->right != nullptr){
            return prevNode(root->right , node);
        }
        else if (node->data < root->data and root->left != nullptr){
            return prevNode(root->left , node);
        }
        else {
            return root;
        }
    }

    struct node* maxElement (node* node ){
        auto ptr = node->left;
        while (ptr->right != nullptr){
            ptr = ptr->right;
        }
        return ptr;
    }
};

int main() {
    auto bst = new binarySearchTree(6);
    bst->root = bst->addElements(bst->root,9);
    bst->root = bst->addElements(bst->root , 4);
    bst->root = bst->addElements(bst->root, 7);
    bst->root = bst->addElements(bst->root , 10);
    bst->root = bst->addElements(bst->root , 8);
    bst->inOrderDisplay(bst->root);
    cout<<"\n";
    bst->preOrderDisplay(bst->root);
    cout<<"\n";
    bst->postOrderDisplay(bst->root);
    cout<<"\n";
    bst->root = bst->deleteElement(9);
    bst->inOrderDisplay(bst->root);

    return 0;
}
