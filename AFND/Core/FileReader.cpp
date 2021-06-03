#include "FileReader.h"

Core::FileReader::FileReader()
{

}

QString Core::FileReader::GetFileAsString(const QString& filePath)
{
    m_file.setFileName(filePath);

    if (!m_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error reading file";
        return QString();
    }

    QTextStream in(&m_file);
    while (!in.atEnd()) {
        m_fileAsString = in.readLine();
    }

	return m_fileAsString;
}

