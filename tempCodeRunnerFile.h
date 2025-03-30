   void playGame(){
        if (!root){
            cout << "N/A, no root, its broken" << endl;
            return;
        }
        Node<T>* currentNode = root;
    
        while (currentNode) {
    
            cout << currentNode->data.description << endl;
    
            if (currentNode->data.leftEventNumber == -1 && currentNode->data.rightEventNumber == -1){
                cout << "\n fin" endl;
                break
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
    
            if (input == "left" || input == "Left" && currentNode ->left){
                currentNode = currentNode->left;
            }
            else if (input == "right" || input == "Right" && currentNode ->left){
                currentNode = currentNode->right;
            }
            else{
                cout<< "its either left, right, Left, or Right!!!"
            }
    
        }   
        
    }