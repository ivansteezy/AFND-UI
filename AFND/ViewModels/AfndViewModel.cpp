#include "AfndViewModel.h"

UI::AfndViewModel::AfndViewModel(QObject* parent)
{

}

void UI::AfndViewModel::PrintData()
{
	qDebug() << "Se ha presionado el boton";
}

void UI::AfndViewModel::OpenFileDialog()
{
	qDebug() << "Abrir un archivo";
}