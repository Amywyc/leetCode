/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
	UndirectedGraphNode *clone(UndirectedGraphNode *node,
		map<UndirectedGraphNode *,UndirectedGraphNode *>& graph){
		if(node==NULL)
			return NULL;
		if(graph.find(node)!=graph.end())
			return graph[node];
		UndirectedGraphNode *copyNode=new UndirectedGraphNode(node->label);
		graph[node]=copyNode;
		for(int i=0;i<node->neighbors.size();i++){
			UndirectedGraphNode *next=clone(node->neighbors[i],graph);
			copyNode->neighbors.push_back(next);
		}
		return copyNode;
	}
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		map<UndirectedGraphNode *,UndirectedGraphNode *> graph;
		return clone(node,graph);
    }
};