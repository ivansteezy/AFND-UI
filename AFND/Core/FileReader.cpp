#include "FileReader.h"

Core::FileReader::FileReader()
{

}

QString Core::FileReader::GetFileAsString(QString& filePath)
{
    auto sanitizedString = filePath.remove(0, 8);
    m_file.setFileName(sanitizedString);

    if (!m_file.open(QIODevice::ReadOnly | QIODevice::Text)) 
    {
        qDebug() << "Error reading file";
        return QString();
    }

    QTextStream in(&m_file);
    while (!in.atEnd()) 
    {
        m_fileAsString.append(in.readLine());
    }
    m_file.close();

	return m_fileAsString;
}

