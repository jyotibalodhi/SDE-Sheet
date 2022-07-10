
 unordered_map<graphNode*, graphNode*> m;

    graphNode* cloneGraph(graphNode* node) {
        
        if (!node) return NULL;
        if (m.find(node) != m.end())
            return m[node];
        
        graphNode* copy = new graphNode(node->data);
        m[node] = copy;
        
        for(graphNode* neighbor: node->neighbours) {
            copy->neighbours.push_back(cloneGraph(neighbor));
        }
        
        return copy;
}