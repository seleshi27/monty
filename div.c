#include "monty.h"
/**
 * m_div - divs the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_div(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	if (temp->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	valor = temp->next->n / temp->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}
