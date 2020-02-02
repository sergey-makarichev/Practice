#pragma once
#include "TStack.h"
#include <string>
#include "Exñeption.h"
using namespace std;

class Postfix
{
private:
	static int Prioritet(char v);
public:
	static string PostfixForm(const string &v);
	static void GetOperandsValues(const string& postfix, char*& operands, float*& values, int& count);
	static float Calculating(const string &v, char* operands, float* values, int count);
};