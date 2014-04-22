#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <fstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <deque>

class Processor {
private:
    struct node {
      int counter = 1; ///< Amount of equal word encountered
      std::string phrase = nullptr; ///< Data for each string phrase
      enum COLOR {
        BLACK, RED ///< Color of the nodes: black being 0, and red being 1
      } color;
      node *link[2]; ///<link[0] is left child and Link[1] is right child
    };
    /*** Helper function to check if a node is red */
    inline int isRed(node *myNode);
    /*** Helper function to create a node */
    node* createNode(std::string phrase);
    /*** Helper function to add the node to topNodes */
    inline void checkNode(node* someNode);
    /** Helper function to delete the tree */
    void deleteTree(node* someNode);
    int count = 0; ///< Total amount of words encountered
    struct tree {
      node *root;
    } myTree;
    std::deque<node*> topNodes; ///< Deque containing top nodes
    /*** Constructs a node and inserts into R-B tree
    @param node to be inserted */
    void insert(std::string phrase);

public:
  /*** Default Constructor */
  Processor(std::ifstream myFile, double percent); ///<[in] ifstream file
  /*** Inserts a node into R-B tree
  @param node to be inserted */
  node* insert(node* someNode, std::string phrase);
  /*** Reports the top percent of words encountered, excluding stop words.
  */
  int topReport();
  /*** Testing function to see if the tree is valid.
  @param the root node to test from */
  //! This function should only be used for developmental purposes/stage
  int validTree(node *root);
  /*** Performs a single rotation on the R-B tree
  @param the root node to perform the rotation on.
  @param the direction to rotate to, 0 being left, and 1 being right. */
  node* singleRotate(node* someNode, int direction);
  /*** Performs a double rotation on the R-B tree
  @param the root node to perform the rotation on.
  @param the direction to rotate to, 0 being left, and 1 being right. */
  node* doubleRotate(node* someNode, int direction);
  const double percent; ///< Percent to report, used by topReport()
  ~Processor();
};
#endif
