#include <iostream>
#include <queue>

struct Node
{
    std::string position;
    Node* first;
    Node* second;
};

struct CompanyTree
{
    Node* root;

    static CompanyTree createCompanyStructure(const std::string position)
    {
        CompanyTree tree;
        tree.root = new Node {position, nullptr, nullptr};
        return tree;
    }

    static Node* find(Node* root, const std::string& value)
    {
        if (root == nullptr)
            return nullptr;
        
        if (root->position == value)
            return root;
        
        Node* firstFound = CompanyTree::find(root->first, value);

        if (firstFound != nullptr)
            return firstFound;
        
        return CompanyTree::find(root->second, value);
    }

    bool addSubordinate(const std::string& manager, const std::string& subordinate)
    {
        Node* managerNode = CompanyTree::find(root, manager);

        if (managerNode == nullptr)
        {
            std::cout << manager << "를 찾을 수 없습니다." << std::endl;
            return false;
        }

        if (managerNode->first && managerNode->second)
        {
            std::cout << manager << "아래에 " << subordinate << "를 추가할 수 없습니다." << std::endl;
            return false;
        }

        if (managerNode->first == nullptr)
            managerNode->first = new Node {subordinate, nullptr, nullptr};
        else
            managerNode->second = new Node {subordinate, nullptr, nullptr};

        std::cout << manager << "아래에 " << subordinate << "를 추가!" << std::endl;
        return true;
    }
};

int main()
{
    CompanyTree tree = CompanyTree::createCompanyStructure("CEO");

    tree.addSubordinate("CEO", "부사장");
    tree.addSubordinate("부사장", "IT부장");
    tree.addSubordinate("부사장", "마케팅부장");
    tree.addSubordinate("IT부장", "보안팀장");
    tree.addSubordinate("IT부장", "앱개발팀장");
    tree.addSubordinate("마케팅부장", "물류팀장");
    tree.addSubordinate("마케팅부장", "홍보팀장");
    tree.addSubordinate("부사장", "재무부장");
}