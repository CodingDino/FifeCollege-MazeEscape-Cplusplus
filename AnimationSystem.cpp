// Library Includes
#include <assert.h>

// Project Includes
#include "AnimationSystem.h"


AnimationSystem::AnimationSystem()
	: m_sprite()
	, m_animations()
	, m_currentAnimation(nullptr)
{

}

void AnimationSystem::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;

	// Update sprite for all animations in this system
	for (auto it = m_animations.begin(); it != m_animations.end(); ++it)
	{
		it->second.SetSprite(_sprite);
	}
}

Animation& AnimationSystem::CreateAnimation(std::string _name)
{
	// Throw an error if this animation is already in our system
	assert(m_animations.find(_name) == m_animations.end());

	Animation& newAnimation = m_animations[_name];

	if (m_sprite)
		newAnimation.SetSprite(*m_sprite);

	return newAnimation;
}

void AnimationSystem::Play(std::string _newAnimation)
{
	if (m_currentAnimation)
		m_currentAnimation->Stop();

	// Throw an error if this animation is NOT in our system
	assert(m_animations.find(_newAnimation) != m_animations.end());

	m_currentAnimation = &m_animations[_newAnimation];
	m_currentAnimation->Play();
}

void AnimationSystem::Play()
{
	if (m_currentAnimation)
		m_currentAnimation->Play();
}

void AnimationSystem::Pause()
{
	if (m_currentAnimation)
		m_currentAnimation->Pause();
}

void AnimationSystem::Stop()
{
	if (m_currentAnimation)
		m_currentAnimation->Stop();
}

void AnimationSystem::Update(sf::Time _frameTime)
{
	if (m_currentAnimation)
		m_currentAnimation->Update(_frameTime);
}