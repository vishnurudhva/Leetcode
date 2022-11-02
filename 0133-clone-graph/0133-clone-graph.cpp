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
        queue<Node*> q;
        q.push(node);
        Node* root = new Node(node->val);
        visited[node->val] = root;
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            for (int i = 0; i < current->neighbors.size(); i++) {
                Node* nodeX = current->neighbors[i];
                if (visited.find(nodeX->val) == visited.end()) {
                    visited[nodeX->val] = new Node(nodeX->val);
                    q.push(nodeX);
                }
                
                visited[current->val]->neighbors.push_back(visited[nodeX->val]);
            }
        }
        
        return root;
    }

};