//---------------------------------------------------------------------------------------------------------
/// We are given a list of n elements; there are three types of operations.
/// 1. Insert an item into the list
/// 2. Find the Maximum item in the list
/// 3. Remove the Maximum item from the list
/// For a tree which has n nodes, has k = floor(log (n)) as the highest level
/// Maxheap & MinHeap are vice versa. Here MaxHeap is implemented using dynamic array technique.
/// http://www.lightoj.com/article_show.php?article=1005
/// https://www.youtube.com/watch?v=t0Cq6tVNRBA
//---------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class MaxHeap
{
private:
    ll capacity = 4,size = 0;
    ll *items = new ll[capacity];

    ll getleftChildIndex(ll getParentIndex) {return (getParentIndex*2)+1;}
    ll getRightChildIndex(ll getParentIndex) {return (getParentIndex*2)+2;}
    ll getParentIndex(ll childIndex) {return (childIndex-1)/2;}

    bool hasLeftChild(ll getParentIndex) {return getleftChildIndex(getParentIndex) < size;}
    bool hasRighttChild(ll getParentIndex) {return getRightChildIndex(getParentIndex) < size;}
    bool hasParent(ll childIndex) {return getParentIndex(childIndex) >= 0;}

    ll leftChild(ll getParentIndex) {return items[ getleftChildIndex(getParentIndex) ];}
    ll rightChild(ll getParentIndex) {return items[ getRightChildIndex(getParentIndex) ];}
    ll parent(ll childIndex) {return items[ getParentIndex(childIndex) ];}
    void Swap(ll index1, ll index2)
    {
        ll tmp = items[index1];
        items[index1] = items[index2];
        items[index2] = tmp;
    }
    void ensureExtraCapacity()
    {
        if(size == capacity - 1)
        {
            ll *newitems = new ll[capacity*2];
            for(ll i=0; i<size; i++)
                newitems[i] = items[i];
            delete [] items;
            items = newitems;
            capacity*=2;
        }
    }

public:
    ll Max()
    {   /// the complexity is O(1).
        if(size == 0)
        {
            cout<<"the heap is empty so a garbage returned"<<endl;
            return -9999999;
        }
        else
            return items[0];
    }

    ll HeapifyUp()
    {
        ll index = size-1;
        while(hasParent(index) && parent(index)< items[index])
        {
            Swap(getParentIndex(index),index);
            index = getParentIndex(index);
        }
    }

    ll HeapifyDown()
    {
        ll index = 0;
        while(hasLeftChild(index))
        {
            ll BiggerChildIndex = getleftChildIndex(index);
            if(hasRighttChild(index) && rightChild(index) > leftChild(index))
                BiggerChildIndex = getRightChildIndex(index);
            if(items[BiggerChildIndex] < items[index])
                break;
            else
            {
                Swap(index, BiggerChildIndex);
            }
            index = BiggerChildIndex;
        }
    }

    void DeleteMax()
    {   /// the complexity for the deletion of the Maximum number would be O(log n ).
        if(size == 0)
        {
            cout<<"the heap is empty so nothing to delete"<<endl;
        }
        else
        {
            items[0] = items[size-1];
            size--;
            HeapifyDown();
        }
    }

    ll Add(ll value)
    {   /// the complexity for adding an item is O(log n). Thus, the complexity for adding k items is O(k*log n).
        ensureExtraCapacity();
        items[size] = value;
        size++;
        HeapifyUp();
    }

    void HeapSort()
    {   /// complexity: O( n log n ). sort the array in descending order.
        ll *newitems = new ll[capacity], sz = size;
        for(ll i=0; i<sz; i++)
        {
            newitems[i] = Max();
            DeleteMax();
        }
        delete [] items;
        items = newitems;
        size = sz;
    }

    void show()
    {
        if(size == 0)
            cout<<"The Heap is empty"<<endl;
        else
        {
            cout<<"Current elements in Heap : ";
            for(ll i=0; i<size; i++)
            {
                cout<<items[i]<<" ";
            }
            cout<<endl;
        }
    }
};



int main()
{
    MaxHeap MH;
    MH.Add(25);
    cout<<MH.Max()<<endl;
    MH.Add(200);
    cout<<MH.Max()<<endl;
    MH.Add(-21);
    cout<<MH.Max()<<endl;
    MH.Add(150);
    cout<<MH.Max()<<endl;
    MH.Add(10);
    cout<<MH.Max()<<endl;
    MH.show();
    MH.HeapSort();
    MH.show();
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.show();
    MH.DeleteMax();
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    MH.show();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    MH.show();
    cout<<"---------------------------"<<endl;
    MH.Add(25);
    cout<<MH.Max()<<endl;
    MH.Add(200);
    cout<<MH.Max()<<endl;
    MH.Add(-21);
    cout<<MH.Max()<<endl;
    MH.Add(150);
    cout<<MH.Max()<<endl;
    MH.Add(10);
    cout<<MH.Max()<<endl;
    MH.show();
    MH.HeapSort();
    MH.show();
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.show();
    MH.DeleteMax();
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    MH.show();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    cout<<MH.Max()<<endl;
    MH.DeleteMax();
    MH.show();
    return 0;
}
