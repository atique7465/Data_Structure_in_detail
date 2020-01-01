**TREE DATA STRUCTURE IN DETAIL**

- >**<p align="justify">Tree is an efficient way of storing and organizing data that is naturally hierachical.<p/>**
- >**<p align="justify">Tree data structure can be defined as collection of entities called nodes linked together to simulate a hierarchy.<p/>**
- >**<p align="justify">Tree is a non-linear data structure. its a hierarchycal structure.<p/>**
- >**<p align="justify">Each node contains some data & data can be any type.<p/>**

![tree image](img/binary_tree.jpeg)

- Some Points / Definitaion : 
     1. **Root:** The topmost node is called Root of the tree.
     2. **Parent-Children:** Each node may contain link or reference to some other node called its Children & the node itself           is the Parent.
     3. **Sibling:** Children of same parent are called Sibling.
     4. **Leaf Node:** Any node that does not have a child called Leaf Node.
     5. **Ancestor & Descendent:** If we can go from node A to node B then A is ancestor of B. B is discendent of A.

- Properties of Tree:
     1. Recursive Data Structure.
     2. Tree with n nodes can have at most n-1 edges & may be 0 edges.
        <br>if n-1 then it is fully connected tree.
        <br>below n-1 it is a forest.
     3. Depth & Height:<br>
        depth of X = lengrh of path from root to X or no. of edges from root to X.<br>
        height of X = No. of edges in longest path from X to leaf.<br>
        height of Tree = Height of Root Node.
        
-----------------------------------------------------------------------------------------------------------------------------
**Binary Tree**
- Each node in the tree can have at most two children (0/1/2).

