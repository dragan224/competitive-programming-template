class Trie {
    public:
        Trie() : root(new TrieNode(false)) {}

        void insert(string word) {
            TrieNode* node = root;
            for (auto& ch: word) {
                if (node->children.count(ch) == 0) {
                    node->children[ch] = new TrieNode(false);
                }
                node = node->children[ch];
            }
            node->isWord = true;
        }

        bool search(string& word) {
            TrieNode* node = root;
            return descend(node, word) && node->isWord;
        }

        bool startsWith(string& prefix) {
            TrieNode* node = root;
            return descend(node, prefix);
        }
    private:
        struct TrieNode {
                TrieNode(bool isWord_) : isWord(isWord_), children() {
            }
            bool isWord;
            unordered_map<char, TrieNode*> children;
        };
        bool descend(TrieNode*& node, string const& word) {
            for (auto& ch: word) {
                if (node->children.count(ch) == 0) {
                    return false;
                }
                node = node->children[ch];
            }
            return true;
        }
        TrieNode* root;
};