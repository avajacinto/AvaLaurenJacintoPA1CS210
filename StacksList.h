//
// Created by avaja on 10/6/2026.
//
#pragma once

#include "Stack.h"
#include "List.h"

template <typename T>
class StacksList : public Stack<T> {
public:
    void push(T* value) override {
        list_.addFront(value);
    }
    void pop() override {
        list_.deleteFront();
    }
    T* peek() const override {
        return list_.getFront();
    }

    bool isEmpty() const override {
        return list_.isEmpty();
    }

    int size() const override {
        return list_.size();
    }

    void print () const override {
        return list_.print();
    }

private:
    LinkedList<T> list_;
};