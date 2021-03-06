#pragma once

#include "Particle/Particle.h"

class ParticleSource : public Entity
{
public:
	//particle vector size
	int vectorSize;
	int vectorCount;

	//source
	int speedHigh;
	int speedLow;
	int durationHigh;
	int durationLow;
	int sizeLow;
	int sizeHigh;

	int unusedParticles;
	double unusedSpawn;

	int intSpawn;
	double spawn;
	int spawnWidth;
	double spawnPerSec;
	double spawnRemainder;

	std::vector<Particle> particles;
	std::vector<Particle>::iterator particlesIter;

	ParticleSource();
	~ParticleSource();

	//types
	void SpawnSource(Physics& physics);

	void Update(Physics& physics);
	void Draw(Physics& physics, sf::RenderWindow& window);
};