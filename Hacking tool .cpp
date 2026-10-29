/*

copywrite Sniper 350


*/



#include <iostream>
#include "CliSecreens.h"
#include <cstdlib>
#include <ctime>
#include <string>
#include "Help.h"
#include <limits> 
#include "Logos.h"
#include "android.h"
#include "install.h"
using namespace BasicFn;
using namespace Logo;
using namespace android;
using namespace install;
using namespace std;
using namespace FullSecreens;
using namespace help;
using std::string;





void ChekSelectTool(string command);

//------------------HOME-----------------
void HomeDisplay(UserSystemData& UserData)
{

	string command = "";
	bool SniperMode = false;
#ifdef _WIN32
	cout << Blue;
	cout << "(*)" << "\033[43m" << " Some tools will not work well due to environmental incompatibility with them" << "\033[0m" << endl
		<< endl;
#endif
	while (true)
	{


		if (SniperMode == true) {
			cout << Green;
			cout << "-" << Reset;
			cout << Red;
			cout << " sniper/" << Reset;
			cout << Green;
			cout << UserData.UserName << "@";
			cout << Blue;
			cout << "command";
			cout << Green;
			cout << " $";
			cout << Reset;
		}
		else
		{
			cout << "\033[32m" << "-" << "\033[0m";
			cout << Green;
			cout << UserData.UserName << "@";
			cout << Reset;
			cout << Blue;
			cout << "command";
			cout << Green;
			cout << " $";
			cout << Reset;
		}

	
		getline(cin, command);


		string Pass = "";

		if (command == "sniper mode")
		{

			for (int i = 0; i <= 2; i++) {
				cout << "Enter password : ";
				cin >> Pass;
				cin.get();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				if (Pass == "sniper") {
					SniperMode = true;
					break;
				}
				else {
					if (i == 3)
						cout << "I have entered 3 times" << endl;
					cout << "Incorrect password" << endl;
					SniperMode = false;
				}
			}

		}
		else if (command == "exit sniper mode")
			SniperMode = false;

		cin.clear();



		ChekSelectTool(command);
	}

}


void ChekSelectTool(string command)
{
	if (command == "metasploit")     startMetasploat();

	else if (command == "wireshark")    system("sudo wireshark");

	else if (command == "android") AndroidUi();

	else if (command == "nmap")     startNmap();

	else if (command == "wifite")   startWifite();

	else if (command == "zphisher") startZphisher();

	else if (command == "myip")    system("ifconfig");

	else if (command == "clear")	ClearScreen();

	else if (command == "sniper mode")   command = " ";

	else if (command == "exit sniper mode")     command = " ";

	else if (command == "help")    HelpUI();

	else if (command == "ddos" || command == "DDoS") DDoSUI();

	else if (command == "hydra") start_hydra();

	else if (command == "-N" || command == "-n")  New_Command();

	else if (command == "sql") start_sql();

	else if (command == "nikto") start_nikto();

	else if (command == "PwGn" || command == "pwgn") Passwords_generate();

	else if (command == "dirb") start_dirb();
	
	else if (command == "reset frp" || command == "frp" || command == "bypass frp")   StartFrpTool();

	else if (command == "about" || command == "About") AboutUI();



	else
	{
		cout << endl << "help  == Help \t" << "about == About" << endl << endl;
	}
}

//--------------------------------------------------------------------------------------



void StartSystem(UserSystemData& UserData)
{
	
	start();

	PrintLogo_LoginUi(2);


	while (true) {
		HomeDisplay(UserData);
	}	//while loop
}

void LoginUi(UserSystemData& UserData)
{
	PrintLogo_LoginUi(1);
	cout << endl;
	TextColor("blue","ENTER USERNAME : ",0);
	getline(cin, UserData.UserName);

	cout << endl;
	TextColor("red", "Default Password (sniper) . ",1);
	cout << endl;


	Wait();

	StartSystem(UserData);

}

void Waring_UI()
{
        ClearScreen();
	cout << Green; 
	cout << "====================[";
	cout << Blue;
	cout << " WARNING ";
	cout << Green;
	cout << "]====================\n\n";
	cout << "This System is intended for educational and authorized testing purposes only.\n\n";
	cout << "Any misuse of this System for unauthorized access, attacks, or illegal activities\n";
	cout << "is strictly prohibited and may lead to legal consequences.\n\n";
	cout << "The developer is not responsible for any damage, misuse, or illegal actions\n";
	cout << "performed using this System.\n\n";
	cout << "By using this software, you agree to use it only on systems you own\n";
	cout << "or have explicit permission to test.\n\n";
	cout << "==================================================\n";
	cout << Reset; 
	cout << endl << endl; 
	Wait();
}

int main() {


	srand((unsigned)time(NULL));

     ClearScreen();

	Waring_UI();
	system("python3 -m venv venv");
	system("source venv/bin/activate");

#ifdef _WIN32
	system("wsl --install");
#endif

	ClearScreen();

	UserSystemData UserData;
	LoginUi(UserData);


	return 0;

}
