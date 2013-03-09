#ifndef FOOTBALL_AI_TEAM
#define FOOTBALL_AI_TEAM

#include "Pitch.h"

#include <Scene/Node.hpp>

#include <vector>

class Ball;
class Pitch;
class Player;
class Goal;

class Team : public dt::Node
{
public:

	enum TeamColor
	{
		RED,
		BLUE
	};

	Team(Ball* ball, Pitch* pitch, TeamColor color, Goal* goal);

	void onInitialize();

	void onUpdate(double time_diff);

public:
	// Get and set
	TeamColor getTeamColor() const;
	Pitch* getPitch() const;
	Ball* getBall() const;
	Goal* getGoal() const;

	Team* getOpponent() const;
	void setOpponent(Team* opponent);


private:

	/** 
	  * Genrate players 
	  */
	void createPlayers();

private:

	//StateMachine<Team>* mStateMachine;   //!< StateMachine

	Ball* mBall;
	Pitch* mPitch;
	Goal* mGoal;
	TeamColor mColor;                      //!< Team color, RED or BLUE
	Team* mOpponent;                       //!< The opponent team of this
	std::vector<Player*> mPlayers;         //!< Pointers of players this team hold

	Player* mControllingPlayer;            //!< Pointer to the player which is controlling the ball 

};

#endif