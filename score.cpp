#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) :QGraphicsTextItem(parent){
    //inititalize score
    score = 0;

    //draw the text box
    setPlainText("Score:  " + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",30));
}

void Score::increase_score()
{
    ++score;
    setPlainText("Score:  " + QString::number(score));
}

int Score::get_score()
{
    return score;
}




