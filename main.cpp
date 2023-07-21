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
    SnakeType v_food;
    char m_food_char;

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

        m_food_char = 'X';
        srand(time(NULL)); // para toda vez que iniciar o game, a posição da comida ser aleatória
        m_insert_food();

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

        move(v_food.s_y, v_food.s_x);
        addch(m_food_char);
    }

    ~SnakeGame()
    {
        nodelay(stdscr, false);
        getch();
        endwin();
    }

    void m_insert_food()
    {
        while (true)
        {
            int tmpx = rand() % m_maxwidth + 1;
            int tmpy = rand() % m_maxheight + 1;

            for (int i = 0; i < snake.size(); ++i)
            {
                if (snake[i].s_x == tmpx && snake[i].s_y == tmpy)
                {
                    continue;
                }
            }

            if (tmpx >= m_maxwidth - 2 || tmpy >= m_maxheight - 3)
            {
                continue;
            }

            v_food.s_x = tmpx;
            v_food.s_y = tmpy;
            break;

            move(v_food.s_y, v_food.s_x);
            addch(m_food_char);
            refresh();
        }
    }
};

int main(int argc, char **argv)
{
    SnakeGame s;
    return EXIT_SUCCESS;
}