#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

template <typename T>
class GameDecisionTree {
private:
    Node<T>* root;

public:
    // TODO: Constructor
    GameDecisionTree() : root(nullptr) {}

    GameDecisionTree(T data){
        root = new Node<T>(data);
    }
    // destructor, dont plan on using, but here for good preactice.
    ~GameDecisionTree(){
        deleteTree(root);
    }
    void deleteTree(Node<T>* node){
        if (node){
            deleteTree(node->left);
            deleteTree(node->right);
            delete node;
        }
    }

    // TODO: Function to load story data from a text file and build the binary tree
    void loadStoryFromFile(const std::string& filename, char delimiter){}

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){}
};

#endif // GAMEDECISIONTREE_H