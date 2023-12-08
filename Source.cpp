#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int countOfArray = 100;
struct Order {
	int orderNumber;
	int dayOfMounth;
	string clientName;
	string device_Type;
	string serialNumberOfDevice;
	string possibleProblem;
	string service_Technician_Name;
	char repair[50];
	float price;
	int stay_Time;
	string status_Order;
	string type_Order[3] = { "express","fast", "normal" };
};
bool isFill(int& countOfArray, int& n, int& sum) {
	if (sum > countOfArray)
	{
		return false;
	}
	return true;
}
void orderInput(Order order[], int& n, int& sum) {
	cout << "Enter order count: ";
	cin >> n;
	sum += n;
	if (isFill)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << "Order " << i + 1 << endl;
			cout << "Order number: ";
			cin >> order[i].orderNumber;
			cout << "Enter day of mounth: ";
			cin >> order[i].dayOfMounth;
			cin.ignore();
			cout << "Enter client name: ";
			getline(cin, order[i].clientName);
			cout << "Enter type of device: ";
			getline(cin, order[i].device_Type);
			cout << "Enter a serial number of device: ";
			getline(cin, order[i].serialNumberOfDevice);
			cout << "Enter a problem that you have with a device: ";
			getline(cin, order[i].possibleProblem);
			order[i].possibleProblem.substr(0, 50);
			order[i].service_Technician_Name = " ";
			order[i].repair[50] = ' ';
			order[i].price = 0.0;
			order[i].stay_Time = 0;
			order[i].status_Order = " ";
			order[i].type_Order[3] = " ";
		}
	}
	else cout << "Enter valid count of orders!\n";
}
void printAllOrders(Order order[]) {
	system("cls");
	cout << "Orders" << endl;
	for (int i = 0; i < sizeof(order); i++) {
		cout << '-' << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
		cout << left << setw(45) << "Order number" << setw(70) << order[i].orderNumber << endl;
		cout << setw(45) << "Day of mounth" << setw(70) << order[i].dayOfMounth << endl;
		cout << setw(45) << "Client name" << setw(70) << order[i].clientName << endl;
		cout << setw(45) << "Type of device" << setw(70) << order[i].device_Type << endl;
		cout << setw(45) << "Serial number of device" << setw(75) << order[i].serialNumberOfDevice << endl;
		cout << setw(45) << "Problem with a device" << setw(75) << order[i].possibleProblem << endl;
		cout << setw(45) << "Name of service technician" << setw(75) << order[i].service_Technician_Name << endl;
		cout << setw(45) << "Repair" << setw(75) << order[i].repair << endl;
		cout << setw(45) << "Price of repair" << setw(75) << order[i].price << endl;
		cout << setw(45) << "Days of servicer" << setw(75) << order[i].stay_Time << endl;
		cout << setw(45) << "Days of servicer" << setw(75) << order[i].stay_Time << endl;
		cout << setw(45) << "Order status" << setw(75) << order[i].status_Order << endl;
		cout << setw(45) << "Order type" << setw(75) << order[i].type_Order << endl;
	}
	cout << "\n";
}
int main()
{
	Order order[countOfArray];
	int choice = 0;
	do
	{	//menu
		cout << "1.Add a new service order" << endl
			<< "2.Display all devices on screen" << endl
			<< "3.Search and Display" << endl
			<< "4.Sort and display orders" << endl
			<< "5.Working with an external file" << endl
			<< "6.Entering/updating service order data" << endl
			<< "7.Exit" << endl;
		cout << '-' << setfill('-') << setw(38) << '-' << setfill(' ') << endl
			<< "Enter choice: ";
		cin >> choice;
		//validation
		if (choice >= 1 && choice <= 7) {
			switch (choice)
			{
			case 1: {
				int sum = 0;
				int n = 0;
				orderInput(order, n, sum);
			}
				  system("pause");
				  break;
			case 2: {
				printAllOrders(order);
			}
				  break;
			case 3: {

			}
				  break;
			default:
				cout << "Please enter valid numbers!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
	} while (choice <= 7 && choice >= 1);
}