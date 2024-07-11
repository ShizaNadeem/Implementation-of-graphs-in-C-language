#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "node.h"
#include "stack_functions.h"

#define NUM_VERTICES 10

/** This function takes a pointer to the
    adjacency matrix of a Graph and the
    size of this matrix as arguments and
    prints the matrix */
void print_graph(int * graph, int size);

/** This function takes a pointer to the
    adjacency matrix of a Graph, the size
    of this matrix, the source and dest
    node numbers along with the weight or
    cost of the edge and fills the adjacency
    matrix accordingly. */
void add_edge(int * graph, int size, int src, int dst, int cost);

/** This function takes a pointer to the adjacency matrix of
    a graph, the size of this matrix, source and destination
    vertex numbers as inputs and prints out the path from the
    source vertex to the destination vertex. It also prints
    the total cost of this path. */
void find_path_dfs(int * graph, int size, int src, int dst);

int main()
{
    int my_graph[NUM_VERTICES][NUM_VERTICES];   ///An adjacency matrix representation of graph

    memset(my_graph,-1,NUM_VERTICES * NUM_VERTICES * sizeof(int)); ///It is used to fill a block of memory with particular value
    ///Initialize with -1 representing infinite cost.

    for(int i=0; i<NUM_VERTICES; i++)
        add_edge(&my_graph[0][0], NUM_VERTICES, i, i, 0);	/// All the vertices have a cost of 0 for visiting themselves

    add_edge(&my_graph[0][0], NUM_VERTICES, 0, 3, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 0, 13);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 4, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 1, 14);
    add_edge(&my_graph[0][0], NUM_VERTICES, 1, 5, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 1, 6);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 3, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 2, 9, 10);
    add_edge(&my_graph[0][0], NUM_VERTICES, 3, 8, 9);
    add_edge(&my_graph[0][0], NUM_VERTICES, 4, 6, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 4, 8);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 2, 7);
    add_edge(&my_graph[0][0], NUM_VERTICES, 5, 6, 12);
    add_edge(&my_graph[0][0], NUM_VERTICES, 6, 7, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 7, 6, 15);
    add_edge(&my_graph[0][0], NUM_VERTICES, 8, 5, 11);
    add_edge(&my_graph[0][0], NUM_VERTICES, 9, 8, 23);

    /** Adjacency Matrix according to Figure 8 completed according to task 1 **/

    print_graph(&my_graph[0][0], NUM_VERTICES);
    find_path_dfs(&my_graph[0][0], NUM_VERTICES, 1, 4);

    getchar(); ///Reads a single character from the standard input stream stdin.
    return 0;
}

void add_edge(int *graph, int size, int src, int dst, int cost) ///starting address of 'graph'
{
    *(graph+(src*size+dst)) = cost;
}

void print_graph(int *graph, int size) ///starting address of 'graph'
{
    for(int i=0; i<size; i++) ///will print 0-9 numbers in one row, will be executed 10 times
    {
        printf("\t%d", i);
    }

    printf("\n\n");
    for(int x=0; x<size; x++) ///loop for printing row, will execute one time and then the nested loop will execute 10 times
    {
        printf("%d\t", x);
        for(int y=0; y<size; y++) ///loop for printing column
            printf("%d\t", *(graph+(x*size+y)));
        printf("\n");
    }
}

void find_path_dfs(int * graph, int size, int src, int dst)
{
    int visited[10] = {0};  /// To keep track of all the visited nodes

    /**** We make a stack for holding the visited vertices *******/

    struct node *top = NULL;   /// This is the top of the stack

    /** The DFS will work as follows:
        1. Visit src vertex. Set 'current_visiting' to src.
        2. Explore this vertex.
            If it is the destination vertex, stop.
            Otherwise visit its first unvisited neighbor (add to stack the current vertex)
            If no unvisited neighbor vertex remains, go back (pop from stack)
        3. Repeat 2
    */
    int crnt_visiting = src;
    int crnt_exploring = src;
    int path_cost = 0;
    int adjacent_node;
    bool PATH_FOUND = false;
    bool adjacent;

    struct element temp;
    temp.cost_to_visit = 0;
    temp.vertex_num = src;
    push(&top,temp);

    while(!PATH_FOUND)
    {
        visited[crnt_visiting] = 1; /// Now we have visited this node, so, initialize it with '1'
        struct element temp; ///temporary variable used for pushing data into stack

        if(crnt_visiting == dst)	/// If the vertex is found. This condition is when 'src' and 'dst' is same.
        {
            printf("\nPath found: ");
            printf("\nCost: %d\n",path_cost);
            while(!isStackEmpty(&top))		/// Empty the stack so all the allocated memory is freed.
            {
                printf("Pop\n");
                pop(&top);
            }
            PATH_FOUND = true;
            continue; ///Control moves to the beginning of the loop skipping the execution for the current iteration.
        }

        else    /// Explore this vertex
        {
			for(int i=0; i<size; i++)
                {
                    adjacent = false;
                    adjacent_node = *(graph +(crnt_visiting*size+i)); ///cost of node
                    if(adjacent_node != -1 && adjacent_node != 0)
                    {
                          if (visited[i] == 0)
                        {
                            path_cost =  path_cost + adjacent_node;
                            temp.cost_to_visit = path_cost;
                            temp.vertex_num = i;
                            push(&top, temp);
                            crnt_visiting = i;
                            adjacent = true;
                            break;
                        }
                    }
                }
            if(!adjacent) ///If the condition is false then the loop is executed, if(adjacent == false)
            {
            temp = pop(&top);
            path_cost = temp.cost_to_visit;
            crnt_visiting = temp.vertex_num;
            }
        }
    }
}
