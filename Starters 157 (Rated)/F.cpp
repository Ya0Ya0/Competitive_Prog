#include <iostream>
#include <list>
using namespace std;
struct Node
{
    bool data;
    Node *next;
};

class LinkedList
{
public:
    Node *head;

    LinkedList() : head(nullptr) {}

    // Function to add a new node at the end of the linked list
    void append(bool data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
};
int minimum_possible_length(LinkedList &bin_str, int N)
{
    int count_ones = 0;
    int count_zeros = 0;

    // Step 1: Count ones and zeros in the linked list.
    Node *temp = bin_str.head;

    // Count the number of ones in the linked list
    while (temp != nullptr)
    {
        if (temp->data)
        {
            count_ones++;
        }
        else
        {
            count_zeros++;
        }
        temp = temp->next;
    }

    // Step 2: Apply the optimal strategy:
    // If there are no ones, the result is the count of zeros.
    if (count_ones == 0)
    {
        return count_zeros;
    }

    // Step 3: If there are ones, we can remove all the zeros.
    // If the number of ones is odd, we can remove all but one one.
    if (count_ones % 2 == 1)
    {
        return 1; // Odd number of ones, one will remain.
    }
    else
    {
        return 0; // Even number of ones, all can be removed.
    }
}

int main()
{
    // Example usage of the function.
    for(int i =0;i <3;i++){
        int N;
        LinkedList bin_str;
        string input;

        // Read input from stdin (a binary string)
        cin >> N;
        cin >> input;

        // Process the input string and append to LinkedList
        for (char ch : input)
        {
            if (ch == '0')
            {
                bin_str.append(false); // Append 0 as false
            }
            else if (ch == '1')
            {
                bin_str.append(true); // Append 1 as true
            }
        }
        // Create the binary linked list: 1010001

        int result = minimum_possible_length(bin_str, N);
        std::cout << "Minimum possible length: " << result << std::endl;
    }
    return 0;
}