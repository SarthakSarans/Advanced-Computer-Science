/*
 * Binary Search Tree class
 * Do not alter the display() function, this will break the Repl.it
 * tests
 */

#include "BSTree.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

/*
 * Find Element in the Tree
 * find a node by item_key and provide an updated parent node
 *   pointer and location node pointer
 */

void BST::find(int item_key, node **prnt, node **loc) {
  node *ptr, *ptrsave;
  if (root == NULL) {
    *loc = NULL;
    *prnt = NULL;
    return;
  }
  if (item_key == root->key_value) {
    *loc = root;
    *prnt = NULL;
    return;
  }
  if (item_key < root->key_value)
    ptr = root->p_left;
  else
    ptr = root->p_right;
  ptrsave = root;
  while (ptr != NULL) {
    if (item_key == ptr->key_value) {
      *loc = ptr;
      *prnt = ptrsave;
      return;
    }
    ptrsave = ptr;
    if (item_key < ptr->key_value)
      ptr = ptr->p_left;
    else
      ptr = ptr->p_right;
  }
  *loc = NULL;
  *prnt = ptrsave;
}

/*
 * Inserting Element into the Tree
 */
void BST::insert(node *tree, node *newnode) {
  // if (we are at root)
  node *tmp = tree;

  if (root == NULL) {
    // Just create a single node for root to point to,
    //    with all the data in it.
    root = newnode;

  }

  else {
    // if (there is already a node with our key value)
    node *tmp2 = new node;
    find(newnode->key_value, &tree, &tmp2); // finds to see if dupilcate exists
    if (tmp2 != NULL) {
      // Just return
      return;
    }
    // if (the new node is less than the current node)
    if (newnode->key_value < tmp->key_value) {
      // if (see if something is already a child on the left)
      if (tmp->p_left != nullptr) {
        // if so, the recurse insert at this subtree
        insert(tmp->p_left, newnode);
      } else {
        // otherwise the new node goes here as a leaf (ie no children)
        tmp->p_left = newnode;
      }
    } else // it must be to the right
    {

      // if (is there already a child on right?)
      if (tmp->p_right != nullptr) {
        // if so, the recurse insert at this subtree
        insert(tmp->p_right, newnode);

      } else {
        // otherwise the new node goes here as a leaf (ie no children)
        tmp->p_right = newnode;
      }
    }
  }
}

/*
 * Delete Element from the tree
 */
void BST::remove(int item) {
  node *parent, *location;
  if (root == NULL) {
    cout << "Tree empty" << endl;
    return;
  }
  find(item, &parent, &location);
  if (location == NULL) {
    cout << "Item not present in tree" << endl;
    return;
  }
  // if (there is no child on left or right)
  if (location->p_left == NULL && location->p_right == NULL)
    case_0(parent, location);
  // if (there is one child on left only)
  else if (location->p_left != NULL && location->p_right == NULL)
    case_1(parent, location);
  // if (there is one child on right only)
  else if (location->p_left == NULL && location->p_right != NULL)
    case_1(parent, location);
  // if (there are childred on left and right)
  else if (location->p_left != NULL && location->p_right != NULL)
    case_2(parent, location);
  // free(location);
}

/*
 * Case 0
 * the node is simply removed no other updates necessary.
 */
void BST::case_0(node *prnt, node *loc) {
  // if (we are at the root)
  if (loc == root) {
    // update the root
    loc = NULL;
  } else {
    // otherwise simply remove node
    if (prnt->key_value < loc->key_value)
      prnt->p_right = NULL;
    else
      prnt->p_left = NULL;
  }
}

/*
 * Case 1
 * We have only one child so promote the child and replace the target
 * node
 */
void BST::case_1(node *prnt, node *loc) {
  // if (the child is on the left?)
  if (loc->p_left != NULL) {
    // point left
    loc = loc->p_left;

  }
  // else  // must be the right side has child
  else {

    loc = loc->p_right;
  }
  // if (we are at the root handle specialy)
  if (loc == root) {
    // update the root
    root = loc;
  } else {
    // if (the node is left child of parent)
    if (prnt->key_value > loc->key_value) {
      // promote the left
      prnt->p_left = loc;
    }
    // else // the node is right of parent
    else {
      // promote right
      prnt->p_right = loc;
    }
  }
}

/*
 * Case case_2
 * We have to find and promote a successor or predecessor

 */

// Finds successor
node *BST::successor(node *loc) {
  node *tmp = loc;
  if (loc->p_right != NULL) {
    tmp = loc->p_right;
    while (tmp->p_left != NULL)
      tmp = tmp->p_left;
  }
  return tmp;
}
node *BST::psuccessor(node *loc) {
  node *tmp = loc;
  if (loc->p_right != NULL)
    tmp = loc->p_right;
  while (tmp->p_left->p_left != NULL)
    tmp = tmp->p_left;
  return tmp;
}
void BST::case_2(node *prnt, node *loc) {

  if (loc->p_right->p_left == NULL) {
    loc->key_value = loc->p_right->key_value;
    if (loc->p_right->p_right != NULL)
      loc->p_right = loc->p_right->p_right;
    else
      loc->p_right = NULL;
  } else {
    node *suc = successor(loc);
    node *psuc = psuccessor(loc);

    psuc->p_left = suc->p_right;
    loc->key_value = suc->key_value;
  }
  // temporary pointers for node we are manipulating
  //  node *original = loc;
  //  node *suc = loc->p_right;
  //  node *psuc = loc->p_right;
  //  node *rightchild = loc->p_right;
  //  node *leftchild = loc->p_left;
  //  if (suc->p_left != NULL)
  //    suc = suc->p_left;
  //  while (suc->p_left != NULL) {
  //    suc = suc->p_left;
  //    psuc = psuc->p_left;
  //  }
  //  node *successor = new node;
  // successor = suc;

  //  if (loc != root) {
  //    if (suc->p_right != NULL) {
  //      psuc->p_left = psuc->p_left->p_right;
  //    } else {
  //      psuc->p_left = NULL;
  //    }
  //    loc->key_value = successor->key_value;
  //}

  // else {
  //   root->key_value = successor->key_value;
  // }
  // }
  /*void BST::case_2(node *prnt, node *loc) {
    // temporary pointers for node we are manipulating
    node *original = loc;
    node *suc = loc;
    node *rightchild = loc->p_right;
    node *leftchild = loc->p_left;
    // Find successor: Step to the right child

    if (suc->p_right != NULL) {

      suc = loc->p_right;
      while (suc->p_left != NULL) {
        suc = suc->p_left;
      }
    }
    // Find the min of the subtree on parent's right
  node* successor = suc;
    // if (found node has no children)
    if (suc->p_right == NULL) {
      // Replace the target node with the successor node
      loc = suc;
    } else {
      // Temporarily remove the successor node by replacing it with
      // its right child, we will replace the node we are removing
      // with the successor we just removed.
      suc = suc->p_right;
    }
    // if (we are at root)
    if (loc == root) {
      // then update root
      root = successor;
    } else {
      // Insert the successor node where the target node we
      //   are removing is located
      loc = successor;
    }
    // then update the successor child pointers to reflect the old
    //     target's child pointers.
    loc->p_left = leftchild;
    loc->p_right = rightchild;
  }
  */
  /*void BST::case_2(node *prnt, node *loc) {
    // temporary pointers for node we are manipulating
    node *tmp = new node;
    tmp = loc;
    node *original = new node;
    original = loc;

    // Find parent successor and successor
    node *psuc = new node;
    psuc = psuccessor(loc);
    node *suc = new node;
    suc = successor(loc);
    // if (found node has no children)
    if (suc->p_left == nullptr && suc->p_right == nullptr) {
      // Replace the target node with the successor node

      if (prnt->key_value > suc->key_value) {
        prnt->p_left = suc;
        suc->p_left = original->p_left;
        suc->p_right = original->p_right;
      }
            else{
                    prnt->p_right = suc;
        suc->p_left = original->p_left;
        suc->p_right = original->p_right;
            }
    } else {
      //  Temporarily remove the successor node by replacing it with
      //  its right child, we will replace the node we are removing
      //  with the successor we just removed.
      suc = suc->p_right;
      // if (we are at root)
      if (loc == root) {
        // then update root
        root = successor(loc);
      } else {
        // Insert the successor node where the target node we
        //   are removing is located

        loc = successor(loc);
      }
      // then update the successor child pointers to reflect the old
      //     target's child pointers.
      if (successor(loc)!= loc->p_right) {
        // promote the left
          if (prnt->key_value > suc->key_value) {
        prnt->p_left = suc;
        suc->p_left = original->p_left;
        suc->p_right = original->p_right;
      }
            else{
                    prnt->p_right = suc;
        suc->p_left = original->p_left;
        suc->p_right = original->p_right;
            }
      }
      // else // the node is right of parent
      else {
        // promote right
       if (prnt->key_value > loc->key_value) {
        prnt->p_left = loc;

      }
            else{
                    prnt->p_right = loc;

            }
      }
    }
  */
}
/*
 * Display Tree Structure
 */
void BST::display(node *ptr, int level) {
  int i;
  if (ptr != NULL) {
    display(ptr->p_right, level + 1);
    cout << endl;
    if (ptr == root)
      cout << "Root->:  ";
    else {
      for (i = 0; i < level; i++)
        cout << "       ";
    }
    cout << ptr->key_value;
    display(ptr->p_left, level + 1);
  }
}
