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
    
            cout << currentNode->data.description << endl;
    
            if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1){
                cout << "\n fin" << endl;
                break;
            }
    
            cout <<"left or right path? --some might only have one way.."<<endl;
    
            if(currentNode->data.leftEventNumber != -1){
                cout << "left?" << endl;
            }
            if(currentNode->data.rightEventNumber != -1){
                cout << "right?" << endl;
            }
    
            string input;
            cin >> input;
    
            if ((input == "left" || input == "Left") && currentNode ->left){
                currentNode = currentNode->left;
            }
            else if ((input == "right" || input == "Right") && currentNode ->left){
                currentNode = currentNode->right;
            }
            else{
                cout<< "its either left, right, Left, or Right!!!";
            }
    
        }   
        
    }

};

#endif // GAMEDECISIONTREE_H