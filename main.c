#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queue.h"

const int items_count = 10;
const char message[46] = "Proccessing item %i from queue %i. Time: %i.\n";

int randomDelay() {
	return rand() % (1000) + 1;
}

void delay(int milliseconds) {
	struct timespec timeSleep = {
		milliseconds / 1000,
		(milliseconds) * 1000000L
	};
	nanosleep(&timeSleep, NULL);
}

void printAndDelay(int milliseconds, int queue, int *item) {
	printf(message, *item, queue, milliseconds);
	delay(milliseconds);
}

int main() {
	Queue *queue1 = initQueue();
	Queue *queue2 = initQueue();
	Queue *queue3 = initQueue();
	Queue *queue4 = initQueue();
	Queue *queue5 = initQueue();

	for(int i = 0; i < items_count; i++) {
		enqueue(queue1, randomDelay());
		enqueue(queue2, randomDelay());
		enqueue(queue3, randomDelay());
		enqueue(queue4, randomDelay());
		enqueue(queue5, randomDelay());
	}

	for(int i = 0; i < items_count; i++) {
		printAndDelay(dequeue(queue1), 1, &i);
		printAndDelay(dequeue(queue2), 2, &i);
		printAndDelay(dequeue(queue3), 3, &i);
		printAndDelay(dequeue(queue4), 4, &i);
		printAndDelay(dequeue(queue5), 5, &i);
		printf("---\n");
	}

	printf("All task proccessed.\n");

	return 0;
}
