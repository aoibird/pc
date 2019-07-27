#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define NAMELEN 10
using namespace std;

struct task {
  char name[NAMELEN];
  int time;
  struct task *next;
};

struct task *head = NULL;
struct task *tail = NULL;

void enqueue(char name[], int time)
{
  struct task *e = (struct task *) malloc(sizeof(struct task));
  int i = 0;
  while (name[i] != '\0') {
    e->name[i] = name[i];
    i++;
  }
  e->name[i] = '\0';
  e->time = time;
  e->next = NULL;

  if (tail == NULL) {
    head = tail = e;
  }
  else {
    tail->next = e;
    tail = e;
  }

}

void dequeue()
{
  if (head == NULL) return;

  if (head == tail) {
    free(head);
    head = tail = NULL;
  }
  else {
    struct task *d = head;
    head = head->next;
    free(d);
  }
}

void move()
{
  tail->next = head;
  head = head->next;
  tail = tail->next;
  tail->next = NULL;
}

void print(int cnt)
{
  if (head == NULL) return;
  cout << head->name << " " << cnt << endl;
}


int main()
{
  int n, q;
  cin >> n >> q;
  char name[NAMELEN];
  int time;
  while (scanf("%s %d", name, &time) != EOF) {
    enqueue(name, time);
  }

  int cnt = 0;
  while (head != NULL) {
    if (head->time <= q) {
      cnt += head->time;
      print(cnt);
      dequeue();
    }
    else {
      cnt += q;
      head->time -= q;
      move();
    }
  }

  //cout << cnt << endl;
}
