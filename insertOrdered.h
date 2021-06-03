template <typename T>
void LinkedList<T>::insertOrdered(const T& newData) 
{

  // new node or on those existing nodes that are adjacent to the new node.

    Node *newNode = new Node(newData);
    size_++;
 
    // If first node to be insetailed in doubly
    // linked list
    if (!head_) {
	newNode->next = nullptr;
	newNode->prev = nullptr;
        head_ = newNode;
        tail_ = newNode;
        return;
    }
 
    // If node to be insetailed has value less
    // than first node
    if (newNode->data < head_->data)
    {
        newNode->prev = nullptr;
        head_->prev = newNode;
        newNode->next = head_;
        head_ = newNode;
        return;
    }
 
    // If node to be insetailed has value more
    // than last node
    if (newNode->data > tail_->data)
    {
        newNode->prev = tail_;
        tail_->next = newNode;
        tail_ = newNode;
        return;
    }
 
    // Find the node before which we need to
    // insert p.
    Node *temp = head_->next;
    while ((temp->data) < (newNode->data))
        temp = temp->next;
 
    // Insert new node before temp
    (temp->prev)->next = newNode;
    newNode->prev = temp->prev;
    temp->prev = newNode;
    newNode->next = temp;
}
