/***
************************************************************************************
*                                   WARNING!                                       *
* Unauthorized reproduction of any part of this source code of any means without   *
* the official consent of the auther will be subjected to the Republic Act 8293 or *
* the Intellectual Property Act of the Philippines.                                *
*                                                                                  *
*                     Author: Luie John Malimit                                    *
*               Program Name: Student Information System                           *
*         Date of Completion: October 27, 2019                                     *
* Author Contact Information: luiejohnmalimit@gmail.com                            *
************************************************************************************
***/

#include <iostream>
#include <fstream>
#include <windows.h>
#include <dirent.h>

using namespace std;
void mainMenu();
void addStudent();
void deleteStudent();
void displayStudent(int status);
void searchStudent();
void editStudent();
void clearData();
void exportCSV();
int check_dir(const char *path, string csvFilename);

int sCounter = 0;

string student[100][8];
string infoCol[8] = {"Last Name", "First Name", "Middle Name", "Birthdate", "Sex", "Religion", "Course", "Section"};

int main(int argc, char** argv) {


    cout<<"  Welcome to Student Information System"<<endl<<endl;
    mainMenu();

    cout<<"An error occured!"<<endl
		<<"Press any key to continue...";
    cin.ignore();
	cin.get();

    return 0;
}

void mainMenu() {

    int input;

    while (1) {
    	cout<<endl;
        cout<<"****************************************"<<endl
            <<"* 1) Add Student                       *"<<endl
            <<"* 2) Delete Student                    *"<<endl
            <<"* 3) Display All Students              *"<<endl
            <<"* 4) Search Student                    *"<<endl
            <<"* 5) Edit Student Data                 *"<<endl
            <<"* 6) Clear Records                     *"<<endl
            <<"* 7) Export data to csv                *"<<endl
            <<"* 8) Exit program                      *"<<endl
            <<"****************************************"<<endl
            <<"Input: ";
        cin>>input;

        if (input == 1) {
            addStudent();
            break;
        } else if (input == 2) {
            deleteStudent();
            break;
        } else if (input == 3) {
            displayStudent(0);
            break;
        } else if (input == 4) {
            searchStudent();
            break;
        } else if (input == 5) {
            editStudent();
            break;
        } else if (input == 6) {
            clearData();
            break;
        } else if (input == 7) {
            exportCSV();
            break;
        } else if (input == 8) {
            exit(0);
        }  else {
            cout<<"Invalid input! Please follow the instructions."<<endl;
        }
    }
}
void addStudent() {

    cin.ignore();
    cout<<endl
        <<"              STUDENT ENTRY"<<endl
        <<"****************************************"<<endl;
    for (int i = 0; i < 8; i++) {
        cout<<"Enter "<<infoCol[i]<<": ";
        getline(cin, student[studentCounter][i]);
    }
    cout<<"****************************************"<<endl
        <<"ADDED 1 STUDENT!"<<endl<<endl;
    studentCounter++;

    mainMenu();
}
void deleteStudent() {
	int input;
	char confirmDelete = 'y';
	
	cin.ignore();
	while (1) {
		cout<<endl;
		displayStudent(1);
		cout<<"Enter student number: ";
		cin>>input;
		cout<<endl
			<<"Do you want to delete student "<<input<<" information? Y | N"<<endl;
		cin>>confirmDelete;
		if (confirmDelete == 'y'|| confirmDelete == 'Y') {
			break;
		}
	}
	
	for (int i = 0; i < 8; i++) {
		student[input-1][i] = "";
	}
	
	if (input < studentCounter) {
		for (int i = input-1; i < studentCounter; i++) {
			for (int j = 0; j < 8; j++) {
				student[i][j] = student[i+1][j];
			}
		}
		
		for (int i = 0; i < 8; i++) {
			student[studentCounter-1][i] = "";
		}
	}
	
	studentCounter--;
	
	cout<<"Student "<<input<<" info is deleted."<<endl;

	cout<<"Delete student"<<endl;
	mainMenu();
}
void displayStudent(int status) {
    cout<<"+----------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl
        <<"|                                                                      STUDENT LIST                                                                              |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl
        <<"| No. |        Last Name         |        First Name        |        Middle Name       |  Birthdate  | Sex |     Religion    |        Course        |  Section   |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;

    for (int i = 0; i < studentCounter; i++) {
            int j = 0;
            printf("| %3d | %-24s | %-24s | %-24s | %-11s | %-3s | %-15s | %-20s | %-10s |\n",
                    i+1, student[i][j].c_str(), student[i][j+1].c_str(), student[i][j+2].c_str(), student[i][j+3].c_str(), student[i][j+4].c_str(), student[i][j+5].c_str(), student[i][j+6].c_str(), student[i][j+7].c_str());
            cout<<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;
    }
    
    if (status == 0) {
    	mainMenu();
	}
}
void searchStudent() {
	string searchMatches[100][8];
	string searchQuery;
	int numberOfMatches = 0;
	
	cout<<endl
        <<"             STUDENT SEARCH"<<endl
        <<"****************************************"<<endl;
	cout<<"Search for: ";
	cin.ignore();
	getline(cin, searchQuery);
	
	for (int i = 0; i < studentCounter; i++) {
		for (int j = 0; j < 8; j++) {
			if (searchQuery == student[i][j]) {
				for (int k = 0; k < 8; k++) {
					searchMatches[numberOfMatches][k] = student[i][k];
				}
				numberOfMatches++;
			}
		}
	}
	
	cout<<"+----------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl
        <<"|                                                                      STUDENT LIST                                                                              |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl
        <<"| No. |        Last Name         |        First Name        |        Middle Name       |  Birthdate  | Sex |     Religion    |        Course        |  Section   |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;

    for (int i = 0; i < numberOfMatches; i++) {
            printf("| %3d | %-24s | %-24s | %-24s | %-11s | %-3s | %-15s | %-20s | %-10s |\n",
                    i+1, searchMatches[i][0].c_str(), searchMatches[i][1].c_str(), searchMatches[i][2].c_str(), searchMatches[i][3].c_str(), searchMatches[i][4].c_str(), searchMatches[i][5].c_str(), searchMatches[i][6].c_str(), searchMatches[i][7].c_str());
            cout<<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;
    }
    
    if (numberOfMatches == 0) {
    	cout<<"Your query \""<<searchQuery<<"\" doesn't match anything."<<endl;
	}
    
    cout<<"Query \""<<searchQuery<<"\" has "<<numberOfMatches<<" match/es."<<endl;
    
    mainMenu();
}
void editStudent() { 	
	int studentNumber;
	
	displayStudent(1);
	
	cout<<endl
        <<"              STUDENT EDIT"<<endl
        <<"****************************************"<<endl;
	cout<<"Enter student number: ";
	cin>>studentNumber;
	
	cout<<"+----------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl
        <<"|                                                                      STUDENT LIST                                                                              |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl
        <<"| No. |        Last Name         |        First Name        |        Middle Name       |  Birthdate  | Sex |     Religion    |        Course        |  Section   |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;

		int i = studentNumber-1;

        printf("| %3d | %-24s | %-24s | %-24s | %-11s | %-3s | %-15s | %-20s | %-10s |\n",
                1, student[i][0].c_str(), student[i][1].c_str(), student[i][2].c_str(), student[i][3].c_str(), student[i][4].c_str(), student[i][5].c_str(), student[i][6].c_str(), student[i][7].c_str());
        cout<<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;
    
    cin.ignore();
    for (i = 0; i < 8; i++) {
    	string editInput = "";
        cout<<"Enter "<<infoCol[i]<<" (Type \'/s\' to unchange): ";
        getline(cin, editInput);
        
        if (editInput == "/s") {
        	continue;
		} else {
			student[studentNumber-1][i] = editInput;
		}
    }
    
    cout<<"+----------------------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl
        <<"|                                                                      STUDENT LIST                                                                              |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl
        <<"| No. |        Last Name         |        First Name        |        Middle Name       |  Birthdate  | Sex |     Religion    |        Course        |  Section   |"<<endl
        <<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;

		i = studentNumber-1	;

        printf("| %3d | %-24s | %-24s | %-24s | %-11s | %-3s | %-15s | %-20s | %-10s |\n",
                 1, student[i][0].c_str(), student[i][1].c_str(), student[i][2].c_str(), student[i][3].c_str(), student[i][4].c_str(), student[i][5].c_str(), student[i][6].c_str(), student[i][7].c_str());
        cout<<"+-----+--------------------------+--------------------------+--------------------------+-------------+-----+-----------------+----------------------+------------+"<<endl;
    
    cout<<"Student info updated!"<<endl;
    
    mainMenu();
}
void clearData() {
	char confirmDelete;
		
	if (studentCounter != 0) {
		while (1) {
			cout<<"Are you sure you want to delete all data? Y | N"<<endl;
			cin>>confirmDelete;
			if (confirmDelete == 'y' | confirmDelete == 'Y') {
				for (int i = 0; i < studentCounter; i++) {
					for (int j = 0; j < 8; j++) {
						student[i][j] = "";
					}
				}
				studentCounter = 0;
			} else {
				cout<<"Action aborted. You are being directed to the main menu."<<endl;
				mainMenu();
			}
		}
	}
	
	cout<<"All data has been cleared."<<endl;
	mainMenu();
}
void exportCSV() {
	string filename;
	string fullPath;
	
	fstream OpenFile;
	
	cout<<endl
		<<"Checking directory..."<<endl;
	if (CreateDirectory("C:/CSV File Save", NULL)) {
		cout<<"Directory doesn't exist."<<endl
			<<"Creating directory...100%"<<endl
			<<"Directory created."<<endl<<endl;
	} else if (ERROR_ALREADY_EXISTS == GetLastError()) {
		cout<<"Directory Exists."<<endl<<endl;
	} else {
		cout<<endl
			<<"Something went wrong. =("<<endl;
	}
	
	while (1) {
		cout<<"Input csv filename: ";
		cin>>filename;
		if (check_dir("C:/CSV File Save", filename) == 0) {
			break;
		}
		cout<<endl
			<<"File already exists. Delete the existing file or think of a new filename."<<endl<<endl;
	}
	
	fullPath = "C:/CSV File Save/"+filename+".csv";
	cout<<"Exporting data to CSV file."<<endl;
	
	OpenFile.open(fullPath.c_str(), ios::out | ios::app);
	
	OpenFile<<"Student No., ";
	for (int i = 0; i < 8; i++) {
		if (i < 7) {
			OpenFile<<infoCol[i]<<", ";
		} else if (i == 7) {
			OpenFile<<infoCol[i]<<endl;
		}
	}
	
	for (int i = 0; i < studentCounter; i++) {
		cout<<"Exporting student "<<i+1<<"..."<<endl;
		OpenFile<<i+1<<", ";
		for (int j = 0; j < 8; j++) {
			if (j < 7) {
				OpenFile<<student[i][j].c_str()<<", ";
			} else if (j == 7) {
				OpenFile<<student[i][j].c_str()<<endl;
			}
		}
		cout<<"Exported student "<<i+1<<endl<<endl;
	}
	
	cout<<"Exported file to "<<fullPath<<endl
		<<"Export finished."<<endl<<endl;
	OpenFile.close();
	mainMenu();
}

int check_dir(const char *path, string csvFilename) {
    struct dirent *entry;
    csvFilename += ".csv";

    DIR *dir = opendir(path);

    if (dir == NULL) {
        return 0;
    }

    while ((entry = readdir(dir)) != NULL) {
		
        if(entry->d_name == csvFilename) {
        	return 1;
        	break;
		}
	}
    closedir(dir);

    return 0;
}
