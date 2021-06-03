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

	public:
		explicit AfndViewModel(QObject* parent = nullptr);

		Q_INVOKABLE void PrintData();
		Q_INVOKABLE QString GetFileText(QString filePath);

		QString FileAsString() const;
		void FileAsString(const QString& fileAsString);

	signals:
		void FileAsStringChanged();

	public slots:

	private:
		Core::FileReader m_fileReader;
		QString m_fileAsString;
	};
}

#endif