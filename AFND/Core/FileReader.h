#ifndef FILEREADER_H
#define FILEREADER_H
#include <QFile>
#include <QString>
#include <QFileDialog>

namespace Core
{
	class FileReader
	{
	public:
		FileReader();

	public:
		QString GetFileAsString();
		void ReadFile(QString filePath);
		void OpenFileDialog();

	private:
		QString m_filePath;
		QFile m_file;
	};
}

#endif
