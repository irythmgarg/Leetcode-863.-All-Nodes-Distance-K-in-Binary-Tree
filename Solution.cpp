class Solution {
public:

    /**
     * Builds a map from each node to its parent using DFS traversal.
     *
     * @param root: Current node in traversal.
     * @param parent: Parent of the current node.
     * @param parentmap: Map to store parent references for all nodes.
     */
    void childtoparent(TreeNode* root, TreeNode* parent, unordered_map<TreeNode*, TreeNode*>& parentmap) {
        if (!root) return;
        parentmap[root] = parent;  // Map current node to its parent
        childtoparent(root->left, root, parentmap);   // Recurse on left child
        childtoparent(root->right, root, parentmap);  // Recurse on right child
    }

    /**
     * Recursively collects all nodes at distance k below a given node.
     *
     * @param root: Current node in downward traversal.
     * @param k: Remaining distance to reach the target level.
     * @param ans: Vector to store node values at the correct distance.
     * @param visited: Set of already visited nodes to avoid cycles.
     */
    void neeche(TreeNode* root, int k, vector<int>& ans, unordered_set<TreeNode*>& visited) {
        if (!root || visited.count(root)) return;

        visited.insert(root);  // Mark current node as visited

        if (k == 0) {
            ans.push_back(root->val);  // Add node value if distance matches
            return;
        }

        // Explore left and right children recursively
        neeche(root->left, k - 1, ans, visited);
        neeche(root->right, k - 1, ans, visited);
    }

    /**
     * Finds all nodes in the binary tree that are exactly distance k from the target node.
     *
     * @param root: Root of the binary tree.
     * @param target: The target node from where distance is measured.
     * @param k: Desired distance.
     * @return Vector of node values at distance k from target.
     */
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent;   // Maps child → parent
        childtoparent(root, NULL, parent);            // Build parent relationships

        vector<int> ans;
        unordered_set<TreeNode*> visited;

        // Explore downward from the target node
        neeche(target, k, ans, visited);

        // Traverse upward and explore opposite subtrees at decreasing distances
        TreeNode* curr = target;
        for (int dist = 1; dist <= k; ++dist) {
            curr = parent[curr];      // Move up to parent
            if (!curr) break;

            neeche(curr, k - dist, ans, visited);  // Explore sibling subtree
        }

        return ans;
    }
};
