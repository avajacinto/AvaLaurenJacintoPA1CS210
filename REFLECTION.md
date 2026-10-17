1. Why does concat only need to work between two lists of the same representation? What would
you have to do differently, or what would go wrong, if you tried to make it work between a
LinkedList and an ArrayList?

concat only works between the same representation because an ArrayList stores pointers in an array, while a LinkedList stores them inside linked nodes. A mismatched dynamic_cast fails safely, so the method prints an error and leaves both lists unchanged. Supporting both would require a different method for transferring elements without directly accessing the other structure's private storage.

2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.

The three pointers are previous, current, and next. previous keeps track of the portion that is already reversed, current identifies the node being changed, and next saves the rest of the original list. Losing any one of them could disconnect part of the list or cause nodes to point incorrectly.

3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?

For addAnywhere, the valid positions are 0 through size_, because inserting at size_ adds to the end. For deleteAnywhere, the valid positions are 0 through size_ - 1, because the position equal to size_ does not contain an element. If the position is invalid, then the implementation prints out "Invalid position" and returns without changing the list. 

4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?

addFront and deleteFront only use head_, but concatenation must connect to the last node, so a linked list without a tail pointer would need to go from the head to the end. In my implementation, LinkedList already tracks tail_, so concat can attach the files directly in O(1) time. If a tail pointer were added to a version without one, it would need to be updated in addFront, addBack, deleteFront, addAnywhere, deleteAnywhere, reverse, and whenever the list becomes empty.

5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.

In ArrayList::addAnywhere, existing pointers shift one position to the right, starting at the last element and moving backeward toward the insertion position. This creates an empty slot for the new pointer. If the elements shifted from left to right, earlier assignments would overwrite pointers that still needed to be moved.

6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing.

The line that changes the direction of play is as follows: table->reverse();. Without the call, the players would remain in the original order after the reverse card scene, and the turn direction would not visibly change. With the current code, the call is not automatically connected to Tom's played card, so the scene should be described as using reverse() during the reverse card event rather than claiming the card itself that triggers it. 