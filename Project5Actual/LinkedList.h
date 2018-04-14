/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for a pointer-based implementation of the ADT list
 *  that uses smart pointers.
 *
 *  Adapted from pages 297-298 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 3 Mar 2018
 *
 *  @version 7.0 */

#ifndef LINKED_LIST_
#define LINKED_LIST_

#include <memory>

#include "ListInterface.h"
#include "Node.h"

/** @class LinkedList LinkedList.h "LinkedList.h"
 *
 *  Specification of a smart pointer-based ADT list. */
template <typename ItemType>
class LinkedList : public ListInterface<ItemType> {
private:
    // Note: automatically initialized to nullptr:
    std::shared_ptr<Node<ItemType>> headPtr;
    
    int itemCount = 0;
    
    /** Locates the node at the specified position in this list.
     *
     *  @pre 1 <= position <= itemCount
     *
     *  @post None.
     *
     *  @param position The desired position to locate.
     *
     *  @return A smart pointer to the position-th node in this list.
     */
    auto getNodeAt(const int position) const;
    
public:
    LinkedList() = default;
    
    LinkedList(const LinkedList<ItemType>& aList);
    
#ifdef DTOR_TEST
    virtual ~LinkedList();
#else
    virtual ~LinkedList() = default;
#endif
    
    virtual bool isEmpty() const;
    
    virtual int getLength() const;
    
    virtual bool insert(const int newPosition,
                        const ItemType& newEntry);
    
    virtual bool remove(const int position);
    
    virtual void clear();
    
    virtual ItemType getEntry(const int position) const;
    
    virtual ItemType replace(const int position,
                             const ItemType& newEntry);
};

#include "LinkedList.cpp"

#endif
