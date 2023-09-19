#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * add_node - function to add node
 * @head: input of address
 * @str: input string
 * @x: input of number node
 * Return: returns the size of node
*/

list_t *add_node(list_t **head, const char *str, int x)
{
	list_t *n_head;

	if (!head)
		return (NULL);
	n_head = malloc(sizeof(list_t));
	if (!n_head)
		return (NULL);
	_memset((void *)n_head, 0, sizeof(list_t));
	n_head->num = x;
	if (str)
	{
		n_head->str = _strdup(str);
		if (!n_head->str)
		{
			free(n_head);
			return (NULL);
		}
	}
	n_head->next = *head;
	*head = n_head;
	return (n_head);
}

/**
 * add_node_end - function to add node at end
 * @head: input of address
 * @str: input string
 * @x: input of node
 * Return: returns the size
*/

list_t *add_node_end(list_t **head, const char *str, int x)
{
	list_t *n_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	n_node = malloc(sizeof(list_t));
	if (!n_node)
		return (NULL);
	_memset((void *)n_node, 0, sizeof(list_t));
	n_node->num = x;
	if (str)
	{
		n_node->str = _strdup(str);
		if (!n_node->str)
		{
			free(n_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = n_node;
	}
	else
		*head = n_node;
	return (n_node);
}

/**
 * print_list_str - function to print list
 * @h: input of pointer
 * Return: returns the size
*/

size_t print_list_str(const list_t *h)
{
	size_t y = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		y++;
	}
	return (y);
}

/**
 * delete_node_at_index - function to delete node
 * @head: input of address
 * @index: the node index
 * Return: 1 alawys success
*/

int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *p_node;
	unsigned int y = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (y == index)
		{
			p_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		y++;
		p_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - function to free lists
 * @head_ptr: input of address
 * Return: returns 1 alawys success
*/

void free_list(list_t **head_ptr)
{
	list_t *node, *nxt_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		nxt_node = node->next;
		free(node->str);
		free(node);
		node = nxt_node;
	}
	*head_ptr = NULL;
}
