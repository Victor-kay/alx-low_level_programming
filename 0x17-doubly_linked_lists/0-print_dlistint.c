#include <stdio.h>
#include <stddef.h>

typedef struct dlistint_t {
    int data;
    struct dlistint_t *prev;
    struct dlistint_t *next;
} dlistint_t;

size_t print_dlistint(const dlistint_t *h) {
    size_t node_count = 0;

    while (h != NULL) {
        printf("%d\n", h->data);
        h = h->next;
        node_count++;
    }

    return node_count;
}

int main() {
    // Example usage
    dlistint_t node1 = {1, NULL, NULL};
    dlistint_t node2 = {2, NULL, NULL};
    dlistint_t node3 = {3, NULL, NULL};

    node1.next = &node2;
    node2.prev = &node1;
    node2.next = &node3;
    node3.prev = &node2;

    dlistint_t *head = &node1;

    size_t count = print_dlistint(head);
    printf("Number of nodes: %zu\n", count);

    return 0;
}
