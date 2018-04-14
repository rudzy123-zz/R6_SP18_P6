/** @file
 *
 *  @course CS1521
 *  @section 1
 *
 *  Header file for a pointer-based implementation of the ADT queue.
 *
 *  Adapted from page 421 in Carrano 7e.
 *
 *  @author Frank M. Carrano
 *  @author Timothy Henry
 *  @author Steve Holtz
 *
 *  @date 9 Mar 2018
 *
 *  @version 7.0 */

#ifndef LINKED_QUEUE_
#define LINKED_QUEUE_

#include <memory>

#include "QueueInterface.h"
#include "Node.h"

/** @class LinkedQueue LinkedQueue.h "LinkedQueue.h"
 *
 *  Specification of a pointer-based ADT queue. */
template <typename ItemType>
class LinkedQueue : public QueueInterface<ItemType> {
private:
    using NodePtr = std::shared_ptr<Node<ItemType>>;
    
    NodePtr backPtr;
    NodePtr frontPtr;
    int length;
    
public:
    LinkedQueue() = default;
    
    LinkedQueue(const LinkedQueue<ItemType>& aQueue);
    
    virtual ~LinkedQueue() = default;
    
    int getLength() const ;
    
    bool isEmpty() const override;
    
    bool enqueue(const ItemType& newEntry) override;
    
    bool dequeue() override;
    
    ItemType peekFront() const override;
};

#include "LinkedQueue.cpp"

#endif
