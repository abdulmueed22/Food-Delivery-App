#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
 
class Menu{
    string dish_name;
    int price;
    Menu* next;
    
    public:
        Menu(string dish_name = "abc" , int price = 0 , Menu* next = NULL){
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
        
        void setMenuNext(Menu* next){
            this->next = next;
        }
        
        string getDishName(){
            return dish_name; 
        }
        
        int getDishPrice(){
            return price;
        }
        
        Menu* getMenuNext(){
            return next;
        }
};

class MenuList{
    public:
        Menu* head;
        Menu* tail; 
    
        MenuList(){
            head = NULL;
            tail = NULL;
        }
        
        void InsertInCart(string dishName , int dishPrice){
        	Menu* newDish = new Menu;
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
            
            Menu* newDish = new Menu;
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
        	Menu* current = head;
        	int itemNum = 0 , price;
        	
        	cout<<"\n Select Item Number : ";
        	cin>>itemNum;
        	
        	for(int i=0 ; i<itemNum-1 ; i++){
        		current = current->getMenuNext();
                if(current == NULL){
                    cout<<"\nThis Item doesnt exsist!";
                    return;
                }
			}
			
			cout<<"Enter New Price : ";
			cin>>price;
			current->setDishPrice(price);
		}
        
        void DeleteMenuItem(){
        	Menu* current = head;
            Menu* temp ;
            
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
                    if(current == NULL){
                        cout<<"\nThis Item doesnt exsist!";
                        return;
                    }
	            }	
	            
	            temp = current->getMenuNext();
	            current->setMenuNext(temp->getMenuNext());
	            delete temp;
			}
        }
        
        void DisplayOrder(){
            Menu* current = head;
        	int count = 0 , total = 0;
			cout<<"\n\n\t\t====Order====";
        	while(current){
        		count++;
				cout<<"\n "<<count<<"-\t"<<current->getDishName()<<" ------- "<<setw(4)<<"Rs "<<current->getDishPrice();
				total = total + current->getDishPrice();
				current = current->getMenuNext();
			}
			
			cout<<"\n\tTotal amount = "<<total;
        }

        void DisplayCart(){
        	Menu* current = head;
        	int count = 0 , total = 0;
			cout<<"\n\n\t\t====Cart====";
        	while(current){
        		count++;
				cout<<"\n "<<count<<"-\t"<<current->getDishName()<<" ------- "<<setw(4)<<"Rs "<<current->getDishPrice();
				total = total + current->getDishPrice();
				current = current->getMenuNext();
			}
			
			cout<<"\n\tTotal amount = "<<total;
		}
        
        void DisplayMenu(){
        	Menu* current = head;
        	int count = 0;
        	
			cout<<"\n\n\t\t====Menu====";
        	while(current){
        		count++;
				cout<<"\n "<<count<<"-\t"<<current->getDishName()<<" ------- "<<setw(4)<<"Rs "<<current->getDishPrice();
				current = current->getMenuNext();
			}
		}
		
		Menu* selectMenuItem_Menu(int index){
			
            if(head == NULL){
                cout<<"\n This Item doesnt exsist";
                return NULL;
            }
            
            else{
                Menu* current = head;
                for(int i=0 ; i<index-1 ; i++){
                    current = current->getMenuNext();
                    if(current == NULL){
                        cout<<"\n This Item doesnt exsist";
                        return NULL;
                    } 
                }
                
                return current;
            }
			
		}
		
		void DeleteMenu(){
			Menu* current = head;
			
			while(current){
				Menu* temp = current;
				current = current->getMenuNext();
				delete temp;
			}
			head = NULL;
			tail = NULL;
		}
};
