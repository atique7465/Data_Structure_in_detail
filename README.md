# Data_Structure_in_detail
----------------------------------------------------------------------------------------------------------------------------------------

>**<p align="justify">In computer science, a data structure is a data organization, management, and storage format that enables efficient access and modification. More precisely, a data structure is a collection of data values, the relationships among them, and the functions or operations that can be applied to the data.<p/>**

- Which Data structure should use depends on : 
     1. what needs to be stored.
     2. Cost of operation.
     3. Memory Uses.
     4. Ease of implementation.
     
**Resource:**
1. Data structures: Introduction to Trees.<br/>
[https://www.youtube.com/watch?v=qH6yxkw0u78&list=PL2_aWCzGMAwI3W_JlcBbtYTwiQSsOTa6P&index=25](url)
--------------------------------------------------------------------------------------------------------------------------
- [ ] **Hash_Table** (_For any interview problem, have hash_table at the top of mind._)<br/> 
_<p align="justify"> **Note: For this topic resource link 02 given below explained everything very smartly.**<p/>_

**_<p align="justify">"Assume that we have an object and we want to assign a key to it to make searching easy. To store the key/value pair, we can use a simple array like a data structure where keys (integers) can be used directly as an index to store values. However, in cases where the keys are large and cannot be used directly as an index, we should use hashing."<p/>_**[Hackerearth notes]

- <p align="justify">In hashing, large keys are converted into small keys by using hash functions. The values are then stored in a data structure called hash table. The idea of hashing is to distribute entries (key/value pairs) uniformly across an array. Each element is assigned a key (converted key). By using that key you can access the element in O(1) time. Using the key, the algorithm (hash function) computes an index that suggests where an entry can be found or inserted.<p/>
- <p align="justify">At high label a hash_table is key-value look up. so it gives a way, of given  a key associating a value with it for very very quick look ups.<p/>
- the key as well as the value can be basically any type of data structure. 
- <p align="justify">if we want to store the objects in an array. like , creating an instance with a string key in an array.  A Hash_function converts that string key into some sort of Hash_value(Integer) and then this value gonna remapped into an index into that array.<p/>
- so, Key -> Hash_code -> index to the array.
- Hash_Codes are remapped into an index because the potential Hash_Codes may be billion or more but an array cant effort these.

**Hash function**
_<p align="justify">A hash function is any function that can be used to map a data set of an arbitrary size to a data set of a fixed size, which falls into the hash table. The values returned by a hash function are called hash values, hash codes, hash sums, or simply hashes.<p/>_
- To achieve a good hashing mechanism, It is important to have a good hash function with the following basic requirements:

- Easy to compute: It should be easy to compute and must not become an algorithm in itself.

- Uniform distribution: It should provide a uniform distribution across the hash table and should not result in clustering.

- Less collisions: Collisions occur when pairs of elements are mapped to the same hash value. These should be avoided.
```
hash = hashfunc(key)
index = hash % array_size
```
   _<p align="justify"> **Note: Irrespective of how good a hash function is, collisions are bound to occur. Therefore, to maintain the performance of a hash table, it is important to manage collisions through various collision resolution techniques.**<p/>_

**Problem 01-> Collision:**

- <p align="justify">Two different string key could actually have the same Hash_code that's  because there infinite number of string out there but finite number of Hash_Codes.<p/>
- Even two things with different Hash_Codes could actually wind up mapped to the same index.

**Solutions:**
there are many solutions.

- Separate chaining (open hashing): <br/>
  -> when there is a collision just store them in a linked list in the same index of the array.<br/>
  -> So, rather than an array of instances it will be an array of linked list of instances.<br/>
  -> linked list just not save the instances, the actual keys with instances as well.<br/>
  -> thus the search can be occure accurately. Otherwise there is possibility of mass up.
 
 - Linear probing (open addressing or closed hashing):<br/>
    ```
    index = index % hashTableSize
    index = (index + 1) % hashTableSize
    index = (index + 2) % hashTableSize
    index = (index + 3) % hashTableSize
    .
    .
    .
    and so on…
    ```
- Quadratic Probing:<br/>
    ```
    index = index % hashTableSize
    index = (index + 12) % hashTableSize
    index = (index + 22) % hashTableSize
    index = (index + 32) % hashTableSize
    .
    .
    and so on…
    ```
- Double hashing:<br/>
    ```
    index = (index + 1 * indexH) % hashTableSize;
    index = (index + 2 * indexH) % hashTabl eSize;
    .
    .
    and so on…
    ```
**Complexity:**
- It depends on the Hash_Fuction.
- O ( 1 ) for good Hash_Funtion.
- O ( n ) for terrible Hash_Table.

**Applications:**
- Associative arrays: Hash tables are commonly used to implement many types of in-memory tables. They are used to implement   associative arrays (arrays whose indices are arbitrary strings or other complicated objects).
- Database indexing: Hash tables may also be used as disk-based data structures and database indices (such as in dbm).
- Caches: Hash tables can be used to implement caches i.e. auxiliary data tables that are used to speed up the access to       data, which is primarily stored in slower media.
- Object representation: Several dynamic languages, such as Perl, Python, JavaScript, and Ruby use hash tables to implement   objects.
- Hash Functions are used in various algorithms to make their computing faster


**Resources for Hash_Table:**

1. hackerrank data structure on youtube.<br/>
[https://www.youtube.com/watch?v=shs0KM3wKv8&list=PLI1t_8YX-Apv-UiRlnZwqqrRT8D1RhriX&index=13](url)
2. Hackerearth notes. ***Better one**<br/>
[https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/tutorial/](url) 
3. Lecture note: Hashing (Hash functions and so on).<br/>
[https://www.cpp.edu/~ftang/courses/CS240/lectures/hashing.htm](url)
4. CP-Algorithms -> String Hashing.<br/>
[https://cp-algorithms.com/string/string-hashing.html](url)
5. codeforces -> [Tutorial] Rolling hash and 8 interesting problems [Editorial] <br/>
[https://codeforces.com/blog/entry/60445](url)
6. codeforces -> Anti-hash test. <br/>
[https://codeforces.com/blog/entry/4898](url)
7. Medium -> Simple Hash Map (Hash Table) Implementation in C++. <br/>
[https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250](url)

**To Explore Deeply**
1. Codexon<br>
   [https://web.archive.org/web/20101114013835/http://www.codexon.com/posts/hash-functions-the-modulo-prime-myth](url)
2. General Purpose Hash Function Algorithms.
   [https://web.archive.org/web/20101115165208/http://www.partow.net/programming/hashfunctions#HashAndPrimes](url)
  
----------------------------------------------------------------------------------------------------------------------------------------
**Underlying Data Structure of SLT in C++**
- unordered_map -> hash table
- std::map -> usually implemented with a red-black tree or self balanced binary tree
- unordered_set -> uses hash table
- std::set -> usually implemented with a red-black tree or self balanced binary tree
- Vector -> dynamically resizing array
- List -> Doubly Linked List
- C++ string class -> internally uses char array to store character but all memory management, allocation, and null  
  termination is handled by string class itself that is why it is easy to use.
- stack -> could be an array, a vector, an ArrayList, a linked list, or any other collection.
- queue -> could be an array, a Vector, an ArrayList, a LinkedList, or any other collection.
- priority_queue -> heap sort.

