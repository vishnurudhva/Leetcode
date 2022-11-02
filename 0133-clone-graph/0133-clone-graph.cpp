/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) return NULL;
        unordered_map<int, Node*> visited;
        return generateAndReturn(node, visited);
    }
    
    Node* generateAndReturn(Node* node, unordered_map<int, Node*>& visited) {
        if (visited.find(node->val) != visited.end()) return visited[node->val];
        Node* newNode = new Node(node->val);
        visited[newNode->val] = newNode;
        for (int i = 0; i < node->neighbors.size(); i++) {
            newNode->neighbors.push_back(generateAndReturn(node->neighbors[i], visited));
        }
        return newNode;
    }
};