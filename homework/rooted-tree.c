#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FOLDER 1
#define FILE 0

struct node {
    char name[100];
    int size;
    int type;
    int total_size;
    struct node* parent;
    struct node* firstChild;
    struct node* nextSibling;
};

struct node* createNode(char* name, int size, int type) {
    struct node* node = (struct node*) malloc(sizeof(struct node));

    strcpy(node->name, name);
    node->size = size;
    node->type = type;
    node->total_size = 0;
    node->parent = NULL;
    node->firstChild = NULL;
    node->nextSibling = NULL;

    return node;
}

void addChild(struct node* parent, struct node* child) {
    if (parent == NULL || child == NULL) return;

    child->parent = parent;
    child->nextSibling = parent->firstChild;
    parent->firstChild = child;
}

void preorderTraversal(struct node* node) {
    if (node == NULL) return;

    struct node* child = node->firstChild;
    while (child != NULL) {
        preorderTraversal(child);
        child = child->nextSibling;
    }

    node->total_size = node->size;
    child = node->firstChild;
    while (child != NULL) {
        node->total_size += child->total_size;
        child = child->nextSibling;
    }
}

void postorderTraversal(struct node* node) {
    if (node == NULL) return;

    struct node* child = node->firstChild;
    while (child != NULL) {
        postorderTraversal(child);
        child = child->nextSibling;
    }

    printf("Name: %s total size: %dk ", node->name, node->total_size);
}

void freeTree(struct node* node) {
    if (node == NULL) return;

    struct node* child = node->firstChild;
    while (child != NULL) {
        struct node* nextChild = child->nextSibling;
        freeTree(child);
        child = nextChild;
    }

    free(node); 
}

int main() {
    struct node* root = createNode("/user/rt/courses/", 1, 1);

    struct node* cs016 = createNode("cs016/", 2, 1);
    struct node* cs252 = createNode("cs252/", 1, 1);

    struct node* grades_cs016 = createNode("grades", 8, 0);
    struct node* homeworks = createNode("homeworks/", 1, 1);
    struct node* programs = createNode("programs/", 1, 1);

    struct node* projects = createNode("projects/", 1, 1);
    struct node* grades_cs252 = createNode("grades", 3, 0);

    struct node* papers = createNode("papers/", 1, 1);
    struct node* demos = createNode("demos/", 1, 1);

    struct node* hw1 = createNode("hw1", 3, 0);
    struct node* hw2 = createNode("hw2", 2, 0);
    struct node* hw3 = createNode("hw3", 4, 0);
    struct node* pr1 = createNode("pr1", 57, 0);
    struct node* pr2 = createNode("pr2", 97, 0);
    struct node* pr3 = createNode("pr3", 74, 0);
    
    struct node* buylow = createNode("buylow", 26, 0);
    struct node* sellhigh = createNode("sellhigh", 55, 0);
    struct node* market = createNode("market", 4786, 0);

    addChild(root, cs016);
    addChild(root, cs252);

    addChild(cs016, grades_cs016);
    addChild(cs016, homeworks);
    addChild(cs016, programs);

    addChild(cs252, projects);
    addChild(cs252, grades_cs252);
    addChild(projects, papers);
    addChild(projects, demos);

    addChild(homeworks, hw1);
    addChild(homeworks, hw2);
    addChild(homeworks, hw3);

    addChild(programs, pr1);
    addChild(programs, pr2);
    addChild(programs, pr3);

    addChild(papers, buylow);
    addChild(papers, sellhigh);
    addChild(demos, market);

    printf("Total Sizes:\n");
    preorderTraversal(root);

    postorderTraversal(root);

    freeTree(root);

    return 0;
}
