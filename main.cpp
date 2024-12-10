//Kit Pollinger
//210 Final Part 1
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>

using namespace std;

//Customers Name and Drink Order
struct Node {
    string name;
    string drinkOrder;
    Node* next;

    Node (const string& name, const string& drinkOrder)
    : name(name),drinkOrder(drinkOrder), next(nullptr){}

};

//Struct for other Vendors
struct customerBooth {
    string name;
    string drinkOrder;
};

//Function to add new customer to Linked List
void enqueue(Node*& head, Node*& tail, const string& name, const string& order){
    Node* newNode = new Node(name, order);
    if (!tail){
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

//Function to serve to a customer
void dequeue(Node*& head, Node*& tail){

    if (!head) return;
    Node* temp = head;
    head = head->next;

    if (!head) tail = nullptr; //if empty
    delete temp;

}
//Coffee Booth
void CoffeeBooth(Node*& head, Node*& tail, const vector<string>& names, const vector<string>& order){
    if (head){
        cout << "Serving Coffee to: " << head->name << " - " << head->drinkOrder << "\n";
        dequeue(head,tail);
    } else {
        cout << "Coffee booth empty. \n";
    }

    // 50% probability new Customer
    if(rand() % 2 == 0){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % order.size();
        cout << "New Customer Joined Coffee Booth: " << names[customerIndex] << " - " << order[customerOrder] << "\n";
    }
}

int main (){
    srand(static_cast<unsigned int>(time(0)));

    //Customer Names
    vector<string> names = {"Ryan", "Harry", "Lisa", "Elizabeth", "Max"};
    vector<string> coffeeOrders = {"Latte", "Espresso", "Cappuccino"};

    //Coffee booth Linked List
    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    //Coffee (Linked list)
    for (int i = 0; i < 3; i++){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % names.size();
        enqueue(coffeeHead, coffeeTail, names[customerIndex], coffeeOrders[customerOrder]);
    }
    return 0;
}