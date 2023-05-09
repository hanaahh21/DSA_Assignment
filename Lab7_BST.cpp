#include <iostream>
using namespace std;

struct node 
{
  int key;
  struct node *left, *right;
};

//create new nodes
struct node *newNode(int key)
{
  struct node *new_node = new node;
  new_node->key = key;
  new_node->left =NULL;
  new_node->right = NULL;
  return new_node;
}

// Inorder traversal
void traverseInOrder(struct node *root) 
{
  if (root==NULL) return;
  
  //traverse left
  traverseInOrder(root->left);
  //print root
  cout << root->key << ",";
  //traverse left
  traverseInOrder(root->right);
}

// Insert a node
struct node *insertNode(struct node *node, int key) 
{
  if (node==NULL) return newNode(key);

  //insert left if key is smaller
  if (key < node->key) 
  {
    if (node->left==NULL){
        node->left = newNode(key);
    }
    else insertNode(node->left, key);
    
  }//insert right if key is bigger
  else if (key > node->key) 
  {
    if (node->right==NULL){
        node->right = newNode(key);
    } 
    else insertNode(node->right, key);
  }

  return node;
}

// to find the minimum value in given sub root tree
struct node *minValNode(struct node *node) 
{
  struct node *temp = node;

  while (temp && temp->left != NULL)
    temp = temp->left;

  return temp;
}

// Deleting a node
struct node *deleteNode(struct node *node, int key) 
{
  if (node == NULL)
    return node;

  if (key == node->key) 
  {
    // Case 1: Node with no children
    if (node->left == NULL && node->right == NULL) {
      delete node;
      return NULL;
    } 
    //Case 2 :Node with one child
    else if (node->left == NULL || node->right == NULL) {
      struct node *temp = node->left ? node->left : node->right;
      delete node;
      return temp;
    } 
    //Case 3: Node with two children
    else{
      struct node *min_right = minValNode(node->right);
      node->key = min_right->key;
      node->right = deleteNode(node->right, min_right->key);
      return node;
    }
  } 
  else if (key < node->key)
    node->left = deleteNode(node->left, key);
  else
    node->right = deleteNode(node->right, key);

  return node;
}

// Driver code
int main() 
{
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) 
  {
    switch(operation) 
    {
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
