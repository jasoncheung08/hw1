/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

void deleteList(Node* head){
  if (head == nullptr){
    return;
  }
  deleteList(head->next);
  delete head;
}

int main(int argc, char* argv[])
{
  // Creates linked list and calls split function and prints odds and evens
  Node* list = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5, new Node(6, nullptr))))));
  Node* odds = nullptr;
  Node* evens = nullptr;

  split(list, odds, evens);

  Node* temp = odds;
  cout << "Odds: ";
  while (temp){
    cout << temp->value << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;

  temp = evens;
  cout << "Evens: ";
  while (temp){
    cout << temp->value << " -> ";
    temp = temp->next;
  }
  cout << "NULL" << endl;

  // Free memory
  deleteList(odds);
  deleteList(evens);

  return 0;
}