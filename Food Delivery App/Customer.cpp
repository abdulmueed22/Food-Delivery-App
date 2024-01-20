//#include "cart.cpp"
//#include "Menu.cpp"
#include "Resturant.cpp"
using namespace std;
 
class Customer{
	string name;
	string contactNumber;
	string address;
	string password;
	MenuList cartList;
	Customer* next;
	
	public:
		Customer(string name = "abc" , string contactNumber = "000" , string address = "xyz" , string password = "abc123" , Resturant* next = NULL ){
			this->name = name;
			this->contactNumber = contactNumber;
			this->address = address;
			this->password = password;
		}
		
		void setCustName(string name){
			this->name = name;
		}
		
		void setCustNumber(string contactNumber){
			this->contactNumber = contactNumber;
		}
		
		void setCustAddress(string address){
			this->address = address;
		}
		
		void setCustPassword(string password){
			this->password = password;
		}
		
//		void setCustMenu(){
//			cartList.InsertMenuItem();
//		}
		
		void setCustNext(Customer* next){
			this->next = next;	
		}
		
		string getCustName(){
			return name;
		}
		
		string getCustNumber(){
			return contactNumber;
		}
		
		string getCustAddress(){
			return address;
		}
		
		string getCustPassword(){
			return password;
		}
		
		Customer* getCustNext(){
			return next;
		}
		
		void EditCustInformation(){
			char choice;
			string newInfo;
			cout<<"\n\n Press\t(1) To Change Customer Name\n \t(2) To Change Address\n \t(3) To Change Contact Number\n \t(4) To Change Password\n\tEnter your choice : ";
			cin>>choice;
			
			if(choice == '1'){
				cout<<" Enter New Name : ";
				cin.ignore();
				getline(cin , newInfo);
				setCustName(newInfo);
			}
			
			else if(choice == '2'){
				cout<<" Enter New Address : ";
				cin.ignore();
				getline(cin , newInfo);
				setCustAddress(newInfo);
			}
			
			else if(choice == '3'){
				cout<<" Enter New Contact Number : ";
				cin.ignore();
				getline(cin , newInfo);
				setCustNumber(newInfo);
			}
			
			else if(choice == '4'){
				cout<<" Enter New Password : ";
				cin.ignore();
				getline(cin , newInfo);
				setCustPassword(newInfo);
			}
			
			else{
				cout<<"\n\tInvalid Choice!";
			}
		}
		
		
		void DisplayCustInformation(){
			cout<<"\n\t====Customer Information====";
			cout<<"\n Name : "<<getCustName();
			cout<<"\n Address : "<<getCustAddress();
			cout<<"\n Contact Number : +92"<<getCustNumber();
			cout<<"\n Password : "<<getCustPassword();
		}
		
		void addToCart(Resturant* selectedRest){
			Menu* menuItem;
			int index;
			while(true){
				cout<<"\nSelect Item number to add in cart or Press 0 To Place Order : ";
				cin>>index;
				
				if(index == 0){
					break;
				}
				
				else{
					menuItem = selectedRest->selectMenuItem_rest(index);
					if(menuItem != NULL){
						cartList.InsertInCart(menuItem->getDishName() , menuItem->getDishPrice());	
					}
				}
				
			}
		}
		
		void ToPlaceOrder(ResturantList* restList , Customer* FoundCustomer){
			int index;
			char choice;
			Resturant* selectedRest;
			
			restList->ViewAllRestaurants();
			cout<<"\n Select Restaurant number : ";
			cin>>index;
			
			selectedRest = restList->SelectRestaurant(index);
			if(selectedRest == NULL){
				return;
			}
			
			selectedRest->DisplayRestMenu();
			
			addToCart(selectedRest);
			
			cartList.DisplayCart();
			
			cout<<"\n\n Press\t(1) To Confirm Order\n \t(2) Remove Items From Cart\n \t(3) Cancel Order\n\tEnter your choice : ";
			cin>>choice;
			if(choice == '1'){
				if(cartList.head == NULL){
					cout<<"\nNo order placed yet";
				}
				else{
					selectedRest->AddAssignOrder_rest(FoundCustomer->getCustName(), FoundCustomer->getCustAddress(), FoundCustomer->getCustNumber() , &cartList);
					cartList.DeleteMenu();	
				}
			}
			
			else if(choice == '2'){
				cartList.DeleteMenuItem();
				cartList.DisplayCart();
			}
			
			else if(choice == '3'){
				cartList.DeleteMenu();
				return;
			}
			
			else{
				cout<<"Invalid Choice!";
			}
			
		}
};

class CustomerList{
	Customer* head;
	Customer* tail;
	public:
		CustomerList(){
			head = NULL;
			tail = NULL;
		}
		
		Customer* insertCustomer(){
			Customer* newCust = new Customer;
			string name , password , number , address;
			char choice;
			
			cout<<"\n Enter Customer Name : ";
			cin.ignore();
			getline(cin , name);
			cout<<" Enter Address of Customer : ";
			getline(cin , address);
			cout<<" Enter Contact Number : +92";
			getline(cin , number);
			cout<<" Enter Password : ";
			getline(cin , password);
			
			newCust->setCustName(name);
			newCust->setCustAddress(address);
			newCust->setCustNumber(number);
			newCust->setCustPassword(password);
			
			if(head == NULL){
				head = newCust;
				tail = newCust;
			}
			
			else{
				tail->setCustNext(newCust);
				tail = newCust;
			}
			
			return newCust;
		}
		
		Customer* SearchCustomer(){
			string name, password;
			bool found = false;
			Customer* current = head;
		
			cout<<" Enter Your Customer name : ";
			cin.ignore();
			getline(cin , name);
			while(current){
				
				if(current->getCustName() == name){
					found = true;
					cout<<" Enter Password : ";
					cin>>password;
					
					for(int i=1 ; i<3 ; i++){
						if(current->getCustPassword() == password){
							return current;
						}
						
						cout<<"\n You have Enter Incorrect Password!";
						cout<<"\n Enter password again : ";
						cin>>password;
					}
					return NULL;
				}
				
				current = current->getCustNext();
			}
			
			if(!found){
				cout<<"\n There is no Cutomer with this name!";
				return NULL;
			}
		}
		
		void DeleteCustAccount(Customer* FoundCustomer){
			
			if(head == tail && FoundCustomer == head){
				// delete FoundCustomer;
				head == NULL;
				tail == NULL;
			}
			
			else if(FoundCustomer == head){
				head = head->getCustNext();
				// delete FoundCustomer;
			}
			
			else{
				Customer* temp = head;
				while(FoundCustomer != temp->getCustNext()){
					temp = temp->getCustNext();
				}
				
				temp->setCustNext(FoundCustomer->getCustNext());
				// delete FoundCustomer;
			}
		}

		void ViewAllCustomers(){
			Customer* current = head;
			int count = 0;
			
			cout<<"\n\t\t====Registered Customers====";
			while(current){
				count++;
				cout<<"\n "<<count<<"-\t"<<current->getCustName();
				current = current->getCustNext();
			}
		}
};


