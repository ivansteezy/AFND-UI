#include "AfndViewModel.h"

UI::AfndViewModel::AfndViewModel(QObject* parent)
{

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


//----------------------
void UI::AfndViewModel::PrintData()
{
	qDebug() << "Se ha presionado el boton";
}

void UI::AfndViewModel::GetFileTextFromReader()
{
	FileAsString(m_fileReader.GetFileAsString(m_filePathString));
}
