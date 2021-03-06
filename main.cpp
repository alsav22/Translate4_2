#include <QtGui>
#include "translate.h"
#include "Data.h"
#include "MySlider.h"

#include <Windows.h>
#include <cstdlib>


#ifdef DEBUG
#include <vld.h>
#endif


int main(int argc, char **argv)
{	
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    QApplication app(argc, argv);
	
	QTextCodec::setCodecForTr(QTextCodec::codecForName("CP1251"));
	

	if (!start())
	{
		app.quit();
		return 0;
	}
	
	MyWidget myWidget;
	//myWidget.change_cursor();
	myWidget.setWindowIcon(QIcon("icon.png"));
	
	QObject::connect(&myWidget, SIGNAL(destroyed()), &app, SLOT(quit()));
	
	myWidget.move(700, 300);

    myWidget.show();

	//PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 1, 0x04090409);
	
	return app.exec();
}



