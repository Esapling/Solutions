#include <stack>
#include <iostream>
#include <ostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        int carry = 0, x, p = 0;
        Node* head = NULL, * temp = NULL;
        stack<int> s1;
        stack<int> s2;
        stack<int> result;
        while (first != NULL)
        {
            s1.push(first->data);
            first = first->next;
        }
        while (second != NULL)
        {
            s2.push(second->data);
            second = second->next;
        }
        while (s1.empty() != true && s2.empty() != true)
        {
            x = s1.top() + s2.top() + carry;
            s1.pop();
            s2.pop();
            if (x >= 10)
            {
                carry = x / 10;
                p = x - 10;
            }
            else
            {
                carry = 0;
                p = x;
            }
            result.push(p);

        }
        if (s1.empty())
        {
            while (!s2.empty())
            {

                x = s2.top() + carry;
                if (x >= 10)
                {
                    carry = x / 10;
                    p = x - 10;
                }
                else {
                    carry = 0;
                    p = x;

                }
                result.push(p);
                s2.pop();
            }
        }
        else if (s2.empty())
        {
            while (!s1.empty())
            {
                x = s1.top() + carry;
                if (x >= 10)
                {
                    carry = x / 10;
                    p = x - 10;
                }
                else {
                    carry = 0;
                    p = x;

                }
                result.push(p);
                s1.pop();
            }
        }
        if (carry > 0) {
            result.push(carry);
        }
        while (!result.empty())
        {
            x = result.top();
            result.pop();
            if (head == NULL)
            {
                head = new Node(x);
                temp = head;
            }
            else {
                temp->next = new Node(x);
                temp = temp->next;
            }
        }
        return head;

    }
    

};
Node* NodeAdd(int size, Node* ptr)
{
    Node* head = NULL;
    for (int i = 0; i < size; i++) {
        int x = 0;
        std::cout << "Enter x: " << std::endl;
         std::cin >> x;
        if (ptr == NULL)
        {

            head = new Node(x);
            ptr = head;
        }
        else {
            ptr->next = new Node(x);
            ptr = ptr->next;
        }
    }
    return head;
}

std::ostream& operator<<(std::ostream& os,Node* ptr)
{
    while (ptr != NULL)
    {
        os << ptr->data;
        ptr = ptr->next;
    }
    return os;
}
int main() {
    Node* list1 = NULL, * list2 = NULL;
    Node* resultList;
    int numsize1, numsize2;
    std::cout << "Enter the number of digits of first num : " << std::endl;
    std::cin >> numsize1;
    std::cout << "Enter the number of digit of the second num : " << std::endl;
    std::cin >> numsize2;
    list1 = NodeAdd(numsize1, list1);
    list2 = NodeAdd(numsize2, list2);
    Solution obj;
    resultList= obj.addTwoLists(list1, list2);

    std::cout << resultList;

}