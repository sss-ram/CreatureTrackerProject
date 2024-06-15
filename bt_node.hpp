#ifndef BT_NODE_HPP
#define BT_NODE_HPP

template <typename T>
class BTNode {
public:
    T data;
    BTNode* left;
    BTNode* right;

    BTNode(const T& data)
        : data(data), left(nullptr), right(nullptr) {}
};

#endif // BT_NODE_HPP
