#ifndef FINDER_H
#define FINDER_H

#include "Graph.h"

namespace Core
{
	class Finder
	{
	public:
		Finder(const ::Graph& graph, const std::string& input);

		std::size_t GetWebCoincidences() const;
		std::size_t GetEbayCoincidences() const;
		void CheckIfIsCoincidence(StatePtr state);
		bool IsSearchFinished() const;

	private:
		void FindCoincidendes();

	private:
		::Graph m_graph;
		Coincidences m_coincidences;
		bool m_searchFinished;
		std::string m_input;
		StatePtr aux;
	};
}

#endif
