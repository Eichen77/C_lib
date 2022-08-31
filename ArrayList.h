#pragma once

typedef struct intlist intlist;
intlist *newList();
void expand(intlist *al);
void reduce(intlist *al);
void add_elem(intlist *al, int n);
void delete_elem(intlist *al);
int get_elem(intlist *al, int index);
void change_elem(intlist *al, int n, int index);
void add_elem_index(intlist *al, int n, int index);
void print(intlist *al);