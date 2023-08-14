#pragma once
struct seller {
	char** names;
	char** passs;
	int* money;
};
struct buyer {
	char** names;
	char** passs;
	int* money;
	int* numofgoods;
	struct good* buyergoods;
};
struct good
{
	char** names;
	int* prices;
	int* counts;
	int* sellers;
};
int signup(char* name, char* pass, int sizeofname, int sizeofpass, struct seller* doers, int* num);
int login(char* name, char* pass, int sizeofname, int sizeofpass, struct seller* doers, int* num);
int addgoods(int loggedinseller, struct good* goods, struct seller* sellers, int* numofgoods, char* name,int sizeofname, int* price, int* count);
int buygoods(int loggedinbuyer, struct good* goods, int numofgoods, struct buyer* buyers, struct seller* sellers, char* name, int sizeofname, int count, char* sellername);
void error(int n);