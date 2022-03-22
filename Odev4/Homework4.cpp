/*****************************************************************
					Student Name:	Mehmet Fatih Yýldýz
					Student Number:	B201202013
******************************************************************/
#include <iostream>
#include <iomanip>
#include <string.h>
#include <conio.h>
#include<cctype>

using namespace std;

int	messageLength = 0;			//variable for message length
int	passwordLength = 0;			//variable for password length
int	messCounter = 0;			//will be used in functions to define message length
int	passCounter = 0;			//will be used in functions to define password length
int	a = 0;		//will be used in functions
int b = 0;		//will be used in functions

class steps {
public:
	char Password[100];				//char for password
	char newPassword[100];			//char for new password (new password is the password which has same length with the message)
	char Message[100];				//char for message
	char encryptedMessage[100];		//char for encryptep message
	char decryptedMessage[100];		//char for decrypted message

	void getMessandpass() {			//function for taking message and password from user
		cout << "ENTER A PASSWORD" << setw(7) << ": ";
		cin.getline(Password, 100);
		
		cout << "ENTER A MESSAGE" << setw(8) << ": ";
		cin.getline(Message, 100);
	}

	void messageLong(char Message[], char Password[]) {			//This function defines character numbers of the password and message
		while (Message[messCounter] != '\0') {		
				messageLength++;
				messCounter++;
		}
		while (Password[passCounter] != '\0') {
			passwordLength++;
			passCounter++;
		}
	}
	
	int createNewPassword(int messageLenght, int passwordLenght, char password[]) {			//This function creates new password

		for (a = 0; a < messageLenght; a++) {
			if (isspace(Message[a])) {			//with isspace program finds space characters
				newPassword[a] = password[b];	//This one assign a character for space character
				newPassword[a + 1] = password[b + 1];	//With this one password continues to order
			}
			else if (b == passwordLenght) {		//This if loop returns the number of password character to zero
				b = 0;
			newPassword[a] = password[b];		
				b++;
			}
			else {
				newPassword[a] = password[b];		
				b++;					
			}
		}
		return newPassword[messageLenght];		//And it assign new password
	}
	
	void encrypt(int messageLenght, char message[], char newPassword[]) {		//This function encrypts the message

		for (a = 0; a < messageLenght; a++) {
			if (isspace(Message[a])) {			//with isspace program finds space characters
				encryptedMessage[a] = ' ';
			}
			else {
				encryptedMessage[a] = ((message[a] + newPassword[a]) % 26) + 'A';		//This part works on ASCII table numbers
			}																			//Long definition on the PDF
		}

		cout << "---------------------------------------" << endl;
		cout << "ENCRYPTED TEXT" << setw(9) << ": ";
		for (a = 0; a < messageLenght; a++) {			//Prints encrypted message
			cout << encryptedMessage[a];
		}
		cout << endl;
		for (a = 0; a < messageLenght; a++) {
			cout << newPassword[a];
		}
		cout << endl;
	}

	void decrypt(int messageLenght, char encryptedMessage[], char newPassword[]) {			//This function decrypts encrypted message

		for (a = 0; a < messageLenght; a++) {
			if (isspace(Message[a])) {			//with isspace program finds space characters
				decryptedMessage[a] = ' ';
			}
			else {
				decryptedMessage[a] = (((encryptedMessage[a] - newPassword[a]) + 26) % 26) + 'A';		//This part works on ASCII table numbers
			}																							////Long definition on the PDF
		}

		cout << "DECRYPTED TEXT" << setw(9) << ": ";
		for (a = 0; a < messageLenght; a++) {			//Prints decrypted message
			cout << decryptedMessage[a];
		}
		cout << endl;
		cout << "---------------------------------------";	
	}

	void printMessages(char message[], char  password[]) {			//This function for the print message and password
		cout << "---------------------------------------" << endl;
		cout << "PASSWORD" << setw(15) << ": ";
		cout << password << endl;
		
		cout << "MESSAGE" << setw(16) << ": ";
		cout << message << endl;
	}
};

int main() {
	steps encrypt;			//Main steps of the programs
	encrypt.getMessandpass();		//Firstly gets the message and password
	encrypt.messageLong(encrypt.Message, encrypt.Password);		//Then decides message and password length
	encrypt.createNewPassword(messageLength, passwordLength, encrypt.Password);		//Creates new password
	encrypt.printMessages(encrypt.Message, encrypt.Password);		//Prints message and password
	encrypt.encrypt(messageLength, encrypt.Message, encrypt.newPassword);		//Finds and prints encrypted message
	encrypt.decrypt(messageLength, encrypt.encryptedMessage, encrypt.newPassword);		//Finds and prints decrypted message from encrypted message
	return 0;
}