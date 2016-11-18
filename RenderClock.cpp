/*
 * RenderClock.cpp
 *
 * Base class to display the returned date and time values by the ClockData.
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#include "RenderClock.h"

RenderClock::RenderClock() :
	m_hour_position(0.0),
	m_minute_position(0.0),
	m_second_position(0.0),
	m_hour(0),
	m_min(0),
	m_sec(0) {
	;
}

RenderClock::~RenderClock() {
	;
}

void RenderClock::setHourPos(float p) {
	this->m_hour_position = p;
}
void RenderClock::setMinPos(float p) {
	this->m_minute_position = p;
}
void RenderClock::setSecPos(float p) {
	this->m_second_position = p;
}
void RenderClock::setHour(int h) {
	this->m_hour = h;
}
void RenderClock::setMinute(int m) {
	this->m_min = m;
}
void RenderClock::setSecond(int s) {
	this->m_sec = s;
}