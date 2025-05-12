int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	tmp = *head;

	while (tmp && p < index)
	{
		tmp = tmp->next;
		p++;
	}

	if (!tmp)
		return (-1);

	if (tmp->prev)
		tmp->prev->next = tmp->next;
	else
		*head = tmp->next; // We're deleting the head

	if (tmp->next)
		tmp->next->prev = tmp->prev;

	free(tmp);
	return (1);
}
