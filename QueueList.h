//
// Created by avaja on 10/6/2026.
//

#pragma once

#include "Queue.h"

template <typename T>
class QueueList : public Queue<T> {
public:
    void enqueue (T* value) override {
        this->enqueue(value);
    }

    void dequeue() override {
        this->dequeue();
    }

    int front() override {
        return this->front();
    }

    bool isEmpty() const override {
        return this->isEmpty();
    }

    int size() const override {
        return this->size();
    }

    void print() const override {
        this->print();
    }

private:
    LinkedList<T> list_;

};