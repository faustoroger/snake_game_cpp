#include <ncurses.h> // para as funções da ncurses
#include <iostream>  // time e rand
#include <vector>    // lógica das coordenadas
#include <unistd.h>  //usleep()

// Lógica para armazenar as coordenadas
struct SnakeType
{
    int s_x, s_y;
    SnakeType(int s_col, int s_row)
    {
        s_x = s_col;
        s_y = s_row;
    }
    SnakeType()
    {
        s_x = 0;
        s_y = 0;
    }
};

class SnakeGame
{
protected:
    int m_maxwidth;  // tamanho da largura da tela
    int m_maxheight; // tamanho da altura da tela
    std::vector<SnakeType> snake;
    char m_snake_char; // desenha a snake

public:
    SnakeGame()
    {
        initscr();
        nodelay(stdscr, true); // para a snake não parar
        keypad(stdscr, true);  // KEY_...,
        noecho();              // para não exibir teclas na tela
        curs_set(0);           // desliga o cursor no terminal

        m_maxwidth = getmaxx(stdscr) / 2;
        m_maxheight = getmaxy(stdscr) / 2;

        m_snake_char = 'o'; // desenha a snake

        // Desenha o espaço do game
        for (int i = 0; i < m_maxwidth - 1; ++i)
        {
            move(0, i);
            if (i == 0)
            {
                addch('+');
            }
            else if (i == (m_maxwidth - 2))
            {
                addch('+');
            }
            else
            {
                addch('-');
            }
        }

        for (int i = 1; i < m_maxheight - 1; ++i)
        {
            move(i, 0);
            if (i == (m_maxheight - 2))
            {
                addch('+');
            }
            else
            {
                addch('|');
            }
        }

        for (int i = 0; i < m_maxwidth - 1; ++i)
        {
            move(m_maxheight - 2, i);
            if (i == 0)
            {
                addch('+');
            }
            else if (i == (m_maxwidth - 2))
            {
                addch('+');
            }
            else
            {
                addch('-');
            }
        }

        for (int i = 1; i < m_maxheight - 1; ++i)
        {
            move(i, m_maxwidth - 2);
            if (i == (m_maxheight - 2))
            {
                addch('+');
            }
            else if (i == 0)
            {
                addch('+');
            }
            else
            {
                addch('|');
            }
        }

        // desenha o tamanho inicial da snake
        for (int i = 0; i < 5; ++i)
        {
            snake.push_back(SnakeType(40 + i, 10));
        }

        // Lógica para posicionar
        for (int i = 0; i < snake.size(); ++i)
        {
            move(snake[i].s_y, snake[i].s_x);
            addch(m_snake_char);
        }
    }

    ~SnakeGame()
    {
        nodelay(stdscr, false);
        getch();
        endwin();
    }
};

int main(int argc, char **argv)
{
    SnakeGame s;
    return EXIT_SUCCESS;
}