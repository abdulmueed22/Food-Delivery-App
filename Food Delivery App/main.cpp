#include "Customer.cpp"
//#include "asignOrder.cpp"
//#include "Resturant.cpp"
#include<iostream>
#include<string>
 #include<windows.h>
using namespace std;

//void Loading(){
//	for(int i=0 ; i<10 ; i++){
//		cout<<"****";
//		Sleep("70");
//	}
//}

int main() {
	system("Color f0");
	cout<<"                                                                                                            "<<endl;
	cout<<"     =============================================================================================== "<<endl;
	cout<<"     |                                                                                             | "<<endl;
	cout<<"     |                                                                                             | "<<endl;
	cout<<"     |*******    * ** *        * ** *     * * * *.           **      **   **        **  ********.  | "<<endl;
	cout<<"     |**       *        *    *        *   **      *          **      **   **        **  **      *  | "<<endl;
	cout<<"     |**      **        **  **        **  **       *         **      **   **        **  **     .*  | "<<endl;
    cout<<"     |******* **        **  **        **  **        *        **********   **        **  *******.   | "<<endl;
    cout<<"     |**      **        **  **        **  **        *        **      **   **        **  **      *  | "<<endl;
    cout<<"     |**       *        *    *        *   **      .*         **      **    *.       .*  **     .*  | "<<endl;
    cout<<"     |**        *  **  *      *  **  *    * * * *            **      **      * * * *    ********   | "<<endl;          
	cout<<"     =============================================================================================== "<<endl;

	char choice1 , choice2;
	ResturantList restList;
	CustomerList custList;
	
	while(true){
		cout<<"\n\t\t=======MAIN MENU=======";
		cout<<"\n Press\t(1) For Resturant\n \t(2) For Customer\n \t(3) For Admin\n \t(4) To Exit Program\n\tEnter your choice : ";
		cin>>choice1;
		
		if(choice1 == '1'){
			cout<<"\n Press\t(1) Sign Up\n \t(2) Sign In\n\tEnter your choice : ";
			cin>>choice2;
		
			if(choice2 == '1'){
				Resturant* FoundResturant;
				FoundResturant = restList.insertResturant();
				if(FoundResturant){
					while(true){
						FoundResturant->DisplayRestInformation();
						char choice;
						
						cout<<"\n\n Press\t(1) To Edit Restaurant Information\n \t(2) To Edit Menu\n \t(3) To See Placed orders\n \t(4) To See Sales History\n \t(5) To Delete Acoount\n \t(6) To Sgn Out\n\tEnter your choice : ";
						cin>>choice;
						
						if(choice == '1'){
							FoundResturant->EditRestInformation();
						}
						
						else if(choice == '2'){
							FoundResturant->EditRestMenu();
						}
						
						else if(choice == '3'){
							cout<<"\n\n Press\t(2) View All Orders\n \t(2) Server Order\n\tEnter your choice : ";
							cin>>choice;
							if(choice == '1'){
								FoundResturant->ViewAllOrders_rest();
							}

							else if(choice == '2'){
								FoundResturant->serveOrder_rest();
							}

							else{
								cout<<"\nInvalid choice!";
							}
						}
						
						else if(choice == '4'){
							FoundResturant->ViewSalesHistory_rest();
						}
						
						else if(choice == '5'){
							restList.DeleteRestAccount(FoundResturant);
							break;
						}
						
						else if(choice == '6'){
							break;
						}
						
						else{
							cout<<"\n\tInvalid Choice!";
						}
					}
				}
			}
		
			else if(choice2 == '2'){
				Resturant* FoundResturant;
				FoundResturant = restList.SearchResturant();
				if(FoundResturant){
					while(true){
						FoundResturant->DisplayRestInformation();
						char choice;
						
						cout<<"\n\n Press\t(1) To Edit Restaurant Information\n \t(2) To Edit Menu\n \t(3) To See Placed orders\n \t(4) To See Sales History\n \t(5) To Delete Acoount\n \t(6) To Sgn Out\n\tEnter your choice : ";
						cin>>choice;
						
						if(choice == '1'){
							FoundResturant->EditRestInformation();
						}
						
						else if(choice == '2'){
							FoundResturant->DisplayRestMenu();
							FoundResturant->EditRestMenu();
						}

						
						else if(choice == '3'){
							cout<<"\n\n Press\t(1) View All Orders\n \t(2) Server Order\n\tEnter your choice : ";
							cin>>choice;
							if(choice == '1'){
								FoundResturant->ViewAllOrders_rest();
							}

							else if(choice == '2'){
								FoundResturant->serveOrder_rest();
							}

							else{
								cout<<"\nInvalid choice!";
							}
						}
						
						else if(choice == '4'){
							FoundResturant->ViewSalesHistory_rest();
						}
						
						else if(choice == '5'){
							restList.DeleteRestAccount(FoundResturant);
							break;
						}
						
						else if(choice == '6'){
							break;
						}
						
						else{
							cout<<"\n\tInvalid Choice!";
						}
					}
				}
			}
		
			else{
				cout<<"\n\tInvalid Choice!";
			}
		}
	
		else if(choice1 == '2'){
			cout<<"\n Press\t(1) Sign Up\n \t(2) Sign In\n\tEnter your choice : ";
			cin>>choice2;
		
			if(choice2 == '1'){
				Customer* FoundCustomer;
				FoundCustomer = custList.insertCustomer();if(FoundCustomer){
					while(true){
						FoundCustomer->DisplayCustInformation();
						char choice;
						
						cout<<"\n\n Press\t(1) To Edit Customer Information\n \t(2) To Place Order\n \t(3) To Delete Account\n \t(4) To Sgn Out\n\tEnter your choice : ";
						cin>>choice;
						
						if(choice == '1'){
							FoundCustomer->EditCustInformation();
						}
						
						else if(choice == '2'){
							FoundCustomer->ToPlaceOrder(&restList , FoundCustomer);
						}
						
						else if(choice == '3'){
							custList.DeleteCustAccount(FoundCustomer);
							break;	
						}
						
						else if(choice == '4'){
							break;
						}
						else{
							cout<<"\n\tInvalid Choice!";
						}
					}
				}
			}
		
			else if(choice2 == '2'){
				Customer* FoundCustomer;
				FoundCustomer = custList.SearchCustomer();
				if(FoundCustomer){
					while(true){
						FoundCustomer->DisplayCustInformation();
						char choice;
						
						cout<<"\n\n Press\t(1) To Edit Customer Information\n \t(2) To Place Order\n \t(3) To Delete Account\n \t(4) 2To Sgn Out\n\tEnter your choice : ";
						cin>>choice;
						
						if(choice == '1'){
							FoundCustomer->EditCustInformation();
						}
						
						else if(choice == '2'){
							FoundCustomer->ToPlaceOrder(&restList , FoundCustomer);
						}
						
						else if(choice == '3'){
							custList.DeleteCustAccount(FoundCustomer);
							break;	
						}
						
						else if(choice == '4'){
							break;
						}
						else{
							cout<<"\n\tInvalid Choice!";
						}
					}
				}
			}
		
			else{
				cout<<"\n\tInvalid Choice!";
			}
		}
	
		else if(choice1 == '3'){
			cout<<"\n Press\t(1) To View All Restaurants\n \t(2) To View All Customers\n\tEnter your choice : ";
			cin>>choice2;

			if(choice2 == '1'){
				restList.ViewAllRestaurants();
			}

			else if(choice2 == '2'){
				custList.ViewAllCustomers();	
			}
		}
		
		else if(choice1 == '4'){
			break;
		}
		
		else{
			cout<<"\n\tInvalid Choice!";
		}
	}
	
	return 0;
}
