/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a sorted list-based implementation of the
 *  ADT priority queue.
 *
 *  Adapted from page 432 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 9 Mar 2018
 *
 *  @version 7.0 */

#include <memory>

template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue()
: sListPtr(std::make_unique<LinkedSortedList<ItemType>>() ) {
}

template <typename ItemType>
PriorityQueue<ItemType>::PriorityQueue(const PriorityQueue<ItemType>& pq)
: sListPtr(std::make_unique<LinkedSortedList<ItemType>>(*(pq.sListPtr)) ) {
}

template <typename ItemType>
bool PriorityQueue<ItemType>::isEmpty() const {
    
    return sListPtr->isEmpty();
}

template <typename ItemType>
bool PriorityQueue<ItemType>::enqueue(const ItemType& newEntry) {
    
    return sListPtr->insertSorted(newEntry);
}

template <typename ItemType>
bool PriorityQueue<ItemType>::dequeue() {
    
//    return sListPtr->remove(sListPtr->getLength());
        return sListPtr->remove(1);
}

template <typename ItemType>
ItemType PriorityQueue<ItemType>::peekFront() const {
    
//    return sListPtr->getEntry(sListPtr->getLength());
    return sListPtr->getEntry(1);
}
