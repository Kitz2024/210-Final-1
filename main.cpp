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
    string order;
};

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
        cout << "Serving Coffee to: " << head->name << " - " << head->drinkOrder << "\n";
        dequeue(head,tail);
    }
}

int main (){
    

    return 0;
}