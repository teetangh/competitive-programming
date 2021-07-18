// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
    int findMax(Node *root)
    {
        // Code here
        if (root == NULL)
            return -1;

        if (root->left == NULL && root->right == NULL)
            return root->data;

        int currentMax = root->data;

        int leftMax = findMax(root->left);
        if (leftMax != -1)
            currentMax = std::max(currentMax, leftMax);

        int rightMax = findMax(root->right);
        if (rightMax != -1)
            currentMax = std::max(currentMax, rightMax);

        return currentMax;
    }
    int findMin(Node *root)
    {
        // Code here
        if (root == NULL)
            return -1;

        if (root->left == NULL && root->right == NULL)
            return root->data;

        int currentMin = root->data;

        int leftMin = findMin(root->left);
        if (leftMin != -1)
            currentMin = std::min(currentMin, leftMin);

        int rightMin = findMin(root->right);
        if (rightMin != -1)
            currentMin = std::min(currentMin, rightMin);

        return currentMin;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        int mx = obj.findMax(root);
        int mn = obj.findMin(root);
        cout << mx << " " << mn << "\n";
    }
    return 0;
} // } Driver Code Ends