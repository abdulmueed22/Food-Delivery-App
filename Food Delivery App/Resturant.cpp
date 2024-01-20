#include "asignOrder.cpp"
using namespace std;

class Resturant{
	string name; 
	string contactNumber;
	string location;
	string password;
	MenuList menuList;
	AssignOrder_List OrderList;
	AssignOrder_List HistoryList;
	Resturant* next;
	
	public:
		Resturant(string name = "abc" , string contactNumber = "000" , string location = "xyz" , string password = "abc123" , Resturant* next = NULL ){
			this->name = name;
			this->contactNumber = contactNumber;
			this->location = location;
			this->password = password;
		}
		
		void setRestName(string name){
			this->name = name;
		}
		
		void setRestNumber(string contactNumber){
			this->contactNumber = contactNumber;
		}
		
		void setRestLocation(string location){
			this->location = location;
		}
		
		void setRestPassword(string password){
			this->password = password;
		}
		
		void setRestMenu(){
			menuList.InsertMenuItem();
		}
		
		void setRestNext(Resturant* next){
			this->next = next;	
		}
		
		string getRestName(){
			return name;
		}
		
		string getRestNumber(){
			return contactNumber;
		}
		
		string getRestLocation(){
			return location;
		}
		
		string getRestPassword(){
			return password;
		}
		
		Resturant* getRestNext(){
			return next;
		}
		
		void DisplayRestMenu(){
			menuList.DisplayMenu();
		}
		
		void EditRestInformation(){
			char choice;
			string newInfo;
			cout<<"\n\n Press\t(1) To Change Restaurant Name\n \t(2) To Change Location\n \t(3) To Change Contact Number\n \t(4) To Change Password\n\tEnter your choice : ";
			cin>>choice;
			
			if(choice == '1'){
				cout<<" Enter New Name : ";
				cin.ignore();
				getline(cin , newInfo);
				setRestName(newInfo);
			}
			
			else if(choice == '2'){
				cout<<" Enter New Location : ";
				cin.ignore();
				getline(cin , newInfo);
				setRestLocation(newInfo);
			}
			
			else if(choice == '3'){
				cout<<" Enter New Contact Number : ";
				cin.ignore();
				getline(cin , newInfo);
				setRestNumber(newInfo);
			}
			
			else if(choice == '4'){
				cout<<" Enter New Password : ";
				cin.ignore();
				getline(cin , newInfo);
				setRestPassword(newInfo);
			}
			
			else{
				cout<<"\n\tInvalid Choice!";
			}
		}
		
		void EditRestMenu(){
//			DisplayRestMenu();
			char choice;
			cout<<"\n\n Press\t(1) To Add Items in Menu\n \t(2) To Edit Menu Items Price \n \t(3) To Delete Menu Item \n \t(4) To Delete Complete Menu\n\tEnter your choice : ";
			cin>>choice;
			
			if(choice == '1'){
				this->setRestMenu();
			}
			
			else if(choice == '2'){
				menuList.EditMenuItemsPrice();
			}
			
			else if(choice == '3'){
				menuList.DeleteMenuItem();
			}
			
			else if(choice == '4'){
				menuList.DeleteMenu();
			}
			
			else{
				cout<<"\n\tInvalid Choice!";
			}
		}
		
		void DisplayRestInformation(){
			cout<<"\n\n\t====Restaurant Information====";
			cout<<"\n Name : "<<getRestName();
			cout<<"\n Location : "<<getRestLocation();
			cout<<"\n Contact Number : +92"<<getRestNumber();
			cout<<"\n Password : "<<getRestPassword();
			// DisplayRestMenu();
		}
		
		Menu* selectMenuItem_rest(int index){
			return menuList.selectMenuItem_Menu(index);
		}
		
		void AddAssignOrder_rest(string name, string address, string num , MenuList* cartList){
			OrderList.insertOrder(name, address, num , cartList);
		}
		
		void serveOrder_rest(){
			insertHistory_rest();
			OrderList.ServeOrder_clearHistory();
		}

		void ViewAllOrders_rest(){
			OrderList.ViewAllOrders();
		}
		
		void ViewSalesHistory_rest(){
			HistoryList.ViewAllOrders();
		}

		void insertHistory_rest(){
			AssignOrders* temp = OrderList.head;
			HistoryList.insertHistory(temp->custName , temp->custAddress , temp->custNumber ,  &temp->cartListOrderAssign);
		}
};

class ResturantList{
	Resturant* head;
	Resturant* tail; 
	
	public:
		ResturantList(){
			head = NULL;
			tail = NULL;
		}
		
		Resturant* insertResturant(){
			Resturant* newRest = new Resturant;
			string name , password , number , location;
			char choice;
			
			cout<<"\n Enter Name of Resturant : ";
			cin.ignore();
			getline(cin , name);
			cout<<" Enter location of Resturant : ";
			getline(cin , location);
			cout<<" Enter Contact Number : +92";
			getline(cin , number);
			cout<<" Enter Password : ";
			getline(cin , password);
			
			newRest->setRestName(name);
			newRest->setRestLocation(location);
			newRest->setRestNumber(number);
			newRest->setRestPassword(password);
			
			cout<<"  Press Y/y to insert Items in Menu : ";
			cin>>choice;
			while(choice == 'y' || choice == 'Y'){
				newRest->setRestMenu();
				cout<<" \n Press Y/y to insert another Item to Menu : ";
				cin>>choice;
			}
			
			if(head == NULL){
				head = newRest;
				tail = newRest;
			}
			
			else{
				tail->setRestNext(newRest);
				tail = newRest;
			}
			
			return newRest;
		}
		
		Resturant* SearchResturant(){
			string name, password;
			bool found = false;
			Resturant* current = head;
		
			cout<<" Enter Your Resturant name : ";
			cin.ignore();
			getline(cin , name);
			while(current){
				
				if(current->getRestName() == name){
					found = true;
					cout<<" Enter Password : ";
					cin>>password;
					
					for(int i=1 ; i<3 ; i++){
						if(current->getRestPassword() == password){
							cout<<"\n\tSign In Successfully";
							return current;
						}
						
						cout<<"\n You have Enter Incorrect Password!";
						cout<<"\n Enter password again : ";
						cin>>password;
					}
					return NULL;
					
				}
				
				current = current->getRestNext();
			}
			
			if(!found){
				cout<<"\n There is no Resturant with this name!";
				return NULL;
			}
		}
		
		void ViewAllRestaurants(){
			Resturant* current = head;
			int count = 0;
			
			cout<<"\n\t\t====Available Restaurants====";
			while(current){
				count++;
				cout<<"\n "<<count<<"-\t"<<current->getRestName();
				current = current->getRestNext();
			}
		}
		
		Resturant* SelectRestaurant(int index){
			Resturant* current;
			// cout<<"\n\n\t\tcurrent : "<<current<<"\thead : "<<head;
			if(head == NULL){
				cout<<"\nThis Restaurant doesnt exsist!";
				return NULL;
			}
			else{
				current = head;
				for(int i=1 ; i<index ; i++){
					current = current->getRestNext();
					if(current == NULL){
						cout<<"\nThis Restaurant doesnt exsist!";
						return NULL;
					}
				}
				
				return current;
			}
			
		}
		
		void DeleteRestAccount(Resturant* FoundResturant){
			
			if(head == tail && FoundResturant == head){
				head == NULL;
				tail == NULL;
				// delete FoundResturant;
			}
			
			else if(FoundResturant == head){
				head = head->getRestNext();
				// delete FoundResturant;
			}
			
			else {
			
				Resturant* temp = head;
				while(FoundResturant != temp->getRestNext()){
					temp = temp->getRestNext();
				}
				
				temp->setRestNext(FoundResturant->getRestNext());
				// delete FoundResturant;
			}
		}	
};


