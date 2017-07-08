/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   vector2f.h
 * Author: boutina
 *
 * Created on 15 mars 2017, 19:00
 */

#ifndef BOUNCE_H
#define BOUNCE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QWidget>
#include <QDebug>
#include <QResizeEvent>
#include <QTimer>
#include <QtMultimedia/QSound>

#include "bullet.h"
#include "letterwall.h"
#include "recttext.h"
#include "animatedsprite.h"
#include "resourcemanager.h"
#include "bouncemenu.h"
#include "bouncedata.h"

// Size (x*x) of a single wall
#define WALL_SIZE 40

// Number of walls per side
#define WALL_NUMBER 20

enum class GameSate{
	Pause,
	Play,
	Lost
};

/**
 * @brief The Bounce class
 * Bounce class is the main class for the bounce game
 * The game consist of a simple bullet bouncing between different walls
 * anti-clockwise, the player has to presse the key corresponding to
 * the letter the bullet of targetting
 */
class BounceGame : public QGraphicsView
{
	Q_OBJECT
public:
	BounceGame(BounceData *dataHolder, QWidget *parent = 0);

	/**
	 * @brief init
	 * Inits all the differents components of the object
	 * Does not reset anything
	 */
	void init();

	virtual ~BounceGame();

	void resizeEvent(QResizeEvent *event);


public slots:
	/**
	 * @brief tick
	 * Tick event, called by the timer to update the game display/logic
	 *
	 * @param dt time since last update
	 */
	void tick(int dt);

	/**
	 * @brief play
	 * When the player choose to play (clicks the 'play' button of the menu)
	 */
	void play();

	/**
	 * @brief stateChanges
	 * Called whenever the state of the game changes, used to update the UI and logic
	 *
	 * @param nwState the nwState of the game
	 */
	void stateChanges(GameSate nwState);

	/**
	 * @brief restart
	 * Restarts the game
	 * (called when user presses 'enter')
	 */
	void restart();

signals:
	/**
	 * @brief gameEnded Trigerred when the 'esc' key is pressed
	 * @param score score when key is pressed
	 */
	void gameEnded(int score);

protected:
	void keyPressEvent(QKeyEvent *event) override;

	void keyReleaseEvent(QKeyEvent *event) override;

	void mousePressEvent(QMouseEvent *event) override;

	void loadResources();

private:	
	// All the possible letters to display (contains punctuation too)
	static const QString alphabet;

	// Starting lives
	static const int startingLives;

	/**
	 * @brief looseLife
	 * When bullet hits a wall without
	 * having it activated
	 */
	void looseLife();

	/**
	 * @brief spawnSparkles
	 * Spawns sparkles 'particle' (it's a sprite actually)
	 * at the given position
	 * @param position the position where to spawn the sparkles
	 */
	void spawnSparkles(const QPointF &position);

	/**
	 * @brief spawnPuff
	 * Spawns a 'puff' effect at the given position
	 * @param position the position where to spawn the puff effect
	 */
	void spawnPuff(const QPointF &position);

	/**
	 * @brief randomSparkle
	 * Gets a random sparkles from the existing images
	 * @return a pixmap of the random sparkle
	 */
	const QPixmap &randomSparkle();

	/**
	 * @brief createWall
	 * Creates a single wall, containing <numberOfWalls> walls
	 * Used to create the four walls of the game
	 *
	 * @param numberOfWalls number of wall for a side
	 * @param start point where to start placing the walls
	 * @param increment difference between each wall
	 * @param wallSide size of a wall
	 * @return all the walls created (and added to the scene)
	 */
	QVector<LetterWall*> createWall(int numberOfWalls, QPoint start, QPoint increment, DIRECTION wallSide);

	/**
	 * @brief initWalls
	 * Init the 4 walls the the game (in the four directions)
	 */
	void initWalls();

	/**
	 * @brief nextTarget
	 * Updates the next target of the bullet, and
	 * the display to indicate the user that the target has changed
	 *
	 * @param nwTarget the new target that the bullet must hit
	 */
	void nextTarget(LetterWall *nwTarget = nullptr);

	/**
	 * @brief uncollideBullet
	 * Used to uncollide a bullet from a wall, when a bullet collide a wall
	 * it might be to 'deep' in the wall, an the 'collide' function might be called
	 * a second time. To avoid that, we 'uncollide' the bullet from the given wall
	 *
	 * @param collider the wall that collide with the bullet
	 * @param targetDir the opposite direction of the wall
	 */
	void uncollideBullet(LetterWall *collider, DIRECTION targetDir);

	/**
	 * @brief getEndMessage
	 * Bakes the message to display when the game is over
	 * (with the score and indications)
	 *
	 * @return the item to add in the scene
	 */
	RectText *createMessageBox(QString msg);

	/**
	 * @brief randomLetter
	 * Selects a random letter from the given alphabet
	 * @return a random letter
	 */
	QChar randomLetter();

	/**
	 * @brief randomTarget
	 * Finds a random letterWall in the wall of the given direction
	 * If no direction is given, will choose a random wall direction
	 *
	 * @param nwDirection
	 * @return a randomly-selected wall
	 */
	LetterWall *randomTarget(DIRECTION nwDirection = NO_DIRECTION);


	// The current target of the bullet
	LetterWall *currentTarget_ = nullptr;

	// View's scene
	QGraphicsScene scene_;

	// Game's bullet
	Bullet *bullet_;

	// The last char pressed by the user (is kept, even when the user releases the key)
	QChar currentPressed_ = '\0';

	//Associated hash, to easily find all the wall that contains the given char
	QHash<QChar, QVector<LetterWall*>> equivalents_;

	// Associated hash, each direction has several wals
	QHash<DIRECTION, QVector<LetterWall*>> walls_;

	// Timer to update the game logic every n seconds
	QTimer timer_;

	// All the pixmap are stored here
	ResourceManager rm_;

	// State of the game
	GameSate state_ = GameSate::Play;

	BounceData *dataHolder_;

};

#endif // BOUNCE_H