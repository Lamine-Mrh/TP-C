#include "queue_link.h"
#include "item.h"
#include "binary_tree.h"
#include <stdio.h>
#include <stdlib.h>


struct node_Q *new_node_Q(link h) {
    struct node_Q *new_node = (struct node_Q *)malloc(sizeof(struct node_Q));
    if (new_node == NULL) {
        return NULL;
    }
    new_node->value = h;
    new_node->next = NULL;
    return new_node;
}


void delete_node_Q(struct node_Q **nq) {
    if (*nq != NULL) {
        free(*nq);
        *nq = NULL;
    }
}

struct queue *init_queue() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    if (q == NULL) {
        fprintf(stderr, "Memory allocation failed for queue\n");
        return NULL;
    }
    q->first = NULL;
    q->last = NULL;
    return q;
}

void delete_queue(struct queue **q) {
    if (*q != NULL) {
        while (!is_empty_queue(*q)) {
            dequeue(*q);
        }
        free(*q);
        *q = NULL;
    }
}

int is_empty_queue(const struct queue *q) {
    return q == NULL || q->first == NULL;
}

link dequeue(struct queue *q) {
    if (is_empty_queue(q)) {
        fprintf(stderr, "Queue is empty\n");
        return NULL;
    }

    link value = q->first->value;
    struct node_Q *temp = q->first;

    if (q->first == q->last) {
        q->first = q->last = NULL;
    } else {
        q->first = q->first->next;
    }

    delete_node_Q(&temp);
    return value;
}

void enqueue(struct queue *q, link h) {
    struct node_Q *new_node = new_node_Q(h);
    if (new_node == NULL) {
        return;
    }

    if (is_empty_queue(q)) {
        q->first = q->last = new_node;
    } else {
        q->last->next = new_node;
        q->last = new_node;
    }
}
