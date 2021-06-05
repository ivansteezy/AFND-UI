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

	private:
		void FindCoincidendes();
		void CheckIfIsCoincidence(StatePtr state);
		bool IsSearchFinished() const;

	private:
		::Graph m_graph;
		std::string m_input;
		bool m_searchFinished;
		Coincidences m_coincidences;
	};
}

#endif
