Project: 0x1A. C - Hash tables
Tasks
0. >>> ht = {}
mandatory
Write a function that creates a hash table.

Prototype: hash_table_t *hash_table_create(unsigned long int size);
1. djb2
mandatory
Write a hash function implementing the djb2 algorithm.

Prototype: unsigned long int hash_djb2(const unsigned char *str);
2. key -> index
mandatory
Write a function that gives you the index of a key.

Prototype: unsigned long int key_index(const unsigned char *key, unsigned long int size);
3. >>> ht['betty'] = 'cool'
mandatory
Write a function that adds an element to the hash table.

Prototype: int hash_table_set(hash_table_t *ht, const char *key, const char *value);
4. >>> ht['betty']
mandatory
Write a function that retrieves a value associated with a key.

Prototype: char *hash_table_get(const hash_table_t *ht, const char *key);
5. >>> print(ht)
mandatory
Write a function that prints a hash table.

Prototype: void hash_table_print(const hash_table_t *ht);
6. >>> del ht
mandatory
Write a function that deletes a hash table.

Prototype: void hash_table_delete(hash_table_t *ht);
where ht is the hash table
7. $ht['Betty'] = 'Cool'
#advanced
In PHP, hash tables are ordered. Wait… WAT? How is this even possible?
100-sorted_hash_table.c
