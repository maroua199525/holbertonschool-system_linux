#include "rb_trees.h"

/**
* rb_tree_node - a function that creates a Red-Black Tree node
*@parent: a pointer to the parent node of the node to create
*@value: the value to put in the new node
*@color: the color of the node
*Return:  a pointer to the new node, or NULL on failure
*/
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *rb_tree_new;

	rb_tree_new = malloc(sizeof(rb_tree_t));
	if (rb_tree_new == NULL)
		return (NULL);
	rb_tree_new->n = value;
	rb_tree_new->color = color;
	rb_tree_new->parent = parent;
	rb_tree_new->left = NULL;
	rb_tree_new->right = NULL;
	return (rb_tree_new);

}
