// This program creates an integer binary search tress using 30 random numbers between 0 and 100 
// If a number is repeated then it is labled as a repeat and not added to the tree again
// The program then preforms an in-order traversal printing the nodes and their memory locations
// Finally the program randomly find 5 nodes to delete from the tree
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack> 

using namespace std;

class binaryTree {
public:
	int value;
	binaryTree* left;
	binaryTree* right;
};

//this creates the tree, prints the number stored, and indicates if it was a repeated number
int main() {
	srand(time(NULL));
	binaryTree* newleafptr = nullptr;
	binaryTree* head = nullptr;
	binaryTree* ptr = nullptr;
	int arr[30];
	int repeats = 0;
 	for (int i = 0; i < 30; i++) {
		arr[i] = (rand() % 100) + 1;
	}
	cout << "New Tree: " << endl;
	for (int k = 0; k < 30; k++) {
		if (k == 0) {
			head = new binaryTree();
			head->value = arr[k];
			head->left = nullptr;
			head->right = nullptr;
			cout << k << ": " << arr[k] << endl;
		}
		else {
			newleafptr = new binaryTree();
			newleafptr->value = arr[k];
			newleafptr->left = nullptr;
			newleafptr->right = nullptr;
			ptr = head;
			while (ptr != nullptr) {
				if ((ptr->value) > arr[k]) {
					if ((ptr->left) == nullptr) {
						ptr->left = newleafptr;
						cout << k << ": " << arr[k] << endl;
						break;
					}
					else {
						ptr = ptr->left;
					}
				}
				else if ((ptr->value) < arr[k]) {
					if ((ptr->right) == nullptr) {
						ptr->right = newleafptr;
						cout << k << ": " << arr[k] << endl;
						break;
					}
					else {
						ptr = ptr->right;
					}
				}
				else {
					cout << k << ": " << arr[k] << " repeat" << endl;
					repeats++;
					break;
				}
			}
		}
	}
// This prints the adresses of the contents of the tree in order
	cout << "Node locations:  " << endl;
	for (int k = 0; k < 100; k++) {
		ptr = head;
		while (ptr != nullptr){
			if (k == (ptr->value)) {
				cout << ptr->value <<": "<< ptr << endl;
				break;
			}
			else if (k < (ptr->value)) {
				ptr= ptr->left;
			}
			else if (k > (ptr->value)) {
				ptr = ptr->right;
			}

		}
	}
	cout << "Delete 5 at random: " << endl;
	stack <binaryTree*> s; 
	for (int k = 0; k < 5; k++) {
		int t = (rand() % 100) + 1;
		ptr = head;
		s.push(ptr);
		while (ptr != nullptr) {
 			if (t == (ptr->value)) {
				cout << "delete " << ptr->value << endl;
				//ptr->left->right;
				s.pop();
				binaryTree* top = s.top();
				cout << top->value << endl;
				if (top->left != nullptr) {
					cout << top->left->value << endl;
				}
				else {
					cout << "leff null" << endl;
				}
				if (top->right != nullptr) {
					cout << top->right->value << endl;
				}
				else {
					cout << "right null" << endl;
				}
				break;
			}
			else if (t < (ptr->value)) {
				ptr = ptr->left;
				s.push(ptr);
			}
			else if (t > (ptr->value)) {
				ptr = ptr->right;
				s.push(ptr);
			}
			if (ptr == nullptr) {
				k--;
			}
		}
	}

	char k;
	cout << "Press any key to exit" << endl;
	cin >> k;

}