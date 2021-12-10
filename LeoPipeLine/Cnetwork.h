#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "StreamTable.h"
#include "Ccheck.h"
#include "Cpipe.h"
#include "Cstation.h"

using namespace std;

class Cnetwork
{
public:
	unordered_map <int, Cpipe> Pipes;
	unordered_map <int, Cstation> Stations;
	vector <int> vec_picked_ids;

	void AfterTableMenu();
	void WhatStatusToSet();

	void PipeTable(StreamTable& table, std::unordered_map<int, Cpipe>& Pipes, std::vector<int>& vec_picked_ids);
	void StationTable(StreamTable& table, std::unordered_map<int, Cstation>& Stations, std::vector<int>& vec_picked_ids);

	void PipeMainMenu();
	void StationMainMenu();

	// add search by ID
	void SearchPipes();
	void SearchStations();

	void save();
	void load();

	// todo
	//void PipeConnect();
	//void PipeDisconnect();
	//void NetworkMap();

	template <typename T, typename S>
	using Filter = bool(*)(const S& pipe, T param);

	template <typename T, typename S>
	static vector <int> findByFilter(const unordered_map<int, S>& pipes, Filter<T, S> f, T param) {
		vector <int> keys;
		for (auto& i : pipes) {
			if (f(i.second, param))
				keys.push_back(i.first);
		}
		return keys;
	};
};

