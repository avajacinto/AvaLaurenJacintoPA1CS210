#include <iostream>
#include "List.h"
#include "Data.h"
#include "Process.h"
#include "StackList.h"
#include "QueueList.h"
#include "Player.h"

// STEP 3 and STEP 5 of the lab guide: uncomment these two includes
// once the files exist.
// #include "StackList.h"
// #include "QueueList.h"

int main() {
    // ---- Part 0: the List you already know, plus the new methods. ----
    // This part runs right now. Build and run it before you write anything.
    std::cout << "== List<int> ==" << std::endl;
    std::unique_ptr<List<int>> list = makeList<int>();
    list->addFront(new int(20));
    list->addFront(new int(10));
    list->addBack(new int(30));
    list->print();                                           // 10,20,30,
    std::cout << "getFront: " << *list->getFront() << std::endl;   // 10
    std::cout << "size: " << list->size() << std::endl;            // 3
    list->deleteFront();
    list->print();                                           // 20,30,

    // ---- Part 1: StackList. Uncomment after STEP 3. ----
/*
    std::cout << std::endl << "== Stack<int> ==" << std::endl;
    StackList<int> stack;
    stack.push(new int(1));
    stack.push(new int(2));
    stack.push(new int(3));
    stack.print();                                           // 3,2,1,
    std::cout << "peek: " << *stack.peek() << std::endl;     // 3
    stack.pop();
    stack.print();                                           // 2,1,
    std::cout << "size: " << stack.size() << std::endl;      // 2

    std::cout << std::endl << "== Stack<Data> ==" << std::endl;
    StackList<Data> dataStack;
    dataStack.push(new Data(1, "Alice"));
    dataStack.push(new Data(2, "Bilal"));
    dataStack.push(new Data(3, "Chen"));
    dataStack.print();                                       // 3 Chen,2 Bilal,1 Alice,
    dataStack.pop();
    std::cout << "peek: " << *dataStack.peek() << std::endl; // 2 Bilal

    std::cout << std::endl << "== Empty stack ==" << std::endl;
    StackList<int> emptyStack;
    emptyStack.pop();                                        // LinkedList is empty.
    std::cout << "isEmpty: " << emptyStack.isEmpty() << std::endl; // 1
*/

    // ---- Part 2: QueueList. Uncomment after STEP 5. ----
/*
    std::cout << std::endl << "== Queue<int> ==" << std::endl;
    QueueList<int> queue;
    queue.enqueue(new int(1));
    queue.enqueue(new int(2));
    queue.enqueue(new int(3));
    queue.print();                                           // 1,2,3,
    std::cout << "front: " << *queue.front() << std::endl;   // 1
    queue.dequeue();
    queue.print();                                           // 2,3,
    std::cout << "size: " << queue.size() << std::endl;      // 2

    std::cout << std::endl << "== Queue<Data> ==" << std::endl;
    QueueList<Data> dataQueue;
    dataQueue.enqueue(new Data(1, "Alice"));
    dataQueue.enqueue(new Data(2, "Bilal"));
    dataQueue.enqueue(new Data(3, "Chen"));
    dataQueue.print();                                       // 1 Alice,2 Bilal,3 Chen,
    dataQueue.dequeue();
    std::cout << "front: " << *dataQueue.front() << std::endl; // 2 Bilal

    // Empty the queue, then reuse it. Checks that tail_ resets correctly.
    std::cout << std::endl << "== Drain and reuse ==" << std::endl;
    queue.dequeue();
    queue.dequeue();
    std::cout << "isEmpty: " << queue.isEmpty() << std::endl; // 1
    queue.enqueue(new int(99));
    queue.print();                                           // 99,

    return 0;
    */

    std::cout << std::endl << "== Uno turn order ==" << std:: endl;

    std::unique_pt<List<Player>> table = makeList<Player>();

    // Add three players from the original table
    Player* isabelle = new Player(1, "Isabelle");
    Player* tom = new Player(2, "Tom");
    Player* slider = new Player (3, "Slider");

    table->addBack(isabelle);
    table->addBack(tom);
    table->addBack(slider);

    std::cout << "Initial turn order:" << std::endl;
    table->print();

    std::cout << "Blathers joins in the middle:" << std::endl;
    Player* blathers = new Player(4, "Blathers");
    table->addAnywhere(1, blathers);
    table->print();

    isabelle->receiveCard(new Card("Red", "5"));
    isabelle->receiveCard(new Card("Green", "Skip"));

    tom->receiveCard(new Card("Blue", "2"));
    tom->receiveCard(new Card("Yellow", "Reverse"));

    slider->receiveCard(new Card("Red", "Draw Two"));
    slider->receiveCard(new Card("Blue", "7"));

    blathers->receiveCard(new Card("Green", "9"));
    blathers->receiveCard(new Card("Yellow", "Skip"));

    std::cout << "Cards dealt to the players." << std::endl;
    std::cout << "Isabelle's hand: ";
    isabelle->printHand();

    std::cout << "Tom's hand: ";
    tom->printHand();

    std::cout << "Slider's hand: ";
    slider->printHand();

    std::cout << "Blather's hand: ";
    blathers->printHand();


    // The direction of play reverses
    std::cout << "Before Reverse:" << std::endl;
    table->print();

    table->reverse();

    std::cout << "After Reverse:" << std::endl;
    table->print();

    Card* playedCard = tom->playCard();

    if (playedCard != nullptr) {
        std::cout << "Tom plays: " << *playedCard << std::endl;
        delete playedCard;
    }

    // Player leaves from a position other than the front
    std::cout << "A player leaves from the middle:" << std::endl;
    table->deleteAnywhere(2);
    table->print();

    // A new table is formed separately
    std::unique_ptr<List<Player>> secondTable = makeList<Player>();

    Player* timmy = new Player(5, "Timmy");
    Player* tommy = new Player(6, "Tommy");

    secondTable->addBack(timmy);
    secondTable->addBack(tommy);

    timmy->receiveCard(new Card("Red", "1"));
    timmy->receiveCard(new Card("Blue", "Skip"));

    tommy->receiveCard(new Card("Green", "4"));
    tommy->receiveCard(new Card("Yellow", "Reverse"));


    std::cout << "Timmy's hand: ";
    timmy->printHand();

    std::cout << "Tommy's hand: ";
    tommy->printHand();


    std::cout << "Second table before concat:" << std::endl;
    secondTable->print();

    // The second table transfers its players into the first table
    table->concat(secondTable.get());

    std::cout << "First table after concat:" << std::endl;
    table->print();

    std::cout << "Second table after concat:" >> std::endl;
    secondTable->print();

    std::cout << std::endl << "== Queue<Process> ==" << std::endl;

    QueueList<Process> processQueue;
    processQueue.enqueue(new Process (1, "Browser", "Google Chrome"));
    processQueue.enqueue(new Process (2, "Game", "Minecraft"));
    processQueue.enqueue(new Process (3, "Music", "Spotify"));

    processQueue.print();
    std::cout << std::endl;

    std::cout<< "front: ";
    processQueue.front()->print();
    std::cout << std::endl;

    processQueue.dequeue();

    std::cout << "After dqueue: ";
    processQueue.print();
    std::cout << std::endl;

std::cout << "size: " << processQueue.size() << std::endl;
}
