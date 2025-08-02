#include <iostream>
#include <vector>
#include <cstdlib>
#include "dynamicProgramming/houseRobbery.h"

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};


static
void arrayTestCase(void)
{
    long long T;
    long long n; 
    // get the no. of testcases 
    // cout << "Enter T: ";
    cin >> T;
    for ( long long i = 0; i < T; i++ ) {
        cin >> n;
        vector<int> vect;
        int value;
        // get the array value
        // cout << " Elements of array: \n";
        for (long long j=0; j < n; j++ ) {
            cin >> value;
            vect.push_back(value);
        }
        cout << houseRobber(vect);
        return;
    }
}

void testfunc(void)
{
    vector<int> vect;
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(2); 
    houseRobber(vect);
}


struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insertNode(struct node* root, int data) {
    // base condition
    if (root == NULL) {
        struct node* newNode = createNode(data);
        root = newNode;
        return root;
    }
    if (data > root->data) {
        root = insertNode(root->right, data); 
    } else {
        root = insertNode(root->left, data);
    }

    return root;
}

void inOrderTraversal(struct node *node)
{
    if (node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    printf("%d", node->data);
    inOrderTraversal(node->right);
}



int main()
{
    // arrayTestCase();
    testfunc();
    return 0;
}