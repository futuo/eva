/**
 * Defines the structure of a binary tree.
 *
 * Author: Bernardo Marques (bernardomarques5@gmail.com)
 */


/**
 * Represents a node in a tree. Has a generic value and pointers to its parent
 * and to its left and right children.
 */
typedef struct _treenode {

    /**
     * The value of the node. Keeping it as pointer without type allows its use
     * as a generic tree, capable of holding any type of orderable data. 
     */
    void *value;

    /**
     * A pointer to the left child of the node. Should be set to NULL when the
     * node does not have any children on its left branch.
     */
    struct _treenode *left;

    /**
     * A pointer to the right child of the node. Should be set to NULL when the
     * node does not have any children on its right branch.
     */
    struct _treenode *right;

    /**
     * A pointer to the parent of the node. Should be set to NULL when the
     * node is the root of the tree.
     */
    struct _treenode *parent;
};

/**
 * From here now on we shall refer to a tree node as "treenode_t".
 */
typedef struct _treenode treenode_t;

/**
 * Represents a tree. Keeps the tree size an a pointer to the root. Moreover,
 * the function used to order the data held by the tree is stored in this 
 * struct.
 */
typedef struct _tree {
    
    /**
     * The number of nodes held by the tree.
     */
    int size;

    /**
     * A pointer to the root node of the tree.
     */ 
    treenode_t *root;

    /**
     * A function to order the nodes in the tree. When comparing the value of
     * two nodes, if this function return a negative value, the first argument
     * of the node should be less than the second argument. The inverse holds
     * when the function returns a positive number. If the function returns 0
     * the values are assumed to be equal.
     */ 
    int (*cmp)(const void *, const void *);
};

/**
 * From here now on we shall refer to a tree as "tree_t".
 */
typedef struct _tree tree_t;

/**
 * Allocates memory, and initializes it accordingly, for a tree.
 *
 * @param cmp A function that will be used to order the items. This functions
 *            is expected to return -1 when the first argument is lesser than
 *            the second one, 1 in the inverse case and 0 when their equal.
 * @return A pointer to the allocated tree.
 */
tree *newTree(int (*cmp)(const void*, const void *));

/**
 * Searches the tree for the given value. Assuming that this is a balanced
 * tree, a call to this function will take O(logN) time.
 * 
 * @param tree  The tree in which the value will be searched for.
 * @param value The value that should be searched for in the tree.
 * @return A pointer to the tree node that holds the given value. In case the
 *         value is not found in the tree, a NULL pointer is returned instead.
 */ 
treenode_t *tree_find(tree_t *tree, void *value);

/**
 * Inserts a new value in the tree. Depending uppon configuration the logic
 * used to balance the tree may be based on different algorithms. Currently
 * the only algorithm supported is the AVL.
 * 
 * Assuming this is called on a balanced tree, a call to this function will
 * take O(logN) time. 
 *
 * @param tree  The tree in which the value will be inserted.
 * @param value The value that should be inserted in the tree.
 * @return 0 in case the value is correctly inserted in the tree, -1 if it's
 *         unable to allocate memory for the new node and -2 if there is
 *         already an item with a similar value.
 */
int tree_insert(tree_t *tree, void *value);

/**
 * Updates the value of the given node in the tree. Depending uppon 
 * configuration the logic used to balance the tree may be based on different
 * algorithms. Currently the only algorithm supported is the AVL.
 * 
 * In case the new value already exists on the tree, this functions will have
 * no effect on the tree and this function will return -2.
 *
 * Assuming this function is called on a balanced tree, a call to this function
 * should take O(logN) time.
 * 
 * @param tree     The tree to update.
 * @param oldValue The value that should be changed.
 * @param newValue The new value to which the given tree node should be set.
 * @return 0 in case the value is properly updated, -1 in case the value does
 *         not exist in the tree and -2 in can the newValue already exists in
 *         the tree.
 */
int tree_update(tree_t *tree, void *oldValue, void *newValue);

/**
 * Deletes the given node from the given tree. Depending uppon configuration
 * the logic used to balance the tree may be based on different algorithms. 
 * Currently the only algorithm supported is the AVL.
 *
 * Assuming this function is called on a balanced tree, a call to this function
 * should take O(logN) time.
 *
 * @param tree  The tree from which the node should be deleted.
 * @param value The value that should be deleted from the tree.
 * @return 0 in case the value is properly deleted and -1 in case the node does
 *         not exist in the tree.
 */
tree_delete(tree_t *tree, void *valueToDelete);

