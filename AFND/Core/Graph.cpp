#include "Graph.h"

Core::GraphBuilder::GraphBuilder()
{
	BuildGrpah();
}

[[nodiscard]]
::Graph Core::GraphBuilder::GetGraph() const
{
	return m_automata;
}

void Core::GraphBuilder::BuildGrpah()
{
	m_automata.push_back(std::make_shared<State>(false, "state 1"));   //0
	m_automata.push_back(std::make_shared<State>(false, "state 12"));  //1
	m_automata.push_back(std::make_shared<State>(false, "state 15"));  //2
	m_automata.push_back(std::make_shared<State>(false, "state 135")); //3
	m_automata.push_back(std::make_shared<State>(false, "state 16"));  //4
	m_automata.push_back(std::make_shared<State>(true, "state 146"));  //5
	m_automata.push_back(std::make_shared<State>(false, "state 17"));  //6
	m_automata.push_back(std::make_shared<State>(true, "state 18"));   //7

	GenerateDirections();
}

void Core::GraphBuilder::GenerateDirections()
{
	Direction direction1Node1{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (1)-w->(12)
	Direction direction2Node1{ 'e',  excludedTokens.at(0), m_automata.at(2) };		// (1)-e->(15)
	Direction direction3Node1{ '\0', excludedTokens.at(1), m_automata.at(0) };		// (1)-*~(e,w)->(1)
	std::vector<Direction> directionsNode1{ direction1Node1 , direction2Node1, 
		                                    direction3Node1 };	   
																					
	Direction direction1Node12{ '\0', excludedTokens.at(1), m_automata.at(0) };		// (12)-*~(e,w)->(1)
	Direction direction2Node12{ 'e',  excludedTokens.at(0), m_automata.at(3) };		// (12)-e->(135)
	Direction direction3Node12{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (12)-w->(12)
	std::vector<Direction> directionsNode12{ direction1Node12 , direction2Node12, 
		                                     direction3Node12 };  
																					
	Direction direction1Node15{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (15)-w->(12)
	Direction direction2Node15{ 'b',  excludedTokens.at(0), m_automata.at(4) };		// (15)-b->(16)
	Direction direction3Node15{ '\0', excludedTokens.at(2), m_automata.at(0) };		// (15)-*~(b,e,w)->(1)
	Direction direction4Node15{ 'e',  excludedTokens.at(0), m_automata.at(2) };		// (15)-e->(15)
	std::vector<Direction> directionsNode15{ direction1Node15, direction2Node15,
											 direction3Node15, direction4Node15 };

	Direction direction1Node135{ 'e',  excludedTokens.at(0), m_automata.at(2) };	// (135)-e->(15)
	Direction direction2Node135{ 'w',  excludedTokens.at(0), m_automata.at(1) };	// (135)-w->(12)
	Direction direction3Node135{ '\0', excludedTokens.at(2), m_automata.at(0) };	// (135)-*~(b,e,w)->1
	Direction direction4Node135{ 'b',  excludedTokens.at(0), m_automata.at(5) };	// (135)-b->(146)
	std::vector<Direction> directionsNode135{ direction1Node135, direction2Node135 ,
											  direction3Node135, direction4Node135 };

	Direction direction1Node16{ 'e',  excludedTokens.at(0), m_automata.at(2) };		// (16)-e->(15)
	Direction direction2Node16{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (16)-e->(12)
	Direction direction3Node16{ 'a',  excludedTokens.at(0), m_automata.at(6) };		// (16)-a->(17)
	Direction direction4Node16{ '\0', excludedTokens.at(2), m_automata.at(0) };		// (16)-*~(b,e,w)->(1)
	std::vector<Direction> directionsNode16{ direction1Node16, direction2Node16 ,
											 direction3Node16, direction4Node16 };

	Direction direction1Node146{ 'w',  excludedTokens.at(0), m_automata.at(1) };	// (146)-w->(12)
	Direction direction2Node146{ '\0', excludedTokens.at(3), m_automata.at(0) };	// (146)-*~(a,e,w)->(1)
	Direction direction3Node146{ 'a',  excludedTokens.at(0), m_automata.at(6) };	// (146)-a->(17)
	Direction direction4Node146{ 'e',  excludedTokens.at(2), m_automata.at(2) };	// (146)-e->(15)
	std::vector<Direction> directionsNode146{ direction1Node146, direction2Node146,
											  direction3Node146, direction4Node146 };

	Direction direction1Node17{ 'e',  excludedTokens.at(0), m_automata.at(2) };		// (17)-e->(15)
	Direction direction2Node17{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (17)-w->(12)
	Direction direction3Node17{ 'y',  excludedTokens.at(0), m_automata.at(7) };		// (17)-y->(18)
	Direction direction4Node17{ '\0', excludedTokens.at(4), m_automata.at(0) };		// (17)-*~(e,w,y)->(1)
	std::vector<Direction> directionsNode17{ direction1Node17, direction2Node17,
											 direction3Node17, direction4Node17 };

	Direction direction1Node18{ 'w',  excludedTokens.at(0), m_automata.at(1) };		// (18)-w->(12)
	Direction direction2Node18{ 'e',  excludedTokens.at(0), m_automata.at(2) };		// (18)-e->(15)
	Direction direction3Node18{ '\0', excludedTokens.at(1), m_automata.at(0) };		// (18)-*~(e,w)->(1)
	std::vector<Direction> directionsNode18{ direction1Node18 , direction2Node18, 
		                                     direction3Node18 };


	m_automata.at(0)->directions = directionsNode1;   // state 1
	m_automata.at(1)->directions = directionsNode12;  // state 12
	m_automata.at(2)->directions = directionsNode15;  // state 15
	m_automata.at(3)->directions = directionsNode135; // state 135
	m_automata.at(4)->directions = directionsNode16;  // state 16
	m_automata.at(5)->directions = directionsNode146; // state 146
	m_automata.at(6)->directions = directionsNode17;  // state 17
	m_automata.at(7)->directions = directionsNode18;  // state 18
}
