#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Cart{
    string dish_name;
    int price;
    Cart* next;
    
    public:
        Menu(string dish_name = "abc" , int price = 0 , Cart* next = NULL){
            this->dish_name = dish_name;
            this->price = price;
            this->next = next;
        }
        
        void setDishName(string dish_name ){
            this->dish_name = dish_name; 
        }
        
        void setDishPrice(int price){
            this->price = price;
        }
        
        void setMenuNext(Cart* next){
            this->next = next;
        }
        
        string getDishName(){
            return dish_name; 
        }
        
        int getDishPrice(){
            return price;
        }
        
        Cart* getMenuNext(){
            return next;
        }
};

class CartList{
    Cart* head;
    Cart* tail; 
    
    public:
        MenuList(){
            head = NULL;
            tail = NULL;
        }
        
        void InsertInCart(string dishName , int dishPrice){
        	Cart* newDish = new Cart;
            newDish->setDishName(dishName); 
            newDish->setDishPrice(dishPrice);
            
            if(head == NULL){
                head = newDish;
                tail = newDish;
            }
            
            else{
                tail->setMenuNext(newDish);
                tail = newDish;
            }
		}
        
        void InsertMenuItem(){
            int price;
            string dish_name;
            cin.ignore();
            cout<<" Enter Dish Name : ";
            getline(cin , dish_name);
            
            cout<<" Enter Price of Dish : ";
            cin>>price;
            
            Cart* newDish = new Cart;
            newDish->setDishName(dish_name); 
            newDish->setDishPrice(price);
            
            if(head == NULL){
                head = newDish;
                tail = newDish;
            }
            
            else{
                tail->setMenuNext(newDish);
                tail = newDish;
            }
        }
        
        void EditMenuItemsPrice(){
        	Cart* current = head;
        	int itemNum = 0 , price;
        	
        	cout<<"\n Select Item Number : ";
        	cin>>itemNum;
        	
        	for(int i=0 ; i<itemNum-1 ; i++){
        		current = current->getMenuNext();
			}
			
			cout<<"Enter New Price : ";
			cin>>price;
			current->setDishPrice(price);
		}
        
        void DeleteMenuItem(){
        	Cart* current = head;
            Cart* temp ;
            
			int index;
            cout<<"  Select Item number you want to delete : ";
            cin>>index;
            
            if(index == 1){
    			head = head->getMenuNext();
				delete current;        	
			}
			
			else{
				for(int i=1 ; i<index-1 ; i++){
                	current = current->getMenuNext();
	            }	
	            
	            temp = current->getMenuNext();
	            current->setMenuNext(temp->getMenuNext());
	            delete temp;
			}
        }
        
        void DisplayCart(){
        	Cart* current = head;
        	int count = 0 , total = 0;
			cout<<"\n\n\t\t====Cart====";
        	while(current){
        		count++;
				cout<<"\n "<<count<<"-\t"<<current->getDishName()<<" ------- "<<setw(4)<<"Rs "<<current->getDishPrice();
				total = total + current->getDishPrice();
				current = current->getMenuNext();
			}
			
			cout<<"\tTotal amount = "<<total;
		}
        
        void DisplayMenu(){
        	Cart* current = head;
        	int count = 0;
        	
			cout<<"\n\n\t\t====Menu====";
        	while(current){
        		count++;
				cout<<"\n "<<count<<"-\t"<<current->getDishName()<<" ------- "<<setw(4)<<"Rs "<<current->getDishPrice();
				current = current->getMenuNext();
			}
		}
		
		Cart* selectMenuItem_Menu(int index){
			Cart* current = head;
			
			for(int i=1 ; i<=index ; i++){
				current = current->getMenuNext();
			}
			
			return current;
		}
};
