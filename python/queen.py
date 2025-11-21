class Node:
    def __init__(self, value):
        self.value = value
        self.edges = []

    def add_edge(self, node):
        self.edges.append(node)

def detector(graph):
    visited = set()
    rec_stack = set()
    something = []

    def dfs(node, path):
        if node in rec_stack:
            start_index = path.index(node)
            something.append(path[start_index:])
            return
        if node in visited:
            return
        
        visited.add(node)
        rec_stack.add(node)
        path.append(node)

        for neighbor in node.edges:
            dfs(neighbor, path[:])

        rec_stack.remove(node)

    for node in graph:
        if node not in visited:
            dfs(node, [])

    return something

# Create nodes
nodes = [Node(i) for i in range(10)]

edges = [
    (0, 1), (1, 2), (2, 6), (6,0),  
    (3, 4), (4, 5), (5, 3),  
    (6, 7), (7, 8), (8, 6),
    (2, 3), (5, 6), (8, 9)   
]

# Add edges to the graph
for start, end in edges:
    nodes[start].add_edge(nodes[end])

something = detector(nodes)
total_something = len(something)
print("Something found:")
for s in something:
    print([node.value for node in s])

print("Total number of something:",total_something )