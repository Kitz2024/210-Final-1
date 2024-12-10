//Kit Pollinger
//210 Final Exam
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime> //Random Generator
using namespace std;

//Customers Name and Drink Order
struct Node {
    string name;
    string order;
    Node* next;

    Node (const string& name, const string& order)
    : name(name),order(order), next(nullptr){}
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
void CoffeeBooth(Node*& head, Node*& tail, const vector<string>& names, const vector<string>& orders){
    if (head){
        cout << "Serving Coffee to: " << head->name << " - " << head->order << "\n";
        dequeue(head,tail);
    } else {
        cout << "Coffee booth empty. \n";
    }

    // 50% probability new Customer
    if(rand() % 2 == 0){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % orders.size();
        cout << "New Customer joined Coffee Booth: " << names[customerIndex] << " - " << orders[customerOrder] << "\n";
    }
}
//Struct for other Vendors
struct customerBooth {
    string name;
    string order;
};
void muffinBooth(deque<customerBooth>& queue, const vector<string>& names, const vector<string>& orders){
    if (!queue.empty()){
        auto customer = queue.front();
        cout << "serving muffin(s) to: " << customer.name << " - " << customer.order << "\n";
        queue.pop_front();
    } else {
        cout << "Muffin Booth Empty.\n";
    }
    if(rand() % 2 == 0){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % orders.size();
        queue.push_back({names[customerIndex], orders[customerOrder]});
        cout << "New Customer joined the Muffin Booth: " << names[customerIndex] << " - " << orders[customerOrder] << "\n";
    }
}
//Bracelet Booth
void friendBraceltBooth(vector<customerBooth>& queue, const vector<string>& names, const vector<string> & orders){
    if (!queue.empty()){
        auto customer = queue.front();
        cout << "Serving Friendship Bracelet to: " << customer.name << " - " << customer.order << "\n";
        queue.erase(queue.begin());
    }else {
        cout << "Friendship Bracelet Booth Empty.\n";
    }
    if(rand() % 2 == 0){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % orders.size();
        queue.push_back({names[customerIndex], orders[customerOrder]});
        cout << "New Customer joined the Friendship Bracelet Booth: " << names[customerIndex] << " - " << orders[customerOrder]<< "\n";
    }
}

//Book booth

void bookBooth (deque<customerBooth>& queue, const vector<string>& names, const vector<string> & orders){
    if (!queue.empty()){
    auto customer = queue.front();
    cout << "Serving book to: " << customer.name << " - " << customer.order;
    queue.pop_front();
    } else {
        cout << "book Booth empty.\n";
    }
    if (rand() % 2 == 0 ){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % orders.size();
        queue.push_back({names[customerIndex], orders[customerOrder]});
        cout << "New Customer joiend the Book Booth: " << names[customerIndex] << " - " << orders[customerOrder]<< "\n";
    }
}
    
int main (){

    srand(static_cast<unsigned int>(time(0)));

    //Customer Names
    vector<string> names = {"Ryan", "Harry", "Max"};
    vector<string> coffeeOrders = {"Latte", "Espresso", "Cappuccino"};
    vector<string> muffinOrders = {"Blueberry", "Chocolate", "Red Velvet"};
    vector<string> friendBraceltOrders = {"Red", "Blue", "Green", "Rainbow"};
    vector<string> bookOrders = {"Fantasy", "Fiction", "Non-Fiction", "Sci-fi"};

    //Coffee booth Linked List
    Node* coffeeHead = nullptr;
    Node* coffeeTail = nullptr;

    for (int i = 0; i < 3; i++){
        int customerIndex = rand() % names.size();
        int customerOrder = rand() % coffeeOrders.size();
        enqueue(coffeeHead, coffeeTail, names[customerIndex], coffeeOrders[customerOrder]);
    }

    //Muffin Booth (deque)
    deque<customerBooth> muffinQueue;

    //Friendship Bracelet Booth (Vector)
    vector<customerBooth> braceletQueue;

    //Book Booth (deque)
    deque<customerBooth> bookQueue;


    //Simulation
    for (int boothRound = 1; boothRound <= 10; ++boothRound){
        cout << " Rounds " << boothRound;

        cout << "\nCoffee Booth:\n";
        CoffeeBooth(coffeeHead, coffeeTail, names, coffeeOrders);
        
        cout << "\nMuffin Booth:\n";
        muffinBooth(muffinQueue, names, muffinOrders);

        cout << "\nFriendship bracelet Booth:\n";
        friendBraceltBooth(braceletQueue, names, friendBraceltOrders);

        cout << "\nBook Booth\n";
        bookBooth (bookQueue, names, bookOrders);

    }

    while (coffeeHead) dequeue(coffeeHead, coffeeTail);

    return 0;
}