#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
// Pushback. Adds value to the back f the list
void ULListStr::push_back(const std::string& val){
  if (tail_ == NULL){ // If list is empty, create new item
    tail_ = new Item();
    head_ = tail_;
  }

  if(tail_->last < ARRSIZE){ // If theres space in current tail node
    tail_->val[tail_->last] = val;
    tail_->last++;
  }
  else{ // If no space, create new node
    Item* newNode = new Item();
    newNode->prev = tail_;
    tail_->next = newNode;
    tail_ = newNode;
    tail_->val[tail_->last] = val;
    tail_->last++;
  }

  size_++;
}

// Pushfront, adds new value to the front of the list
void ULListStr::push_front(const std::string& val){
  if (head_ == NULL){ // If list is empty, create new item
    head_ = new Item();
    tail_ = head_;
    head_->first = ARRSIZE; // Adjust first and last to start from the end
    head_->last = ARRSIZE;
  }

  if (head_->first > 0){ // If there is space before first index
    head_->first--;
    head_->val[head_->first] = val;
  }
  else{ // if no space, create new head node
    Item* newNode = new Item();
    newNode->next = head_;
    head_->prev = newNode;
    head_ = newNode;
    head_->first = ARRSIZE - 1;
    head_->last = ARRSIZE;
    head_->val[head_->first] = val;
  }

  size_++;
}

// Pop back removes a value from the back of the list
void ULListStr::pop_back(){
  if (tail_ == NULL){
    return; // If empty list, do nothing
  }

  tail_->last--;
  size_--;

  if (tail_->first == tail_->last){ // If node becomes empty, remove it
    Item* temp = tail_;
    tail_ = tail_->prev;
    if (tail_) tail_->next = NULL;
    else head_ = NULL; // No nodes left -> set head to NULL
    delete temp;
  }
}

// Pop front removes a value from the front of the list
void ULListStr::pop_front(){
  if (head_ == NULL){
    return;
  }

  head_->first++;
  size_--;

  if (head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    if (head_) head_->prev = NULL;
    else tail_ = NULL;
    delete temp;
  }
}

// 'back' returns a reference to the last element
std::string const& ULListStr::back() const{
  if (tail_ == NULL) throw std::runtime_error("List is empty");
  return tail_->val[tail_->last - 1];
}

// 'front' returns a reference to the first element
std::string const& ULListStr::front() const{
  if (head_ == NULL) throw std::runtime_error("List is empty");
  return head_->val[head_->first];
}

// Helper function, finds value at location
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (loc >= size_) return NULL; // Invalid loc

  Item* curr = head_;
  size_t index = loc;

  while (curr){
    size_t numElements = curr->last - curr->first;
    if (index < numElements){ // Found val in current node
      return &curr->val[curr->first + index];
    }
    index -= numElements;
    curr = curr->next;
  }

  return NULL;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
