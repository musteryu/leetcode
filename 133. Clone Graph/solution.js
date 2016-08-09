/**
 * Definition for undirected graph.
 * function UndirectedGraphNode(label) {
 *     this.label = label;
 *     this.neighbors = [];   // Array of UndirectedGraphNode
 * }
 */

/**
 * @param {UndirectedGraphNode} graph
 * @return {UndirectedGraphNode}
 */
var cloneGraph = function(graph) {
    if (graph === null) return null;
    var marked = {};
    var dfs = function(node) {
        if (marked[node.label] !== undefined) return marked[node.label];
        var root = new UndirectedGraphNode(node.label);
        marked[root.label] = root;
        for (var n of node.neighbors) {
            root.neighbors.push(dfs(n));
        }
        return root;
    };
    return dfs(graph);
};