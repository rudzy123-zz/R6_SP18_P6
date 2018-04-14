/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Implementation file for a pointer-based implementation of the ADT
 *  list that uses smart pointers.
 *
 *  Adapted from pages 298-300 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Rudolf Musika
 *
 *  @date 3 Mar 2018
 *
 *  @version 7.0 */

//#define NDEBUG

#include <string>
#include <new>
#include <memory>

#include <cassert>

#include "PrecondViolatedExcep.h"

template <typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList) {
    
    itemCount = 0; // Empty linked chain
    
    if (aList.headPtr) {
        auto aListPtr(aList.headPtr);
        
        try {
            headPtr = std::make_shared<Node<ItemType>>(aListPtr->getItem() );
            
            ++itemCount; // Increment after successful Node allocation
            
            auto thisListPtr(headPtr);
            
            aListPtr = aListPtr->getNext();
            
            while (aListPtr) {
                auto newNodePtr(
                                std::make_shared<Node<ItemType>>(aListPtr->getItem())
                                );
                
                thisListPtr->setNext(newNodePtr);
                
                ++itemCount; // Increment after each successful Node allocation
                
                thisListPtr = thisListPtr->getNext();
                aListPtr = aListPtr->getNext();
            }
        }
        catch (const std::bad_alloc&) {
            clear();
            throw;
        }
    }
}

#ifdef DTOR_TEST

#include <iostream>

template <typename ItemType>
LinkedList<ItemType>::~LinkedList() {
    
    std::cerr << "LinkedList destructor called on:\n"
    << "\theadPtr: "
    << headPtr
    << "\n"
    << "\titemCount: "
    << itemCount
    << std::endl;
}

#endif

template <typename ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    
    return !itemCount;
}

template <typename ItemType>
int LinkedList<ItemType>::getLength() const {
    
    return itemCount;
}

template <typename ItemType>
bool LinkedList<ItemType>::insert(const int newPosition,
                                  const ItemType& newEntry) {
    
    bool ableToInsert(newPosition >= 1 &&
                      newPosition <= itemCount + 1);
    
    if (ableToInsert) {
        try {
            if (newPosition == 1) {
                headPtr = std::make_shared<Node<ItemType>>(newEntry,
                                                           headPtr);
            }
            else {
                auto prevPtr(getNodeAt(newPosition - 1) );
                
                prevPtr->setNext(
                                 std::make_shared<Node<ItemType>>(newEntry,
                                                                  prevPtr->getNext())
                                 );
            }
            
            ++itemCount;
        }
        catch (const std::bad_alloc&) {
            ableToInsert = false;
        }
    }
    
    return ableToInsert;
}

template <typename ItemType>
bool LinkedList<ItemType>::remove(const int position) {
    
    bool ableToRemove(position >= 1 &&
                      position <= itemCount);
    
    if (ableToRemove) {
        if (position == 1) {
            headPtr = headPtr->getNext();
        }
        else {
            auto prevPtr(getNodeAt(position - 1) );
            
            auto curPtr(prevPtr->getNext() );
            
            prevPtr->setNext(curPtr->getNext() );
        }
        
        --itemCount;
    }
    
    return ableToRemove;
}

template <typename ItemType>
void LinkedList<ItemType>::clear() {
    
    headPtr = nullptr; // or headPtr.reset();
    itemCount = 0;
}

template <typename ItemType>
ItemType LinkedList<ItemType>::getEntry(const int position) const {
    
    bool ableToGet(position >= 1 &&
                   position <= itemCount);
    
    if (!ableToGet) {
        std::string message("LinkedList::getEntry() called with an empty ");
        message += "list or an invalid position.";
        
        throw PrecondViolatedExcep(message);
    }
    
    auto nodePtr(getNodeAt(position) );
    
    return nodePtr->getItem();
}

template <typename ItemType>
ItemType LinkedList<ItemType>::replace(const int position,
                                       const ItemType& newEntry) {
    
    bool ableToSet(position >= 1 &&
                   position <= itemCount);
    
    if (!ableToSet) {
        std::string message("LinkedList::setEntry() called with an empty ");
        message += "list or an invalid position.";
        
        throw PrecondViolatedExcep(message);
    }
    
    auto nodePtr(getNodeAt(position) );
    
    ItemType oldEntry(nodePtr->getItem() );
    
    nodePtr->setItem(newEntry);
    
    return oldEntry;
}

template <typename ItemType>
auto LinkedList<ItemType>::getNodeAt(const int position) const {
    
    assert(position >= 1 && position <= itemCount);
    
    auto curPtr(headPtr);
    
    for (int skip(1); skip < position; ++skip) {
        curPtr = curPtr->getNext();
    }
    
    return curPtr;
}
