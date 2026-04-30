#include<bits/stdc++.h>
using namespace std;

class FoodOrder{
private:
    string OrderId;
    string CustomerName;
    vector<string>items;
    bool isPlaced;
    double TotalAmount;
public:
    FoodOrder(string OrderId, string CustomerName)
    :OrderId(OrderId), CustomerName(CustomerName), isPlaced(false), TotalAmount(0.0){}

    //allow item to be in the list only if the order is not placed
    void AddToList(string name, double price){
        if(isPlaced){
            cout<<"Your order is already placed, you cannot add more items"<<endl;
            return;
        }
        items.push_back(name);
        TotalAmount+=price;
    }

    bool placeOrder(){
        if(isPlaced || items.empty()){
            return false;
        }
        isPlaced=true;
        return true;
    }
    int getItemCount()const{
        return items.size();
    }
    void displayOrder(){
        cout<< "Status: "<<(isPlaced?"Placed":"Pending")<<endl;
        cout<<"Order Id: "<<OrderId<<" Customer Name: "<<CustomerName<<endl;
        cout<<"Items list: ";
        for(const auto& item : items){
            cout<<item<<", ";
        }cout<<endl;
        cout<<"Total Amount: "<<TotalAmount<<endl;
    }
};
int main(){
    FoodOrder order1("101","Arun");
    order1.AddToList("Cheese Pasta", 400);
    order1.AddToList("Pizza", 230);
    order1.AddToList("Mocktail", 420);
    order1.placeOrder();
    cout<<"total items no. "<<order1.getItemCount()<<endl;
    order1.displayOrder();

    FoodOrder order2("102","Asim");
    order2.AddToList("Garlic Bread", 103.56);
    order2.AddToList("Chilli Potato", 230);
    order2.placeOrder();
    order2.AddToList("Cold Coffee", 234.5);
    cout<<"total items no. "<<order2.getItemCount()<<endl;
    order2.displayOrder();

}
