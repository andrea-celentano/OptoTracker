#ifndef TOFPETHIT_HG
#define TOFPETHIT_HG


#include "TObject.h"

class TTofpetHit:public TObject{


private:

	short m_channel,m_xi,m_yi,m_detector;
	double m_channelIdleTime,m_tacIdleTime;


	float m_eventEnergy,m_eventTot;
	float m_TQT,m_TQE;

	long long time;



public:

	short getChannel() const {
		return m_channel;
	}

	void setChannel(short channel) {
		m_channel = channel;
	}

	double getChannelIdleTime() const {
		return m_channelIdleTime;
	}

	void setChannelIdleTime(double channelIdleTime) {
		m_channelIdleTime = channelIdleTime;
	}

	short getDetector() const {
		return m_detector;
	}

	void setDetector(short detector) {
		m_detector = detector;
	}

	float getEventEnergy() const {
		return m_eventEnergy;
	}

	void setEventEnergy(float eventEnergy) {
		m_eventEnergy = eventEnergy;
	}

	float getEventTot() const {
		return m_eventTot;
	}

	void setEventTot(float eventTot) {
		m_eventTot = eventTot;
	}

	double getTacIdleTime() const {
		return m_tacIdleTime;
	}

	void setTacIdleTime(double tacIdleTime) {
		m_tacIdleTime = tacIdleTime;
	}

	float getTqe() const {
		return m_TQE;
	}

	void setTqe(float tqe) {
		m_TQE = tqe;
	}

	float getTqt() const {
		return m_TQT;
	}

	void setTqt(float tqt) {
		m_TQT = tqt;
	}

	short getXi() const {
		return m_xi;
	}

	void setXi(short xi) {
		m_xi = xi;
	}

	short getYi() const {
		return m_yi;
	}

	void setYi(short yi) {
		m_yi = yi;
	}

	long long getTime() const {
		return time;
	}

	void setTime(long long time) {
		this->time = time;
	}

	ClassDef(TTofpetHit,1);
};





#endif
