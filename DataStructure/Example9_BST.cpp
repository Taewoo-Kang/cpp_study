// Binary Search Tree
// 부모 노드의 왼쪽에는 항상 작거나 같은 값의 원소
// 부모 노드의 오른쪽에는 항상 크거나 같은 값의 원소

#include <iostream>

struct Node
{
    int data;
    Node* left;
    Node* right;
};

struct BST
{
    private:
        Node* m_root = nullptr;
    
    public:
        Node* find(int value)
        {
            return findImpl(m_root, value);
        }

        void insert(int value)
        {
            if (m_root == nullptr)
                m_root = new Node {value, nullptr, nullptr};
            else
                insertImpl(m_root, value);
        }

        void inorder()
        {
            inorderImpl(m_root);
        }

        Node* successor(Node* start)
        {
            Node* current = start->right;
            while (current != nullptr && current->left != nullptr)
                current = current->left;
            
            return current;
        }

        void deleteValue(int value)
        {
            m_root = deleteImpl(m_root, value);
        }

    private:
        Node* findImpl(Node* current, int value)
        {
            if (current == nullptr)
            {
                std::cout << std::endl;
                return nullptr;
            }

            if (current->data == value)
            {
                std::cout << value << "를 찾았습니다." << std::endl;
                return current;
            }

            if (value < current->data)
            {
                std::cout << current->data << "에서 왼쪽으로 이동: ";
                return findImpl(current->left, value);
            }

            std::cout << current ->data << "에서 오른쪽으로 이동: ";
            return findImpl(current->right, value);
        }

        void insertImpl(Node* current, int value)
        {
            if (value < current->data)
            {
                if (current->left == nullptr)
                    current->left = new Node {value, nullptr, nullptr};
                else
                    insertImpl(current->left, value);
            }
            else
            {
                if (current->right == nullptr)
                    current->right = new Node {value, nullptr, nullptr};
                else
                    insertImpl(current->right, value);
            }
        }

        void inorderImpl(Node* start)
        {
            if (start == nullptr)
                return;
            
            inorderImpl(start->left);
            std::cout << start->data << " ";
            inorderImpl(start->right);
        }

        Node* deleteImpl(Node* start, int value)
        {
            if (start == nullptr)
                return nullptr;

            if (value < start->data)
                start->left = deleteImpl(start->left, value);
            else if (value > start->data)
                start->right = deleteImpl(start->right, value);
            else
            {
                // 자식 노드가 전혀 없거나, 왼쪽 자식 노드만 없는 경우
                if (start->left == nullptr)
                {
                    Node* tmp = start->right;
                    delete start;
                    return tmp;
                }

                // 오른쪽 자식 노드만 없는 경우
                if (start->right == nullptr)
                {
                    Node* tmp = start->right;
                    delete start;
                    return tmp;
                }

                // 자식 노드가 둘 다 있는 경우
                Node* succNode = successor(start);
                start->data = succNode->data;

                // 오른쪽 서브 트리에서 successor를 찾아 삭제
                start->right = deleteImpl(start->right, succNode->data);
            }

            return start;
        }
};

int main()
{
    BST tree;
    tree.insert(12);
    tree.insert(10);
    tree.insert(20);
    tree.insert(8);
    tree.insert(11);
    tree.insert(15);
    tree.insert(28);
    tree.insert(4);
    tree.insert(2);

    std::cout << "중위 순회: ";
    tree.inorder(); // BST의 모든 원소를 오름차순으로 출력
    std::cout << std::endl;

    tree.deleteValue(12);
    std::cout << "12를 삭제한 후 중위 순회: ";
    tree.inorder();
    std::cout << std::endl;

    if (tree.find(12))
        std::cout << "원소 12는 트리에 있습니다." << std::endl;
    else
        std::cout << "원소 12는 트리에 없습니다." << std::endl;
}