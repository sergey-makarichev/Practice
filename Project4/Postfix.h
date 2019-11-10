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
	static string PostfixForm(string v);
	static float Calculating(string v, string name, float* values);
};