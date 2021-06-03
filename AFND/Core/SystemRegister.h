#ifndef SYSTEM_REGISTER_H
#define SYSTEM_REGISTER_H

#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "ViewModels/AfndViewModel.h"


namespace Core
{
	class SystemRegister
	{
	public:
		SystemRegister(QQmlApplicationEngine& engine);

	public:
		void InitializeSystemRegister();

	private:
	};
}

#endif
