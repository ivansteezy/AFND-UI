#ifndef GRAPH_H
#define GRAPH_H

#include "Foundation.h"

namespace Core
{
	class GraphBuilder
	{
	public:
		GraphBuilder();

	public:
		[[no_discard]]
		::Graph GetGraph() const;

	private:
		void BuildGrpah();
		void GenerateDirections();

		::Graph m_automata;
	};
}

#endif
