#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "LeoPipeLine.h"
#include "StreamTable.h" // исключить!
#include "Ccheck.h"
#include "Cpipe.h"
#include "Cstation.h"

void PrintMenu();

void TablePipes(StreamTable& table, std::unordered_map<int, Cpipe>::iterator& it_pipe, std::unordered_map<int, Cpipe>& Pipes, std::vector<int>& vec_picked_ids);

void AfterTableMenu();

void WhatStatusToSet();

void PipeTable(StreamTable& table, std::unordered_map<int, Cpipe>& Pipes, std::vector<int>& vec_picked_ids);

void StationTable(StreamTable& table, std::unordered_map<int, Cstation>& Stations, std::vector<int>& vec_picked_ids);

void Save(std::unordered_map<int, Cpipe>& Pipes, std::unordered_map<int, Cstation>& Stations, std::string& str);

void PrintEditMenu();

void PrintMultiEditMenu();

void PrintSearchMenu();

void Save();

void Load();

