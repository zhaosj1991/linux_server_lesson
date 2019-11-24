typedef int KEY_TYPE;

// #define RBTREE_ENTRY(name, type)  \
//     struct name                   \
//     {
//         struct type *right;       \
//         struct type *left;        \
//         struct type *parent;      \
//                                   \
//         unsigned char color;      \
//     }                             \
    

typedef struct _rbtree_node
{
    unsigned char color;
    rbtree_node *right;
    rbtree_node *left;
    rbtree_node *parent;

    KEY_TYPE key;
    void *value;

} rbtree_node;

typedef struct _rbtree
{
    rbtree_node *root;
    rbtree_node *nil;  //leaves node
} rbtree;

void rbtree_left_rotate(rbtree *T, rbtree_node *x)
{
    rbtree_node *y = x->right;
    
    x->right = y->left;
    if (y->left != T->nil)
    {
        y->left->parent = x;
    }

    y->parent = x->parent;
    if (x->parent == T->nil)
    {
        T->root = y;
    }
    else if(x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }
    
    y->left = x;
    x->parent = y;
}

// left --> right
// right --> left
// x --> y
// y --> x
void rbtree_left_rotate(rbtree *T, rbtree_node *x)
{

}

void rbtree_intsert(rbtree *T, rbtree_node *z)
{
    // 1 find location to insert
    rbtree_node *y = T->nil;
    rbtree_node *x = T->root;

    while (x != T->nil)
    {
        
    }
    
}
