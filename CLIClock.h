/*
 * CLIClock.h
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#ifndef CLICLOCK_H_
#define CLICLOCK_H_

#include <iostream>
#include <sstream>
#include <string>
#include "RenderClock.h"

class CLIClock: public RenderClock {
private:
	int m_timeline_len;
	int m_hour_place;
	int m_minute_place;
	int m_second_place;
public:
	CLIClock();
	virtual ~CLIClock();

	void show();

	void setTimelineLen(int l);
};

#endif /* CLICLOCK_H_ */
