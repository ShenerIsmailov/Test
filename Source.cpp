#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SizeOfArray_Struct = 100;
const string typeOrder[3] = { "express","fast","normal" };
struct Order {
	int orderNumber;
	int dayOfMounth;
	string clientName;
	string device_Type;
	string serialNumberOfDevice;
	string possibleProblem;
	string service_Technician_Name;
	string repair;
	float price;
	int stay_Time;
	string status_Order;
	string type_Order;
};
bool isFill(const int& SizeOfArray_Struct, int& n, int& sum) {
	if (sum > SizeOfArray_Struct)
	{
		return false;
	}
	return true;
}
void orderInput(Order order[], int& n, int& sum) {
	cout << "Enter order count: ";
	cin >> n;
	sum += n;
	if (isFill(SizeOfArray_Struct, n, sum))
	{
		for (int i = 0; i < n; i++)
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
			order[i].repair = " ";
			order[i].price = 0.0;
			order[i].stay_Time = 0;
			order[i].status_Order = " ";
			order[i].type_Order = " ";
		}
	}
	else {
		cout << "Enter valid count of orders!\n";
	}
}
void printAllOrders(Order* order, const int& sizeOfOrder) {
	system("cls");
	cout << "Orders" << endl;
	for (int i = 0; i < sizeOfOrder; i++) {
		cout << '-' << setfill('-') << setw(40) << '-' << setfill(' ') << endl;
		cout << left << setw(30) << "Order number" << setw(70) << order[i].orderNumber << endl;
		cout << setw(30) << "Day of mounth" << setw(70) << order[i].dayOfMounth << endl;
		cout << setw(30) << "Client name" << setw(70) << order[i].clientName << endl;
		cout << setw(30) << "Type of device" << setw(70) << order[i].device_Type << endl;
		cout << setw(30) << "Serial number of device" << setw(75) << order[i].serialNumberOfDevice << endl;
		cout << setw(30) << "Problem with a device" << setw(75) << order[i].possibleProblem << endl;
		cout << setw(30) << "Name of service technician" << setw(75) << order[i].service_Technician_Name << endl;
		cout << setw(30) << "Repair" << setw(75) << order[i].repair << endl;
		cout << setw(30) << "Price of repair" << setw(75) << order[i].price << endl;
		cout << setw(30) << "Days of servicer" << setw(75) << order[i].stay_Time << endl;
		cout << setw(30) << "Order status" << setw(75) << order[i].status_Order << endl;
		cout << setw(30) << "Order type" << setw(75) << order[i].type_Order << endl;
	}
	cout << "\n";
}
void sort_arrayByDay(Order order[], const int& sizeOfOrder) {
	//sorting by ascending order
	bool flag = true;
	for (int i = sizeOfOrder; i > 1; i--)
	{
		if (flag == false)break;else flag = false;
		for (int j = 0; j < i - 1; j++)
		{
			if (order[j].dayOfMounth > order[j + 1].dayOfMounth)
			{
				swap(order[j], order[j + 1]);
				flag = true;
			}
		}
	}
}
void swap(int& a, int& b) {
	int buff = 0;
	buff = a;
	a = b;
	b = buff;
}
int main()
{
	Order order[SizeOfArray_Struct];
	int choice = 0;
	int sum = 0;
	int n = 0;
	int sizeOfOrder = 0;
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
			char option = ' ';
			switch (choice)
			{
			case 1:
				orderInput(order, n, sum);
				break;
			case 2:
				sizeOfOrder += n;
				printAllOrders(order, sizeOfOrder);
				break;
			case 3:
				cout << "a.Search and display devices by type" << endl
				<< "b.Search and display devices by status" << endl
				<< "Enter option: ";
				cin >> option;
				break;
			case 4:
				cout << "a.Sort orders by date received" << endl
					<< "b.Separation of completed orders to a specific technician and sorted by day of receipt" << endl
					<< "c.Separate orders with a specific problem for a device and sort in descending order by device type." << endl
					<< "Enter option: ";
				cin >> option;
				switch (option)
				{
				case 'a':
					sort_arrayByDay(order, sizeOfOrder);
					break;
				case 'b':
					break;
				case 'c':
					break;
				}
				break;
			case 5:
				cout << "a. Output the order array to a file." << endl
					<< "b.Entering the order array from a file." << endl
					<< "Enter option: ";
				break;
			case 6:
				break;
			default:
				cout << "Please enter valid numbers!" << endl;
				system("pause");
				system("cls");
				break;
			case 7:
				exit(1);
			}
		}
	} while (choice >= 1 && choice <= 7);
}
