#ifndef TOFPETHIT_HG
#define TOFPETHIT_HG


#include "TObject.h"

class TTofpetHit:public TObject{


private:

	short m_channel,m_xi,m_yi,m_detector;
	double m_channelIdleTime,m_tacIdleTime;


	float m_energy,m_ToT;
	float m_TQT,m_TQE;

	long long m_time;



public:

	TTofpetHit();
	virtual ~TTofpetHit();
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

	float getEnergy() const {
		return m_energy;
	}

	void getEnergy(float eventEnergy) {
		m_energy = eventEnergy;
	}

	float getToT() const {
		return m_ToT;
	}

	void setTot(float eventTot) {
		m_ToT = eventTot;
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
		return m_time;
	}

	void setTime(long long time) {
		m_time = time;
	}

	ClassDef(TTofpetHit,1);
};





#endif
