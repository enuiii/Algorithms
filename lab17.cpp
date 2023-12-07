#include <iostream>
#include <string>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    void remove(int value) {
        root = removeRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value);
    }

    std::string getLinearBracketNotation() {
        return generateLinearBracketNotation(root);
    }

    void printLinearBracketNotation() {
        std::cout << "Binary Search Tree (Linear Bracket Notation): " << getLinearBracketNotation() << std::endl;
    }

private:
    Node* root;

    Node* insertRecursive(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    Node* removeRecursive(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }

        if (value < node->data) {
            node->left = removeRecursive(node->left, value);
        }
        else if (value > node->data) {
            node->right = removeRecursive(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = removeRecursive(node->right, temp->data);
        }

        return node;
    }

    bool searchRecursive(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }

        if (value == node->data) {
            return true;
        }
        else if (value < node->data) {
            return searchRecursive(node->left, value);
        }
        else {
            return searchRecursive(node->right, value);
        }
    }

    std::string generateLinearBracketNotation(Node* node) {
        if (node == nullptr) {
            return "";
        }

        std::string result = std::to_string(node->data);

        if (node->left != nullptr || node->right != nullptr) {
            result += "(" + generateLinearBracketNotation(node->left) + ")";
            if (node->right != nullptr) {
                result += "(" + generateLinearBracketNotation(node->right) + ")";
            }
        }

        return result;
    }
};

int main() {
    BinarySearchTree bst;

    std::string input;
    std::cout << "Enter Binary Search Tree in linear bracket notation: ";
    std::getline(std::cin, input);

    // Парсинг линейно-скобочной записи и вставка узлов в дерево
    for (char c : input) {
        if (isdigit(c)) {
            int value = c - '0';
            bst.insert(value);
        }
    }

    while (true) {
        std::cout << "\nMenu:\n1. Add Node\n2. Remove Node\n3. Search Node\n4. Print Linear Bracket Notation\n5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::cout << "Enter value to add: ";
            int value;
            std::cin >> value;
            bst.insert(value);
            break;
        }
        case 2: {
            std::cout << "Enter value to remove: ";
            int value;
            std::cin >> value;
            bst.remove(value);
            break;
        }
        case 3: {
            std::cout << "Enter value to search: ";
            int value;
            std::cin >> value;
            std::cout << (bst.search(value) ? "Node found" : "Node not found") << std::endl;
            break;
        }
        case 4:
            bst.printLinearBracketNotation();
            break;
        case 5:
            std::cout << "Binary Search Tree (Linear Bracket Notation): " << bst.getLinearBracketNotation() << std::endl;
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}
// (5(3(1)(4))(7(6)(8)))
