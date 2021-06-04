#include "AfndViewModel.h"

UI::AfndViewModel::AfndViewModel(QObject* parent)
{

}

void UI::AfndViewModel::GetFileTextFromReader()
{
	FileAsString(m_fileReader.GetFileAsString(m_filePathString));
}

void UI::AfndViewModel::BeginFind()
{
	Core::GraphBuilder builder;
	Core::Finder finder(builder.GetGraph(), m_fileAsString.toLower().toStdString());

	m_ebayCoincidences = finder.GetEbayCoincidences();
	m_webCoincidences = finder.GetWebCoincidences();
}

QString UI::AfndViewModel::FileAsString() const
{
	return m_fileAsString;
}

void UI::AfndViewModel::FileAsString(const QString& fileAsString)
{
	if (fileAsString != m_fileAsString)
	{
		m_fileAsString = fileAsString;
		emit FileAsStringChanged();
	}
}

QString UI::AfndViewModel::FilePathString() const
{
	return m_filePathString;
}

void UI::AfndViewModel::FilePathString(const QString& filepathString)
{
	if (filepathString != m_filePathString)
	{
		m_filePathString = filepathString;
		emit FilePathStringChanged();
	}
}

int UI::AfndViewModel::WebCoincidences() const
{
	return m_webCoincidences;
}

void UI::AfndViewModel::WebCoincidences(int webCoincidences)
{
	if (webCoincidences != m_webCoincidences)
	{
		m_webCoincidences = webCoincidences;
		emit WebCoincidencesChanged();
	}
}

int UI::AfndViewModel::EbayCoincidences() const
{
	return m_ebayCoincidences;
}

void UI::AfndViewModel::EbayCoincidences(int ebayCoincidences)
{
	if (ebayCoincidences != m_ebayCoincidences)
	{
		m_ebayCoincidences = ebayCoincidences;
		emit EbayCoincidencesChanged();
	}
}