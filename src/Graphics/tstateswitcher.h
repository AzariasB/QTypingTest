#ifndef TSTATESWITCHER_H
#define TSTATESWITCHER_H

#include <QState>
#include <QStateMachine>

class TStateSwitcher : public QState
{
	Q_OBJECT
public:
	TStateSwitcher(QStateMachine *machine );

	virtual void onEntry(QEvent *event) override;

	virtual void onExit(QEvent *event) override;

	void addState(QState *state, QAbstractAnimation *animation);

private:
	int stateCount_;
	int lastIndex_;
};

#endif // TSTATESWITCHER_H

