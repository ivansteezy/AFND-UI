#include "Finder.h"

Core::Finder::Finder(const ::Graph& graph, const std::string& input) :
	m_graph(graph),
	m_searchFinished(false),
	m_input(input),
	m_coincidences({ 0, 0 })
{
	FindCoincidendes();
}

void Core::Finder::FindCoincidendes()
{
	auto aux = m_graph.at(0);
	for (const auto& currentCharacter : m_input)
	{
		for (const auto& transition : aux->directions)
		{
			if (currentCharacter == transition.token)
			{
				aux = transition.destinyNode;
				CheckIfIsCoincidence(aux);
				break;
			}

			if (!transition.excludedTokens.empty())
			{
				if (transition.excludedTokens.find(currentCharacter) == std::string::npos)
				{
					aux = transition.destinyNode;
					CheckIfIsCoincidence(aux);
					break;
				}
			}
		}
	}

	m_searchFinished = true;
}

void Core::Finder::CheckIfIsCoincidence(StatePtr state)
{
	if (state->isFinalState && state->stateName == "state 146")
	{
		m_coincidences.webCoincidences++;
	}
	if (state->isFinalState && state->stateName == "state 18")
	{
		m_coincidences.ebayCoincidences++;
	}
}

std::size_t Core::Finder::GetWebCoincidences() const
{
	return m_coincidences.webCoincidences;
}

std::size_t Core::Finder::GetEbayCoincidences() const
{
	return m_coincidences.ebayCoincidences;
}

bool Core::Finder::IsSearchFinished() const
{
	return m_searchFinished;
}
