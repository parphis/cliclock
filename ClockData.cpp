/*
 * ClockData.cpp
 * Calculate and provide access to system date and time values.
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */

#include "ClockData.h"

void ClockData::calculateDividers(void) {
	this->m_hour_divider = (float)this->m_hour/(float)23;
	this->m_minute_divider = (float)this->m_min/(float)60;
	this->m_second_divider = (float)this->m_sec/(float)60;
}

void ClockData::getSystemLocalTime(void) {
	time_t rawtime;
	struct tm * timeinfo;

	time(&rawtime);

	timeinfo = localtime(&rawtime);

	this->m_year = timeinfo->tm_year;
	this->m_yday = timeinfo->tm_yday;
	this->m_wday = timeinfo->tm_wday;
	this->m_sec = timeinfo->tm_sec;
	this->m_mon = timeinfo->tm_mon;
	this->m_min = timeinfo->tm_min;
	this->m_mday = timeinfo->tm_mday;
	this->m_isdst = timeinfo->tm_isdst;
	this->m_hour = timeinfo->tm_hour;
}

void ClockData::getDateTime(void) {
	switch((int)ClockData::MethodType) {
	case mLocalSystem:
		this->getSystemLocalTime();
		break;
	case mTestData:
		this->m_hour = 23;
		this->m_min = 59;
		this->m_sec = 20;
		break;
	default: ;
	}

	this->calculateDividers();
}

ClockData::ClockData() :
		m_sec(0),
		m_min(0),
		m_hour(0),
		m_mday(0),
		m_mon(0),
		m_year(0),
		m_wday(0),
		m_yday(0),
		m_isdst(0),
		m_hour_divider(1),
		m_minute_divider(1),
		m_second_divider(1),
		MethodType(mTestData){
	;
}

ClockData::~ClockData() {
	;
}

void ClockData::_get(void) {
	this->getDateTime();
}

int ClockData::getYear(void) {
	return this->m_year;
}
int ClockData::getMonth(void) {
	return this->m_mon;
}
int ClockData::getDay(void) {
	return this->m_mday;
}
int ClockData::getHour(void) {
	return this->m_hour;
}
int ClockData::getMinute(void) {
	return this->m_min;
}
int ClockData::getSecond(void) {
	return this->m_sec;
}

float ClockData::getHourDivider(void) {
	return this->m_hour_divider;
}
float ClockData::getMinuteDivider(void) {
	return this->m_minute_divider;
}
float ClockData::getSecondDivider(void) {
	return this->m_second_divider;
}

