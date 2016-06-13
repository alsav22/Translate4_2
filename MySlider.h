#ifndef MY_SLIDER
#define MY_SLIDER
#include <phonon>
//#include <QSlider>

class MySlider: public Phonon::VolumeSlider
{
public:
	MySlider(QWidget* parent = 0)
	{}

protected:

	void mousePressEvent(QMouseEvent* e)
	{
		qDebug() << "PressEvent MySlider  " << e ->x() << "  " << e ->y();
	}
};
#endif