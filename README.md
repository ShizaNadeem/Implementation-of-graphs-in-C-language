# Implementation-of-graphs-in-C-language
## Graph Traversal Using Depth-First Search (DFS)
## About
This project demonstrates the implementation of a graph data structure and traversal using Depth-First Search (DFS) in C. The program initializes a graph with vertices, adds edges with specified costs, and finds a path between two vertices using DFS. The graph is represented as an adjacency matrix and includes functions for adding edges, printing the graph, and performing DFS to find a path from a source to a destination.

## Features
- **Graph Representation:**
  - Use of an adjacency matrix to represent the graph.
  - Initialization of the graph with default values and edge costs.

- **DFS Traversal:**
  - Implementation of DFS to find a path between two vertices.
  - Use of a stack to keep track of the path and visited vertices.
  - Calculation of the path cost during traversal.

- **Graph Operations:**
  - Functions to add edges with costs to the graph.
  - Function to print the graph in a readable format.

## Requirements
- C Compiler (e.g., GCC)
- Standard C Libraries: `stdio.h`, `stdlib.h`, `string.h`, `stdbool.h`

## Instructions
1. **Clone the Repository:**
   ```
   git clone https://github.com/yourusername/graph-dfs-traversal.git
   ```
2. **Open the Project:**
   - Navigate to the project directory.

3. **Compile the Code:**
   ```
   gcc -o graph_dfs main.c node.c stack_functions.c
   ```
4. **Run the Executable:**
   ```
   ./graph_dfs
   ```

5. **Output:**
   - The program initializes the graph, adds edges, prints the graph, and finds the path from vertex 7 to vertex 8 using DFS.

## Usage
- **Graph Initialization:**
  - The graph is initialized with a size of 10 vertices, and edges are added with specified costs.

- **Adding Edges:**
  - Use the `add_edge` function to add an edge between two vertices with a specified cost.

- **Printing the Graph:**
  - Use the `print_graph` function to print the adjacency matrix representation of the graph.

- **DFS Traversal:**
  - The `find_path_dfs` function performs DFS to find a path from the source vertex to the destination vertex, printing the path and its cost.
