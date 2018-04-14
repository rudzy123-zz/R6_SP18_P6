/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  queue.
 *
 *  Adapted from pages 421-424 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 9 Mar 2018
 *
 *  @version 7.0 */

#include <string>
#include <new>
#include <memory>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedQueue<ItemType>::LinkedQueue(const LinkedQueue<ItemType>& aQueue) {
    
    if (aQueue.frontPtr) {
        auto aQueuePtr(aQueue.frontPtr);
        
        try {
            frontPtr = std::make_shared<Node<ItemType>>(aQueuePtr->getItem() );
            
            backPtr = frontPtr;
            
            aQueuePtr = aQueuePtr->getNext();
            
            while (aQueuePtr) {
                backPtr->setNext(std::make_shared<Node<ItemType>>(aQueuePtr->getItem()) );
                
                backPtr = backPtr->getNext();
                aQueuePtr = aQueuePtr->getNext();
            }
        }
        catch (const std::bad_alloc&) {
            frontPtr.reset();
            backPtr.reset();
            
            throw;
        }
    }
}
template <typename ItemType>
int LinkedQueue<ItemType>::getLength() const{
    return length;
}
template <typename ItemType>
bool LinkedQueue<ItemType>::isEmpty() const {
    
    return !frontPtr;
}

template <typename ItemType>
bool LinkedQueue<ItemType>::enqueue(const ItemType& newEntry) {
    
    bool ableToEnqueue(true);
    
    try {
        auto newNodePtr(std::make_shared<Node<ItemType>>(newEntry) );
        
        if (isEmpty() ) {
            frontPtr = newNodePtr;
        }
        else {
            backPtr->setNext(newNodePtr);
        }
        
        backPtr = newNodePtr;
    }
    catch (const std::bad_alloc&) {
        ableToEnqueue = false;
    }
    
    return ableToEnqueue;
}

template <typename ItemType>
bool LinkedQueue<ItemType>::dequeue() {
    
    bool ableToDequeue(!isEmpty() );
    
    if (ableToDequeue) {
        if (frontPtr == backPtr) {
            frontPtr.reset();
            backPtr.reset();
        }
        else {
            frontPtr = frontPtr->getNext();
        }
    }
    
    return ableToDequeue;
}

template <typename ItemType>
ItemType LinkedQueue<ItemType>::peekFront() const {
    
    if (isEmpty() ) {
        std::string message("LinkedQueue::peekFront() called ");
        message += "on an empty queue.";
        
        throw PrecondViolatedExcep(message);
    }
    
    return frontPtr->getItem();
}
