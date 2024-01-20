#include "Menu.cpp"
//#include "Resturant.cpp"
 
class AssignOrders{
	public:

		string custName;
		string custAddress;
		string custNumber;
		AssignOrders* next;
		MenuList cartListOrderAssign;
		
		AssignOrders(string name="abc" , string address="zer" , string num="ewq"){
			custAddress=address;
			custName=name;
			custNumber=num;
			next = NULL;
		}
		
		void setAssignOrderNext(AssignOrders * next){
			this->next = next;
		}
		
		AssignOrders* getAssignOrderNext(){
			return next;
		}
};

class AssignOrder_List{
	public:
		AssignOrders* head;
		AssignOrders* tail;
	
		AssignOrder_List(){
			head = NULL;
			tail = NULL;
		}
		
		void insertOrder(string name, string address, string num , MenuList* cartL){
			AssignOrders* newOrder = new AssignOrders;
			newOrder->custName=name;
			newOrder->custAddress=address;
			newOrder->custNumber=num;
			
			Menu* temp = cartL->head;
			while(temp){
				newOrder->cartListOrderAssign.InsertInCart(temp->getDishName() , temp->getDishPrice());
				temp = temp->getMenuNext();
			}

			if(head == NULL){
				head = newOrder;
				tail = newOrder;
			}
			
			else{
				tail->setAssignOrderNext(newOrder);
				tail = newOrder;
			}
		}
		
		void insertHistory(string name, string address, string num , MenuList* cartL){
			
			AssignOrders* newOrder = new AssignOrders; 
			newOrder->custName=name;
			newOrder->custAddress=address;
			newOrder->custNumber=num;
			
			Menu* temp = cartL->head;
			while(temp){
				newOrder->cartListOrderAssign.InsertInCart(temp->getDishName() , temp->getDishPrice());
				temp = temp->getMenuNext();
			}

			if(head==NULL){
				head=newOrder;
				tail=newOrder;
			}
			else{
				newOrder->setAssignOrderNext(head);
				head=newOrder;
			}
		}

		void ViewAllOrders(){

			if(head == NULL){
				cout<<"\nThere is no orders yet!";
				return;
			}
			else{
				int count = 1;
				AssignOrders* current = head;
				while(current){
					cout<<"\n\t\tCustomer "<<count;
					cout<<"\nCustomer Name : "<<current->custName;
					cout<<"\nAddress : "<<current->custAddress;
					cout<<"\nContact Number : "<<current->custNumber;
					current->cartListOrderAssign.DisplayOrder();

					current = current->getAssignOrderNext();
				}
			}
		}

		void ServeOrder_clearHistory(){ 
			if(head == NULL){ 
				cout<<"\nThere is no order yet!";
				return;
			}

			else{
				cout<<"\n\t\tCustomer Information";
				cout<<"\nCustomer Name : "<<head->custName;
				cout<<"\nAddress : "<<head->custAddress;
				cout<<"\nContact Number : "<<head->custNumber;
				cout<<"\n\t\tOrder";
				head->cartListOrderAssign.DisplayCart();
				
				head = head->getAssignOrderNext();
				// delete temp;	
			}
		}
};
