template <typename T>
MaxHeap<T>::MaxHeap()
{
    m_heapSize = 0;
    m_arraySize = 10;
    m_arr = new T[m_arraySize];
}

template <typename T>
MaxHeap<T>::~MaxHeap()
{
    m_heapSize = 0;
    delete[] m_arr;
    m_arr = nullptr;
}

template <typename T>
void MaxHeap<T>::resize()
{
    T* new_arr = new T[m_arraySize*2];
    for(int i=0;i<m_arraySize;i++)
    {
        new_arr[i]=m_arr[i];
    }
    delete[] m_arr;
    m_arr=new_arr;
    new_arr = nullptr;
    m_arraySize=m_arraySize*2;
}

template <typename T>
void MaxHeap<T>::upheap(int index)
{
    if (index<=0)
    {
        return;
    }
    int parent= (index-1)/2 ;
    if (!(m_arr[index] < m_arr[parent]))//greater than
    {
        swap(m_arr[index],m_arr[parent]);
        upheap(parent);
    }

}

template <typename T>
void MaxHeap<T>::downheap(int index)
{
    if (index>=m_heapSize)
    {
        return;
    }
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (!(m_arr[leftChild] < m_arr[rightChild]))//gretater than
    {
        if (m_arr[index] < m_arr[leftChild])
        {
            swap(m_arr[index], m_arr[2 * index + 1]);
            downheap(2*index +1);
        }
    }
    else//right child is bigger
    {
        if (m_arr[index] < m_arr[rightChild])
        {
            swap(m_arr[index], m_arr[2 * index + 2]);
            downheap(2 * index + 2);
        }
    }
    
    return;
}



template <typename T>
bool MaxHeap<T>::isEmpty() const
{
    if (m_heapSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

template <typename T>
int MaxHeap<T>::getNumberOfNodes() const
{
    return m_heapSize;
}

template <typename T>
int MaxHeap<T>::getHeight() const
{
    return (    recgetHeight(0) );
}

template <typename T>
int MaxHeap<T>::recgetHeight(int index) const
{
    if (index*2+1<m_heapSize)
    {
        return (1 + recgetHeight(index * 2 + 1));
    }
    else
    {
        return 0;
    }
    
}

template <typename T>
T MaxHeap<T>::peekTop() const
{
    if (m_heapSize == 0)
    {
        throw(runtime_error("CAN NOT PEEK AT EMPTY HEAP"));
    }
    else 
    {
        return m_arr[0];
    }
}

template <typename T>
void MaxHeap<T>::add(const T &newData)
{
    if (m_heapSize+1>m_arraySize)
    {
        resize();
    }
    m_arr[m_heapSize] = newData;
    upheap(m_heapSize);
    m_heapSize = m_heapSize+1;
}

template <typename T>
void MaxHeap<T>::remove()
{
    if (isEmpty())
    {
        throw(runtime_error("CAN NOT REMOVE FROM AN EMPTY HEAP"));
    }

    swap(m_arr[0], m_arr[m_heapSize-1]);
    m_heapSize= m_heapSize-1;
    downheap(0);
}

template <typename T>
void MaxHeap<T>::clear()
{
    while (m_heapSize!=0)
    {
        remove();
    }
}