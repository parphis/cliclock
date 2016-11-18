/*
 * RenderClock.h
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#ifndef RENDERCLOCK_H_
#define RENDERCLOCK_H_

class RenderClock {
private:
protected:
	float m_hour_position;
	float m_minute_position;
	float m_second_position;
	int m_hour;
	int m_min;
	int m_sec;
public:
	RenderClock();
	virtual ~RenderClock();

	virtual void show() = 0;

	void setHourPos(float p);
	void setMinPos(float p);
	void setSecPos(float p);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
};

#endif /* RENDERCLOCK_H_ */