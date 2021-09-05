#include "headers.h"

void put_char(char c)
{
	write(1, &c, 1);
}

void put_str(char *str)
{
	while (*str != '\0')
	{
		put_char(*str);
		str++;
	}
}

list *newnodelines(int lines)
{
	list *l;

	l = malloc(sizeof(list));
	l->numLines = lines;
	l->next = NULL;
	return (l);
}

list *newnode(char c)
{
	list *l;

	l = malloc(sizeof(list));
	l->c = c;
	l->next = NULL;
	return (l);
}

list *insertnodeend(char c, list *l)
{
	list *node;
	list *tmp;

	tmp = l;
	node = newnode(c);
	while (l->next)
	{
		l = l->next;
	}
	l->next = node;
	return (tmp);
}
