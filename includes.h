#pragma once

#include <iostream>
using namespace std;

#include <string>
#include <sstream>
#include <windows.h>
#include <fstream>
#include <stdio.h>

#define NMAXRECORDS 50




template <class T>
bool from_string(T& t, const std::string& s, std::ios_base& (*f)(std::ios_base&))
{
	std::istringstream iss(s);
	return !(iss >> f >> t).fail();
}

