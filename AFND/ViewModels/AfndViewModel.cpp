#include "AfndViewModel.h"

UI::AfndViewModel::AfndViewModel(QObject* parent)
{

}

void UI::AfndViewModel::PrintData()
{
	qDebug() << "Se ha presionado el boton";
}

QString UI::AfndViewModel::GetFileText(QString filePath)
{
	return m_fileReader.GetFileAsString(filePath);
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
