#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INIT_SIZE 4
// Struct list with length variable
typedef struct intlist {
  int length,
      capacity; // length: # elements in list, capacity: maximum element number
  int *items;
} intlist;

// Make a new list
intlist *newList() {
  intlist *newlist = malloc(sizeof(intlist));
  int *listitems =
      malloc(INIT_SIZE * sizeof(int)); // 4: initial length of list,
  *newlist = (intlist){0, 4, listitems};
  return newlist;
}

// Expand list
void expand(intlist *al) {
  al->capacity = al->capacity * 2;
  al->items = realloc(al->items, al->capacity * sizeof(int));
}

void reduce(intlist *al) {
  al->capacity = al->capacity / 2;
  al->items = realloc(al->items, al->capacity * sizeof(int));
}

// Add an element to list
void addElem(intlist *al, int n) {
  if (al->length >= al->capacity)
    expand(al);
  al->items[al->length] = n;
  al->length++;
}

int deleteElem(intlist *al) {
  int e = al->items[al->length];
  al->items[al->length] = 0;
  if (al->length <= (al->capacity) / 2)
    reduce(al);
  al->length--;
  return e;
}

int getElem(intlist *al, int index) { return al->items[index]; }

void changeElem(intlist *al, int n, int index) { al->items[index] = n; }

void addElemIndex(intlist *al, int n, int index) {
  int len = al->length;
  int old, cur;
  if (index >= len - 1)
    return addElem(al, n);
  if (len >= al->capacity)
    expand(al);
  cur = n;
  for (int i = index; i <= len; i++) {
    old = al->items[i];
    al->items[i] = cur;
    cur = old;
  }
  al->length++;
}

int deleteElemIndex(intlist *al, int index) {
  int len = al->length;
  int old, cur;
  if (index >= len - 1)
    return deleteElem(al);
  if (len <= al->capacity / 2)
    reduce(al);
  int e = al->items[len];
  for (int i = index + 1; i < len; i++) {
    old = al->items[i];
    al->items[i - 1] = al->items[i];
  }
  al->items[len] = 0;
  al->length--;
  return e;
}

// Print list
void print(intlist *al) {
  printf("[ ");
  for (int i = 0; i < al->length; i++) {
    if (i > 0)
      printf(", ");
    printf("%d", al->items[i]);
  }
  printf(" ]\n");
}

int main(void) {
  intlist *numbers;
  numbers = newList();
  for (int i = 0; i < 7; i++)
    addElem(numbers, i);
  addElemIndex(numbers, 69, 4);
  print(numbers);
  deleteElemIndex(numbers, 3);
  print(numbers);
}