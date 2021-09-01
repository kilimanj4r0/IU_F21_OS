#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node* next;
} type_node;

type_node * create_node(int);
void print_list(type_node **);
void insert_node(type_node **, type_node *);
void delete_node(type_node **, type_node *);

int main(){
	type_node * head = create_node(0);
	print_list(&head);

	type_node * el_2 = create_node(3);
	insert_node(&head, el_2);
	print_list(&head);

	type_node * el_3 = create_node(7);
	insert_node(&el_2, el_3);
	print_list(&head);

	delete_node(&head, el_3);
	print_list(&head);

	return 0;
}

type_node * create_node(int val){
	type_node * node = (type_node *) malloc(sizeof(type_node));
	node->val = val;
	node->next = NULL;
	return node;
}

void print_list(type_node ** head) {
	type_node * current = *head;
	while (current != NULL) {
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
}

void insert_node(type_node ** tail, type_node * node) {
	if (*tail == NULL)
		return ;
	if ((*tail)->next == NULL)
		(*tail)->next = node;
	else {
		node->next = (*tail)->next;
		(*tail)->next = node;
	}
}

void delete_node(type_node ** head, type_node * node) {
	if (*head == node) {
		node->next = NULL;
		return ;
	}
	type_node * current = *head;
	type_node * previous;
	while (current != NULL && current != node) {
		previous = current;
		current = current->next;
	}
	if (current == NULL)
		return ;
	previous->next = current->next;
	current->next = NULL;
}
