
#include "Player.h"

void Player::Aiming(sf::RenderWindow &window)
{
	//Executing where to face and where to aim

	legX = mousePosX - armT1.getPosition().x;
	legY = mousePosY - armT1.getPosition().y;
	hyp = sqrt(legX*legX + legY*legY);
	angle = (asin(legY / hyp) * 180) / 3.1415;

	if (legX > 0 && legY < 0)
	{
		//Quadrant 1
		angle = angle - 90;
	}
	else if (legX < 0 && legY < 0)
	{
		//Quadrant 2
		angle = 90 - angle;
	}
	else if (legX < 0 && legY > 0)
	{
		//Quadrant 3
		angle = 90 - angle;
	}
	else if (legX > 0 && legY > 0)
	{
		//Quadrant 4
		angle = angle - 90;
	}

	armT2.setRotation(angle);
	armB2.setRotation(angle);

	if (facing == LEFT)
	{
		armT1.setRotation(angle - 20);
		armB1.setRotation(angle - 20);
	}
	else if (facing == RIGHT)
	{
		armT1.setRotation(angle + 20);
		armB1.setRotation(angle + 20);
	}

	//Shooting
	/*if (userInputM == LEFTCLICK)
	{
		Projectile projectile(armT1.getPosition().x, armT1.getPosition().y);

		projectile.speed = 1200;

		sum = abs(legX) + abs(legY);

		ratioX = (abs(legX) / sum) * projectile.speed; // proArray->size();
		ratioY = (abs(legY) / sum) * projectile.speed; // proArray->size();

		if (legX > 0 && legY < 0)
		{
			//Quadrant 1
			ratioX = ratioX;
			ratioY = -ratioY;
		}
		else if (legX < 0 && legY < 0)
		{
			//Quadrant 2
			ratioX = -ratioX;
			ratioY = -ratioY;
		}
		else if (legX < 0 && legY > 0)
		{
			//Quadrant 3
			ratioX = -ratioX;
			ratioY = ratioY;
		}
		else if (legX > 0 && legY > 0)
		{
			//Quadrant 4
			ratioX = ratioX; 
			ratioY = ratioY;
		}
		
		projectile.ratioX = ratioX;
		projectile.ratioY = ratioY;

		proArray->push_back(projectile);
	}*/
}

void Player::Running(sf::RenderWindow &window)
{
	if (footHeight < 0)
	{
		footHeight = 0;
	}
	if ((grounded == true || canJump == true) && speedX != 0)
	{
		footSpeed = speedX;
		torsoHeight = -pow(footPos / 18, 2) + 70;
	}
	else
	{
		//torsoHeight = baseTorsoHeight;
		footSpeed = speedX / 4;
	}

	if (time == 0)
	{
		footVelocity = 0;
	}
	else
	{
		footVelocity = footSpeed * time;
	}

	//foot step oscilation 
	if (speedX < 0 && legToggle == 0)
	{
		if (footPos <= -50)
		{
			legToggle = 1;
		}
		footPos = footPos + footVelocity;
	}

	if (speedX < 0 && legToggle == 1)
	{
		if (footPos >= 50)
		{
			legToggle = 0;
		}
		footPos = footPos - footVelocity;
	}

	if (speedX > 0 && legToggle == 0)
	{
		if (footPos <= -50)
		{
			legToggle = 1;
		}
		footPos = footPos - footVelocity;
	}

	if (speedX > 0 && legToggle == 1)
	{
		if (footPos >= 50)
		{
			legToggle = 0;
		}
		footPos = footPos + footVelocity;
	}

	// from here, calculates angle of legs
	footHyp = sqrt(pow(torsoHeight - footHeight, 2) + pow(footPos, 2));
	angleA = acos((torsoHeight - footHeight) / footHyp) * 180 / 3.1415;
	angle2 = (pow(legLength / 2, 2) + pow(legLength / 2, 2) - pow(footHyp, 2)) / (2 * (legLength / 2)*(legLength / 2)); //a^2 + b^2 - c^2 / 2ab, sss triangle equation
	angle2 = acos(angle2) * 180 / 3.1415;
	angleC = (180 - angle2) / 2;
	angle1 = 180 - (angleA + angleC);


	if (footPos >= 0)
	{
		legT1.setRotation((180 - angle1) * -1);// left, only for pos
		legT2.setRotation(legT1.getRotation() - ((180 - angle2) * -1));
	}
	else
	{
		angle1 = 180 - angleA + angleC;
		legT1.setRotation(180 - angle1);// left, only for pos
		legT2.setRotation(legT1.getRotation() + (180 - angle2));
	}

	footHyp = sqrt(pow(torsoHeight - footHeight, 2) + pow(footPos, 2));
	angleA = acos((torsoHeight - footHeight) / footHyp) * 180 / 3.1415;
	angle2 = (pow(legLength / 2, 2) + pow(legLength / 2, 2) - pow(footHyp, 2)) / (2 * (legLength / 2)*(legLength / 2)); //a^2 + b^2 - c^2 / 2ab, sss triangle equation
	angle2 = acos(angle2) * 180 / 3.1415;
	angleC = (180 - angle2) / 2;
	angle1 = 180 - (angleA + angleC);

	if (footPos <= 0)
	{
		legB1.setRotation((180 - angle1) * -1);// left, only for pos
		legB2.setRotation(legB1.getRotation() - ((180 - angle2) * -1));
	}
	else
	{
		angle1 = 180 - angleA + angleC;
		legB1.setRotation(180 - angle1);// left, only for pos
		legB2.setRotation(legB1.getRotation() + (180 - angle2));
	}

	//torso angle
	torso.setRotation(15);
	if (userInputK == RIGHT && facing == RIGHT)
	{
		torso.setRotation(20);
	}
	if (userInputK == LEFT && facing == RIGHT)
	{
		torso.setRotation(10);
	}

	if (userInputK == RIGHT && facing == LEFT)
	{
		torso.setRotation(10);
	}
	if (userInputK == LEFT && facing == LEFT)
	{
		torso.setRotation(20);
	}

	//Determining what direction to face and where the player will aim
	if (mousePosX < playerX)
	{
		facing = LEFT;

		legB1.setRotation(legB1.getRotation() * -1);
		legB2.setRotation(legB2.getRotation() * -1);

		legT1.setRotation(legT1.getRotation() * -1);
		legT2.setRotation(legT2.getRotation() * -1);

		torso.setRotation(torso.getRotation() * -1);
	}

	if (mousePosX > playerX)
	{
		facing = RIGHT;
	}
}

void Player::Jump(Controls *controls)
{
	if (controls->space == true && grounded == true)
	{
		speedY = fallSpeed;
		grounded = false;
	}
}

void Player::Idle()
{
	/*if (speedX == 0 && idleToggle == 0 && torsoHeight >= baseTorsoHeight - 10)
	{
	if (footPos >= baseTorsoHeight + 9 && footPos <= baseTorsoHeight + 11)
	{
	idleToggle = 1;
	}
	torsoHeight = torsoHeight - (50/time);
	}
	else if (speedX == 0 && idleToggle == 1 && torsoHeight <= baseTorsoHeight + 10)
	{
	if (torsoHeight <= baseTorsoHeight - 9 && torsoHeight >= baseTorsoHeight - 11)
	{
	idleToggle = 0;
	}
	torsoHeight = torsoHeight + (50/time);
	}

	if (speedX != 0 || grounded == false)
	{
	torsoHeight = baseTorsoHeight;
	}*/
}