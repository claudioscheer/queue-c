typedef struct {
	int *items;
	int size;
} Queue;

Queue* initQueue() {
	Queue *q = (Queue *)malloc(sizeof (Queue));
	q->items = (int *)malloc(sizeof (int));
	q->size = 0;
	return q;
}

int enqueue(Queue *queue, int item) {
	queue->size++;
	queue->items = (int *)realloc(queue->items, queue->size * sizeof(int));
	queue->items[queue->size - 1] = item;
	return 1;
}

int dequeue(Queue *queue) {
	queue->size--;
	int item = queue->items[0];
	int *newItems = (int *)malloc(queue->size * sizeof(int));
	for (int i = 0; i < queue->size; i++) {
		newItems[i] = queue->items[i + 1];
	}
	free(queue->items);
	queue->items = newItems;
	return item;
}

int peek(Queue *queue) {
	return queue->items[0];
}
