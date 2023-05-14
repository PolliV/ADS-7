// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

template<typename T>
class TPQueue {
 private:
    struct Item {
      T item;
      Item* next;
    };
    Item* head;
    Item* tail;

 public:
    TPQueue() : head(nullptr), tail(nullptr) {}
    ~TPQueue() {
      while (head) {
        pop();
      }
    }
    void push(const T& value) {
      Item* data = new Item;
      data->item = value;
      data->next = nullptr;
      if (head == nullptr) {
        head = data;
        tail = data;
        return;
      }
      if (head->data.prior < data.prior) {
        data->next = head;
        head = data;
        return;
      }
      Item* dop = head;
      while (dop->next != nullptr && dop->next->item.prior >= data.prior) {
        dop = dop->next;
        data->next = dop->next;
        dop->next = data;
        if (data->next == nullptr) {
          tail = data;
        }
      }
    }
    void T pop() {
      Item* item = head->next;
      T data = head->data;
      delete head;
      return data;
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
