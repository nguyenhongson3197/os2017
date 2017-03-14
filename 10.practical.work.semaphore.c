#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 10

typedef struct
{
	  char type; //fried chicken : 0, french fries : 1
	  int amount; //piece, weight
	  char unit; //piece : 0, gram : 1
}item

item bufer[BUFFER_SIZE];
int first = 0;
int last = 0;
sem_t s; 
int sem_init(sem_t *sem, int pshared,unsigned int value);
int sem_wait(sem_t *sem);
int sem_post(sem_t *sem);
int sem_destroy(sem_t *sem);

void produce(item *i) {
	while ((first + 1) % BUFFER_SIZE == last) {
		// do nothing -- no free buffer item
	}
	semWait(&s);
	memcpy(&buffer[first], i, sizeof(item));
	first = (first + 1) % BUFFER_SIZE;
	semPost(&s);
}

item *consume() {
	item *i = malloc(sizeof(item));
	while (first == last) {
		// do nothing -- nothing to consume
	}
	semWait(&s);
	memcpy(i, &buffer[last], sizeof(item));
	last = (last + 1) % BUFFER_SIZE;
	semPost(&s);
	return i;
}

void *Prothread(void *param){

item a;
	a.type = '1';
	b.amount = 0;
	c.unit = '1';
item b;
	b.type = '1';
	b.amount = 5;
	b.unit = '1';
item c;
	c.type = '5';
	c.amount = 5;
	c.unit = '1';
	
        printf("item 1:\n Type: %c\n Amount: %d\n Unit: %c\n", a.type, a.amount, a.unit);
	printf("item 2:\n Type: %c\n Amount: %d\n Unit: %c\n", b.type, b.amount, b.unit);
	printf("item 3:\n Type: %c\n Amount: %d\n Unit: %c\n", c.type, c.amount, c.unit);

	produce(&i1);
	printf("Produce item a: first: %d  last: %d\n", first, last);
	
	produce(&i2);
	printf("Produce item b: first: %d  last: %d\n", first, last);
	
	produce(&i3);
	printf("Produce item c: first: %d  last: %d\n", first, last);
	return 0;
}

void *Conthread(void *param){
	consume();
	printf("Consume an item: first: %d  last: %d\n", first, last);
	
	consume();
	printf("Consume another item: first: %d  last: %d\n", first, last);
	return 0;
}

int main(){
  sem_init(&s,0,1);
	pthread_t pt, ct;
        pthread_create(&pt, NULL, Prothread, NULL);
	pthread_create(&ct, NULL, Conthread, NULL);
	pthread_join(pt, NULL);
	pthread_join(ct, NULL);
  sem_destroy(&s);
	return 0;
}
