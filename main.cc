#include <iostream>
#include <random>

#include "ui_button.h"

int main()
{
	sf::RenderWindow window_(sf::VideoMode(450, 700), "Dice Game");

	UiButton btn_one_;
	UiButton btn_tow_;
	UiButton btn_three_;
	UiButton btn_four_;
	UiButton btn_five_;
	UiButton btn_six_;

	UiButton btn_bet_one_;
	UiButton btn_bet_tow_;
	UiButton btn_bet_three_;
	UiButton btn_bet_four_;
	UiButton btn_bet_five_;
	UiButton btn_bet_six_;

	UiButton btn_end_;

	sf::Text text_choice_;
	sf::Text text_bankroll_;
	sf::Font font_;

	sf::Text text_win_or_lose_;
	sf::Text text_invalid_bet_;

	sf::Sprite dice_sprite_;
	sf::Texture dice_one_texture_;
	sf::Texture dice_tow_texture_;
	sf::Texture dice_three_texture_;
	sf::Texture dice_four_texture_;
	sf::Texture dice_five_texture_;
	sf::Texture dice_six_texture_;

	int number_choice_ = 0;
	int bet_choice_ = 0;

	bool is_win_ = false;
	bool is_lose_ = false;
	bool is_invalid_bet_ = false;
	bool is_end_ = false;
	bool is_choice_ = true;
	bool is_bet_ = false;


	bool choice_number_lock_ = false;
	bool choice_bet_lock_ = false;



	int choice_number_ = 0;
	int choice_bet_ = 0;
	int result_ = 0;

	int player_bankroll_ = 1000;
	int bet_ = 0;

	bool replay_ = true;

	bool is_choice_number = true;
	bool is_choice_bet = false;

	dice_one_texture_.loadFromFile("ressources/dice_one.png");
	dice_tow_texture_.loadFromFile("ressources/dice_tow.png");
	dice_three_texture_.loadFromFile("ressources/dice_three.png");
	dice_four_texture_.loadFromFile("ressources/dice_four.png");
	dice_five_texture_.loadFromFile("ressources/dice_five.png");
	dice_six_texture_.loadFromFile("ressources/dice_six.png");

	if (!font_.loadFromFile("ressources/kenvector_future.ttf")) {
		// Handle error: Unable to load font
	}

	text_choice_.setFont(font_);
	text_choice_.setFillColor(sf::Color::Yellow);

	text_bankroll_.setFont(font_);
	text_bankroll_.setFillColor(sf::Color::Yellow);

	text_win_or_lose_.setFont(font_);
	text_win_or_lose_.setFillColor(sf::Color::Yellow);

	text_invalid_bet_.setFont(font_);
	text_invalid_bet_.setFillColor(sf::Color::Yellow);

	btn_one_.CreateButton(sf::Vector2f(window_.getSize().x / 6, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "1", 30, sf::Color::Yellow);
	btn_tow_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 100, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "2", 30, sf::Color::Yellow);
	btn_three_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 200, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "3", 30, sf::Color::Yellow);
	btn_four_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 300, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "4", 30, sf::Color::Yellow);
	btn_five_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 100, window_.getSize().y / 2 + 250), sf::Vector2f(95, 50), "5", 30, sf::Color::Yellow);
	btn_six_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 200, window_.getSize().y / 2 + 250), sf::Vector2f(95, 50), "6", 30, sf::Color::Yellow);

	btn_bet_one_.CreateButton(sf::Vector2f(window_.getSize().x / 6, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "10", 30, sf::Color::Yellow);
	btn_bet_tow_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 100, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "50", 30, sf::Color::Yellow);
	btn_bet_three_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 200, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "100", 30, sf::Color::Yellow);
	btn_bet_four_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 300, window_.getSize().y / 2 + 175), sf::Vector2f(95, 50), "250", 30, sf::Color::Yellow);
	btn_bet_five_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 100, window_.getSize().y / 2 + 250), sf::Vector2f(95, 50), "500", 30, sf::Color::Yellow);
	btn_bet_six_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 200, window_.getSize().y / 2 + 250), sf::Vector2f(95, 50), "1000", 30, sf::Color::Yellow);

	btn_end_.CreateButton(sf::Vector2f(window_.getSize().x / 6 + 150, window_.getSize().y / 2 + 200), sf::Vector2f(95, 50), "Quit", 30, sf::Color::Yellow);

	btn_one_.call_back_ = [&]()
		{
			number_choice_ = 1;
			is_choice_ = false;
			is_bet_ = true;
		};
	btn_tow_.call_back_ = [&]()
		{
			number_choice_ = 2;
			is_choice_ = false;
			is_bet_ = true;
		};
	btn_three_.call_back_ = [&]()
		{
			number_choice_ = 3;
			is_choice_ = false;
			is_bet_ = true;
		};
	btn_four_.call_back_ = [&]()
		{
			number_choice_ = 4;
			is_choice_ = false;
			is_bet_ = true;
		};
	btn_five_.call_back_ = [&]()
		{
			number_choice_ = 5;
			is_choice_ = false;
			is_bet_ = true;
		};
	btn_six_.call_back_ = [&]()
		{
			number_choice_ = 6;
			is_choice_ = false;
			is_bet_ = true;
		};

	btn_bet_one_.call_back_ = [&]()
		{
			bet_choice_ = 1;
			is_bet_ = false;
			is_choice_ = true;
		};
	btn_bet_tow_.call_back_ = [&]()
		{
			bet_choice_ = 2;
			is_bet_ = false;
			is_choice_ = true;
		};
	btn_bet_three_.call_back_ = [&]()
		{
			bet_choice_ = 3;
			is_bet_ = false;
			is_choice_ = true;
		};
	btn_bet_four_.call_back_ = [&]()
		{
			bet_choice_ = 4;
			is_bet_ = false;
			is_choice_ = true;
		};
	btn_bet_five_.call_back_ = [&]()
		{
			bet_choice_ = 5;
			is_bet_ = false;
			is_choice_ = true;
		};
	btn_bet_six_.call_back_ = [&]()
		{
			bet_choice_ = 6;
			is_bet_ = false;
			is_choice_ = true;
		};

	text_invalid_bet_.setString("Invalid Bet");
	const sf::FloatRect text_invalid_bet = text_invalid_bet_.getLocalBounds();
	text_invalid_bet_.setOrigin(text_invalid_bet.left + text_invalid_bet.width / 2.0f, text_invalid_bet.top + text_invalid_bet.height / 2.0f);
	text_invalid_bet_.setPosition(window_.getSize().x / 2, window_.getSize().y - 50);

	sf::Clock clock;

	double dt_ = 0;

	while (window_.isOpen())
	{
		do
		{
			sf::Event event;
			while (window_.pollEvent(event))
			{

				int choice_test = 0;
				number_choice_ = 0;
				if (is_choice_number)
				{
					if (btn_one_.HandleEvent(event, dt_) ||
						btn_tow_.HandleEvent(event, dt_) ||
						btn_three_.HandleEvent(event, dt_) ||
						btn_four_.HandleEvent(event, dt_) ||
						btn_five_.HandleEvent(event, dt_) ||
						btn_six_.HandleEvent(event, dt_))
					{
						choice_test = number_choice_;
					}


					if (choice_test > 0)
					{
						is_lose_ = false;
						is_win_ = false;
						choice_number_ = choice_test;
						choice_number_lock_ = true;
						is_choice_number = false;
						is_choice_bet = true;
					}

					if (is_choice_number && !choice_number_lock_ && !is_end_)
					{
						choice_number_lock_ = true;
						choice_bet_lock_ = false;
					}
				}
				else if (is_choice_bet)
				{
					choice_test = 0;

					bet_choice_ = 0;

					if (btn_bet_one_.HandleEvent(event, dt_) ||
						btn_bet_tow_.HandleEvent(event, dt_) ||
						btn_bet_three_.HandleEvent(event, dt_) ||
						btn_bet_four_.HandleEvent(event, dt_) ||
						btn_bet_five_.HandleEvent(event, dt_) ||
						btn_bet_six_.HandleEvent(event, dt_))
					{
						choice_test = bet_choice_;
					}

					if (choice_test > 0)
					{
						choice_bet_ = choice_test;
						is_invalid_bet_ = false;
						choice_bet_lock_ = true;
						is_choice_bet = false;
					}
				}

			}

			if (choice_bet_lock_ && !is_end_)
			{
				bet_ = 0;

				switch (choice_bet_)
				{
				case 1:
				{
					bet_ = 10;
				}
				break;
				case 2:
				{
					bet_ = 50;
				}
				break;
				case 3:
				{
					bet_ = 100;
				}
				break;
				case 4:
				{
					bet_ = 250;
				}
				break;
				case 5:
				{
					bet_ = 500;
				}
				break;
				case 6:
				{
					bet_ = 1000;
				}
				break;
				default:
				{
					EXIT_FAILURE;
				}
				}

				if (bet_ > player_bankroll_)
				{
					choice_bet_lock_ = false;
					is_bet_ = true;
					is_choice_ = false;
					is_invalid_bet_ = true;
				}
				if (choice_bet_lock_)
				{
					bool good_rand;

					//Roll Die
					do
					{
						result_ = 0;

						std::random_device rand;
						std::uniform_int_distribution<int> nb_rand{ 1,  6 };

						result_ = nb_rand(rand);

						if (result_ <= 0 || result_ > 6)
						{
							good_rand = false;
						}
						else
						{
							good_rand = true;
						}

					} while (!good_rand);

					switch (result_)
					{
					case 1:
					{
						dice_sprite_.setTexture(dice_one_texture_);
					}
					break;
					case 2:
					{
						dice_sprite_.setTexture(dice_tow_texture_);
					}
					break;
					case 3:
					{
						dice_sprite_.setTexture(dice_three_texture_);
					}
					break;
					case 4:
					{
						dice_sprite_.setTexture(dice_four_texture_);
					}
					break;
					case 5:
					{
						dice_sprite_.setTexture(dice_five_texture_);
					}
					break;
					case 6:
					{
						dice_sprite_.setTexture(dice_six_texture_);
					}
					break;
					default:
					{
						std::cout << "Error choice image";
					}
					}

					dice_sprite_.setOrigin(dice_sprite_.getGlobalBounds().width / 2, dice_sprite_.getGlobalBounds().height / 2);
					dice_sprite_.setPosition(window_.getSize().x / 2, window_.getSize().y / 4 + 45);

					//Compare with player choice
					if (result_ == choice_number_)
					{

						is_win_ = true;
						if (is_win_)
						{
							text_win_or_lose_.setString("You Win " + std::to_string(bet_ * 2) + "$");
						}

						const sf::FloatRect text_win_or_lose = text_win_or_lose_.getLocalBounds();
						text_win_or_lose_.setOrigin(text_win_or_lose.left + text_win_or_lose.width / 2.0f, text_win_or_lose.top + text_win_or_lose.height / 2.0f);
						text_win_or_lose_.setPosition(window_.getSize().x / 2, window_.getSize().y - 50);

						player_bankroll_ += bet_ * 2;
					}
					else
					{

						is_lose_ = true;

						if (is_lose_)
						{
							text_win_or_lose_.setString("You Lose " + std::to_string(bet_) + "$");
						}

						const sf::FloatRect text_win_or_lose = text_win_or_lose_.getLocalBounds();
						text_win_or_lose_.setOrigin(text_win_or_lose.left + text_win_or_lose.width / 2.0f, text_win_or_lose.top + text_win_or_lose.height / 2.0f);
						text_win_or_lose_.setPosition(window_.getSize().x / 2, window_.getSize().y - 50);

						player_bankroll_ -= bet_;
					}

					choice_number_lock_ = false;
					choice_number_ = false;
					is_choice_number = true;
				}
			}

			if (player_bankroll_ <= 0)
			{
				is_end_ = true;
				is_bet_ = false;
				is_choice_ = false;

				bool is_quit = false;
				is_quit = btn_end_.HandleEvent(event, dt_);
				if (is_quit)
				{
					replay_ = false;
					window_.close();

					player_bankroll_ = 1000;
				}
			}


			if (event.type == sf::Event::Closed)
			{
				window_.close();
				replay_ = false;
			}


			window_.clear(sf::Color::Blue);

			if (is_choice_)
			{
				text_choice_.setString("Choice Number");
			}

			if (is_bet_)
			{
				text_choice_.setString("Choice Bet");
			}


			const sf::FloatRect text_choice_rect = text_choice_.getLocalBounds();
			text_choice_.setOrigin(text_choice_rect.left + text_choice_rect.width / 2.0f, text_choice_rect.top + text_choice_rect.height / 2.0f);
			text_choice_.setPosition(window_.getSize().x / 2, window_.getSize().y / 2 + 100);

			text_bankroll_.setString("Bankroll : " + std::to_string(player_bankroll_) + "$");
			const sf::FloatRect text_bankroll_rect = text_bankroll_.getLocalBounds();
			text_bankroll_.setOrigin(text_bankroll_rect.left + text_bankroll_rect.width / 2.0f, text_bankroll_rect.top + text_bankroll_rect.height / 2.0f);
			text_bankroll_.setPosition(225, window_.getSize().y - 15);

			window_.draw(dice_sprite_);

			if (is_choice_)
			{
				window_.draw(btn_one_);
				window_.draw(btn_tow_);
				window_.draw(btn_three_);
				window_.draw(btn_four_);
				window_.draw(btn_five_);
				window_.draw(btn_six_);
			}

			if (is_bet_)
			{
				window_.draw(btn_bet_one_);
				window_.draw(btn_bet_tow_);
				window_.draw(btn_bet_three_);
				window_.draw(btn_bet_four_);
				window_.draw(btn_bet_five_);
				window_.draw(btn_bet_six_);
			}

			if (is_end_)
			{
				window_.draw(btn_end_);
			}

			if (is_choice_ || is_bet_)
			{
				window_.draw(text_choice_);
			}

			window_.draw(text_bankroll_);

			if (is_win_ || is_lose_)
			{
				window_.draw(text_win_or_lose_);
			}

			if (is_invalid_bet_)
			{
				window_.draw(text_invalid_bet_);
			}

			window_.display();

			dt_ = clock.restart().asSeconds();
		} while (replay_);
	}

}