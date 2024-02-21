#include "sort.h"
/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @node1: A pointer to the first node
 * @node2: A pointer to the second node
 */
void swap_nodes(listint_t **head, listint_t **node1, listint_t **node2)
{
	(*node1)->next = (*node2)->next;
	if ((*node2)->next != NULL)
		(*node2)->next->prev = *node1;
	(*node2)->prev = (*node1)->prev;
	(*node2)->next = *node1;

	if ((*node1)->prev != NULL)
		(*node1)->prev->next = *node2;
	else
		*head = *node2;
	(*node1)->prev = *node2;
	*node1 = (*node2)->prev;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 * order
 * @list: A pointer to the head of a doubly linked list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *iterator, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (iterator = (*list)->next; iterator != NULL; iterator = temp)
	{
		temp = iterator->next;
		insert = iterator->prev;

		while (insert != NULL && iterator->n < insert->n)
		{
			swap_nodes(list, &insert, &iterator);
			print_list((const listint_t *)*list);
		}
	}
}
