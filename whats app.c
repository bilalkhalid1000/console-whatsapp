#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void main_menu();
void sign_up();
void sign_in();
void help();
int int_input();
int int_check(int ,int );
void char_input(char* );
void input_password(char* );
void username_check(char* );
void sign_in_check(char* username,char* password);
void user_menu(char* username);
void password_length_check(char* ,int ,int );
int char_check(char );
void p_bar();
void Exit();
void user_folder(char* username);
void profile_menu(char* username);
void contacts_menu(char* username);
void notification_menu(char* username);
void view_profile(char* username);
void edit_profile(char* username);
void view_contacts(char* username);
void add_contacts(char* username);
void contacts_check(char* username, char* contact);

struct profile{
	char first_name[25],last_name[25],gender[10],dob[20];
}p;

char contact[100][50];

void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main()
{
	main_menu();
}

void main_menu()
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,191);
	Sleep(100);
	printf("\t\t\t\t\t\t      %c MAIN MENU %c\n",179,179);
	Sleep(100);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,217);
	Sleep(200);
	
	printf("\n\t\t\t\t\t\tWelcome To The Main Menu\n\n");
	Sleep(200);
	
	printf("\t\t\t\t\t\t\t1. Sign up\n");
	Sleep(100);
	printf("\t\t\t\t\t\t\t2. Sign in\n");
	Sleep(100);
	printf("\t\t\t\t\t\t\t3. Help\n");
	Sleep(100);
	printf("\t\t\t\t\t\t\t4. Exit\n");
	Sleep(100);
	printf("\t\t\t\t\t\t\t:> ");
	
	int input;
	input = int_input();
	input = int_check(input,4);
	
	if(input == 1)
	{
		system("cls");
		sign_up();
		fflush(stdin);
		printf("\nPress any key to go back to main menu . . .\t");
		fflush(stdin);
		getch();
		main_menu();
	}
	else if(input == 2)
	{
		system("cls");
		sign_in();
	}
	else if(input == 3)
	{
		help();
	}
	else if(input == 4)
	{
		system("cls");
		Exit();
	}
}

void sign_up()
{
	system("cls");
	char u_name[25],p_word[21],filename[30],folder[100];
	
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c SIGN UP MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n\t\t\t\t\t\t   ...Create an Account...");
	
	printf("\n\nEnter Your Username:\t");
	char_input(u_name);
	username_check(u_name);
	
	printf("\nYour username is:\t%s",u_name);
	
	printf("\nEnter Pasword(6 - 20):\t");
	gets(p_word);
	password_length_check(p_word,6,20);
	
	printf("\nYour password is:\t%s",p_word);
	
	printf("\n\nCongratulations account sucessfully created to user name:\t%s",u_name);
	printf("\n\nPress any key to continue entring profile data...");
	fflush(stdin);
	getch();
	
	system("cls");
	
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c SIGN UP MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n\t\t\t\t\t     ...Enter Your Profile...");
	
	printf("\n\nEnter First-Name:\t");
    gets(p.first_name);
	printf("\nEnter Last-Name:\t");
    gets(p.last_name);
    printf("\nEnter your gender(male/female):\t");
    scanf("%s",&p.gender);
	printf("\nEnter your date of birth(dd/mm/yy):\t");
	scanf("%s",&p.dob);
	
	system("cls");
	printf("Welcome to WHATSAPP %s %s",p.first_name,p.last_name);
	
	FILE* f=fopen("master file.txt","a");
	if(f == NULL)
	{
		printf("\nAn error occured in opening master file\nPress any key to go back to main menu");
		fflush(stdin);
		getch();
		main_menu();
	}
	fprintf(f,"%s\n%s\n",u_name,p_word);
	fclose(f);
	
	user_folder(u_name);  //creates a folder with the name of the user
	
	strcpy(folder,u_name);
	strcat(folder,"/");
	strcpy(filename,u_name);
	strcat(filename,".txt");
	strcat(folder,filename);
	
	FILE* uf=fopen(folder,"w");
	
	fprintf(uf,"%s %s",p.first_name ,p.last_name);
	fprintf(uf,"\n%s",p.gender);
	fprintf(uf,"\n%s",p.dob);
	
	fclose(uf);
	
	strcpy(folder,u_name);
	strcat(folder,"/");
	strcpy(filename,u_name);
	strcat(filename,"_notifications");
	strcat(filename,".txt");
	strcat(folder,filename);
	
	FILE* nf=fopen(folder,"w");
	fclose(nf);
	
	strcpy(folder,u_name);
	strcat(folder,"/");
	strcpy(filename,u_name);
	strcat(filename,"_contacts");
	strcat(filename,".txt");
	strcat(folder,filename);
	
	FILE* cf=fopen(folder,"w");
	fclose(cf);
	
}

void sign_in()
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c SIGN IN MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	
	char u_name[25],p_word[21];
	
	printf("\nEnter your username:\t");
	char_input(u_name);
	printf("\nYour user name is:\t%s",u_name);
	printf("\nEnter your password:\t");
	input_password(p_word);
	printf("\nYour password is:\t%s",p_word);
	
	sign_in_check(u_name,p_word);
	
	user_menu(u_name);
}

void help()
{
	system("cls");
	int input;
	
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c HELP MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n\t\t\t\t\t      ...Welcome to Help Center...\n\n");
	printf("\t\t\t\t\t\t\t1. FAQs\n");
	printf("\t\t\t\t\t\t\t2. Main Menu\n");
	printf("\t\t\t\t\t\t\t:> ");
	
	input = int_input();
	input = int_check(input,2);
	
	if(input == 1)
	{
		system("cls");
		
		printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,191);
		printf("\t\t\t\t\t\t      %c    FAQs    %c\n",179,179);
		printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,217);
		
		printf("\nQuestion.\tHow do I create a Whatsapp Account?");
		printf("\nAnswer:-\n\tWhen The Prompt Start Enter 1 to Sign-Up.\n\tFill The Form Acoording to requirments. Agree Terms and Conditions.\n\tYou Are Done..!!");	
		printf("\n\nQuestion.\tHow I Log Into my Account?");
		printf("\nAnswer:-\n\tWhen The Propmt Start Press 2 to Sign In.\n\tEnter Your Username And Pssword Acoording to your Acoount. Then Press Enter.\n\tYou Are Done..!!");
//		printf("\n\nQuestion.\tHow do I Change my Account Information?");
//		printf("\nAnswer:-\n\tThis Help will be provided In 3rd weak project..!");
		printf("\n\nPress any key to Main Menu.....");
		fflush(stdin);
		getch();
		main_menu();
	}
	else if(input == 2)
	{
		main_menu();
	}
}

int int_input()
{
	char a,b[20];
	int i,c,esc;
	esc=0;
	
	for(i=0;1;i++)
	{
		a = getch();
		if((a>=48 && a<=57) && i<10)
		{
			b[i]=a;
			printf("%c",b[i]);
		}
		else if(a == 8 && i != 0)//backspace
		{
			printf("\b \b");
			i -=2;
		}
		else if(a == 13)//enter
		{
			b[i]= '\0';
			break;
		}
		else if(a == 27)
		{
			printf("\a");
			main_menu();
		}
		else
		{
			printf("\a");
			i--;
		}
	}
	c=atoi(b);
	return c;
}

int int_check(int input,int limit)
{
	if(input < 1 || input > limit)
	{
		printf("\a\n\t\t\t\t\t\t\tInvalid input\n\t\t\t\t\t\tPlease re-enter your selection\n\t\t\t\t\t\t\t:> ");
		input = int_input();
		input = int_check(input,limit);
	}
	return input;
}

int char_check(char ch)
{
	if(ch == 'y' || ch == 'Y')
	{
		return 1;
	}
	else if(ch == 'n' || ch == 'N')
	{
		return 2;
	}
	else
	{
		printf("\a");
		return 3;
	}
}

void Exit()
{
	char check;
	int ck;
	
	printf("Do you realy want to exit(y/n)");
	fflush(stdin);
	scanf("%c",&check);
	
	ck = char_check(check);
	
	if(ck == 1)
	{
		exit(0);
	}
	else if(ck == 2)
	{
		main_menu();
	}
	else
	{
		printf("Wrong input\n");
		Exit();
	}
}

void password_length_check(char* password,int min,int max)
{
	if(strlen(password) < min)
	{
		printf("\a\nToo Short pasword.....");
		printf("\nRe-Enter Pasword(6 - 20):\t");
		gets(password);
		password_length_check(password,min,max);
	}
	else if(strlen(password) > max)
	{
		printf("\a\nToo Long pasword.....");
		printf("\nRe-Enter Pasword(6 - 20):\t");
		gets(password);
		password_length_check(password,min,max);
	}
}

void char_input(char* ch)
{
	char a;
	int i,c,esc;
	esc=0;
	
	for(i=0;1;i++)
	{
		BACK:
		if(esc==1)
		{
			system("cls");
			printf("%s",ch);
			esc=0;
		}
		
		a = getch();
		
		if((a>=65 && a<=90) || (a>=48 && a<=57) || (a>=97 && a<=122) || a == 46 && i<200 || a == 95)
		{
			ch[i]=a;
			printf("%c",ch[i]);
		}
		else if(a == 8 && i != 0)//backspace
		{
			printf("\b \b");
			i -= 2;
		}
		else if(a == 13)//enter
		{
			ch[i] = '\0';
			break;
		}
		else if(a == 27)//escape
		{
			printf("\a");
			main_menu();
		}
		else
		{
			printf("\a");
			i--;
		}
	}
}

void username_check(char* username)
{
	FILE* f = fopen("master file.txt","r");
	if(f == NULL)
	{
		printf("\nAn error occured in opening master file\nPress any key to go back to main menu");
		fflush(stdin);
		getch();
		main_menu();
	}
	
	char u_name[20];
	int test = 0;
	do
	{
		fscanf(f,"%s",u_name);
		
		if(strcmp(username,u_name) == 0)
		{
			test++;
		}
	}while(!feof(f));
	
	if(test > 0)
	{
		fclose(f);
		printf("\nThis username already exists....");
		printf("\nRe-enter username:\t");
		gets(username);
		username_check(username);
	}
}

void input_password(char* password)
{
	int i=0;
	char check;
	
	while(1)
	{
	    check = getch();
	    
		if(check == 8 && i != 0)//backspace
		{
			printf("\b \b");
			i -=2;
		}
		else if(check == 8 && i == 0)
		{
			printf("\a");
			i-=1;
		}
		else if(check == 13 && i != 0)//enter
		{
			password[i]= '\0';
			break;
		}
	    else
		{
			printf("*");
			password[i] = check;
		}
	    i++;
	}
}

void sign_in_check(char* username,char* password)
{
	int test;
	char name_comp[30],pass_comp[21],filename[40];
	
	FILE* fp = fopen("master file.txt","r");
	if(fp == NULL)
	{
		printf("An error occured in opening master file\nPress any key to go back to main menu\t");
		fflush(stdin);
		getch();
		main_menu();
	}
	
	do
	{
		fscanf(fp,"%s%s",name_comp,pass_comp);
		
		if((strcmp(username,name_comp) == 0) && (strcmp(password,pass_comp) == 0))
		{
			test = -1;
			break;
		}
	}while(!feof(fp));
	
	if(test == -1)
	{
		system("cls");
		printf("\n\t\t\t\t\t\t\tSigning in");
		p_bar();
	}
	else
	{
		printf("\nInvalid password\nPress any key to try again\t");
		fflush(stdin);
		getch();
		sign_in();
	}
}

void p_bar()
{
	int xs,xe,ys,ye,a;
	
	xs=1;
	xe=113;
	ys=2;
	
	ye=ys+2;
	gotoxy(xs,ys);
	printf("%c",218);
	
	for (a=1; a<xe; a++)
	{
		gotoxy(xs+a,ys);
		printf("%c",196);
	}
	
	gotoxy(xs+xe,ys);
	printf("%c",191);
	
	gotoxy(xs,ys+1);
	printf("%c",179);
	gotoxy(xs+xe,ys+1);
	printf("%c",179);
	
	gotoxy(xs,ye);
	printf("%c",192);
	
	for (a=1; a<xe; a++)
	{
		gotoxy(xs+a,ye);
		printf("%c",196);
	}
	
	gotoxy(xs+xe,ye);
	printf("%c",217);
	for (a=1; a<xe; a++)
	{
		system("ping 127.0.0.1 -n 1 > nul");
		gotoxy(xs+a,ys+1);
		printf("%c",177);
		gotoxy(xs+xe+1,ys+1);
		printf("%.0f%%",((a+1.0)/xe)*100.0);
	}
	printf("\n\n");
	system("ping 127.0.0.1 -n 2 > nul");
}

void user_menu(char* username)
{
	system("cls");
	
	char filename[30], folder[100];
	int input;
	
	strcpy(folder,username);
	strcat(folder,"/");
	strcpy(filename,username);
	strcat(filename,".txt");
	strcat(folder,filename);
	
	FILE* f = fopen(folder,"r");
	if(f == NULL)
	{
		printf("An error occured in opening user file\nPress any key to go back to main menu\t");
		fflush(stdin);
		getch();
		main_menu();
	}
	
	fscanf(f,"%s%s",p.first_name,p.last_name);
	fclose(f);
	
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c USER MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n\t\t\t\t\t\t...Welcome %s %s...\n\n",p.first_name,p.last_name);
	printf("\t\t\t\t\t\t       1. Notifications\n");
	printf("\t\t\t\t\t\t       2. Profile\n");
	printf("\t\t\t\t\t\t       3. Contacts\n");
	printf("\t\t\t\t\t\t       4. Log out\n");
	printf("\t\t\t\t\t\t       :> ");
	
	input = int_input();
	input = int_check(input,4);
	
	if(input == 1)
	{
		notification_menu(username);
	}
	else if(input == 2)
	{
		profile_menu(username);
	}
	else if(input == 3)
	{
		contacts_menu(username);
	}
	else if(input == 4)
	{
		main_menu();
	}
}

void user_folder(char* username)
{
	WCHAR address[1024];
	size_t size;
	int test =0,check;
	char folder[150], name[150], s[2] = "\\";
	char *token ,*token2;
	
	GetModuleFileNameW(NULL, address, 1024);  //gets exe file location
	size = wcstombs(folder, address, 1024);  //converts dirname from wchar to char*
	
	token=strtok(folder,s);  //replaces '\' with '/'
	while(token != NULL)
	{	
		if(test == 0)
			strcpy(name,token);
		else
			strcat(name,token);
		
		strcat(name,"/");
		token = strtok(NULL,s);
		test++;
	}
	
	int index, len, i = 0;
	len = strlen(name);
	
	for(; len >= 0; len--)
	{
		if(name[len] == '/')
		{
			i++;
			if(i == 2)
			{
				index = len;
				break;
			}
		}
	}
	
	name[++index] = '\0';
	
	strcat(name,username);  //adds name of folder with its address to be created
	
	check = mkdir(name);  //creates the folder at the required location
	
	if (!check)  //checks wheather the folder is created or not
		printf("\nDirectory created\n");
	else
	{
		printf("\nUnable to create directory\n");
		exit(1);
	}
	
}

void profile_menu(char* username)
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c PROFILE %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n");
	printf("\t\t\t\t\t\t    1. View Profile\n");
	printf("\t\t\t\t\t\t    2. Edit Profile\n");
	printf("\t\t\t\t\t\t    3. User Menu\n");
	printf("\t\t\t\t\t\t    :> ");
	
	int input;
	input = int_input();
	input = int_check(input,3);
	
	if(input ==1)
	{
		view_profile(username);
	}
	else if(input == 2)
	{
		edit_profile(username);
	}
	else if(input == 3)
	{
		user_menu(username);
	}
	else
	{
		printf("\n\t\t\t\t\tThis option is under devolepement...");
		getch();
		profile_menu(username);
	}
}

void contacts_menu(char* username)
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c CONTACTS MENU %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	
	printf("\n");
	printf("\t\t\t\t\t\t\t1. View Contacts\n");
	printf("\t\t\t\t\t\t\t2. Add Contacts\n");
	printf("\t\t\t\t\t\t\t3. User Menu\n");
	printf("\t\t\t\t\t\t\t:> ");
	
	int input;
	input = int_input();
	input = int_check(input,3);
	
	if(input == 1)
	{
		view_contacts(username);
	}
	else if(input == 2)
	{
		add_contacts(username);
	}
	else if(input == 3)
	{
		user_menu(username);
	}
	else
	{
		printf("\n\t\t\t\t\tThis option is under devolepement...");
		getch();
		contacts_menu(username);
	}
}

void notification_menu(char* username)
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c NOTIFICATION %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217);
	
	char file[50], folder[100], filename[150];
	
	strcpy(file,username);
	strcat(file,"_notifications.txt");
	strcpy(folder,username);
	strcpy(filename,folder);
	strcat(filename,"/");
	strcat(filename,file);
	
	FILE* f = fopen(filename,"r");
	if(f == NULL)
	{
		printf("\nAn error occured opening notifications file\nPress any key to go to user menu");
		getch();
		user_menu(username);
	}
	
	char notifications[500] = " ";
	int i=0;
	
	do
	{
		fgets(notifications,500,f);
		if(strlen(notifications) < 2)
		{
			printf("\nYou don\'t have any notifications...");
			break;
		}
		else
		{
			printf("\n\t\t\t%d. %s",i+1,notifications);
			i++;
		}
	}while(!feof(f));
	fclose(f);
	
	printf("\n\t\t\t\t\tPress any key to go back to user menu...");
	getch();
	user_menu(username);
}

void view_profile(char* username)
{
	char folder[150];
	
	strcpy(folder,username);
	strcat(folder,"/");
	strcat(folder,username);
	strcat(folder,".txt");
	
	FILE* f = fopen(folder,"r");
	fscanf(f,"%s%s%s%s",p.first_name ,p.last_name, p.gender,p.dob);
	fclose(f);
	
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c PROFILE %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,217);
	
	printf("\nUsername:\t%s",username);
	printf("\nFirst Name:\t%s",p.first_name);
	printf("\nLast Name:\t%s",p.last_name);
	printf("\nGender:\t\t%s",p.gender);
	printf("\nDate of Birth:\t%s",p.dob);
	
	printf("\n\nPress any key to back...");
	getch();
	profile_menu(username);
}

void edit_profile(char* username)
{
	char folder[150];
	
	strcpy(folder,username);
	strcat(folder,"/");
	strcat(folder,username);
	strcat(folder,".txt");
	
	FILE* f = fopen(folder,"r");
	if(f == NULL)
	{
		printf("\nAn occured opening user file\nPress any key to go back....");
		getch();
		profile_menu(username);
	}
	fscanf(f,"%s%s%s%s",p.first_name ,p.last_name, p.gender,p.dob);
	fclose(f);
	
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c PROFILE %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c\n",192,196,196,196,196,196,196,196,196,196,217);
	
	printf("\nUsername:\t%s\n",username);
	printf("\n1. First Name");
	printf("\n2. Last Name");
	printf("\n3. Gender");
	printf("\n4. Date of Birth");
	printf("\n5. Go Back");
	printf("\n\nWhat do you want to edit?");
	printf("\n:> ");
	
	int input;
	input = int_input();
	input = int_check(input, 5);
	
	if(input == 1)
	{
		system("cls");
		printf("Existing\t\tNew");
		printf("\n%s\t\t\t",p.first_name);
		scanf("%s",&p.first_name);
		
		strcpy(folder,username);
		strcat(folder,"/");
		strcat(folder,username);
		strcat(folder,".txt");
		
		FILE* f = fopen(folder,"w");
		if(f == NULL)
		{
			printf("\nAn occured opening user file\nPress any key to go back....");
			getch();
			profile_menu(username);
		}
		fprintf(f,"%s %s\n%s\n%s",p.first_name ,p.last_name, p.gender,p.dob);
		fclose(f);
		
		printf("First Name has been edited\nPress any key to continue....");
		getch();
		profile_menu(username);
	}
	else if(input == 2)
	{
		system("cls");
		printf("Existing\t\tNew");
		printf("\n%s\t\t\t",p.last_name);
		scanf("%s",&p.last_name);
		
		strcpy(folder,username);
		strcat(folder,"/");
		strcat(folder,username);
		strcat(folder,".txt");
		
		FILE* f = fopen(folder,"w");
		if(f == NULL)
		{
			printf("\nAn occured opening user file\nPress any key to go back....");
			getch();
			profile_menu(username);
		}
		fprintf(f,"%s %s\n%s\n%s",p.first_name ,p.last_name, p.gender,p.dob);
		fclose(f);
		
		printf("Last Name has been edited\nPress any key to continue....");
		getch();
		profile_menu(username);
	}
	else if(input == 3)
	{
		system("cls");
		printf("Existing\t\tNew");
		printf("\n%s\t\t\t",p.gender);
		scanf("%s",&p.gender);
		
		strcpy(folder,username);
		strcat(folder,"/");
		strcat(folder,username);
		strcat(folder,".txt");
		
		FILE* f = fopen(folder,"w");
		if(f == NULL)
		{
			printf("\nAn occured opening user file\nPress any key to go back....");
			getch();
			profile_menu(username);
		}
		fprintf(f,"%s %s\n%s\n%s",p.first_name ,p.last_name, p.gender,p.dob);
		fclose(f);
		
		printf("Gender has been edited\nPress any key to continue....");
		getch();
		profile_menu(username);
	}
	else if(input == 4)
	{
		system("cls");
		printf("Existing\t\tNew");
		printf("\n%s\t\t",p.dob);
		scanf("%s",&p.dob);
		
		strcpy(folder,username);
		strcat(folder,"/");
		strcat(folder,username);
		strcat(folder,".txt");
		
		FILE* f = fopen(folder,"w");
		if(f == NULL)
		{
			printf("\nAn occured opening user file\nPress any key to go back....");
			getch();
			profile_menu(username);
		}
		fprintf(f,"%s %s\n%s\n%s",p.first_name ,p.last_name, p.gender,p.dob);
		fclose(f);
		
		printf("Date of Birth has been edited\nPress any key to continue....");
		getch();
		profile_menu(username);
	}
	else if(input == 5)
	{
		profile_menu(username);
	}
}

void view_contacts(char* username)
{
	char folder[150];
	
	strcpy(folder,username);
	strcat(folder,"/");
	strcat(folder,username);
	strcat(folder,"_contacts.txt");
	
	FILE* f = fopen(folder,"r");
	if(f == NULL)
	{
		printf("\nAn occured opening contacts file\nPress any key to go back....");
		getch();
		contacts_menu(username);
	}
	
	int i;
	for(i = 0; !feof(f); i++)
	{
		fscanf(f, "%s", contact[i]);
	}
	fclose(f);
	
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c CONTACTS %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c\n\n",192,196,196,196,196,196,196,196,196,196,196,217);
	
	int j;
	for(j = 0; j <= i; j++)
	{
		if(strlen(contact[j]) > 1)
		{
			printf("\t\t\t\t\t\t      %d. %s\n",j+1 ,contact[j]);
		}
		else if(strlen(contact[0]) <1)
		{
			printf("\t\t\t\t\t       You don't have contact....");
			break;
		}
	}
	
	printf("\n\n\t\t\t\t\t\tPress any key to back...");
	getch();
	contacts_menu(username);
}

void add_contacts(char* username)
{
	system("cls");
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c\n",218,196,196,196,196,196,196,196,196,196,196,191);
	printf("\t\t\t\t\t\t      %c CONTACTS %c\n",179,179);
	printf("\t\t\t\t\t\t      %c%c%c%c%c%c%c%c%c%c%c%c\n\n",192,196,196,196,196,196,196,196,196,196,196,217);
	
	int test = 0;
	char u_name[50], name_comp[50], pass_comp[21], filename[40];
	
	printf("\n\t\t\t\t\t\tEnter username to search:\t");
	scanf("%s",&u_name);
	
	FILE* fp = fopen("master file.txt","r");
	if(fp == NULL)
	{
		printf("An error occured in opening master file\nPress any key to go back to main menu\t");
		fflush(stdin);
		getch();
		contacts_menu(username);
	}
	
	do
	{
		fscanf(fp,"%s%s",name_comp,pass_comp);
		
		if((strcmp(u_name,username) == 0))
		{
			test = -2;
			break;
		}
		
		if((strcmp(u_name,name_comp) == 0))
		{
			test = -1;
			break;
		}
	}while(!feof(fp));
	
	fclose(fp);
	int input = 0;
	if(test == -1)
	{
		printf("\n\t\t\t\t\t\t       User Found\n\t\t\t     Enter 1 to add user to contacts or press any key to continue.");
		fflush(stdin);
		input = getch();
		printf("\n\t\t\t\t\t%d",input);
		Sleep(1000);
		if(input == 49)
		{
			contacts_check(username,u_name);
		}
		else
		{
			contacts_menu(username);
		}
	}
	else if(test == -2)
	{
		printf("\n\t\t\t\t\t  Yes, you do exist in our database...");
		fflush(stdin);
		getch();
		add_contacts(username);
	}
	else
	{
		printf("\n\t\t\t\t\t      No user found with username:\t%s\n\t\t\t\t\t     Press any key to try again\t",u_name);
		fflush(stdin);
		getch();
		add_contacts(username);
	}
}

void contacts_check(char* username, char* contact1)
{
	char folder[150];
	
	strcpy(folder,username);
	strcat(folder,"/");
	strcat(folder,username);
	strcat(folder,"_contacts.txt");
	
	char c_check[50];
	int test = 0;
	
	FILE* f = fopen(folder,"r");
	if(f == NULL)
	{
		printf("\nAn occured opening contacts file\nPress any key to go back....");
		getch();
		contacts_menu(username);
	}
	
	do
	{
		fscanf(f,"%s",c_check);
		
		if((strcmp(contact1,c_check)) == 0)
		{
			test = -1;
			break;
		}
	}while(!feof(f));
	fclose(f);
	
	if(test == -1)
	{
		printf("\n\t\t\t\t     Contact already added in your contact list....");
		getch();
		add_contacts(username);
	}
	else if(test == 0)
	{
		FILE* fc = fopen(folder,"a");
		if(fc == NULL)
		{
			printf("\nAn occured opening contacts file\nPress any key to go back....");
			getch();
			contacts_menu(username);
		}
		
		fprintf(fc,"%s\n",contact1);
		fclose(fc);
		
		printf("\n\t\t\t\t\t\t   Contact added");
		getch();
		contacts_menu(username);
	}
	else
	{
		printf("\n\t\t\t\t\t\tAn error occured...");
		getch();
		contacts_menu(username);
	}
}
