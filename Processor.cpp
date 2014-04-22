#include "Processor.h"

/** Default constructor */
Processor::Processor(std::ifstream myFile, double percent = 0.05) : percent(percent){

}

/** Reports the top percent (by default is 5%) of occured words */
int Processor::topReport(){
for (int i = 0; i < (int)(percent*count); i++)
  //Binary search for top count
}

/** Checks if the node is of color Red.
  @param node to be checked.
  @return int with 0 being Black and 1 being Red. */
inline int isRed(node *myNode){
  return (myNode != NULL) && (myNode->COLOR == RED);
}

/** Validates if the Tree matches R-B conditions.
    @return a positive int >= 1, equal to the height of the tree, if the tree is valid, \
            else 0 if the tree is invalid.*/
int Processor::validTree(node* root /**< [in] base node */){
  if (root == NULL) return 1;
  else {
    node *leftNode = root->link[0];
    node *rightNode = root->link[1];
    if (isRed(root))
       if (isRed(leftNode) && isRed(rightNode)) {//Childs are red when root is red
       std::cout << "Red Violation";
       return 0;
     }
  }

  /* Binary Search Tree Validation */
  if (((leftNode != NULL) && (leftNode->phrase >= root->phrase))
      || ((rightNode != NULL) && (rightNode->phrase <= root->phrase))) {
        std::cout << "Binary Tree Violation";
        return 0;
      }

  int leftHeight = validTree(leftNode), rightHeight = validTree(rightNode); //Recursion through the branches of the tree

  if ((leftHeight != 0) && (rightHeight != 0))
    /* Black Height Validation */
    if (leftHeight != rightHeight) { //The two branches for both sides should be equal
    std::cout << "Black Height Violation";
    return 0;
  }
    else return isRed(root) ? leftHeight : leftHeight+1; //leftHeight and rightHeight can be used interchangeably here
  else return 0;
}

/** Helper function to check if the node should be added to the top reoccuring deque.
  @param the node to be checked. */
inline void checkNode(node* someNode){
  int i = 0;
    if (someNode->data > topNodes[0]->data) {
      if ((int)(count * percent) < topNodes.size())
        topNodes.pop_front();
      else {
        while ((topNodes[i] != NULL) && (someNode->data > topNodes[i]->data))
        i++;
      topNodes.insert(topNodes.begin() + i, someNode);
      }
    }
}

/** Inserts a node into the R-B tree.
    @param the Root node to be inserting to.
    @param the data for the new node to be created to have.
    @return the pointer to the inserted Node
    */
node* Processor::insert(node* someNode, std::string phrase) {
  if (someNode == NULL) {
    someNode = createNode(phrase);
    count++;
  }
  else if (phrase == someNode->phrase) {
    someNode->count++;
    count++;
  }
  else {
    int direction = phrase >= root->phrase; //0 for left, and 1 for right
    root->link[direction] = insert(root->link[direction], phrase); //Recursion to find the right location to insert
  /** Fixes, and rebalances, the R-B tree if it is invalid */
    if (isRed(someNode->link[direction])) {
      if (isRed(someNode->link[!direction])) {
        //If both children is red, then the parent has to be black; we flip the colors
        someNode->COLOR = RED;
        someNode->link[0]->COLOR = someNode->link[1]->COLOR = BLACK;
      }
      else {
      //If the children are of different colors
      if (isRed(someNode->link[direction]->link[direction]))
        //If the left child of the child is the violation, do a single rotation
        someNode = singleRotate(someNode, !direction);
      else if (isRed(someNode->link[direction]->link[!direction]))
        //If the right child of the child is the violation, do a double rotation
        someNode = doubleRotate(someNode, !direction);
      else std::cerr << "Logic Error!";
      }
    }
  }
  return someNode;
}


/** Inserts directly into the tree a node with the phrase.
  @param the data to be inserted as a node with that phrase. */
void Processor::insert(std::string phrase) {
  myTree->root = insert(myTree->root, phrase);
  myTree->root->COLOR = BLACK;
}

/** Helper function to create a red node.
   @param string data to be inserted.
   @return pointer to created Node */
node* Processor::createNode(std::string phrase){
  try {
    node* newNode = new node;
    newNode->phrase = phrase;
    newNode->COLOR = RED; //Creating a red node, and fixing it after, because it's preffered over a black node (as a black node will always have a violation)
    newNode->link[0] = newNode->Link[1] = NULL; //Sets the leafs to be null
  }
  catch (std::bad_alloc& exception) {
  std::cerr << exception; }

  return newNode;
}

/** Single rotation then setting the old root as red, and new one as black.
  @param the Root node to be rotating with.
  @param the direction to rotate to. An integer value 0 being left, 1 being right.
  @return the new node rotated.
  */
node* Processor::singleRotate(node* someNode, int direction) {
  node* tempNode = someNode->link[!direction];
  someNode->link[!direction] = tempNode->link[direction];
  tempNode->link[direction] = someNode;

  someNode->COLOR = RED;
  tempNode->COLOR = BLACK;

  return tempNode;
}

/** Double rotation, implicitly uses the single rotation.
  @param the Root node to be rotating with.
  @param the direction to rotate to. An integer value 0 being left, 1 being right.
  @return the new node rotated.
  */
node* Processor::doubleRotate(node* someNode, int direction) {
  someNode->link[!direction] = singleRotate(someNode->link[!direction], !direction);
  return singleRotate(someNode, direction);
}

ostream& opeartor<<(ostream& out, Processor& processor){

}

/** Helper function to delete the tree through recursion.
   @param the root node to begin deletion. */
void Processor::deleteTree(node* someNode) {
  if (someNode == NULL) return;
//Delete subtrees
  deleteTree(someNode->link[0]);
  deleteTree(someNode->link[1]);
  delete someNode;
}

/** Deconstructor */
Processor::~Processor(){
  //Cleanup
  deleteTree(myTree->root);
  myTree->root = NULL;
}
