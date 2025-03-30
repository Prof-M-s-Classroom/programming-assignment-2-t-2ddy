[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/jIKk4bke)
# CS210 Data Structures SP25
## Programming Assignment 2: Text-Based RPG Using Decision Trees

### **Student Name:** `Theo Leonard`  
### **Student ID:** `825318930`  

---

## **1. Project Overview**
(Provide a brief summary of your RPG game. Describe how it uses a decision tree and how the player interacts with it.)

Example:
> This project implements a text-based RPG using a **binary decision tree**. Each game event is represented as a node, and the player progresses by choosing between two paths at each stage. The storyline is loaded from an external text file (`story.txt`), which is parsed to construct the decision tree. The game ends when a leaf node (with `-1` as left and right children) is reached.

---

## **2. Folder & File Structure**
(Explain the role of each file in your project.)

- **`main.cpp`** → `Reads story text file and runs the game.`  
- **`GameDecisionTree.h`** → `Contains the tree of the game events where the tree is built from the root node and contains the function to play run game`  
- **`Node.h`** → `Node class to make our story events and give a path to the following events through left and right pointers.`  
- **`Story.h`** → `Initializes the event elements through the story class.`  
- **`story.txt`** → `[The game loasds the story events by reading each line of the text file and making story nodes with their respective characteristics. And the choice paths connect the nodes to their intended paths making our tree] Each story event has an event number, the event, and possible routs at the end. The game should read from the root node and progress with only the possible following routs attached to the current node to -1.`

---

## **3. Decision Tree Construction**
(Explain how the decision tree is built from the `story.txt` file.)

- How are `Story` objects created from the text file?  
    They are made from splitting, or parcing with "|"(the delimiter) into the event number, event, left and right choices.
- How are nodes linked based on left and right event numbers?  
    They are linked by the possible next events that the node current node can proceed to.
- What happens if an event has `-1` as left or right children?  
    If an event has -1 as left or right, then it loses that specifc direction in choice / path movement.

---

## **4. Game Traversal**
(Describe how the game moves through the decision tree.)

- How does user input determine the path taken?  
    The user inputs 1 for left and 2 for right in our tree.
- What happens when the player reaches a leaf node?  
    If the player reaches a leaf node, the game ends becuase it has no decendent events.
- Explain the special case where multiple events lead to the same outcome.  
    In my storys case, two events lead to starting dinner as being their only option. Visually the tree would just look like a dimnond with the root at the top and that choice at event 4 with 2 and 3 connected to the left and right respectively.

---

## **5. File Parsing & Data Loading**
(Explain the process of reading `story.txt` and constructing the decision tree.)

- How is the file read and parsed using a delimiter?  
    The file is cut into the event number, the event text, left node connection, and right node connection, split with the delimiter of |
- How do you ensure nodes are properly linked?  
    By checking the last two integers in the story text file and making sure the connections are correct.
- Any challenges faced while handling file input?  
    Yes, undefined reference to Story::Story(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int, int) was my error and I explain it a little more in the debugging section, but in short I needed to compile both main.cpp and story.cpp together and then run that .exe file becuase there was a linker error.

---

## **6. Debugging Process (Errors & Fixes)**
(Describe one or more debugging challenges you faced and how you fixed them.)
GameDecisionTree.h:125:13: error: expected ';' before '}' token:
- forgot a ; after a print statement
GameDecisionTree.h:82:42: error: 'sotryData' was not declared in this scope;
- spelling error
Conditional logic mess up with capitalization, just found I was missing parenthasees () on left, Left and right, Right.

undefined reference to Story::Story(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int, int, int)
- cannot find story constructor method, so when compiling it is needed to directly include story.cpp
- so the code is compiled into a .exe and then ran after running with g++ main.cpp Story.cpp -o game.exe ; if ($?) { ./game.exe }

Example:
> Initially, my program was crashing when trying to access an uninitialized node. I realized it was because I was not properly checking for `nullptr` before accessing child nodes, so I added a check to prevent accessing uninitialized memory.

---

## **7. Sample Output & Walkthrough**
(Provide an example of how the game runs, including player input.)
 You are beginning to prepare dinner for you and your family. 
what next? option 1 or 2?

1.  You prepare the protein first. 
2.  You prepare the vegtable stirfry first. 
its either 1 or 2

just move down the story board and try to get a good outcome!!! with 1 or 2.

---

## **8. Big-O Analysis of Core Methods**
(Analyze the complexity of key methods.)

- **Loading the tree from the file** → `O(n)`  
- **Searching for an event in the tree** → `O(logn)`  
- **Game traversal efficiency** → `O(1)`  

---

## **9. Edge Cases & Testing**
(Describe at least one edge case you tested and its outcome.)
Tested the case where someone enters an invalid input and made sure the story would not break by adding that as a condtion in my input check.

Example:
> I tested a scenario where the player reaches a dead-end (leaf node) and ensured the program correctly ends the game.

---

## **10. Justification of Additional Features (If Any)**
(If you added extra features, describe them and explain why.)
--no
Example:
> I added a **save/load feature** so players can resume the game later. This was done by writing the current node’s event number to a file and reading it when restarting.

---

## **Final Notes**
- **README is mandatory** → `(-10 points deduction if missing).`  
- **Code must compile and run** → `(Code that does not run will receive a 0).`  
- **Do not modify provided skeleton code** → `(You may only add to it).`  

---
