#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Functions.h"
#include "mystring.h"
int main() { /*In my code "good" means "KALA" and regarded as singular.
			 But "goods" means "KALAHA" and regarded as plural.
			 However, this is not the case in English! :)*/
	printf("Welcome to UT_KALA!\n\n");
	int i;
	int numofsellers = 1;
	int numofbuyers = 1;
	int numofgoods = 1;
	//loggedin_num and loggedin_role show which one of users is online (0 means all users are offline)
	int loggedin_num = 0;
	char loggedin_role = '\0';

	//First mallocing
	struct seller* sellers = (struct seller*)malloc(sizeof(struct seller)); if (sellers == NULL)error(404);//done
	sellers->names = (char**)malloc(sizeof(char*) * 2); if (sellers->names == NULL)error(404);//done
	sellers->passs = (char**)malloc(sizeof(char*) * 2); if (sellers->passs == NULL)error(404);//done
	sellers->money = (int*)malloc(sizeof(int) * 2); if (sellers->money == NULL)error(404);//done
	sellers->names[0] = (char*)malloc(sizeof(char) * 2); if (sellers->names[0] == NULL)error(404);//done
	sellers->passs[0] = (char*)malloc(sizeof(char) * 2); if (sellers->passs[0] == NULL)error(404);//done

	struct buyer* buyers = (struct buyer*)malloc(sizeof(struct buyer)); if (buyers == NULL)error(404);//done
	buyers->names = (char**)malloc(sizeof(char*) * 2); if (buyers->names == NULL)error(404);//done
	buyers->passs = (char**)malloc(sizeof(char*) * 2); if (buyers->passs == NULL)error(404);//done
	buyers->money = (int*)malloc(sizeof(int) * 2); if (buyers->money == NULL)error(404);//done
	buyers->numofgoods = (int*)malloc(sizeof(int) * 2); if (buyers->numofgoods == NULL)error(404);//done
	buyers->buyergoods = (struct good*)malloc(sizeof(struct good)); if (buyers->buyergoods == NULL)error(404);//done
	buyers->names[0] = (char*)malloc(sizeof(char) * 2); if (buyers->names[0] == NULL)error(404);//done
	buyers->passs[0] = (char*)malloc(sizeof(char) * 2); if (buyers->passs[0] == NULL)error(404);//done

	buyers->buyergoods->names = (char**)malloc(sizeof(char*) * 2); if (buyers->buyergoods->names == NULL)error(404);//done
	buyers->buyergoods->prices = (int*)malloc(sizeof(int) * 2); if (buyers->buyergoods->names == NULL)error(404);//done
	buyers->buyergoods->counts = (int*)malloc(sizeof(int) * 2); if (buyers->buyergoods->counts == NULL)error(404);//done
	buyers->buyergoods->sellers = (int*)malloc(sizeof(int) * 2); if (buyers->buyergoods->sellers == NULL)error(404);//done
	buyers->buyergoods->names[0] = (char*)malloc(sizeof(char) * 2); if (buyers->buyergoods->names[0] == NULL)error(404);//done

	struct good* goods = (struct good*) malloc(sizeof(struct good)); if (goods == NULL)error(404);//done
	goods->names = (char**)malloc(sizeof(char*) * 2); if (goods->names == NULL)error(404);//done
	goods->prices = (int*)malloc(sizeof(int) * 2); if (goods->prices == NULL)error(404);
	goods->counts = (int*)malloc(sizeof(int) * 2); if (goods->counts == NULL)error(404);
	goods->sellers = (int*)malloc(sizeof(int) * 2); if (goods->sellers == NULL)error(404);
	goods->names[0] = (char*)malloc(sizeof(char) * 2); if (goods->names[0] == NULL)error(404);

	while (1) {
		char* backup = (char*)malloc(sizeof(char)); if (backup == NULL)error(404);
		//Setting section
		int sizeofsection = 1;
		char* section = malloc(sizeof(char)); if (section == NULL)error(404);
		while (1) {
			section = realloc(section, ++sizeofsection); if (section == NULL)error(404);
			scanf_s("%c", section + sizeofsection - 2);
			if (*(section + sizeofsection - 2) == ' ' || *(section + sizeofsection - 2) == '\n') { *(section + sizeofsection - 1) = '\0'; break; }
		}

		if (strcompare(section, "signup ")) {
			if (!loggedin_num) {
				char* name;
				char* pass;
				char* role;
				int sizeofname = 1;
				int sizeofpass = 1;
				int sizeofrole = 1;
				//Inputing username
				while (1) {
					backup = realloc(backup, ++sizeofname); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofname - 2);
					if (*(backup + sizeofname - 2) == ' ' || *(backup + sizeofname - 2) == '\n') { *(backup + sizeofname - 1) = '\0'; break; }
				}
				name = (char*)malloc(sizeof(char) * sizeofname); if (name == NULL)error(404);
				strcopy(backup, name);
				//Inputing password
				while (1) {
					backup = realloc(backup, ++sizeofpass); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofpass - 2);
					if (*(backup + sizeofpass - 2) == ' ' || *(backup + sizeofpass - 2) == '\n') { *(backup + sizeofpass - 1) = '\0'; break; }
				}
				pass = (char*)malloc(sizeof(char) * (sizeofpass)); if (pass == NULL)error(404);
				strcopy(backup, pass);
				//Inputing role
				while (1) {
					backup = realloc(backup, ++sizeofrole); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofrole - 2);
					if (*(backup + sizeofrole - 2) == ' ' || *(backup + sizeofrole - 2) == '\n') { *(backup + sizeofrole - 1) = '\0'; break; }
				}
				role = (char*)malloc(sizeof(char) * (sizeofrole)); if (role == NULL)error(404);
				strcopy(backup, role);
				//Referencing to signup function
				if (strcompare(role, "seller\n")) {
					if (signup(name, pass, sizeofname, sizeofpass, sellers, &numofsellers)) {
						sellers->names = realloc(sellers->names, (numofsellers + 1) * sizeof(char*)); if (sellers->names == NULL)error(404);
						sellers->passs = realloc(sellers->passs, (numofsellers + 1) * sizeof(char*)); if (sellers->names == NULL)error(404);
						sellers->money = realloc(sellers->money, (numofsellers + 1) * sizeof(int)); if (sellers->money == NULL)error(404);
						sellers->names[numofsellers] = (char*)malloc(sizeof(char)); if (sellers->names[numofsellers] == NULL)error(404);
						sellers->passs[numofsellers] = (char*)malloc(sizeof(char)); if (sellers->passs[numofsellers] == NULL)error(404);
						numofsellers++;
						//Viewing (confirmation)
						printf("Seller signed up!\n\tUsername: ");
						for (int k = 0; k < sizeofname; k++)
							printf("%c", sellers->names[numofsellers - 2][k]);
						printf("\n\tPassword: ");
						for (int k = 0; k < sizeofpass; k++)
							printf("%c", sellers->passs[numofsellers - 2][k]);
						printf("\n\n");
					}
					else
						error(3);
				}
				else if (strcompare(role, "buyer\n")) {
					if (signup(name, pass, sizeofname, sizeofpass, buyers, &numofbuyers)) {
						buyers->names = realloc(buyers->names, (numofsellers + 1) * sizeof(char*)); if (buyers->names == NULL)error(404);
						buyers->passs = realloc(buyers->passs, (numofsellers + 1) * sizeof(char*)); if (buyers->names == NULL)error(404);
						buyers->money = realloc(buyers->money, (numofsellers + 1) * sizeof(int)); if (buyers->money == NULL)error(404);
						buyers->numofgoods = realloc(buyers->numofgoods, (numofsellers + 1) * sizeof(int)); if (buyers->numofgoods == NULL)error(404);
						buyers->names[numofbuyers] = (char*)malloc(sizeof(char)); if (buyers->names[numofbuyers] == NULL)error(404);
						buyers->passs[numofbuyers] = (char*)malloc(sizeof(char)); if (buyers->passs[numofbuyers] == NULL)error(404);
						buyers->numofgoods[numofbuyers - 1] = 0;
						numofbuyers++;
						//Viewing (confirmation)
						printf("Buyer signed up!\n\tUsername: ");
						for (int k = 0; k < sizeofname; k++)
							printf("%c", buyers->names[numofbuyers - 2][k]);
						printf("\n\tPassword: ");
						for (int k = 0; k < sizeofpass; k++)
							printf("%c", buyers->passs[numofbuyers - 2][k]);
						printf("\n\n");
					}
					else
						error(3);
				}
				else
					error(11);
				free(name);
				free(pass);
				free(role);
			}
			else
				error(14);
		}
		else if (strcompare(section, "login ")) {
			char* name;
			char* pass;
			char* role;
			int sizeofname = 1;
			int sizeofpass = 1;
			int sizeofrole = 1;
			//Inputing username
			while (1) {
				backup = realloc(backup, ++sizeofname * sizeof(char)); if (backup == NULL)error(404);
				scanf_s("%c", backup + sizeofname - 2);
				if (*(backup + sizeofname - 2) == ' ' || *(backup + sizeofname - 2) == '\n') { *(backup + sizeofname - 1) = '\0'; break; }
			}
			name = (char*)malloc(sizeof(char) * sizeofname); if (name == NULL)error(404);
			strcopy(backup, name);
			//Inputing password
			while (1) {
				backup = realloc(backup, ++sizeofpass * sizeof(char)); if (backup == NULL)error(404);
				scanf_s("%c", backup + sizeofpass - 2);
				if (*(backup + sizeofpass - 2) == ' ' || *(backup + sizeofpass - 2) == '\n') { *(backup + sizeofpass - 1) = '\0'; break; }
			}
			pass = (char*)malloc(sizeof(char) * (sizeofpass)); if (pass == NULL)error(404);
			strcopy(backup, pass);
			//Inputing role
			while (1) {
				backup = realloc(backup, ++sizeofrole * sizeof(char)); if (backup == NULL)error(404);
				scanf_s("%c", backup + sizeofrole - 2);
				if (*(backup + sizeofrole - 2) == ' ' || *(backup + sizeofrole - 2) == '\n') { *(backup + sizeofrole - 1) = '\0'; break; }
			}
			role = (char*)malloc(sizeof(char) * (sizeofrole)); if (role == NULL)error(404);
			strcopy(backup, role);
			//Referencing to login function
			if (strcompare(role, "seller\n")) {
				loggedin_num = login(name, pass, sizeofname, sizeofpass, sellers, &numofsellers);
				loggedin_role = 's';
				//Viewing (confirmation)
				if (loggedin_num) {
					printf("Seller logged in!\n\tUsername: ");
					for (int k = 0; k < sizeofname; k++)
						printf("%c", name[k]);
					printf("\n\tPassword: ");
					for (int k = 0; k < sizeofpass; k++)
						printf("%c", pass[k]);
					printf("\n\n");
				}
				else
					error(4);
			}
			else if (strcompare(role, "buyer\n")) {
				loggedin_num = login(name, pass, sizeofname, sizeofpass, buyers, &numofbuyers);
				loggedin_role = 'b';
				//Viewing (confirmation)
				if (loggedin_num) {
					printf("Buyer logged in!\n\tUsername: ");
					for (int k = 0; k < sizeofname; k++)
						printf("%c", buyers->names[numofbuyers - 2][k]);
					printf("\n\tPassword: ");
					for (int k = 0; k < sizeofpass; k++)
						printf("%c", buyers->passs[numofbuyers - 2][k]);
					printf("\n\n");
				}
				else
					error(4);
			}
			else
				error(11);
			free(name);
			free(pass);
			free(role);
		}
		else if (strcompare(section, "logout\n")) {
			loggedin_num = 0;
			loggedin_role = '\0';
			printf("All users are logged out!\n\n");
		}
		else if (strcompare(section, "view\n")) {
			if (loggedin_role == 's') {
				printf("Your info:\n\tUsername: ");
				for (int k = 0; sellers->names[loggedin_num - 1][k] != ' '; k++)
					printf("%c", sellers->names[loggedin_num - 1][k]);
				printf("\n\tRole: seller\n\tMoney: %d\n\tGoods:\tname\tprice\tcount\n\t\t", sellers->money[loggedin_num - 1]);
				for (int k = 0; k < numofgoods; k++)
					if (goods->sellers[k] == loggedin_num) {
						for (int j = 0; goods->names[k][j] != ' '; j++)
							printf("%c", goods->names[k][j]);
						printf("\t%d\t%d", goods->prices[k], goods->counts[k]);
						printf("\n\t\t");
					}
				printf("\n\n");
			}
			else if (loggedin_role == 'b') {
				printf("Your info:\n\tUsername: ");
				for (int k = 0; buyers->names[loggedin_num - 1][k] != ' '; k++)
					printf("%c", buyers->names[loggedin_num - 1][k]);
				printf("\n\tRole: buyer\n\tMoney: %d\n\tGoods:\tname\tprice\tcount\tseller", buyers->money[loggedin_num - 1]);
				for (int k = 0; k < buyers->numofgoods[loggedin_num - 1]; k++) {
					printf("\n\t\t");
					for (int j = 0; buyers->buyergoods->names[k][j] != ' '; j++)
						printf("%c", buyers->buyergoods->names[k][j]);
					printf("\t%d\t%d\t", buyers->buyergoods->prices[k], buyers->buyergoods->counts[k]);
					for (int j = 0; sellers->names[buyers->buyergoods->sellers[k]][j] != ' '; j++)
						printf("%c", sellers->names[buyers->buyergoods->sellers[k]][j]);
				}
				printf("\n\n");
			}
			else
				error(1);
		}
		else if (strcompare(section, "deposit ")) {
			if (loggedin_num && loggedin_role == 'b') {
				int money;
				scanf_s(" %d", &money);
				if (money > 0) {
					while (getchar() != '\n');
					buyers->money[loggedin_num - 1] += money;
					printf("Deposited!\n\n");
				}
				else
					error(12);
			}
			else {
				while (getchar() != '\n'); //Ignoring next useless value(s)
				error(5);
			}
		}
		else if (strcompare(section, "add_goods ")) {
			if (loggedin_role == 's') {
				char* name;
				int price;
				int count;
				int sizeofname = 1;
				//Inputing goods name
				while (1) {
					backup = realloc(backup, ++sizeofname * sizeof(char)); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofname - 2);
					if (*(backup + sizeofname - 2) == ' ' || *(backup + sizeofname - 2) == '\n') { *(backup + sizeofname - 1) = '\0'; break; }
				}
				name = (char*)malloc(sizeof(char) * sizeofname); if (name == NULL)error(404);
				strcopy(backup, name);
				//Inputing price and count
				scanf_s("%d %d", &price, &count);
				while (getchar() != '\n');
				if (!addgoods(loggedin_num, goods, sellers, &numofgoods, name, sizeofname, &price, &count))
					error(6);
				else {
					goods->names = realloc(goods->names, (numofgoods + 1) * sizeof(char*)); if (goods->names == NULL)error(404);
					goods->prices = realloc(goods->prices, (numofgoods + 1) * sizeof(int)); if (goods->prices == NULL)error(404);
					goods->counts = realloc(goods->counts, (numofgoods + 1) * sizeof(int)); if (goods->counts == NULL)error(404);
					goods->sellers = realloc(goods->sellers, (numofgoods + 1) * sizeof(int)); if (goods->sellers == NULL)error(404);
				}
				free(name);
			}
			else
				error(13);
		}
		else if (strcompare(section, "show_goods\n")) {
			printf("Goods:\tname\tprice\tcount\tseller");
			for (int k = 0; k < numofgoods - 1; k++) {
				printf("\n\t");
				for (int j = 0; goods->names[k][j] != ' '; j++)
					printf("%c", goods->names[k][j]);
				printf("\t%d\t%d\t", goods->prices[k], goods->counts[k]);
				for (int j = 0; sellers->names[goods->sellers[k] - 1][j] != ' '; j++)
					printf("%c", sellers->names[goods->sellers[k] - 1][j]);
			}
			printf("\n\n");
		}
		else if (strcompare(section, "buy ")) {
			if (loggedin_role == 'b') {
				char* name;
				int count;
				char* sellername;
				int sizeofname = 1;
				int sizeofsellername = 1;
				//Inputing goods name
				while (1) {
					backup = realloc(backup, ++sizeofname * sizeof(char)); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofname - 2);
					if (*(backup + sizeofname - 2) == ' ' || *(backup + sizeofname - 2) == '\n') { *(backup + sizeofname - 1) = '\0'; break; }
				}
				name = (char*)malloc(sizeof(char) * sizeofname); if (name == NULL)error(404);
				strcopy(backup, name);
				//Inputing goods count
				scanf_s("%d ", &count);
				//Inputing goods sellername
				while (1) {
					backup = realloc(backup, ++sizeofsellername * sizeof(char)); if (backup == NULL)error(404);
					scanf_s("%c", backup + sizeofsellername - 2);
					if (*(backup + sizeofsellername - 2) == ' ' || *(backup + sizeofsellername - 2) == '\n') { *(backup + sizeofsellername - 1) = '\0'; break; }
				}
				sellername = (char*)malloc(sizeof(char) * sizeofsellername); if (sellername == NULL)error(404);
				strcopy(backup, sellername);
				sellername[sizeofsellername - 2] = ' ';
				if (buygoods(loggedin_num, goods, numofgoods, buyers, sellers, name, sizeofname, count, sellername)) {
					buyers->buyergoods->names = realloc(buyers->buyergoods->names, (buyers->numofgoods[loggedin_num - 1] + 1) * sizeof(char*)); if (buyers->buyergoods->names == NULL)error(404);
					buyers->buyergoods->prices = realloc(buyers->buyergoods->prices, (buyers->numofgoods[loggedin_num - 1] + 1) * sizeof(int*)); if (buyers->buyergoods->prices == NULL)error(404);
					buyers->buyergoods->counts = realloc(buyers->buyergoods->counts, (buyers->numofgoods[loggedin_num - 1] + 1) * sizeof(int*)); if (buyers->buyergoods->counts == NULL)error(404);
					buyers->buyergoods->sellers = realloc(buyers->buyergoods->sellers, (buyers->numofgoods[loggedin_num - 1] + 1) * sizeof(int*)); if (buyers->buyergoods->sellers == NULL)error(404);

					printf("Buyed!\n\n");
				}

				free(name);
				free(sellername);
			}
			else
				error(5);
		}
		else if (strcompare(section, "exit\n")) {
			free(section);
			printf("Goodbye!");
			break;
		}
		else if (section[sizeofsection - 2] != ' ') error(1);
		free(backup);
		free(section);
	}
	//Freeing
	for (int i = 0; i < numofsellers; i++) {
		free(sellers->names[i]);
		free(sellers->passs[i]);
	}
	free(sellers->names);
	free(sellers->passs);
	free(sellers->money);
	free(sellers);
	for (int i = 0; i < numofbuyers; i++) {
		free(buyers->names[i]);
		free(buyers->passs[i]);
	}
	free(buyers->names);
	free(buyers->passs);
	free(buyers->money);
	for (int j = 0; j < numofbuyers; j++)
		for (int i = 0; i < buyers->numofgoods[j]; i++)
			free(buyers->buyergoods->names[i]);
	free(buyers->buyergoods->names);
	free(buyers->buyergoods->prices);
	free(buyers->buyergoods->counts);
	free(buyers->buyergoods);
	free(buyers->numofgoods);
	free(buyers);

	for (int i = 0; i < numofgoods; i++)
		free(goods->names[i]);
	free(goods->names);
	free(goods->prices);
	free(goods->counts);
	free(goods->sellers);
	exit(EXIT_FAILURE);
}