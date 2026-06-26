class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
         auto addOperation = [&](string str) {
        for (int i = 1; i < str.size(); i += 2)
            str[i] = ((str[i] - '0' + a) % 10) + '0';
        return str;
    };

    auto rotateOperation = [&](string str) {
        int n = str.size();
        return str.substr(n - b) + str.substr(0, n - b);
    };

    queue<string> q;
    unordered_set<string> visited;
    string smallest = s;

    q.push(s);
    visited.insert(s);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();

        if (cur < smallest)
            smallest = cur;

        string added = addOperation(cur);
        if (!visited.count(added)) {
            visited.insert(added);
            q.push(added);
        }

        string rotated = rotateOperation(cur);
        if (!visited.count(rotated)) {
            visited.insert(rotated);
            q.push(rotated);
        }
    }

    return smallest;
    }
};