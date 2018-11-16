#include"List.h"

int main()
{
	List a;
	int choice = 0;
	cout << "============================ STUDENT MANAGER ============================\n";
	while (1)
	{
		cout << "\n******************** MENU **********************";
		cout << "\n0.Exit" << endl;
		cout << "1.Display list student." << endl;
		cout << "2.Search information a student." << endl;
		cout << "3.Sort list student." << endl;
		cout << "4.Add a student." << endl;
		cout << "5.Insert covering list sort." << endl;
		cout << "6.Delete information a student." << endl;
		cout << "7.Delete information a student female grade 08." << endl;
		cout << "8.Display list scholarship of all class." << endl;

		cout << "\nEnter your choice : ";
		choice = a.getIntRange(0,8);

		switch (choice)
		{
		case 0: return 0;
		case 1:
		{
			a.Display();
			break;
		}
		case 2:
		{
			a.Search();
			cout << "\n\tSearch successfully! ";
			break;
		}
		case 3:
		{
			a.Sort();
			cout << "\n\tSort successfully! ";
			break;
		}
		case 4:
		{
			Student *pAdd = new Student();
			cout << "Enter student want to add " << endl;
			cin >> (*pAdd);
			a.AddTheFirst(pAdd);
			break;
		}
		case 5:
		{
			Student *pInsert = new Student();
			cout << "Enter student want to insert " << endl;
			cin >> (*pInsert);
			a.AddTheFirst(pInsert);
			break;
		}
		case 6:
		{
			int i;
			string is_ID;
			cin.ignore(1);
			do
			{
				cout << "Enter ID of student want to delete: ";
				getline(cin, is_ID);
				if (is_ID.length() == 9)
				{
					for (i = 0; i < 9; i++)
					{
						if (is_ID[i] < '0' || is_ID[i] > '9') break;
					}
					if (i == 9) break;
				}

			} while (is_ID.length() != 9 || i != 9);
			a.DeleteByID(is_ID);
			cout << "\n\tDelete student successfully!";
		break;
		}
		case 7:
		{
			a.DeleteByFemale08();
			cout << "\n\tDelete student female grade 08 successfully!";
			break;
		}
		case 8:
		{
			a.DisplayScholaship();
			break;
		}
		}
	}
	return 0;
}
