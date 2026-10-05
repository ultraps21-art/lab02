#include <string>
#include "studentRoll.h"
using namespace std;

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *newNode = new Node;
  newNode->next = NULL;
  newNode->s = new Student(s);

  if (head == NULL) {
    head = newNode;
    tail = newNode;
  }
  else {
    tail->next = newNode;
    tail = tail->next;
  }
}

std::string StudentRoll::toString() const {
  string result = "[";
  Node* curr = head;

  while (curr != NULL) {
    result += curr->s->toString();
    if (curr->next != NULL) {
      result += ",";
    }
    curr = curr->next;
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  // STUB
  head = tail = NULL;
  Node* curr = orig.head;
  
  while (curr != NULL) {
    insertAtTail(*curr->s);
    curr = curr->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* curr = head;
  while (curr != NULL) {
    Node* temp = curr->next;
    delete curr->s;
    delete curr;
    curr = temp;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // TODO... Here is where there is code missing that you need to 
  // fill in...
  Node* curr = head;
  while (curr != NULL) {
    Node* temp = curr->next;
    delete curr->s;
    delete curr;
    curr = temp;
  }

  head = tail = NULL;
  curr = right.head;
  while (curr != NULL) {
    insertAtTail(*curr->s);
    curr = curr->next;
  }
  

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}





