/* 
 * File:   KeyboardLetters.h
 * Author: boutina
 *
 * Created on 10 novembre 2015, 13:48
 */

#ifndef KEYBOARDLETTERS_H
#define	KEYBOARDLETTERS_H

#include <QString>
#include <QChar>

class KeyboardLetters {
public:
    enum KEYBOARD_LAYOUT{QWERTY,AZERTY,QWERTZ};
    enum LEARN_STEPS{L1_IN,L1_MI,L1_RI,L1_PI,L2_IN,L2_MI,L2_RI,L2_PI,L0_};
    
    KeyboardLetters();
    KeyboardLetters(const KeyboardLetters& orig);
    virtual ~KeyboardLetters();
private:

};

#endif	/* KEYBOARDLETTERS_H */

