#ifndef GAMEDECISIONTREE_H
#define GAMEDECISIONTREE_H

#include <unordered_map>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Node.h"
#include "Story.h"

using namespace std;

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
    // destructor, dont plan on using, but here for good practice.
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
    void loadStoryFromFile(const string& filename, char delimiter){
        unordered_map<int, Node<T>*> nodeMap;

        ifstream file(filename);
        if (!file.is_open()){
            return;
        }

        string currentLine;
        while (getline(file, currentLine)) {

            stringstream lineStream(currentLine);
            string part;

            getline(lineStream, part, delimiter);
            int eventNum = stoi(part);

            getline(lineStream, part, delimiter);
            string storyText = part;

            getline(lineStream, part, delimiter);
            int leftChoice = stoi(part);

            int rightChoice = -1;
            getline(lineStream, part, delimiter);
            rightChoice = stoi(part);

        T storyEvent(storyText, eventNum, leftChoice, rightChoice);
        Node<T>* newNode = new Node<T>(storyEvent);
        nodeMap[eventNum] = newNode;

        if (eventNum == 1){
            root = newNode;
        }
        }

    for (auto& pair : nodeMap) { //https://stackoverflow.com/questions/6963894/how-to-use-range-based-for-loop-with-stdmap
        Node<T>* currentNode = pair.second;
        T& storyData = currentNode->data;

        if (storyData.leftEventNumber > 0 && nodeMap.count(storyData.leftEventNumber) > 0){
            currentNode->left = nodeMap[storyData.leftEventNumber];
        }
        if (storyData.rightEventNumber > 0 && nodeMap.count(storyData.rightEventNumber) > 0){
            currentNode->right = nodeMap[storyData.rightEventNumber];
        }
    }
    file.close();
    }

    // TODO: Function to start the game and traverse the tree based on user input
    void playGame(){
        if (!root){
            cout << "N/A, no root, its broken" << endl;
            return;
        }
        Node<T>* currentNode = root;
    
        while (currentNode) {
    
            cout << "\n" << currentNode->data.description << endl;
    
            if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1){
                cout << "\n fin" << endl;
                break;
            }
    
            cout <<"what next? option 1 or 2?"<<endl;
    
            bool hasLeftChoice = (currentNode->data.leftEventNumber != -1 && currentNode->left);
            bool hasRightChoice = (currentNode->data.rightEventNumber != -1 && currentNode->right);

            if (hasLeftChoice){
                string leftOptionText = currentNode->left->data.description;
                string preview1 = leftOptionText.substr();
                cout << "1. " << preview1 << endl;
            }
            if (hasRightChoice){
                string rightOptionText = currentNode->right->data.description;
                string preview2 = rightOptionText.substr();
                cout << "2. " << preview2 << endl;
            }
            
            int input;
            cin >> input;
    
            if (input == 1 && currentNode ->left){
                currentNode = currentNode->left;
            }
            else if (input == 2 && currentNode ->right){
                currentNode = currentNode->right;
            }
            else{
                cout<< "its either 1 or 2" << endl;
            }
    
        }   
        
    }

};

#endif // GAMEDECISIONTREE_H