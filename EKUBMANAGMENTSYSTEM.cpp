#include<iostream> //input/output stream library for reading from and writing to the console.
#include<string>   //library for using strings in C++
#include<fstream>  // File stream library for reading from and writing to files
#include<cstdlib> // Standard library for random number generation.
#include<iomanip> // Input/output manipulator library for formatting output.
#include<sstream> //String stream library for converting between strings and other data types.
#include<ctime>  //Time library for handling time-related functions like getting the current time.
using namespace std;
// use structer to store information about the ekub member
struct EKUB_INFORMAION{
      string NAME;
      double CONTRIBUTION;
      bool RECIVED;// check weather the participant won or not
};
const int totalparticipant=10000;// maximum amount of member eligable for the system in general
EKUB_INFORMAION weekly_participant[totalparticipant];  //ekub information structure array for all weekly participants
EKUB_INFORMAION monthly_participant[totalparticipant]; //ekub information structure array for all monthly participants
int numberofparticipant_M=0; //globa declaration of counting member for weekly
int numberofparticipant_W=0; //globa declaration of counting memebrs for monthly
//prototyping all the functions
void REGISTER_EKUB_MEMBER();
void WEEKLY_FILE();
void MONTHLY_FILE();
void VIEW_EKUB_INFOMATION();
void VIEW_WEEKLY_PARTICIPANTS();
void VIEW_MONTHLY_PARTICIPANTS();
void SELECT_WINNER();
void DETERMINE_THE_WINNER_WEEKLY();
void DETERMINE_THE_WINNER_MONTHLY();
void DELETE_EKUB_ACCOUNT();
void DELETE_WEEKLY_FROM_FILE();
void DELETE_MONTHLY_FROM_FILE();
void ABOUT_EKUB_SYSTEM();
//dispaly menu function
void MENU(){
	system("cls"); // clear screen in windows and resetting the position
      cout<<"\n*********************************MENU***************************************\n";
      cout<<"******************************************************************************\n";
      cout<<"***********************WELCOME TO GROUP 5 EKUB SYSTEM*************************\n";
      cout<<"******************************************************************************\n";
      cout<<"******************************************************************************\n";
      cout<<"1. REGISTER NEW EKUB MEMBER\n";
      cout<<"2. EKUB MEMBER INFORMATION\n";
      cout<<"3. DELTE EKUB MEMBER\n";
      cout<<"4. ABOUT EKUB SYSTEM\n";
      cout<<"5. EXIT\n";
      cout<<"ENTER YOUR CHOICE : ";
      int choice;
      cin>>choice;
      switch(choice){
            case 1: REGISTER_EKUB_MEMBER();break;
            case 2: VIEW_EKUB_INFOMATION(); break;
            case 3: DELETE_EKUB_ACCOUNT();break;
            case 4: ABOUT_EKUB_SYSTEM();break;
            case 5: exit(0);break;
            default:cout<<"\nWRONG CHOICE!!!\nTRY AGAIN\n";MENU();break;
      }
}
// registration of new memebr function
void REGISTER_EKUB_MEMBER(){
	system("cls");
      cout<<"\n********************WELCOME TO REGISTRARION PAGE********************\n";

      cout<<"WHICH TYPRE OF EKUB YOU WANT TO PARTICIPATE IN";
      cout<<"\n1. WEEKLY\n2. MONTHLY\n3. GO TO MENU\n4. EXIT\n";
      int type,go;
      cin>>type;
      switch(type) {
        case 1:
      if(numberofparticipant_W<=totalparticipant){
      cout<<"\nENTER YOUR NAME : ";
      cin>>weekly_participant[numberofparticipant_W].NAME;
      cout<<"\nENTER YOUR CONTRIBUTION : ";
      cin>>weekly_participant[numberofparticipant_W].CONTRIBUTION;
      weekly_participant[numberofparticipant_W].RECIVED=false;//initialization of the new member to false b/c stil had not won yet
            cout<<"CONGRATULATION YOU HAVE PARTICIPATED IN WEEKLY EKUB\n";
           WEEKLY_FILE();
            numberofparticipant_W++;// increase the count memeber every time new member regidter
            cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
            cin>>go;
            switch(go){
            	case 1: MENU();break;
            	case 2: exit(0);break;
			}
		   break;
      case 2:
      if(numberofparticipant_M<=totalparticipant){
      cout<<"\nENTER YOUR NAME : ";
      cin>>monthly_participant[numberofparticipant_M].NAME;
      cout<<"\nENTER YOUR CONTRIBUTION : ";
      cin>>monthly_participant[numberofparticipant_M].CONTRIBUTION;
      monthly_participant[numberofparticipant_W].RECIVED=false;//initialization of the new member to false b/c stil had not won yet
            cout<<"CONGRATULATION YOU HAVE PARTICIPATED IN MONTHLY EKUB\n";
            MONTHLY_FILE();
            numberofparticipant_M++;// increase the count memeber every time new member register
            cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
            cin>>go;
            switch(go){
            	case 1: MENU();break;
            	case 2: exit(0);break;
			}
            break;
            case 3:
			system("cls");
			MENU();break;
            case 4: exit(0);break;
			}
}
            }
}
// saving the members after registeration is copmletet
void WEEKLY_FILE(){
    ofstream weekly_file("weekly file.txt",ios::app);
    weekly_file<<left<<setw(20)<<weekly_participant[numberofparticipant_W].NAME<<setw(20)<<weekly_participant[numberofparticipant_W].CONTRIBUTION<<setw(20)<<weekly_participant[numberofparticipant_W].RECIVED<<endl;
}
// saving the members after registeration is copmletet
void MONTHLY_FILE(){
                ofstream monthly_file("monthly file.txt",ios::app);
    monthly_file<<left<<setw(20)<<monthly_participant[numberofparticipant_M].NAME<<setw(20)<<monthly_participant[numberofparticipant_M].CONTRIBUTION<<setw(20)<<monthly_participant[numberofparticipant_M].RECIVED<<endl;
}
//to see the ekub member information and select winner
void VIEW_EKUB_INFOMATION(){
	system("cls");
      cout<<"\n********************WELCOME TO EKUB MEMBER INFORMATION PAGE********************\n";
      cout<<"1. VIEW WEEKLY EKUB MEMBERS\n2. VIEW MONTHLY EKUB MEMBERS\n3. DETREMINE WINNER\n4. GO TO MENU\n5. EXIT\n";
      int choice;
      cin>>choice;
      switch(choice){
        case 1:
        	system("cls");
            cout<<"\n**********WEEKLY EKUB MEMBERS**********\n";
           VIEW_WEEKLY_PARTICIPANTS();
          cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
           cin>>choice;
           if(choice==1)
           MENU();
           else exit(0);
           break;
        case 2:
            system("cls");
            cout<<"\n**********MONTHLY EKUB MEMBERS**********\n";
            VIEW_MONTHLY_PARTICIPANTS();
            cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
            cin>>choice;
            if(choice==1)
            MENU();
            else exit(0);
		    break;
        case 3:
            SELECT_WINNER();break;
		    system("cls");
            cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
            cin>>choice;
             if(choice==1)
            MENU();
            else exit(0);break;
        case 4: exit(0);break;
      }
      cout<<"\nDO YO WNAT TO GO TO MENU.....\n1. YES\n2. NO(EXIT)\n";
      cin>>choice;
      if(choice==1)
        MENU();
        else exit(0);
      }
      // sepicifically to see the weekly members
void VIEW_WEEKLY_PARTICIPANTS(){
	cout<<left<<setw(20)<<"NAME"<<setw(20)<<"CONTRIBUTION"<<setw(20)<<"HAS RECIVED THE SUM"<<endl;
            for(int i=0;i<numberofparticipant_W;i++){
                cout<<left<<setw(20)<<weekly_participant[i].NAME<<setw(20)<<weekly_participant[i].CONTRIBUTION<<setw(20)<<weekly_participant[i].RECIVED<<endl;
            }
}
      // sepicifically to see the monthly members
void VIEW_MONTHLY_PARTICIPANTS(){
   	cout<<left<<setw(20)<<"NAME"<<setw(20)<<"CONTRIBUTION"<<setw(20)<<"HAS RECIVED THE SUM"<<endl;
            for(int i=0;i<numberofparticipant_M;i++){
                cout<<left<<setw(20)<<monthly_participant[i].NAME<<setw(20)<<monthly_participant[i].CONTRIBUTION<<setw(20)<<monthly_participant[i].RECIVED<<endl;
            }
}
//for deleting participant function
void DELETE_EKUB_ACCOUNT(){
    cout<<"\nWHICH TYPES OF EKUB YOU WANT TO DELETE FROM\n1. WEEKLY EKUB\n2. MONTHLY EKUB\n3. GO TO MENU\n4. EXIT\n";
    int delete_user;
    int check_w=0;//check for the member to delete (for weekly)
    int check_m=0;//check for the member to delete (for monthly)
    string DELETED_NAME;
    cin>>delete_user;
    bool member_found=false;//intialization to false to check if the participant is present(if found )
    system("cls");
    switch(delete_user){
        case 1:
cout<<"ENTER THE NAME YOU WNAT TO DELETE : ";
cin.ignore();
getline(cin,DELETED_NAME);
while(check_w<numberofparticipant_W){
	if(weekly_participant[check_w].NAME==DELETED_NAME){
		member_found=true; //change to true b/c the participant hadbeen found
		break;
	}
		check_w++;
}
   if(member_found){
    // replacing the delete member line space by moving the from the bottom member to the delted member space
    for(;check_w<numberofparticipant_W;check_w++){
        weekly_participant[check_w].NAME=weekly_participant[check_w+1].NAME;
        weekly_participant[check_w].CONTRIBUTION=weekly_participant[check_w+1].CONTRIBUTION;
        weekly_participant[check_w].RECIVED=weekly_participant[check_w+1].RECIVED;
    }
    numberofparticipant_W--;// decrese the count b/c the member is decresing
     DELETE_WEEKLY_FROM_FILE();//delteing the member from file function and overwrite the file
    cout<<"\nMEMBER IS DELETED SUCCESSFULL!!!\n";
   }
   break;
        case 2:
cout<<"ENTER THE NAME YOU WNAT TO DELETE : ";
cin.ignore();
getline(cin,DELETED_NAME);
while(check_m<numberofparticipant_M){
	if(monthly_participant[check_m].NAME==DELETED_NAME){
		member_found=true;
		break;
	}
		check_m++;
}
   if(member_found){
    // replacing the delete member line space by moving the above member to the delted member space
    for(;check_m<numberofparticipant_M;check_m++){
        monthly_participant[check_m].NAME=monthly_participant[check_m+1].NAME;
        monthly_participant[check_m].CONTRIBUTION=monthly_participant[check_m+1].CONTRIBUTION;
        monthly_participant[check_m].RECIVED=monthly_participant[check_m+1].RECIVED;
		}

    numberofparticipant_M--;//decrese the count b/c the member is decresing
   DELETE_MONTHLY_FROM_FILE();//delteing the member from file function and overwrite the file
    cout<<"\nMEMBER IS DELETED SUCCESSFULL!!!\n";break;
}
}
cout<<"\nDO YOU WANT TO GO TO MENU......\n1. YES\n2. NO(EXIT)";
int no;
cin>>no;
if(no==1)
MENU();
else exit(0);
}
//delteing the member from file function and overwrite the file
void DELETE_WEEKLY_FROM_FILE(){
    ofstream file_delete("weekly file.txt");
    if (file_delete.is_open()){
        for (int i=0;i<numberofparticipant_W;i++){
        file_delete<<left<<setw(20)<<weekly_participant[i].NAME<<setw(20)<<weekly_participant[i].CONTRIBUTION<<weekly_participant[i].RECIVED<<endl;
        }
        file_delete.close();
    } else {
        cout << "\nUNABLE TO OPEN FILE!\n";
    }
        file_delete.close();
	}
    //delteing the member from file function and overwrite the file
void DELETE_MONTHLY_FROM_FILE(){
        ofstream file_delete("monthly file.txt");
    if (file_delete.is_open()){
        for (int i=0;i<numberofparticipant_M;i++){
        file_delete<<left<<setw(20)<<monthly_participant[i].NAME<<setw(20)<<monthly_participant[i].CONTRIBUTION<<monthly_participant[i].RECIVED<<endl;
        }
        file_delete.close();
    } else {
        cout << "\nUNABLE TO OPEN FILE!\n";
    }
        file_delete.close();
	}
    //selecting a winner function
void SELECT_WINNER(){
     cout<<"\n**********WELCOME TO SELECT A WINNER PAGE **********\n";
     cout<<"PLEASE SELECT THE EKUB TYPE TO SELECT A WINNER FROM\n";
     cout<<"1. WEEKLY WINNER\n2. MONTHLY WINNER\n3. GO TO MENU\4. EXIT\n";
     int win;
     cin>>win;
     switch(win){
        case 1:DETERMINE_THE_WINNER_WEEKLY();break;
        case 2:DETERMINE_THE_WINNER_MONTHLY();break;
        case 3:MENU();break;
        case 4:exit(0);break;
     }
}
//selecting a winner from weekly participants or members
void DETERMINE_THE_WINNER_WEEKLY(){
	srand(time(0));
	int is_there_is_winner=0;
	for(int i=0;i<numberofparticipant_W;i++){
		if(!weekly_participant[i].RECIVED){
			is_there_is_winner++;
		}
	}
	if(is_there_is_winner==0)
	cout<<"\nALL MEMBER RECIVED THE SUM\n";
	int winner;
	do{
		 winner=rand()%numberofparticipant_W;
	}while(weekly_participant[winner].RECIVED);
	cout<<"THE WINNER FOR THE WEEKLY EKUB IS\n";
    cout<<weekly_participant[winner].NAME<<" WITH TOTAL OF "<<weekly_participant[winner].CONTRIBUTION*numberofparticipant_W<<"\n";
	weekly_participant[winner].RECIVED=true;

    cout<<"\nDO YOU WANT TO SELECT WINNER AGAIN......(Y/N)..";
	char ok;
	cin>>ok;
	switch(ok){
		case 'Y' :  case 'y' :
		DETERMINE_THE_WINNER_WEEKLY();break;
		case 'n' :  case 'N' :
		MENU();break;

	}
    //saving every winner to separate file
    ofstream win("weekly winners.txt",ios::out|ios::app);
    win<<weekly_participant[winner].NAME<<endl;
}
//selecting a winner from monthly participants or members
void DETERMINE_THE_WINNER_MONTHLY(){
	srand(time(0));
	int is_there_is_winner=0;
	for(int i=0;i<numberofparticipant_M;i++){
		if(!monthly_participant[i].RECIVED){
			is_there_is_winner++;
		}
	}
	if(is_there_is_winner==0)
	cout<<"\nALL MEMBER RECIVED THE SUM\n";
	int winner;
	do{
		 winner=rand()%numberofparticipant_M;
	}while(monthly_participant[winner].RECIVED);
	cout<<"THE WINNER IS FOR THE MONTHLY EKUB IS\n";
    cout<<monthly_participant[winner].NAME<<" WITH TOTAL OF "<<monthly_participant[winner].CONTRIBUTION*numberofparticipant_M<<"\n";
	monthly_participant[winner].RECIVED=true;
		cout<<"\nDO YOU WANT TO SELECT WINNER AGAIN......(Y/N)..";
	char ok;
	cin>>ok;
	switch(ok){
		case 'Y' :  case 'y' :
		DETERMINE_THE_WINNER_MONTHLY();break;
		case 'n' :  case 'N' :
		MENU();break;
	}
    //saving every winner to separate file
    ofstream win("monthly winners.txt",ios::out|ios::app);
    win<<monthly_participant[winner].NAME<<endl;
}
//information about the ekub system function
void ABOUT_EKUB_SYSTEM(){
	cout<<"\nEKUB SAVING SYSTEM\nINTRODUCTION\nTHE EKUB SAVING SYSTEM ALLOWS INDIVIDUALS TO PARTICIPATE IN A TRADITIONAL SAVING SYSTEM\n";
	cout<<"BY CONTRIBUTING A CERTAIN AMOUNT OF MONEY ON A WEEKLY OR MONTHLY BASIS. THE SYSTEM KEEPS TRACK OF THE PARTICIPANTS,\n";
    cout<<"THEIR CONTRIBUTIONS, AND SELECTS A WINNER AT THE END OF EACH WEEK OR MONTH.\n";
    cout<<"THE WINNER RECEIVES A SUM OF MONEY THAT IS CONTRIBUTED BY ALL THE PARTICIPANTS.\n";
    cout<<"THIS EKUB SAVING SYSTEM WILL BE IMPLEMENTED USING C++ PROGRAMMING LANGUAGE.\n\n";
	cout<<" DO YOU WANT TO GO TO MENU......\n1. YES\n2. NO(EXIT)\n";
	int menu;
	cin>>menu;
	if(menu==1)
	MENU();
	else exit(0);
}
int main(){
    //reading diffrent data type as string
        ifstream read_weekly("weekly file.txt");
                if (read_weekly.is_open()) {
                string line1;

                while (getline(read_weekly, line1) && numberofparticipant_W < 10000) {
                    istringstream iss(line1);
                    iss >> weekly_participant[numberofparticipant_W].NAME>> weekly_participant[numberofparticipant_W].CONTRIBUTION>>weekly_participant[numberofparticipant_W].RECIVED;
                    numberofparticipant_W++;
                }
            read_weekly.close();
            }
                ifstream read_monthly("monthly file.txt");
                if (read_monthly.is_open()) {
                string line2;
                while (getline(read_monthly, line2) && numberofparticipant_M< 10000) {
                    istringstream iss1(line2);
                    iss1 >> monthly_participant[numberofparticipant_M].NAME>> monthly_participant[numberofparticipant_M].CONTRIBUTION>>monthly_participant[numberofparticipant_M].RECIVED;
                    numberofparticipant_M++;
                }
            read_monthly.close();
            }
    // admin information that add delete select a winner for the system
      string admin_username_input="admin";
      string admin_user_password="1234";
      string admin_password;
      string admin_name;
      cout<<"ENTER AFMIN USERNAME : ";
      cin>>admin_name;
      cout<<"ENTER ADMIN  PASSWORD : ";
      cin>>admin_password;
      if((admin_username_input==admin_name)&&(admin_user_password==admin_password)){

   	system("cls");
            cout<<"\nLOGIN SUCESSFUL...........................................\n";
     MENU();
      }
      else
    cout<<"INVALID USER NAME OR PASSWORD....\n";return 0;
       return 0;
}
