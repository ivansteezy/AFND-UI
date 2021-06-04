#ifndef AFNDVIEWMODEL_H
#define AFNDVIEWMODEL_h

#include <QObject>
#include <QString>
#include <QDebug>

#include "Core/FileReader.h"
#include "Core/Finder.h"

namespace UI
{
	class AfndViewModel : public QObject
	{
		Q_OBJECT;
		Q_PROPERTY(QString fileAsString READ FileAsString WRITE FileAsString NOTIFY FileAsStringChanged)
		Q_PROPERTY(QString filePathString READ FilePathString WRITE FilePathString NOTIFY FilePathStringChanged)
		Q_PROPERTY(int webCoincidences READ WebCoincidences WRITE WebCoincidences NOTIFY WebCoincidencesChanged)
		Q_PROPERTY(int ebayCoincidences READ EbayCoincidences WRITE EbayCoincidences NOTIFY EbayCoincidencesChanged)

	public:
		explicit AfndViewModel(QObject* parent = nullptr);

	public:
		Q_INVOKABLE void GetFileTextFromReader();
		Q_INVOKABLE void BeginFind();

		QString FileAsString() const;
		void FileAsString(const QString& fileAsString);

		int WebCoincidences() const;
		void WebCoincidences(int coincidences);

		int EbayCoincidences() const;
		void EbayCoincidences(int coincidences);

		QString FilePathString() const;
		void FilePathString(const QString& filepathString);

	signals:
		void FileAsStringChanged();
		void FilePathStringChanged();
		void WebCoincidencesChanged();
		void EbayCoincidencesChanged();

	public slots:

	private:
		Core::FileReader m_fileReader;
		QString m_fileAsString;
		QString m_filePathString;

		int m_webCoincidences;
		int m_ebayCoincidences;
	};
}

#endif