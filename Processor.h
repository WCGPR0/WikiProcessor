#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <strings.h>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <map>
#include <stdexcept>
#include <boost/algorithm/string.hpp>

class Processor {
  typedef std::pair<std::string,std::string> myPair;
private:
    struct node {
      int counter; ///< Amount of equal word encountered
      std::string phrase;///< Data for each string phrase
      enum COLOR {
        BLACK, RED ///< Color of the nodes: black being 0, and red being 1
      } color;
      node *link[2]; ///<link[0] is left child and Link[1] is right child
   node() : counter(1), phrase("") {
	}
	 };
    /*** Helper function to check if a node is red */
    inline int isRed(node *myNode);
    /*** Helper function to create a node */
    node* createNode(std::string phrase);
    /** Helper function to delete the tree */
    void deleteTree(node* someNode);
    int count; ///< Total amount of words encountered
    struct tree {
      node *root;
    } myTree;
    std::multimap<int,myPair > topNodes; ///< Deque containing top nodes
    /*** Constructs a node and inserts into R-B tree
    @param node to be inserted */
    void insert(std::string phrase);
    /*** Helper function to traverse a list from the left in order */
    void printInOrder (std::ostream& out, node* someNode);
    /*** Helper function that finds first position of punctation, starting at 1 */
    inline int validateString(std::string myString);
    /*** Helper function that compares all of the nodes below with the tree */
    int compare(node* someNode, Processor::tree& tree);
    /*** Helper function that adds nodes to a multimap */
    void addMap (node* someNode);
    std::string title; ///< Current title of words

public:
  /*** Default Constructor */
  Processor(std::string myFile, double percent = 0.05); ///<[in] ifstream file
  /*** Inserts a node into R-B tree
  @param node to be inserted */
  node* insert(node* someNode, std::string phrase);
  /*** Reports the top percent of words encountered, excluding stop words.
  */
  int topReport(std::ofstream& out);
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
  /*** Searches and finds the phrase, irrelevant of case.
    @param the root node to begin searching from.
    @param the string phrase to look for.
    @return 1 if found, else 0 */
  int find(node* someNode, std::string& phrase);
  /*** Deconstructor */
  ~Processor();
  /*** Function that compares two trees
  @param Processor to be compared to
  @return number of matches found between the two */
  int compareTrees(Processor* processor);
  /*** Compares two Integer Iterator */
  struct intComp{
    bool operator()(const std::pair<std::string, int> &var1,
                    const std::pair<std::string, int> & var2) {
                      return var1.second < var2.second;
                    }
  };
  /*** Accessor method for getting count */
  int const getCount();

  /*** Overloading ostream */
  friend std::ostream& operator<<(std::ostream& out, Processor& processor);
};

#endif
