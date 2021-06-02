#ifndef AFNDVIEWMODEL_H
#define AFNDVIEWMODEL_h

#include <QObject>
#include <QDebug>

namespace UI
{
	class AfndViewModel : public QObject
	{
		Q_OBJECT;

	public:
		explicit AfndViewModel(QObject* parent = nullptr);

		Q_INVOKABLE void PrintData();

	signals:

	public slots:
	};
}

#endif