#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_SYMBOLS 10

// Structures for DFA optimization
typedef struct {
    bool nullable;
    int *firstpos;
    int *lastpos;
    int *followpos;
    int firstpos_size;
    int lastpos_size;
    int followpos_size;
} NodeInfo;

typedef struct {
    int states[MAX_NODES][MAX_SYMBOLS];
    char symbols[MAX_SYMBOLS];
    int num_symbols;
    int num_states;
} DFATransitionTable;

// Function prototypes
NodeInfo* create_parse_tree(char *regex);
void compute_node_properties(NodeInfo *nodes, int num_nodes);
void compute_followpos(NodeInfo *nodes, int num_nodes);
DFATransitionTable* generate_dfa_table(NodeInfo *nodes, int num_nodes);
void print_node_info(NodeInfo *nodes, int num_nodes);
void print_dfa_table(DFATransitionTable *dfa);

int main() {
    char regex[100];
    
    // Input regular expression
    printf("Enter a regular expression: ");
    scanf("%s", regex);

    // Create parse tree and compute properties
    NodeInfo *nodes = create_parse_tree(regex);
    compute_node_properties(nodes, strlen(regex) + 1);
    compute_followpos(nodes, strlen(regex) + 1);

    // Print node information
    print_node_info(nodes, strlen(regex) + 1);

    // Generate and print DFA transition table
    DFATransitionTable *dfa = generate_dfa_table(nodes, strlen(regex) + 1);
    print_dfa_table(dfa);

    // Free allocated memory
    // Note: Memory management code would be added here

    return 0;
}

// Placeholder implementations for complex functions
NodeInfo* create_parse_tree(char *regex) {
    // Implement Thompson's construction or similar algorithm
    // This is a complex function that would parse the regex
    NodeInfo *nodes = malloc(sizeof(NodeInfo) * (strlen(regex) + 1));
    
    // Simplified placeholder implementation
    for (int i = 0; i <= strlen(regex); i++) {
        nodes[i].nullable = false;
        nodes[i].firstpos = malloc(sizeof(int) * MAX_NODES);
        nodes[i].lastpos = malloc(sizeof(int) * MAX_NODES);
        nodes[i].followpos = malloc(sizeof(int) * MAX_NODES);
        nodes[i].firstpos_size = 0;
        nodes[i].lastpos_size = 0;
        nodes[i].followpos_size = 0;
    }
    
    return nodes;
}

void compute_node_properties(NodeInfo *nodes, int num_nodes) {
    // Compute nullable, firstpos, lastpos
    // Placeholder implementation
    for (int i = 0; i < num_nodes; i++) {
        // Simplified computations
        nodes[i].nullable = (i % 3 == 0);
        nodes[i].firstpos[0] = i;
        nodes[i].firstpos_size = 1;
        nodes[i].lastpos[0] = i;
        nodes[i].lastpos_size = 1;
    }
}

void compute_followpos(NodeInfo *nodes, int num_nodes) {
    // Compute followpos based on concatenation and Kleene star rules
    for (int i = 0; i < num_nodes; i++) {
        if (i % 2 == 0) {
            // For simplification, assume concatenation for even indexed nodes
            // Followpos of all positions in lastpos of node i
            // gets firstpos of node i + 1
            for (int j = 0; j < nodes[i].lastpos_size; j++) {
                int lastpos_node = nodes[i].lastpos[j];
                for (int k = 0; k < nodes[i + 1].firstpos_size; k++) {
                    nodes[lastpos_node].followpos[nodes[lastpos_node].followpos_size++] = nodes[i + 1].firstpos[k];
                }
            }
        } else {
            // For simplification, assume Kleene star for odd indexed nodes
            // Followpos of all positions in lastpos of node i
            // gets firstpos of node i (for Kleene star)
            for (int j = 0; j < nodes[i].lastpos_size; j++) {
                int lastpos_node = nodes[i].lastpos[j];
                for (int k = 0; k < nodes[i].firstpos_size; k++) {
                    nodes[lastpos_node].followpos[nodes[lastpos_node].followpos_size++] = nodes[i].firstpos[k];
                }
            }
        }
    }
}

DFATransitionTable* generate_dfa_table(NodeInfo *nodes, int num_nodes) {
    DFATransitionTable *dfa = malloc(sizeof(DFATransitionTable));
    
    // Placeholder DFA generation
    dfa->num_symbols = 2;
    dfa->symbols[0] = 'a';
    dfa->symbols[1] = 'b';
    dfa->num_states = 3;

    // Simplified state transitions
    for (int i = 0; i < dfa->num_states; i++) {
        for (int j = 0; j < dfa->num_symbols; j++) {
            dfa->states[i][j] = (i + j) % dfa->num_states;
        }
    }

    return dfa;
}

void print_node_info(NodeInfo *nodes, int num_nodes) {
    printf("\nNode Information:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i);
        printf("  Nullable: %s\n", nodes[i].nullable ? "Yes" : "No");
        
        printf("  FirstPos: ");
        for (int j = 0; j < nodes[i].firstpos_size; j++) {
            printf("%d ", nodes[i].firstpos[j]);
        }
        printf("\n");

        printf("  LastPos: ");
        for (int j = 0; j < nodes[i].lastpos_size; j++) {
            printf("%d ", nodes[i].lastpos[j]);
        }
        printf("\n");

        printf("  FollowPos: ");
        for (int j = 0; j < nodes[i].followpos_size; j++) {
            printf("%d ", nodes[i].followpos[j]);
        }
        printf("\n");
    }
}

void print_dfa_table(DFATransitionTable *dfa) {
    printf("\nDFA Transition Table:\n");
    printf("State Name");
    for (int i = 0; i < dfa->num_symbols; i++) {
        printf(" | Symbol %c", dfa->symbols[i]);
    }
    printf("\n");
    printf("------------------------------------\n");

    for (int i = 0; i < dfa->num_states; i++) {
        printf("State %d", i);
        for (int j = 0; j < dfa->num_symbols; j++) {
            printf(" | %d", dfa->states[i][j]);
        }
        printf("\n");
    }
}

