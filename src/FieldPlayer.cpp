#include "FieldPlayer.h"
#include "SteeringAider.h"

#include <OgreManualObject.h>

FieldPlayer::FieldPlayer(const QString name, float bounding_radius, float max_speed, 
	float max_force, float mass, float turn_rate, QString mesh_handle, QString material_handle,  Team* team, 
	int home_region, PlayerRole role)
	: Player(name, bounding_radius, max_speed, max_force, mass, turn_rate, mesh_handle, material_handle, team, home_region, role) {}

void FieldPlayer::onInitialize()
{
	Player::onInitialize();

	// Set up state machine 
	// and initialize state

	mSteering->separationOn();

	mShootCoolTime = addComponent(new CoolingTimeComponent(0.5));
}

void FieldPlayer::onDeinitialize()
{
	Player::onDeinitialize();
}

//float sum = 1.f;

void FieldPlayer::onUpdate(double time_diff)
{
	this->mIsUpdatingAfterChange = (time_diff == 0);

	//Update here
	getSteering()->calculate();

	//mPhysicsBody->setCentralForce(BtOgre::Convert::toBullet(getSteering()->getSteeringForce()));

	Ogre::Vector3 velocity = getVelocity();

	//ManualObject* obj;

	Player::onUpdate(time_diff);
}

StateMachine<FieldPlayer>* FieldPlayer::getStateMachine() const 
{
	return mStateMachine;
}

bool FieldPlayer::isReadyToKick() const
{
	return mShootCoolTime->ready();
}

bool FieldPlayer::handleMessage(const Message& msg) const 
{
	return mStateMachine->handleMessage(msg);	
}