#ifndef AFNDVIEWMODEL_H
#define AFNDVIEWMODEL_h

#include <QObject>
#include <QString>
#include <QDebug>

#include "Core/FileReader.h"

namespace UI
{
	class AfndViewModel : public QObject
	{
		Q_OBJECT;
		Q_PROPERTY(QString fileAsString READ FileAsString WRITE FileAsString NOTIFY FileAsStringChanged)
		Q_PROPERTY(QString filePathString READ FilePathString WRITE FilePathString NOTIFY FilePathStringChanged)

	public:
		explicit AfndViewModel(QObject* parent = nullptr);

	public:
		Q_INVOKABLE void GetFileTextFromReader();//misc

		QString FileAsString() const; //getter
		void FileAsString(const QString& fileAsString); //setter

		QString FilePathString() const;
		void FilePathString(const QString& filepathString);

	signals:
		void FilePathStringChanged();
		void FileAsStringChanged(); //signal

	public slots:

	private:
		void PrintData(); //misc

	private:
		Core::FileReader m_fileReader;
		QString m_fileAsString;
		QString m_filePathString;
	};
}

#endif