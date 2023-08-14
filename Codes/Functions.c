#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"
#include "mystring.h"
int signup(char* name, char* pass, int sizeofname, int sizeofpass, struct seller* doers, int* num) {
	for (int i = 0; i < *num; i++) //Checking for uniqueness
		if (strcompare(doers->names[i], name))
			return 0;
	doers->names[*num - 1] = realloc(doers->names[*num - 1], sizeofname * sizeof(char)); if (doers->names[*num - 1] == NULL)error(404);
	doers->passs[*num - 1] = realloc(doers->passs[*num - 1], sizeofpass * sizeof(char)); if (doers->passs[*num - 1] == NULL)error(404);
	strcopy(name, doers->names[*num - 1]);
	strcopy(pass, doers->passs[*num - 1]);
	doers->money[*num - 1] = 0;
	return 1;
}
int login(char* name, char* pass, int sizeofname, int sizeofpass, struct seller* doers, int* num) {
	for(int i =0;i<*num;i++)
		if (strcompare(doers->names[i], name)) {
			if (strcompare(doers->passs[i], pass))
				return i + 1;
		}
	return 0;
}
int addgoods(	int loggedinseller,
				struct good* goods,
				struct seller* sellers, 
				int* numofgoods,
				char* name,
				int sizeofname,
				int* price,
				int* count) {
	if (*price < 0 || *count < 0) { //Checking for illegal price and count
		error(2);
		return 0;
	}
	int i;
	for (i = 0; i < *numofgoods; i++) { //Has this goods existed already? (i shows it)
		if (strcompare(name, goods->names[i]))break;
	}
	if (--i == *numofgoods - 1) { //If the goods does not exist...
		goods->names[*numofgoods] = (char*)malloc(sizeof(char));
		goods->names[*numofgoods - 1] = realloc(goods->names[*numofgoods - 1], (sizeofname) * sizeof(char)); if (goods->names[*numofgoods - 1] == NULL)error(404);
		strcopy(name, goods->names[*numofgoods - 1]);
		goods->prices[*numofgoods - 1] = *price;
		goods->counts[*numofgoods - 1] = *count;
		goods->sellers[*numofgoods - 1] = loggedinseller;
		(*numofgoods)++;
		//Viewing (confirmation)
		printf("Good added!\n\tUsername: ");
		for (int k = 0; goods->names[*numofgoods - 2][k] != ' '; k++)
			printf("%c", goods->names[*numofgoods - 2][k]);
		printf("\n\tPrice: %d\n\tCount: %d\n\tSeller: ", goods->prices[*numofgoods - 2], goods->counts[*numofgoods - 2]);
		for (int k = 0; sellers->names[loggedinseller - 1][k] != ' '; k++)
			printf("%c", sellers->names[loggedinseller - 1][k]);
		printf("\n\n");
		return 1;
	}
	else { //But if the goods exists...
		if (goods->sellers[++i] == loggedinseller) {
			goods->prices[i] = *price;
			goods->counts[i] += *count;
			//Viewing (confirmation)
			printf("Good updated!\n\tUsername: ");
			for (int k = 0; goods->names[i][k] != ' '; k++)
				printf("%c", goods->names[i][k]);
			printf("\n\tPrice: %d\n\tCount: %d\n\tSeller: ", goods->prices[i], goods->counts[i]);
			for (int k = 0; sellers->names[loggedinseller - 1][k] != ' '; k++)
				printf("%c", sellers->names[loggedinseller - 1][k]);
			printf("\n\n");
			return 1;
		}
		else 
			return 0;
	}

}
int buygoods(	int loggedinbuyer,
				struct good* goods,
				int numofgoods,
				struct buyer* buyers, 
				struct seller* sellers,
				char* name,
				int sizeofname,
				int count,
				char* sellername) {
	numofgoods--;
	int realgood = 0;
	int i; //i is number of selected good
	for (i = 0; i < numofgoods; i++)
		if (strcompare(name, goods->names[i])) {
			realgood = 1; 
			break;
		}
	//Checking some error that may occur
	if (!realgood) { error(7); return 0; }
	if (!strcompare(sellers->names[goods->sellers[i] - 1], sellername)) { error(8); return 0; }
	if (goods->counts[i] < count) { error(9); return 0; }
	if (goods->prices[i] * count > buyers->money[loggedinbuyer - 1] * count) { error(10); return 0; }
	//Main operation
	buyers->money[loggedinbuyer - 1] -= goods->prices[i] * count;
	goods->counts[i] -= count;
	sellers->money[goods->sellers[i] - 1] += goods->prices[i] * count;
	
	buyers->buyergoods->names[buyers->numofgoods[loggedinbuyer - 1]] = realloc(buyers->buyergoods->names[buyers->numofgoods[loggedinbuyer - 1]], sizeofname * sizeof(char)); if (buyers->buyergoods->names[buyers->numofgoods[loggedinbuyer - 1]] == NULL)error(404);
	strcopy(name, buyers->buyergoods->names[buyers->numofgoods[loggedinbuyer - 1]]);
	buyers->buyergoods->prices[buyers->numofgoods[loggedinbuyer - 1]] = goods->prices[i];
	buyers->buyergoods->counts[buyers->numofgoods[loggedinbuyer - 1]] = count;
	buyers->buyergoods->sellers[buyers->numofgoods[loggedinbuyer - 1]] = goods->sellers[i] - 1;
	buyers->buyergoods->names[buyers->numofgoods[loggedinbuyer - 1] + 1] = (char*)malloc(sizeof(char));
	buyers->numofgoods[loggedinbuyer - 1]++;
	return 1;
}
void error(int n) {
	switch (n)
	{
	case 1:
		printf("Error%d happened! It means command was inserted is illegal now. please retry.\n", n);
		break;
	case 2:
		printf("Error%d happened! It means count or price were inserted are illegal.\n", n);
		break;
	case 3:
		printf("Error%d happened! It means username isn't uniqe. please retry.\n", n);
		break;
	case 4:
		printf("Error%d happened! It means username or password are not founded. please retry.\n", n);
		break;
	case 5:
		printf("Error%d happened! It means a buyer user must be online.\n", n);
		break;
	case 6:
		printf("Error%d happened! It means good was not added.\n", n);
		break;
	case 7:
		printf("Error%d happened! It means good doesn't exist.\n", n);
		break;
	case 8:
		printf("Error%d happened! It means this good doesn't belong to this sellerID.\n", n);
		break;
	case 9:
		printf("Error%d happened! It means there are not enough goods available.\n", n);//check
		break;
	case 10:
		printf("Error%d happened! It means your money is not enough.\n", n);
		break;
	case 11:
		printf("Error%d happened! It means role was inserted is illegal.\n", n);
		break;
	case 12:
		printf("Error%d happened! It means money was inserted is illegal.\n", n);
		break;
	case 13:
		printf("Error%d happened! It means a seller user must be online.\n", n);
		break;
	case 14:
		printf("Error%d happened! It means all users must be logged out.(Input logout)\n", n);
		break;
	case 404:
		printf("Error%d happened! It means memory can not be allocated.\nprogramm will closed!\n", n);
		exit(EXIT_SUCCESS);
		break;
	default:
		break;
	}
}