/*
* Ivan Oswaldo Ayala Martinez   19310216
* David Alonso Trejo Natividad  19310211
* Junio, 2021
*/

#ifndef FOUNDATION_H
#define FOUNDATION_H

#include <memory>
#include <string>
#include <vector>
#include <array>

struct State;
using  StatePtr = std::shared_ptr<State>;

using Graph = std::vector<StatePtr>;
using ExcludedTokens = std::array<std::string, 5>;

static ExcludedTokens excludedTokens{ {"", "ew", "bew", "aew", "ewy"} };

struct Direction
{
	char token = '\0';
	std::string excludedTokens;
	StatePtr destinyNode;
};

struct State
{
	State(bool isFinalState, std::string stateName) :
		isFinalState(isFinalState),
		stateName(stateName)
	{
	}

	std::vector<Direction> directions;
	bool isFinalState;
	std::string stateName;
};

struct Coincidences
{
	std::size_t webCoincidences;
	std::size_t ebayCoincidences;
};

#endif
