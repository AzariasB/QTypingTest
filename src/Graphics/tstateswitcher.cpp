#include "tstateswitcher.h"

TStateSwitcher::TStateSwitcher(QStateMachine *machine)
	:QState(machine),
	  stateCount_(0),
	  lastIndex_(0)
{

}

void TStateSwitcher::onEntry(QEvent *event)
{
	int n;
}

void TStateSwitcher::onExit(QEvent *event)
{

}

void TStateSwitcher::addState(QState *state, QAbstractAnimation *animation)
{

}

/*
 *
 * class StateSwitcher : public QState
{
	Q_OBJECT
public:
	StateSwitcher(QStateMachine *machine)
		: QState(machine), m_stateCount(0), m_lastIndex(0)
	{ }
	//![10]

	//![11]
	virtual void onEntry(QEvent *) Q_DECL_OVERRIDE
	{
		int n;
		while ((n = (qrand() % m_stateCount + 1)) == m_lastIndex)
		{ }
		m_lastIndex = n;
		machine()->postEvent(new StateSwitchEvent(n));
	}
	virtual void onExit(QEvent *) Q_DECL_OVERRIDE {}
	//![11]

	//![12]
	void addState(QState *state, QAbstractAnimation *animation) {
		StateSwitchTransition *trans = new StateSwitchTransition(++m_stateCount);
		trans->setTargetState(state);
		addTransition(trans);
		trans->addAnimation(animation);
	}
	//![12]

private:
	int m_stateCount;
	int m_lastIndex;
};
 *
 * */
