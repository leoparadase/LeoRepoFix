#pragma once
#include <iostream>
#include <string>
using namespace std;

int getInt(int min = 0, int max = INT_MAX);

float getFloat(float min = 0, float max = FLT_MAX);

bool getBool();

string getFileName();

string getString();
