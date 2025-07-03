#include <iostream>

// ANSI color codes for colored terminal output
#define CYAN    "\033[36m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

// Macros for resetting color and printing new line
#define RESETL  std::cout << "\033[0m";
#define NewLine std::cout << "\n";


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// int stoi(char integer);
void asignLinkedList (ListNode*& head, ListNode*& tail, int nums);
void printLinkedList (std::string text, ListNode* list);
void eraseLinkedList (ListNode* list);

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* head = nullptr;

        if (!l1 && !l2)
            return nullptr;

        int sums = ((l1) ? l1->val : 0) + ((l2) ? l2->val : 0);
        
        ListNode* newnode = new ListNode(sums % 10);
        head = newnode;

        if (l1)
            l1 = l1->next;
        if (l2)
            l2 = l2->next;
        if (sums / 10 != 0)
        {
            if (l1)
                l1->val += 1;
            else if (l2)
                l2->val += 1;
            else 
            {
                ListNode* tempnode = new ListNode(1);
                head->next = tempnode;
            }    
        }
        
        if (l1 || l2)
        {
            head->next = addTwoNumbers(l1, l2);
        }
        return head;
    }
};

int main() {
    Solution solution;
    int nums;
    ListNode* head1 = nullptr;  // Head1 pointer for the linked list
    ListNode* tail1 = nullptr;  // Tail1 pointer to add new nodes easily
    ListNode* head2 = nullptr;  // Head2 pointer for the linked list
    ListNode* tail2 = nullptr;  // Tail2 pointer to add new nodes easily

    std::cout << "First Reverse Number Variable  : " << CYAN;
    std::cin >> nums; RESETL
    asignLinkedList(head1, tail1, nums);
    
    std::cout << "Second Reverse Number Variable : " << CYAN;
    std::cin >> nums; RESETL
    asignLinkedList(head2, tail2, nums);
    // Input values and build the linked list
    
    NewLine NewLine
    
    // Traverse and print the linked list
    
    printLinkedList("First Linked List         ", head1);
    printLinkedList("Second Linked List        ", head2);
    
    NewLine
    
    ListNode* Answer = solution.addTwoNumbers(head1, head2);
    printLinkedList("Addition Both Linked List ", Answer);
    

    eraseLinkedList(head1);
    eraseLinkedList(head2);
    eraseLinkedList(Answer);

    return 0;
}

void asignLinkedList (ListNode*& head, ListNode*& tail, int nums)
{
    std::string val = std::to_string(nums);

    for (int i = 0; i < val.size(); i++) {
        // Create a new node with the input value
        ListNode* newNode = new ListNode((int)val[i] - '0');

        if (head == nullptr) {
            // First node in the list
            head = newNode;
            tail = newNode;
        } else {
            // Append to the end and update tail1
            tail->next = newNode;
            tail = newNode;
        }
    }
}

void printLinkedList (std::string text, ListNode* list)
{
    std::cout << text << " : [ ";
    ListNode* current = list;
    while (current != nullptr) {
        std::cout << GREEN << current->val << RESET;
        if (current->next != nullptr) {
            std::cout << ", ";
        }
        current = current->next;
    }
    std::cout << " ]";
    NewLine

    
}

void eraseLinkedList (ListNode* list)
{
    while (list != nullptr) {
        ListNode* nextNode = list->next;
        delete list;
        list = nextNode;
    }
}