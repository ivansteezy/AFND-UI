#include "FileReader.h"

Core::FileReader::FileReader()
{

}

QString Core::FileReader::GetFileAsString(QString& filePath)
{
    QFile file;
    m_fileAsString = "";
    auto sanitizedString = filePath.remove(0, 8);
    file.setFileName(sanitizedString);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Error reading file";
        return QString();
    }

    QTextStream in(&file);
    while (!in.atEnd())
    {
        m_fileAsString.append(in.readLine());
    }
    file.close();

	return m_fileAsString;
}

