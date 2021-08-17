//
// Created by talg on 17/08/2021.
//

#ifndef AUTOCOMPLETE_HPP
#define AUTOCOMPLETE_HPP

#include <string>
#include <vector>
#include <unordered_map>

/**
 * @class AutoComplete
 * @implements
 * Using Trie Tree
 * preprocessing of a given used string list that are sorted by commonly used first.
 * @returns
 * "autocomplete" list for commonly used string given an input of a prefix
 * its done by recursively (DFS) traversing for each node down the tree and store the end string in
 * the output list. the maximum lookup time would be linear time O(n) where n is the size of
 * the given list/dictionary but is does saves a lot of space complexity.
 *
 * the other option (not implemented here) is to
 * store in each node the entire strings list that have this input prefix.
 * this would have wasteful space complexity since there can be a lot of strings starting with
 * a certain prefix. it does however have O(1) constant time lookup
 */
class AutoComplete {

    /**
     * @class TrieNode
     * a trie node class
     * @param prefix_ a str prefix up until this node. (for easy search)
     * @param children2node_ hashmap to node's children from char to TrieNode
     */
    class TrieNode {

    public:
        TrieNode(std::string prefix) {
            prefix_ = prefix;
        }

        std::string prefix_;
        std::unordered_map<char, TrieNode *> children2node_;
        bool is_auto_complete_str_ = false;
    };


public:

    /**
     * AutoComplete Constructor is performing pre processing of given string to trie tree for fast
     * auto complete
     * @param sorted_used_strings
     */
    AutoComplete(const std::vector<std::string> &sorted_used_strings) {
        root_node_ = new TrieNode("");
        // insert string backward because the of the recursive push from the end.
        for (int i=sorted_used_strings.size()-1; i>=0; i--) {
            insertStr(sorted_used_strings[i]);
        }
    }

    std::vector<std::string> getStringsForAutoComplete(const std::string &prefix) {
        std::vector<std::string> result;

        TrieNode *current = root_node_;
        for (const char c : prefix) {
            auto search_char = current->children2node_.find(c);
            if (search_char != current->children2node_.end()) {
                // found character in trie tree
                current = search_char->second;
            } else {
                // not found. return what we have so far
                return result;
            }
        }
        // lets find all string we have up to this character
        findAllChildStrings(current, result);

        return result;
    };

private:

    /**
     * inserts string to trie tree
     * @param str
     * iterating on str's characters and look each on in current node.
     * if found and character is equal to node's key , updating the current node position to current.
     * else, creating a new node with prefix string until that point with character included
     */
    void insertStr(const std::string &str) {
        TrieNode *current = root_node_;
        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            auto search_char = current->children2node_.find(c);
            if (search_char != current->children2node_.end()) {
                // found character in trie tree

            } else {
                // not found. need to have a new node with prefix including character
                current->children2node_[c] = new TrieNode(str.substr(0, i + 1));
                for (auto child : current->children2node_) {
                }
            }
            current = current->children2node_[c];

            if (i == str.size() - 1) {
                current->is_auto_complete_str_ = true;
            }
        }
    }

    /**
     * recursively finds all possible auto complete strings of a given node (character)
     * @param node
     * @param string_vector
     * run time is linear O(n) where n is all possible strings that can be autocomplete
     * for that node.
     */
    void findAllChildStrings(TrieNode *node, std::vector<std::string> &string_vector) {
        if (node->is_auto_complete_str_) {
            // using insert instead of push back so it will go to front instead of back
            // using O(1) because we insert to the beginning always.
            string_vector.push_back(node->prefix_);
        }
        for (auto &child : node->children2node_) {
            findAllChildStrings(node->children2node_[child.first], string_vector);
        }
    }

    TrieNode *root_node_;

};


#endif //AUTOCOMPLETE_HPP
