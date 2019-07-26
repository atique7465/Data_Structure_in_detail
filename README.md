# Data_Structure_in_detail

- [ ] **Hash_Table**

- For any interview problem, have hash_table at the top of mind.

- At high label a hash_table is key-value look up. so it gives a way, of given  a key associating a value with it for very very quick look ups.
- the key as well as the value can be basically any type of data structure. 
- if we want to store the objects in an array. like , creating an instance with a string key in an array.  A Hash_function converts that string key into some sort of Hash_value(Integer) and then this value gonna remapped into an index into that array.
- so, Key -> Hash_code -> index to the array.
- Hash_Codes are remapped into an index because the potential Hash_Codes may be billion or more but an array cant effort these.

1. **Collision:**

- Two different string key could actually have the same Hash_code that's  because there infinite number of string out there but finite number of Hash_Codes.
- Even two things with different Hash_Codes could actually wind up mapped to the same index.

**Solutions:**
there are many solutions.

- Chaining:
-> when there is a collision just store them in a linked list in the same index of the array.
-> So, rather than an array of instances it will be an array of linked list of instances.

