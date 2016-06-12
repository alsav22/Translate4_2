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
	
	myWidget.move(700, 400);

    myWidget.show();

	int X = myWidget.uiForm ->volumeSlider ->x();
	int Y = myWidget.uiForm ->volumeSlider ->y();

	MySlider* myslider = new MySlider();
	myWidget.uiForm ->volumeSlider = myslider;
	//QPoint p(X + 125, Y + 15);
	QPoint p(0, 0);
	QMouseEvent* pressEvent = new QMouseEvent(QEvent::MouseButtonPress, p, Qt::LeftButton, Qt::LeftButton, Qt::NoModifier);
    //QCoreApplication::sendEvent(&myWidget, pressEvent);
	QCoreApplication::sendEvent(myWidget.uiForm ->volumeSlider, pressEvent);
	
	
	//PostMessage(GetForegroundWindow(), WM_INPUTLANGCHANGEREQUEST, 1, 0x04090409);
	
	return app.exec();
}



