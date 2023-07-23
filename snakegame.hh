#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include <iostream>  // time e rand
#include <ncurses.h> // para as funções da ncurses
#include <vector>    // lógica das coordenadas
#include <unistd.h>  // usleep()

// Lógica para armazenar as coordenadas
struct SnakeType
{
  int s_x, s_y;
  SnakeType(int, int);
  SnakeType();
};

class SnakeGame
{
protected:
  int m_maxwidth;  // tamanho da largura da tela
  int m_maxheight; // tamanho da altura da tela
  std::vector<SnakeType> snake;
  char m_snake_char; // desenha a snake
  SnakeType v_food;
  char m_food_char;
  int m_delay;
  char m_direction;
  bool m_tail_stop;
  int m_score;

public:
  SnakeGame();
  ~SnakeGame();
  void m_insert_food();
  void movesnake();
  bool _collide();
  void start();
};
#endif
