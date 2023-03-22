/*
 * LaQueue
 *
 *
 * This is part of a series of labs for the Liberal Arts and Science Academy.
 * The series of labs provides a mockup of an POSIX Operating System
 * referred to as LA(SA)nix or LAnix.
 *
 * (c) copyright 2018, James Shockey - all rights reserved
 *
 * */
#include <cstring>
#include <iostream>
#include <stdio.h>

using namespace std;
struct str {
  int priority;
  void *data;
};

class PQueue {

private:
int MAX_SIZE = 20;
  str *queue;
  int start=0, end=0;

public:
  PQueue();
  void push(void *item, int priority);
  void *top();
  void pop();
  void display();
};
