# amazon_interview Auto Complete Search



## class AutoComplete
### implements Using Trie Tree:
preprocessing of a given used string list that are sorted by commonly used first.
### returns:
"autocomplete" list for commonly used string given an input of a prefix. 
its done by recursively (DFS) traversing for each node down the tree and store the end string in
the output list. the maximum lookup time would be linear time O(n) where n is the size of
the given list/dictionary but is does saves a lot of space complexity.

### Other Implementation Option (not implemented here):
store in each node the entire strings list that have this input prefix.
this would have wasteful space complexity since there can be a lot of strings starting with
a certain prefix. it does however have O(1) constant time lookup