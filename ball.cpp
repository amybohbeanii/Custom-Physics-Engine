#include "ball.h"


Ball::Ball()
{
}

Ball::Ball(double x, double y, double radius, double xVelocity, double yVelocity)
	:mX(x), mY(y), mRadius(radius), mXVelocity(xVelocity), mYVelocity(yVelocity)
{

}

double Ball::getX()
{
	return mX;
}

void Ball::setX(double newX)
{
	mX = newX;
}

double Ball::getNextX()
{
	return mX + mXVelocity;
}

double Ball::getY()
{
	return mY;
}

void Ball::setY(double newY)
{
	mY = newY;
}

double Ball::getNextY()
{
	return mY + mYVelocity;
}

double Ball::getXVelocity()
{
	return mXVelocity;
}

void Ball::setXVelocity(double newXVelocity)
{
	mXVelocity = newXVelocity;
}

double Ball::getYVelocity()
{
	return mYVelocity;
}

void Ball::setYVelocity(double newYVelocity)
{
	mYVelocity = newYVelocity;
}

double Ball::getRadius()
{
	return mRadius;
}
