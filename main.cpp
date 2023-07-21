#include <iostream>  // time e rand
#include <ncurses.h> // para as funções da ncurses
#include <vector>    // lógica das coordenadas
#include <unistd.h>  //usleep()

class SnakeGame
{
protected:
    int m_maxwidth;  // tamanho da largura da tela
    int m_maxheight; // tamanho da altura da tela

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
            move(m_maxwidth - 2, i);
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