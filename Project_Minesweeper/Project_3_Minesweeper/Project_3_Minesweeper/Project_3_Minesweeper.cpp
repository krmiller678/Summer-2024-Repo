// Project_3_Minesweeper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "Board.h"
#include "TextureHelper.h"
#include <fstream>
#include <sstream>
#include <cmath>

void LoadConfig(string configFile, Board& board);
int LoadTestBoard(string testFileName, Board& board);

int main()
{

    /*============= Initilialization =============*/
    Board newBoard;
    (LoadConfig("boards/config.cfg", newBoard));
    //newBoard.PrintBoard();

    sf::RenderWindow window(sf::VideoMode(newBoard.GetWidth()*32, newBoard.GetHeight() * 32 + 100), "Minesweeper");
        
    // Sprite Setup
    sf::Sprite tileHidden(TextureHelper::GetTexture("tile_hidden"));
    sf::Sprite tileReveal(TextureHelper::GetTexture("tile_revealed"));
    sf::Sprite happyFace(TextureHelper::GetTexture("face_happy"));
    sf::Sprite loseFace(TextureHelper::GetTexture("face_lose"));
    sf::Sprite winFace(TextureHelper::GetTexture("face_win"));
    sf::Sprite debug(TextureHelper::GetTexture("debug"));
    sf::Sprite test1(TextureHelper::GetTexture("test_1"));
    sf::Sprite test2(TextureHelper::GetTexture("test_2"));
    sf::Sprite test3(TextureHelper::GetTexture("test_3"));
    sf::Sprite num1(TextureHelper::GetTexture("number_1"));
    sf::Sprite num2(TextureHelper::GetTexture("number_2"));
    sf::Sprite num3(TextureHelper::GetTexture("number_3"));
    sf::Sprite num4(TextureHelper::GetTexture("number_4"));
    sf::Sprite num5(TextureHelper::GetTexture("number_5"));
    sf::Sprite num6(TextureHelper::GetTexture("number_6"));
    sf::Sprite num7(TextureHelper::GetTexture("number_7"));
    sf::Sprite num8(TextureHelper::GetTexture("number_8"));
    sf::Sprite flag(TextureHelper::GetTexture("flag"));
    sf::Sprite mine(TextureHelper::GetTexture("mine"));
    sf::Sprite counter(TextureHelper::GetTexture("digits"));


    /*============= Event Loop =============*/
    bool gameOver = false;
    bool gameWon = false;
    bool showMines = false;
    int flagCounter = newBoard.GetMines();

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::MouseButtonPressed and gameOver == false)
                {
                    if (event.mouseButton.y < newBoard.GetHeight() * 32)
                    {
                        int row = event.mouseButton.y / 32 + 1;
                        int col = event.mouseButton.x / 32 + 1;
                        if (event.mouseButton.button == sf::Mouse::Right and newBoard.vectOfRows.at(row)[col]->GetReveal() == 0)
                        {
                            if (newBoard.vectOfRows.at(row)[col]->GetFlag() == 0)
                            {
                                newBoard.vectOfRows.at(row)[col]->SetFlag(1);
                                flagCounter--;
                            }
                            else
                            {
                                newBoard.vectOfRows.at(row)[col]->SetFlag(0);
                                flagCounter++;
                            }
                        }
                        else if (event.mouseButton.button == sf::Mouse::Left and newBoard.vectOfRows.at(row)[col]->GetFlag() == 0)
                        {
                            newBoard.vectOfRows.at(row)[col]->SetReveal(1);
                            if (newBoard.vectOfRows.at(row)[col]->GetMine() == 1)
                            {
                                gameOver = true;
                                showMines = true;
                            }
                            else if (newBoard.vectOfRows.at(row)[col]->GetSurrounding() == 0)
                                newBoard.vectOfRows.at(row)[col]->RecursiveReveal(newBoard.vectOfRows, row, col);
                        }
                    }
                    else if (event.mouseButton.y >= newBoard.GetHeight() * 32 and event.mouseButton.y < newBoard.GetHeight() * 32 + 64)
                    {
                        if (event.mouseButton.button == sf::Mouse::Left)
                        {
                            if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 64)
                            {
                                //std::cout << "Touched the smiley\n";
                                newBoard.ResetBoard();
                                gameOver = false;
                                gameWon = false;
                                showMines = false;
                                flagCounter = newBoard.GetMines();
                            }
                            else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 128 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 192)
                            {
                                //std::cout << "Touched the debug\n";
                                showMines = !showMines;
                            }
                            else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 +192 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 256)
                            {
                                //std::cout << "Touched the test1\n";
                                flagCounter = LoadTestBoard("boards/testboard1.brd", newBoard);
                            }
                            else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 256 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 320)
                            {
                                //std::cout << "Touched the test2\n";
                                flagCounter = LoadTestBoard("boards/testboard2.brd", newBoard);
                            }
                            else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 320 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 384)
                            {
                                //std::cout << "Touched the test3\n";
                                flagCounter = LoadTestBoard("boards/testboard3.brd", newBoard);
                            }
                        }
                    }
                }
                else if (event.type == sf::Event::MouseButtonPressed and gameOver == true)
                {
                    if (event.mouseButton.y >= newBoard.GetHeight() * 32 and event.mouseButton.y < newBoard.GetHeight() * 32 + 64)
                    {
                        if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 64)
                        {
                            //std::cout << "Touched the smiley\n";
                            newBoard.ResetBoard();
                            gameOver = false;
                            gameWon = false;
                            showMines = false;
                            flagCounter = newBoard.GetMines();
                        }
                        else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 192 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 256)
                        {
                            //std::cout << "Touched the test1\n";
                            flagCounter = LoadTestBoard("boards/testboard1.brd", newBoard);
                            gameOver = false;
                            gameWon = false;
                            showMines = false;
                        }
                        else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 256 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 320)
                        {
                            //std::cout << "Touched the test2\n";
                            flagCounter = LoadTestBoard("boards/testboard2.brd", newBoard);
                            gameOver = false;
                            gameWon = false;
                            showMines = false;
                        }
                        else if (event.mouseButton.x > newBoard.GetWidth() * 32 / 2 + 320 and event.mouseButton.x < newBoard.GetWidth() * 32 / 2 + 384)
                        {
                            //std::cout << "Touched the test3\n";
                            flagCounter = LoadTestBoard("boards/testboard3.brd", newBoard);
                            gameOver = false;
                            gameWon = false;
                            showMines = false;
                        }
                    }
                }

            }

            // Check for Victory condition
            if (gameWon == false)
            {
                gameWon = true;
                for (unsigned int i = 0; i < newBoard.GetHeight(); i++)
                {
                    if (gameWon == false)
                        break;
                    for (unsigned int j = 0; j < newBoard.GetWidth(); j++)
                    {
                        if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetMine() == (newBoard.vectOfRows.at(i + 1)[j + 1]->GetReveal()))
                        {
                            gameWon = false;
                            break;
                        }
                    }
                }
                if (gameWon == true)
                {
                    showMines = true;
                    gameOver = true;
                    flagCounter = 0;
                }
            }


            window.clear(sf::Color::White);
            // Draw Tiles
            for (unsigned int i = 0; i < newBoard.GetHeight(); i++)
            {
                for (unsigned int j = 0; j < newBoard.GetWidth(); j++)
                {
                    if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetReveal() == 0)
                    {
                        tileHidden.setPosition(32.f * j, 32.f * i);
                        window.draw(tileHidden);
                        if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetFlag() == 1)
                        {
                            flag.setPosition(32.f * j, 32.f * i);
                            window.draw(flag);
                        }
                    }
                    else
                    {
                        tileReveal.setPosition(32.f * j, 32.f * i);
                        window.draw(tileReveal);
                        if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() > 0)
                        {
                            if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 1)
                            {
                                num1.setPosition(32.f * j, 32.f * i);
                                window.draw(num1);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 2)
                            {
                                num2.setPosition(32.f * j, 32.f * i);
                                window.draw(num2);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 3)
                            {
                                num3.setPosition(32.f * j, 32.f * i);
                                window.draw(num3);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 4)
                            {
                                num4.setPosition(32.f * j, 32.f * i);
                                window.draw(num4);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 5)
                            {
                                num5.setPosition(32.f * j, 32.f * i);
                                window.draw(num5);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 6)
                            {
                                num6.setPosition(32.f * j, 32.f * i);
                                window.draw(num6);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 7)
                            {
                                num7.setPosition(32.f * j, 32.f * i);
                                window.draw(num7);
                            }
                            else if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetSurrounding() == 8)
                            {
                                num8.setPosition(32.f * j, 32.f * i);
                                window.draw(num8);
                            }
                        }
                    }
                }
            }

            // Draw Buttons
            debug.setPosition(newBoard.GetWidth() * 32 / 2 + 128, newBoard.GetHeight() * 32);
            test1.setPosition(newBoard.GetWidth() * 32 / 2 + 192, newBoard.GetHeight() * 32);
            test2.setPosition(newBoard.GetWidth() * 32 / 2 + 256, newBoard.GetHeight() * 32);
            test3.setPosition(newBoard.GetWidth() * 32 / 2 + 320, newBoard.GetHeight() * 32);
            window.draw(debug);
            window.draw(test1);
            window.draw(test2);
            window.draw(test3);

            if (gameOver == false)
            {
                happyFace.setPosition(newBoard.GetWidth() * 32 / 2, newBoard.GetHeight() * 32);
                window.draw(happyFace);
            }
            else if (gameWon == false)
            {
                loseFace.setPosition(newBoard.GetWidth() * 32 / 2, newBoard.GetHeight() * 32);
                window.draw(loseFace);
            }
            else
            {
                winFace.setPosition(newBoard.GetWidth() * 32 / 2, newBoard.GetHeight() * 32);
                window.draw(winFace);
            }



            // Show mines
            if (showMines == true)
            {
                if (gameOver == false)
                {
                    for (unsigned int i = 0; i < newBoard.GetHeight(); i++)
                    {
                        for (unsigned int j = 0; j < newBoard.GetWidth(); j++)
                        {
                            if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetMine() == 1)
                            {
                                mine.setPosition(32.f * j, 32.f * i);
                                window.draw(mine);
                            }
                        }
                    }
                }
                else if (gameWon == false)
                {
                    for (unsigned int i = 0; i < newBoard.GetHeight(); i++)
                    {
                        for (unsigned int j = 0; j < newBoard.GetWidth(); j++)
                        {
                            if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetMine() == 1)
                            {
                                tileReveal.setPosition(32.f * j, 32.f * i);
                                window.draw(tileReveal);
                                mine.setPosition(32.f * j, 32.f * i);
                                window.draw(mine);
                            }
                        }
                    }
                }
                else
                {
                    for (unsigned int i = 0; i < newBoard.GetHeight(); i++)
                    {
                        for (unsigned int j = 0; j < newBoard.GetWidth(); j++)
                        {
                            if (newBoard.vectOfRows.at(i + 1)[j + 1]->GetMine() == 1)
                            {
                                flag.setPosition(32.f * j, 32.f * i);
                                window.draw(flag);
                            }
                        }
                    }
                }
            }

            // Show counter
            counter.setPosition(0, newBoard.GetHeight() * 32);
            if (flagCounter < 0)
            {
                counter.setTextureRect(sf::IntRect(210, 0, 21, 32));
                window.draw(counter);
            }
            else
            {
                counter.setTextureRect(sf::IntRect(21*abs(flagCounter/100), 0, 21, 32));
                window.draw(counter);
            }
            counter.setPosition(21, newBoard.GetHeight() * 32);
            counter.setTextureRect(sf::IntRect(21*abs(flagCounter%100/10), 0, 21, 32));
            window.draw(counter);
            counter.setPosition(42, newBoard.GetHeight() * 32);
            counter.setTextureRect(sf::IntRect(21 * abs(flagCounter % 10), 0, 21, 32));
            window.draw(counter);

            window.display();
        }



        TextureHelper::Clear();
        return 0;
}

void LoadConfig(string configFile, Board& board)
{
    std::ifstream config(configFile);
    unsigned int width;
    unsigned int height;
    unsigned int mines;
    string token;
    std::getline(config, token);
    width = std::stoi(token);
    std::getline(config, token);
    height = std::stoi(token);
    std::getline(config, token);
    mines = std::stoi(token);
    Board newBoard(width,height,mines);
    board = newBoard;
}

int LoadTestBoard(string testFileName, Board& board)
{
    int flagCounter = 0;
    board.ResetBoard();
    std::ifstream test(testFileName);
    string line;
    char token;
    for (unsigned int i = 0; i < board.GetHeight(); i++)
    {
        (getline(test, line));
        std::istringstream stream(line);
        for (unsigned int j = 0; j < board.GetWidth(); j++)
        {
            stream.get(token);
            if (token == '1')
                flagCounter++;
            board.vectOfRows.at(i + 1)[j + 1]->SetMine(int(token)-48);
        }
    }

    board.CalcSurrounding();
    return flagCounter;
}