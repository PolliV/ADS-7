// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T>
class TPQueue {
 private:
    struct Item {
      T data;
      Item* next;
    };
    Item* header;

 public:
    TPQueue() : header(nullptr) {}
    void push(const T& right) {
      if (header == nullptr) {
        Item* str = new Item;
        str->data = right;
        str->next = NULL;
        header = str;
      } else {
        Item* c1 = header;
        Item* c2 = new Item;
        int count = 0;
        while (c1) {
            if (c1->data.prior < right.prior) {
                break;
            } else {
                c1 = c1->next;
                count++;
            }
        }
        if (count == 0) {
            c2->next = header;
            c2->data = right;
            header = c2;
        } else {
            c1 = header;
            for (int i = 1; i < count; i++) {
                c1 = c1->next;
            }
            c2->next = c1->next;
            c2->data = right;
            c1->next = c2;
        }
    }
    void T pop() {
      T right = header->data;
      Item* c = header->next;
      delete header;
      header = c;
      return right;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
