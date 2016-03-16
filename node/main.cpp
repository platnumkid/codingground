#include <iostream>

using namespace std;

typedef struct TreeNode {
    struct TreeNode *left;
    struct TreeNode *right;
    int          value;
} treeNode;

typedef struct Node {
    struct Node *next;
    struct Node *prev;
    struct Node *child;
    int          value;
} Node;

Node *flattenList(Node *node)
{
    if(!node)
        return  NULL;
    
    Node *ret = node;
    Node *temp = flattenList(node->child);
    Node *tempEnd = flattenList(node->next);

    //temp == NULL means no children
    
    if(temp) {
        if(node->next)
            node->next->prev = temp;
        node->next = node->child;
        ret = temp;
    }
    
    if (tempEnd)
        ret=tempEnd;
        
    return ret;
}

int main()
{
   cout << "Hello World" << endl; 
   
   return 0;
}

