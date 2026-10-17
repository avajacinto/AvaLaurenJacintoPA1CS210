#pragma once
#include <iostream>
#include "Node.h"
#include "List.h"

// Solution file. Lab 3's LinkedList plus addBack, getFront, isEmpty, size.
// tail_ is back so addBack is O(1). size_ is new so size() is O(1).

template <typename T>
class LinkedList : public List<T> {
public:
    LinkedList() : head_(nullptr), tail_(nullptr), size_(0) {}

    void addFront(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        fresh->next = head_;
        head_ = fresh;
        if (tail_ == nullptr) {
            tail_ = fresh;          // first node is both head and tail
        }
        ++size_;
    }

    void addBack(T* value) override {
        Node<T>* fresh = new Node<T>(value);
        if (tail_ == nullptr) {
            head_ = fresh;          // first node is both head and tail
            tail_ = fresh;
        } else {
            tail_->next = fresh;
            tail_ = fresh;
        }
        ++size_;
    }

    void addAnywhere(int position, T* value) override {
        if (position < 0 || position > size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        if (position == 0) {
            addFront(value);
            return;
        }

        if (position == size_) {
            addBack(value);
            return;
        }

        Node<T>* current = head_;

        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        Node<T>* fresh = new Node<T>(value);
        fresh->next = current->next;
        current->next = fresh;

        ++size_;
    }

    void deleteFront() override {
        if (head_ == nullptr) {
            std::cout << "LinkedList is empty." << std::endl;
            return;
        }
        Node<T>* doomed = head_;
        head_ = head_->next;
        if (head_ == nullptr) {
            tail_ = nullptr;        // list is empty again
        }
        delete doomed->data;
        delete doomed;
        --size_;
    }

    void deleteAnywhere(int position) override {
        if (position < 0 || position >= size_) {
            std::cout << "Invalid position." << std::endl;
            return;
        }

        if (position == 0) {
            deleteFront();
            return;
        }

        Node<T>* current = head_;

        for (int i = 0; i < position - 1; ++i) {
            current = current->next;
        }

        Node<T>* doomed = current->next;
        current->next = doomed->next;

        if (doomed == tail_) {
            tail_ = current;
        }

        delete doomed->data;
        delete doomed;

        --size_;
    }

    void reverse() override {
        Node<T>* previous = nullptr;
        Node<T>* current = head_;

        tail_ = head_;

        while (current != nullptr) {
            Node<T>* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        head_ = previous;
    }
    
    void concat(List<T>* other) override {
        LinkedList<T>* otherList = dynamic_cast<LinkedList<T>* >(other);

        if (otherLinked == nullptr) {
            std::cout << "Cannot concatenate different list types." << std::endl;
            return;
        }

        if (otherLinked->size_ == 0) {
            return;
        }

        if (size_ == 0) {
            head_ = otherLinked->head_;
            tail_ = otherLinked->tail_;
        } else {
            tail_->next = otherLinked->head_;
            tail_ = otherLinked->tail_;
        }

        size_ += otherLinked->size_;

        otherLinked->head_ = nullptr;
        otherLinked->tail_ = nullptr;
        otherLinked->size_ = 0;
    }


    T* getFront() const override {
        if (head_ == nullptr) {
            return nullptr;
        }
        return head_->data;
    }

    bool isEmpty() const override {
        return head_ == nullptr;
    }

    int size() const override {
        return size_;
    }

    bool search(T* value) const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            if (*current->data == *value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const override {
        Node<T>* current = head_;
        while (current != nullptr) {
            std::cout << *current->data << ",";
            current = current->next;
        }
        std::cout << std::endl;
    }

    ~LinkedList() override {
        while (head_ != nullptr) {
            Node<T>* doomed = head_;
            head_ = head_->next;
            delete doomed->data;
            delete doomed;
        }
    }

private:
    Node<T>* head_;
    Node<T>* tail_;
    int size_;
};
