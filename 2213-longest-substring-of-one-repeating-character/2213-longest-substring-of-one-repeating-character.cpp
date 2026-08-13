/*
                    "babacc"
                       [0]
                /              \
             "baba"             "cc"
              [1]                [2]
            /     \            /    \
          "ba"    "ba"       "c"    "c"
          [3]      [4]       [5]    [6]
         /  \     /  \
        b    a   b    a

Each Node stores:
    len      → length of segment
    longest  → longest same-character substring
    pref     → same-character prefix length
    suf      → same-character suffix length
    left     → first character
    right    → last character

When merging L + R:
    longest = max(L.longest, R.longest)

    If L.right == R.left:
        longest can become L.suf + R.pref

    pref:
        if entire L is same + boundary matches
        → L.pref + R.pref

    suf:
        if entire R is same + boundary matches
        → R.suf + L.suf

Update:
    change leaf
       ↓
    update parents
       ↓
    tree[1].longest = answer 
    */

static constexpr int N = 1 << 18;

// Each node represents one segment of the string
struct Node {
    int len{0};       // length of current segment
    int longest{0};   // longest same-character substring
    int pref{0};      // same-character prefix length
    int suf{0};       // same-character suffix length

    int left{0};      // first character of segment
    int right{0};     // last character of segment

    Node() {}

    Node(int len, int longest, int pref, int suf, int left, int right)
        : len(len), longest(longest), pref(pref), suf(suf),
          left(left), right(right) {}
};

// Merge two child nodes: L + R
inline Node merge(const Node& L, const Node& R) {

    int len = L.len + R.len;

    // Initially, longest answer is from either child
    int longest = max(L.longest, R.longest);

    // Can suffix of L and prefix of R join?
    bool canPlus = (L.right == R.left);

    // If boundary characters are same,
    // L.suffix + R.prefix can form a longer sequence.
    if (canPlus)
        longest = max(longest, L.suf + R.pref);

    // Calculate new prefix
    int pref = L.pref;

    // If whole L is same character,
    // prefix can continue into R.
    if (L.pref == L.len && canPlus)
        pref += R.pref;

    // Calculate new suffix
    int suf = R.suf;

    // If whole R is same character,
    // suffix can continue into L.
    if (R.suf == R.len && canPlus)
        suf += L.suf;

    // First character comes from L
    // Last character comes from R
    return Node(len, longest, pref, suf, L.left, R.right);
}

Node tree[N];

class SegTree {
public:

    unsigned int n, n2;

    // Build segment tree
    SegTree(string& s) : n(s.size()) {

        // Nearest power of 2 >= n
        n2 = 1;
        while (n2 < n)
            n2 <<= 1;

        // Initialize all nodes as empty
        for (int i = 0; i < 2 * n2; i++)
            tree[i] = Node();

        // Put characters into leaf nodes
        for (int i = 0; i < n; i++) {

            char c = s[i];

            tree[i + n2] = Node(
                1,  // len
                1,  // longest
                1,  // pref
                1,  // suf
                c,  // left character
                c   // right character
            );
        }

        // Build internal nodes from bottom to top
        for (int i = n2 - 1; i >= 1; i--)
            tree[i] = merge(tree[i << 1], tree[(i << 1) + 1]);
    }

    // Update one character
    void update(int idx, char c) {

        // Move to corresponding leaf
        idx += n2;

        // Replace old character
        tree[idx] = Node(1, 1, 1, 1, c, c);

        // Move upward and update all parents
        idx >>= 1;

        while (idx >= 1) {

            tree[idx] = merge(
                tree[idx << 1],
                tree[(idx << 1) + 1]
            );

            // Stop after updating root
            if (idx == 1)
                break;

            idx >>= 1;
        }
    }
};

class Solution {
public:
    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        // Build segment tree
        SegTree seg(s);

        int k = queryIndices.size();

        vector<int> ans(k);

        for (int i = 0; i < k; i++) {

            // Update character at given index
            seg.update(
                queryIndices[i],
                queryCharacters[i]
            );

            // Root contains answer for entire string
            ans[i] = tree[1].longest;
        }

        return ans;
    }
};