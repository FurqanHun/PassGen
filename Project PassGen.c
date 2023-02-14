#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void string_to_hex(char* input, char* output);
void hex_to_string(char* input, char* output);
void generate_password(char* name, int n);
void view_password(char* name);

int main() {
	
	//function color krne ke liay lgaya hai
	system("color"); 
	int choice;
	char name[31]; // maximum name length is 30 characters OK!!!!!!!!!

	printf("\n\n\t\t\033[0;36m!Welcome to the Project PassGen!\033[0m\n\n");
	
	printf("\t\t\033[0;36m 1. \033[0m");
	printf(" Generate a new password\n");
	
	printf("\t\t\033[0;36m 2. \033[0m");
	printf(" View an existing password\n");
	
	printf("\t\t\033[0;36m 3. \033[0m");
	printf(" Team PassGen\n");
	
	printf("\t\t\033[0;36m 4. \033[0m");
	printf(" Help\n");
	
	printf("\n\t\t Enter your choice >> ");
	scanf("%d", &choice);
	
	if(choice==1 || choice==2) {
	
	printf("\nEnter the name for the password (without gap, max limit 30 characters) >> \033[46m");
	scanf("%s", &name);
	printf("\033[0m");
}
	switch (choice) {
		
		case 1:
			printf("\nEnter the number of characters for the password (minimum 15) >> ");
			int n;
			scanf("%d", &n);
			generate_password(name, n);
			break;
		case 2:
			view_password(name);
			break;
			
		case 3:
			system("cls");
		printf("\n\n\t\t\033[0;36m!Team Project PassGen!\033[0m\n");
		printf("\n Muhammad Furqan Khalil	| FurqanHun | \033[0;36m---Lead---\033[0m");
		printf("\n Muhammad Yameen	| Yameen    |\n\n");
		
		break;
		
		case 4:
			system("cls");
			/* TODO (Furqan#1#): Add About in multiple lines pls  */
			printf("\n\n\t\t\033[0;46m!User Manual Project PassGen!\033[0m\n");
				printf("\t\t\033[0;36m 1. \033[0m");
				printf(" How to generate a password?\n");
				
				printf("\t\t\033[0;36m 2. \033[0m");
				printf(" How to view the generated password?\n");
				
				int help_choice;
				printf("\n\t\t Enter your choice >> ");
				scanf("%d", &help_choice);
				
		if(help_choice==1) {
		
			printf("\n\033[0;36mHow to generate a password?\033[0m\n\n");
			printf("\nTO generate a password you only have to follow three(3) simple steps:\n");
			
			printf("\n\033[0;34mSTEP 1 -\033[0m After running the application select option 1 by typing '1' (i.e,Generate a new password).");
			
			printf("\n\033[0;34mSTEP 2 -\033[0m It'll ask you to enter the name for the password. Make sure not to put any");
			printf("\n\t spaces in between the name and that the name is under 30 characters.");
			
			printf("\n\033[0;34mSTEP 3 -\033[0m After that it's gonna ask you to enter the number of charcters for your");
			printf("\n\t password make sure you enter atleast 15 or the program will terminate itself.");
			printf("\n\033[0;34mSTEP 4 -\033[0m Congratulations! you just created a randomised safe password.\n");
		}
		else if(help_choice==2) {
		printf("\n\033[0;36mHow to view the generated password?\033[0m\n\n");
			printf("\nTo view a generated password you only have to follow two(2) simple steps:\n");
			
			printf("\n\033[0;34mSTEP 1 -\033[0m After running the application select option 2 by typing '2'and enter (i.e,View an existing password).");
			
			printf("\n\033[0;34mSTEP 2 -\033[0m It'll ask you to enter the name for the password that you provided it before. Make sure not to put any");
			printf("\n\t spaces in between the name and that the name is under 30 characters.");
		
			printf("\n\033[0;34mSTEP 3 -\033[0m Congratulations! you just viewed a randomly generated safe password.\n");
		}
		else
		{
			printf("\033[0;31m \n\t\t  ---Invalid choice--- \033[0m\n");
		}
			break;
		default:
			printf("\033[0;31m \n\t\t  ---Invalid choice--- \033[0m\n");
			
			break;
	}
	printf("\n\n\t\t\t");
	system("pause");
	return 0;
}

// Converts a string to a hexadecimal string
void string_to_hex(char* input, char* output) {
	
	int input_len = strlen(input);
	
	for (int i = 0; i < input_len; i++) {
		sprintf(output + 2 * i, "%02x", input[i]);
	}
}

// Converts a hexadecimal string to a string
void hex_to_string(char* input, char* output) {
	
	int input_len = strlen(input);
	
	for (int i = 0; i < input_len / 2; i++) {
		sscanf(input + 2 * i, "%02x", &output[i]);
	}
}

// naya pass generate krke "passwords.txt" file main save krega
void generate_password(char* name, int n) {
	
	// Make sure the password has at least 15 characters
	if (n < 15) {
		printf("\n\t\t\033[0;31m---Error: password must be at least 15 characters long---\033[0m\n");
		return;
	}

	char line[100];
	char* pch;
	int found = 0;

	FILE* fp = fopen("passwords.txt", "r");

	// Search the file for the password
	while (fgets(line, 100, fp) != NULL) {
		pch = strtok(line, "|");
		
		if (strcmp(pch, name) == 0) {
			// Name already exists
			found = 1;
			break;
		}
	}

	if (found) {
		printf("\n\t\t\033[0;31m---Error: a password with that name already exists---\033[0m\n");
	} else {
		// Name does not exist, generate a new password
		char password[31]; // maximum password length is 30 characters
		char hex_password[61]; // hexadecimal representation of password (2 characters per byte)


		// Seed the random number generator (hn wohi minecraft wali seed generation)
		srand(time(0));

		// Generate a random password
		for (int i = 0; i < n; i++) {
			// Generate a random number between 33 and 126 (inclusive)
			int r = rand() % 94 + 33;

			// Convert the random number to a character and add it to the password
			password[i] = (char) r;
		}

		// Add a null terminator to the end of the password string
		password[n] = '\0';

		
		string_to_hex(password, hex_password);
		
		fclose(fp);
		
		fp = fopen("passwords.txt", "a");

		
		fprintf(fp, "%s|%s\n", name, hex_password);
		
		fclose(fp);

		printf("\n\t\t\033[0;32m--Your password has been generated and saved to the file 'passwords.txt'.--\033[0m\n");
	}
	
}

// Views the password associated with the given name in the "passwords.txt" file
void view_password(char* name) {
	
	char line[100];
	char* pch;
	int found = 0;
	char hex_password[61];
	char password[31];
	
	FILE* fp = fopen("passwords.txt", "r");

	// Search the file for the password
	while (fgets(line, 100, fp) != NULL) {
		pch = strtok(line, "|");
		if (strcmp(pch, name) == 0) {
			// Password found
			pch = strtok(NULL, "|");
			strcpy(hex_password, pch);
			found = 1;
			break;
		}
	}

	if (!found) {
		printf("\n\t\t\033[0;31m---Error: password not found---\033[0m\n");
	} else {
		// Convert the hexadecimal password to a string
		hex_to_string(hex_password, password);

		printf("\n\n\t\tYour password is: \033[0;42m%s\033[0m", password);
	}
}