typedef struct {
	int *items;
	int size;
	int head;
} Queue;

Queue* initQueue() {
	Queue *queue = (Queue *)malloc(sizeof (Queue));
	queue->items = (int *)malloc(sizeof (int));
	queue->size = 0;
	queue->head = 0;
	return queue;
}

int enqueue(Queue *queue, int item) {
	queue->size++;
	queue->items = (int *)realloc(queue->items, queue->size * sizeof(int));
	queue->items[queue->size - 1] = item;
	return 1;
}

int dequeue(Queue *queue) {
	queue->size--;
	return queue->items[queue->head++];
}

int peek(Queue *queue) {
	return queue->items[0];
}
