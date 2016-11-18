/*
 * CLIClock.cpp
 *
 * Displays the clock in the command line like this (12:35):
 * ---------------|12--|35------------
 *
 *  Created on: 2014.01.09.
 *      Author: istvan_vig
 */
 
#include "CLIClock.h"

CLIClock::CLIClock() :
	m_timeline_len(70),
	m_hour_place(0),
	m_minute_place(0),
	m_second_place(0) {
	;

}

CLIClock::~CLIClock() {
	;
}

void CLIClock::show() {
	this->m_hour_place = this->m_hour_position * this->m_timeline_len;
	this->m_minute_place = this->m_minute_position * this->m_timeline_len;
	this->m_second_place = this->m_second_position * this->m_timeline_len;

	//std::cout << this->m_hour_position << ":" << this->m_minute_position << std::endl;
	//std::cout << "Hour place: " << this->m_hour_place << ", minute place: " << this->m_minute_place << std::endl;

	std::ostringstream oo;
	bool show_separator = true;

	for(int i=0; i<=this->m_timeline_len; i++) {
		if(i==this->m_hour_place) {
			oo << "H" << this->m_hour;
			show_separator = false;
		}
		if(i==this->m_minute_place) {
			oo << "M" << this->m_min;
			show_separator = false;
		}
		if(i==this->m_second_place) {
			oo << "S" << this->m_sec;
			show_separator = false;
		}
		if (show_separator) oo << "-";

		show_separator = true;
	}

	std::cout << "\r" << oo.str();
}

void CLIClock::setTimelineLen(int l) {
	this->m_timeline_len = l;
}
