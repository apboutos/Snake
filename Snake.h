#ifndef SNAKE_H
#define SNAKE_H


class Snake
{
    private: int posX[100];
             int posY[100];
             char direction[100];
             bool exist[100];


    public:
        Snake(); //done
        virtual ~Snake();
        bool driver(); //
        void painter(); //done
        void reset();  //done
        void resolver();

};

#endif // SNAKE_H
