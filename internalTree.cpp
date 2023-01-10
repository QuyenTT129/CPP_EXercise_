#include <vector>
#include <stdexcept>
#include <iostream>

// Internal Node là node có thể có ít nhất một con
int countInternalNodes(const std::vector<int> &tree)
{
    int count = 0;
    for (int i = 0; i < tree.size(); i++)
    {
        for (int j = i + 1; j < tree.size(); j++)
        {
            if (tree[i] == tree[j])
            {
                count++;
            }
        }
    }
    return count;
}
#ifndef RunTests
int main()
{
    std::vector<int> tree;
    tree.push_back(1);
    tree.push_back(3);
    tree.push_back(1);
    tree.push_back(-1);
    tree.push_back(3);
    std::cout << countInternalNodes(tree);
}
#endif
