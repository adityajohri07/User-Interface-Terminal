#include <iostream>
#include <cstdlib>
#include <string>
#include<bits/stdc++.h>

int main() {
    std::system("tput setaf 1");
    std::cout << "\t\tHey Welcome ! to my TUI that makes life Simple" << std::endl;
    std::cout << "\t\t---------------------------------------------" << std::endl;
    std::cout << "Enter the password: " << std::endl;
    
    // Password handling in C++ is more complex and needs to be done securely.
    std::string password;
    int wrong_pass = 1;
    bool flag = true;
    while (password != "ved") {
        if (wrong_pass == 1) {
            std::cout << "You entered the wrong job- Now you have 2 chances to write it correctly" << std::endl;
        }
        std::cout << "You entered the wrong password!" << std::endl;
        std::cout << "Again, Enter your password: ";
        std::cin >> password;
        wrong_pass++;
        if (wrong_pass == 3) {
            if (password != "ved") {
                std::cout << "Sorry! You entered the wrong password 3 times!" << std::endl;
                exit(0);
            }
        }
    }
    std::cout << "Where would you like to perform your job (local/remote): ";
    std::string location;
    std::cin >> location;

    int wrongjob = 1;
    flag = true;
    while (wrongjob <= 3 && flag == true) {
        if (location != "local" && location != "remote") {
            if (wrongjob == 1) {
                std::cout << "You entered the wrong job - you have now only 2 times to write the correct Job!" << std::endl;
            }
            std::cout << "Please! Enter the valid job (local/remote): ";
            std::cin >> location;
            wrongjob++;
        } else {
            flag = false;
        }
    }
    if (wrongjob == 4) {
        std::cout << "You entered the wrong job 3 times! \n Please try again after some time" << std::endl;
        exit(0);
    }
    std::string remoteIp;
    if (location == "remote") {
        std::cout << "In which server do you want to run: " << std::endl;
        std::cout << "Enter remote Ip address: ";
        std::cin >> remoteIp;
    }

    while (true) {
        std::cout << "\t\t    Press 1 : For Printing the date" << std::endl;
        std::cout << "\t\t    Press 2 : For Checking the Calendar" << std::endl;
        std::cout << "\t\t    Press 3 : For Add New User" << std::endl;
        std::cout << "\t\t    Press 4 : For Creating the folder" << std::endl;
        std::cout << "\t\t    Press 5 : For Downloading any software" << std::endl;
        std::cout << "\t\t    Press 6 : For Uninstalling any software" << std::endl;
        std::cout << "\t\t    Press 7 : for exit from this software" << std::endl;
        std::cout << "\t\t    Press 8 : For checking the user" << std::endl;
        std::cout << "\t\t    Press 9 : For Configuring your Web Server" << std::endl;
        std::cout << "\t\t    Press 10: To check all Network card and IP address" << std::endl;
        std::cout << "\t\t    Press 11: For seeing the Port number related to many servers" << std::endl;
        
        std::cout << "*******************************************************************************" << std::endl;

        std::cout << "Enter your choice: ";
        int ch;
        std::cin >> ch;

        if (location == "local") {
            if (ch == 1) {
                std::system("date");
            } else if (ch == 2) {
                std::system("cal");
            } else if (ch == 3) {
                std::cout << "Can you please tell me the name of the user you want to add: ";
                std::string New_User;
                std::cin >> New_User;
                std::system(("useradd " + New_User).c_str());
                std::cout << "enter your password for New User" << std::endl;
                std::system(("passwd " + New_User).c_str());
            } else if (ch == 4) {
                std::cout << "Enter your New Folder Name: ";
                std::string Folder_name;
                std::cin >> Folder_name;
                std::system(("mkdir " + Folder_name).c_str());
            } else if (ch == 5) {
                std::cout << "Enter the software name: ";
                std::string Download_software;
                std::cin >> Download_software;
                std::system(("dnf install " + Download_software).c_str());
            } else if (ch == 6) {
                std::cout << "Enter the software name: ";
                std::string Uninstall_Software;
                std::cin >> Uninstall_Software;
                std::system(("dnf remove " + Uninstall_Software).c_str());
                std::system("tput setaf 2");
                std::cout << "Software is completely removed!" << std::endl;
            } else if (ch == 7) {
                std::cout << "Thank you! for using this Software." << std::endl;
                exit(0);
            } else if (ch == 8) {
                std::cout << "Enter User Name you want to check: ";
                std::string User_Name;
                std::cin >> User_Name;
                std::system(("id " + User_Name).c_str());
            } else if (ch == 9) {
                std::cout << "Initializing web server: HTTPD" << std::endl;
                std::system("dnf install httpd");
                std::cout << "Your web server is installed" << std::endl;
                std::system("systemctl start httpd");
                std::cout << "Your services HTTPD are started" << std::endl;
                std::system("systemctl stop firewalld");
            } else if (ch == 10) {
                std::cout << "Network cards are: " << std::endl;
                std::system("ifconfig");
            } else if (ch == 11) {
                std::cout << "Network cards are: " << std::endl;
                std::system("netstat -tnlp");
            } else {
                std::cout << "wrong input" << std::endl;
            }
            std::cout << "Enter to continue....";
            std::cin.ignore();
            std::cin.get();
            std::system("clear");
        } else {
            if (ch == 1) {
                std::system(("ssh " + remoteIp + " date").c_str());
            } else if (ch == 2) {
                std::system(("ssh " + remoteIp + " cal").c_str());
            } else if (ch == 3) {
                std::cout << "Can you please tell me the name of the user you want to add: ";
                std::string New_User;
                std::cin >> New_User;
                std::system(("ssh " + remoteIp + " useradd " + New_User).c_str());
                std::cout << "enter your password for New User" << std::endl;
                std::system(("ssh " + remoteIp + " passwd " + New_User).c_str());
            } else if (ch == 4) {
                std::cout << "Enter your New Folder Name: ";
                std::string Folder_name;
                std::cin >> Folder_name;
                std::system(("ssh " + remoteIp + " mkdir " + Folder_name).c_str());
            } else if (ch == 5) {
                std::cout << "Enter the software name: ";
                std::string Download_software;
                std::cin >> Download_software;
                std::system(("ssh " + remoteIp + " dnf install " + Download_software).c_str());
            } else if (ch == 6) {
                std::cout << "Enter the software name: ";
                std::string Uninstall_Software;
                std::cin >> Uninstall_Software;
                std::system(("ssh " + remoteIp + " dnf remove " + Uninstall_Software).c_str());
                std::cout << "Software is completely removed!" << std::endl;
            } else if (ch == 7) {
                std::cout << "Thank you! for using this Software." << std::endl;
                exit(0);
            } else if (ch == 8) {
                std::cout << "Enter User Name you want to check: ";
                std::string User_Name;
                std::cin >> User_Name;
                std::system(("ssh " + remoteIp + " id " + User_Name).c_str());
            } else if (ch == 9) {
                std::cout << "Initializing web server: HTTPD" << std::endl;
                std::system(("ssh " + remoteIp + " dnf install httpd").c_str());
                std::cout << "Your web server is installed" << std::endl;
                std::system(("ssh " + remoteIp + " systemctl start httpd").c_str());
                std::cout << "Your services HTTPD are started" << std::endl;
                std::system(("ssh " + remoteIp + " systemctl stop firewalld").c_str());
            } else if (ch == 10) {
                std::cout << "Network cards are: " << std::endl;
                std::system(("ssh " + remoteIp + " ifconfig").c_str());
            } else if (ch == 11) {
                std::cout << "Network cards are: " << std::endl;
                std::system(("ssh " + remoteIp + " 'netstat -tnlp'").c_str());
            } else {
                std::cout << "wrong input" << std::endl;
            }
            std::cout << "Enter to clear....";
            std::cin.ignore();
            std::cin.get();
            std::system("clear");
        }
    }
    return 0;
}
