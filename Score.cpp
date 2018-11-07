
// Project Includes
#include "Score.h"
#include "AssetManager.h"

Score::Score()
	: TextObject() // Initialise parent class
	, m_player (nullptr)
{
	m_text.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
	m_text.setString("Score: 0");
}


void Score::Update(sf::Time _frameTime)
{
	if (m_player != nullptr)
	{
		int score = m_player->GetScore();
		m_text.setString("Score: " + std::to_string(score));
	}
}

void Score::SetPlayer(Player* _player)
{
	m_player = _player;
}