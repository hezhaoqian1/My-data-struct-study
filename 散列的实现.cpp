#include<stdio.h>
#include<stdlib.h>
enum GridStatus {Active ,Removed,Empty};
typedef enum GridStatus Status;
struct HashTable
{
	int* key;
	Status* status;
	int size;
	int remains;
};
typedef struct HashTable* HT;
HT initHashTable(int size)
{
	HT h;
	h = (HT)malloc(sizeof(struct HashTable));
	h->size = h->remains = size;
	h->key = (int*)malloc(sizeof(int) * size);
	if (!h->key)
	{
		free(h->key);
		return NULL;
	}
	h->status = (Status*)malloc(sizeof(Status) * size);
	if (!h->status)
	{
		free(h->key);
		free(h);
		return NULL;
	}
	for (int i = 0; i < size; i++)
	{
		h->status[i] = Empty;
	}
	return h;
}
int main()
{
	HT h = initHashTable(11);
	return 0;
}